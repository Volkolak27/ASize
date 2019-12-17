#ifndef ABOUTPRESENTER_H
#define ABOUTPRESENTER_H

#include "src/Modules/About/IAboutPresenter.h"

class AboutPresenter : public IAboutPresenter
{
	//// Методы
	public:
		AboutPresenter();
		~AboutPresenter() override;

		// IMvpPresenter interface
		void viewIsReady() override;

		// IAboutPresenter interface
		void sendEmailAction() override;
		void aboutQtAction() override;
		void backAction() override;
};

#endif // ABOUTPRESENTER_H
