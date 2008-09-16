/*
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 *
 * Written (W) 2008 Soeren Sonnenburg
 * Copyright (C) 2008 Fraunhofer Institute FIRST and Max-Planck-Society
 */

#ifndef _IDENTITYKERNELNORMALIZER_H___
#define _IDENTITYKERNELNORMALIZER_H___

#include "kernel/KernelNormalizer.h"

/** Identity Kernel Normalization, i.e. no normalization is applied */
class CIdentityKernelNormalizer : public CKernelNormalizer
{
	public:
		/** default constructor */
		CIdentityKernelNormalizer()
		{
		}

		/** default destructor */
		virtual ~CIdentityKernelNormalizer()
		{
		}

		/** initialization of the normalizer (if needed)
         * @param k kernel */
		virtual bool init(CKernel* k)
		{
			return true;
		}

		/** normalize the kernel value
		 * @param value kernel value
		 * @param idx_lhs index of left hand side vector
		 * @param idx_rhs index of right hand side vector
		 */
		inline virtual DREAL normalize(DREAL value, INT idx_lhs, INT idx_rhs)
		{
			return value;
		}

		/** normalize only the left hand side vector
		 * @param value value of a component of the left hand side feature vector
		 * @param idx_lhs index of left hand side vector
		 */
		inline virtual DREAL normalize_lhs(DREAL value, INT idx_lhs)
        {
            return value;
        }

		/** normalize only the right hand side vector
		 * @param value value of a component of the right hand side feature vector
		 * @param idx_rhs index of right hand side vector
		 */
		inline virtual DREAL normalize_rhs(DREAL value, INT idx_rhs)
        {
            return value;
        }
};

#endif