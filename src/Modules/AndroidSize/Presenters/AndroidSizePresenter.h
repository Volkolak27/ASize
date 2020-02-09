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
		void ldpiValueChanged(const QString& newValue) override;
		void mdpiValueChanged(const QString& newValue) override;
		void hdpiValueChanged(const QString& newValue) override;
		void xhdpiValueChanged(const QString& newValue) override;
		void xxhdpiValueChanged(const QString& newValue) override;
		void xxxhdpiValueChanged(const QString& newValue) override;
		void resetToDefaultAction() override;

	private:
		void calcSizes(const QString& fromValue, const AndroidDimension& fromDimension);
		void resetToDefault();
};

#endif // ANDROIDSIZEPRESENTER_H
