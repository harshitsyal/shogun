/*
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 *
 * Written (W) 1999-2008 Soeren Sonnenburg
 * Copyright (C) 1999-2008 Fraunhofer Institute FIRST and Max-Planck-Society
 */

#ifndef _LDA_H___
#define _LDA_H___

#include "lib/common.h"

#ifdef HAVE_LAPACK
#include "features/Features.h"
#include "features/RealFeatures.h"
#include "classifier/LinearClassifier.h"

/** class LDA */
class CLDA : public CLinearClassifier
{
	public:
		/** constructor
		 *
		 * @param gamma gamma
		 */
		CLDA(float64_t gamma=0);

		/** constructor
		 *
		 * @param gamma gamma
		 * @param traindat training features
		 * @param trainlab labels for training features
		 */
		CLDA(float64_t gamma, CRealFeatures* traindat, CLabels* trainlab);
		virtual ~CLDA();

		/** set gamme
		 *
		 * @param gamma the new gamma
		 */
		inline void set_gamma(float64_t gamma)
		{
			m_gamma=gamma;
		}

		/** get gamma
		 *
		 * @return gamma
		 */
		inline float64_t get_gamma()
		{
			return m_gamma;
		}

		/** train  classifier
		 *
		 * @return if training was successful
		 */
		virtual bool train();

		/** get classifier type
		 *
		 * @return classifier type LDA
		 */
		inline virtual EClassifierType get_classifier_type()
		{
			return CT_LDA;
		}

		/** set features
		 *
		 * @param feat features to set
		 */
		virtual inline void set_features(CDotFeatures* feat)
		{
			if (feat->get_feature_class() != C_SIMPLE ||
				feat->get_feature_type() != F_DREAL)
				SG_ERROR("LDA requires SIMPLE REAL valued features\n");

			CLinearClassifier::set_features(feat);
		}

		/** @return object name */
		inline virtual const char* get_name() const { return "LDA"; }

	protected:
		/** gamma */
		float64_t m_gamma;
};
#endif
#endif