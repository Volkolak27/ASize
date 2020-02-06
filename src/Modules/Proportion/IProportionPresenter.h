#ifndef IPROPORTIONPRESENTER_H
#define IPROPORTIONPRESENTER_H

#include "src/Modules/Proportion/IProportionView.h"
#include "src/Pattern/BasePresenter.h"

class IProportionPresenter : public BasePresenter<IProportionView*>
{
	public:
		virtual void aValueChanged(const double& newValue) = 0;
		virtual void bValueChanged(const double& newValue) = 0;
		virtual void dValueChanged(const double& newValue) = 0;
		virtual void mathOperationChanged(const MathOperation& newOperation) = 0;
		virtual void resetToDefaultAction() = 0;
};

#endif // IPROPORTIONPRESENTER_H
