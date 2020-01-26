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
		void sourceValueChanged(const double& newValue) override;
		void ratioPartChanged(const GoldenRatioPart& goldenRatioPart) override;

	private:
		void calcGoldenRatio();
};

#endif // GOLDENRATIOPRESENTER_H
