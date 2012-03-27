%{
#include <shogun/features/FeatureTypes.h>
#include <shogun/kernel/Kernel.h>
#include <shogun/kernel/KernelNormalizer.h>
#include <shogun/kernel/PyramidChi2.h>
#include <shogun/kernel/ANOVAKernel.h>
#include <shogun/kernel/AUCKernel.h>
#include <shogun/kernel/AvgDiagKernelNormalizer.h>
#include <shogun/kernel/RidgeKernelNormalizer.h>
#include <shogun/kernel/CauchyKernel.h>
#include <shogun/kernel/Chi2Kernel.h>
#include <shogun/kernel/CombinedKernel.h>
#include <shogun/kernel/CommUlongStringKernel.h>
#include <shogun/kernel/CommWordStringKernel.h>
#include <shogun/kernel/CircularKernel.h>
#include <shogun/kernel/ConstKernel.h>
#include <shogun/kernel/CustomKernel.h>
#include <shogun/kernel/DiagKernel.h>
#include <shogun/kernel/DistantSegmentsKernel.h>
#include <shogun/kernel/DiceKernelNormalizer.h>
#include <shogun/kernel/ExponentialKernel.h>
#include <shogun/kernel/ScatterKernelNormalizer.h>
#include <shogun/kernel/VarianceKernelNormalizer.h>
#include <shogun/kernel/DistanceKernel.h>
#include <shogun/kernel/FixedDegreeStringKernel.h>
#include <shogun/kernel/GaussianKernel.h>
#include <shogun/kernel/DirectorKernel.h>
#include <shogun/kernel/GaussianShiftKernel.h>
#include <shogun/kernel/GaussianShortRealKernel.h>
#include <shogun/kernel/HistogramIntersectionKernel.h>
#include <shogun/kernel/HistogramWordStringKernel.h>
#include <shogun/kernel/IdentityKernelNormalizer.h>
#include <shogun/kernel/InverseMultiQuadricKernel.h>
#include <shogun/kernel/DotKernel.h>
#include <shogun/kernel/LinearKernel.h>
#include <shogun/kernel/LinearStringKernel.h>
#include <shogun/kernel/SparseSpatialSampleStringKernel.h>
#include <shogun/kernel/LocalAlignmentStringKernel.h>
#include <shogun/kernel/LocalityImprovedStringKernel.h>
#include <shogun/kernel/MatchWordStringKernel.h>
#include <shogun/kernel/MultitaskKernelNormalizer.h>
#include <shogun/kernel/MultitaskKernelMklNormalizer.h>
#include <shogun/kernel/MultitaskKernelTreeNormalizer.h>
#include <shogun/kernel/MultitaskKernelMaskNormalizer.h>
#include <shogun/kernel/MultitaskKernelMaskPairNormalizer.h>
#include <shogun/kernel/MultitaskKernelPlifNormalizer.h>
#include <shogun/kernel/MultiquadricKernel.h>
#include <shogun/kernel/OligoStringKernel.h>
#include <shogun/kernel/PolyKernel.h>
#include <shogun/kernel/PolyMatchStringKernel.h>
#include <shogun/kernel/PowerKernel.h>
#include <shogun/kernel/LogKernel.h>
#include <shogun/kernel/GaussianMatchStringKernel.h>
#include <shogun/kernel/SNPStringKernel.h>
#include <shogun/kernel/RegulatoryModulesStringKernel.h>
#include <shogun/kernel/PolyMatchWordStringKernel.h>
#include <shogun/kernel/SalzbergWordStringKernel.h>
#include <shogun/kernel/SigmoidKernel.h>
#include <shogun/kernel/SimpleLocalityImprovedStringKernel.h>
#include <shogun/kernel/SparseKernel.h>
#include <shogun/kernel/SphericalKernel.h>
#include <shogun/kernel/SplineKernel.h>
#include <shogun/kernel/SqrtDiagKernelNormalizer.h>
#include <shogun/kernel/StringKernel.h>
#include <shogun/kernel/TanimotoKernelNormalizer.h>
#include <shogun/kernel/TensorProductPairKernel.h>
#include <shogun/kernel/TStudentKernel.h>
#include <shogun/kernel/WaveletKernel.h>
#include <shogun/kernel/WaveKernel.h>
#include <shogun/kernel/WeightedCommWordStringKernel.h>
#include <shogun/kernel/WeightedDegreePositionStringKernel.h>
#include <shogun/kernel/WeightedDegreeStringKernel.h>
#include <shogun/kernel/WeightedDegreeRBFKernel.h>
#include <shogun/kernel/SpectrumMismatchRBFKernel.h>
#include <shogun/kernel/ZeroMeanCenterKernelNormalizer.h>
#include <shogun/kernel/RationalQuadraticKernel.h>
#include <shogun/kernel/CircularKernel.h>
#include <shogun/kernel/JensenShannonKernel.h>
%}
