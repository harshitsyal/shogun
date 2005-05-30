#include "regression/svr/LibSVR.h"
#include "lib/io.h"

CLibSVR::CLibSVR()
{
	model=NULL;
}

CLibSVR::~CLibSVR()
{
	free(model);
}

bool CLibSVR::train()
{
	free(model);

	struct svm_problem problem;
	struct svm_parameter param;
	struct svm_node* x_space;

	assert(get_labels() && get_labels()->get_num_labels());
	problem.l=get_labels()->get_num_labels();
	CIO::message(M_INFO, "%d trainlabels\n", problem.l);

	problem.y=new double[problem.l];
	problem.x=new struct svm_node*[problem.l];
	x_space=new struct svm_node[2*problem.l];

	assert(problem.y);
	assert(problem.x);
	assert(x_space);

	for (int i=0; i<problem.l; i++)
	{
		problem.y[i]=get_labels()->get_label(i);
		problem.x[i]=&x_space[2*i];
		x_space[2*i].index=i;
		x_space[2*i+1].index=-1;
	}

	int weights_label[2]={-1,+1};
	double weights[2]={1.0,get_C2()/get_C1()};

	assert(get_kernel());

	param.svm_type=EPSILON_SVR; // epsilon SVR
	param.kernel_type = LINEAR;
	param.degree = 3;
	param.gamma = 0;	// 1/k
	param.coef0 = 0;
	param.nu = 0.5;
	param.kernel=get_kernel();
	param.cache_size = get_kernel()->get_cache_size();
	param.C = get_C1();
	param.eps = epsilon;
	param.p = tube_epsilon;
	param.shrinking = 1;
	param.nr_weight = 2;
	param.weight_label = weights_label;
	param.weight = weights;

	const char* error_msg = svm_check_parameter(&problem,&param);

	if(error_msg)
	{
		fprintf(stderr,"Error: %s\n",error_msg);
		exit(1);
	}

	model = svm_train(&problem, &param);

	if (model)
	{
		assert(model->nr_class==2);
		assert(model->l>0);
		assert(model->SV);
		assert(model->sv_coef && model->sv_coef[0]);

		int num_sv=model->l;

		create_new_model(num_sv);

		//workaround for libsvm bug (?)
		//if the first example has a positive label the whole decision function
		//is inverted, i.e. f(x) becomes -f(x)

		if (problem.y[0]>=0)
		{
			CIO::message(M_WARN, "inverting libsvm's decision function as first label is >= 0\n");
			set_bias(-model->rho[0]);

			for (int i=0; i<num_sv; i++)
			{
				set_support_vector(i, (model->SV[i])->index);
				set_alpha(i, model->sv_coef[0][i]);
			}
		}
		else
		{
			set_bias(model->rho[0]);

			for (int i=0; i<num_sv; i++)
			{
				set_support_vector(i, (model->SV[i])->index);
				set_alpha(i, -model->sv_coef[0][i]);
			}
		}

		delete[] problem.x;
		delete[] problem.y;
		delete[] x_space;

		return true;
	}
	else
		return false;
}

