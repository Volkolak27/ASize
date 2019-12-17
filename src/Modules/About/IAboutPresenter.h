#ifndef IABOUTPRESENTER_H
#define IABOUTPRESENTER_H

#include "src/Modules/About/IAboutView.h"
#include "src/Pattern/BasePresenter.h"

class IAboutPresenter : public BasePresenter<IAboutView*>
{
	public:
		virtual void sendEmailAction() = 0;
		virtual void aboutQtAction() = 0;
		virtual void backAction() = 0;
};

#endif // IABOUTPRESENTER_H
