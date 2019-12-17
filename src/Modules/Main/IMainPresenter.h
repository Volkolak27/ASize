#ifndef IMAINPRESENTER_H
#define IMAINPRESENTER_H

#include "src/Modules/Main/IMainView.h"
#include "src/Pattern/BasePresenter.h"

class IMainPresenter : public BasePresenter<IMainView*>
{
	public:
		virtual void resetToDefaultAction() = 0;
		virtual void toAbout() = 0;
		virtual void closeAppAction() = 0;
};

#endif // IMAINPRESENTER_H
