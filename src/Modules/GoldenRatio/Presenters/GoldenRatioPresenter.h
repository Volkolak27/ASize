#ifndef GOLDENRATIOPRESENTER_H
#define GOLDENRATIOPRESENTER_H

#include "src/Modules/GoldenRatio/IGoldenRatioPresenter.h"

class GoldenRatioPresenter : public IGoldenRatioPresenter
{
	//// Свойства
	private:
		double _sourceValue;
		GoldenRatioPart _goldenRatioPart;

	//// Методы
	public:
		GoldenRatioPresenter();
		~GoldenRatioPresenter() override;

		// IMvpPresenter interface
		void viewIsReady() override;

		// IGoldenRatioPresenter interface
		void sourceValueChanged(const double& newValue, const GoldenRatioPart& newGoldenRatioPart) override;
		void resetToDefaultAction() override;

	private:
		void resetToDefault();
		void calcGoldenRatio();
};

#endif // GOLDENRATIOPRESENTER_H
