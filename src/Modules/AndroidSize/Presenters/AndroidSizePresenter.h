#ifndef ANDROIDSIZEPRESENTER_H
#define ANDROIDSIZEPRESENTER_H

#include "src/Enums/AndroidDimension.h"
#include "src/Modules/AndroidSize/IAndroidSizePresenter.h"

class AndroidSizePresenter : public IAndroidSizePresenter
{
	//// Методы
	public:
		AndroidSizePresenter();
		~AndroidSizePresenter() override;

		// IMvpPresenter interface
		void viewIsReady() override;

		// IAndroidSizePresenter interface
		void ldpiValueChanged(const double& newValue) override;
		void mdpiValueChanged(const double& newValue) override;
		void hdpiValueChanged(const double& newValue) override;
		void xhdpiValueChanged(const double& newValue) override;
		void xxhdpiValueChanged(const double& newValue) override;
		void xxxhdpiValueChanged(const double& newValue) override;
		void resetToDefaultAction() override;

	private:
		void calcSizes(const double& fromValue, const AndroidDimension& fromDimension);
		void resetToDefault();
};

#endif // ANDROIDSIZEPRESENTER_H
