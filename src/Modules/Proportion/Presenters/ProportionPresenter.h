#ifndef PROPORTIONPRESENTER_H
#define PROPORTIONPRESENTER_H

#include "src/Modules/Proportion/IProportionPresenter.h"

class ProportionPresenter : public IProportionPresenter
{
	//// Свойства
	private:
		double _a;
		double _b;
		double _c;
		double _d;
		MathOperation _mathOperation;

	//// Методы
	public:
		ProportionPresenter();
		~ProportionPresenter() override;

		// IMvpPresenter interface
		void viewIsReady() override;

		// IProportionPresenter interface
		void aValueChanged(const double& newValue) override;
		void bValueChanged(const double& newValue) override;
		void dValueChanged(const double& newValue) override;
		void mathOperationChanged(const MathOperation& newOperation) override;
		void resetToDefaultAction() override;

	private:
		void calcProportion();
		void calcMathOperation();
};

#endif // PROPORTIONPRESENTER_H
