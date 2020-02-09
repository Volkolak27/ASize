#ifndef IANDROIDSIZEPRESENTER_H
#define IANDROIDSIZEPRESENTER_H

#include "src/Modules/AndroidSize/IAndroidSizeView.h"
#include "src/Pattern/BasePresenter.h"

class IAndroidSizePresenter : public BasePresenter<IAndroidSizeView*>
{
	public:
		virtual void ldpiValueChanged(const QString& newValue) = 0;
		virtual void mdpiValueChanged(const QString& newValue) = 0;
		virtual void hdpiValueChanged(const QString& newValue) = 0;
		virtual void xhdpiValueChanged(const QString& newValue) = 0;
		virtual void xxhdpiValueChanged(const QString& newValue) = 0;
		virtual void xxxhdpiValueChanged(const QString& newValue) = 0;
		virtual void resetToDefaultAction() = 0;
};

#endif // IANDROIDSIZEPRESENTER_H
