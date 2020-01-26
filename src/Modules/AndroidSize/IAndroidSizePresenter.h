#ifndef IANDROIDSIZEPRESENTER_H
#define IANDROIDSIZEPRESENTER_H

#include "src/Modules/AndroidSize/IAndroidSizeView.h"
#include "src/Pattern/BasePresenter.h"

class IAndroidSizePresenter : public BasePresenter<IAndroidSizeView*>
{
	public:
		virtual void ldpiValueChanged(const double& newValue) = 0;
		virtual void mdpiValueChanged(const double& newValue) = 0;
		virtual void hdpiValueChanged(const double& newValue) = 0;
		virtual void xhdpiValueChanged(const double& newValue) = 0;
		virtual void xxhdpiValueChanged(const double& newValue) = 0;
		virtual void xxxhdpiValueChanged(const double& newValue) = 0;
};

#endif // IANDROIDSIZEPRESENTER_H
