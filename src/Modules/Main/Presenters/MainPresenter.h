#ifndef MAINPRESENTER_H
#define MAINPRESENTER_H

#include "src/Modules/Main/IMainPresenter.h"

class MainPresenter : public IMainPresenter
{
	//// Методы
	public:
		MainPresenter();
		~MainPresenter() override;

		// IMvpPresenter interface
		void viewIsReady() override;

		// IMainPresenter interface
		void resetToDefaultAction() override;
		void toAbout() override;
		void closeAppAction() override;
};

#endif // MAINPRESENTER_H
