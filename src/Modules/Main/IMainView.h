#ifndef IMAINVIEW_H
#define IMAINVIEW_H

#include "src/Pattern/BaseView.h"

class IMainView : public BaseView
{
	public:
		virtual void resetToDefault() = 0;
		virtual void openAbout() = 0;
		virtual void closeApp() = 0;
};

#endif // IMAINVIEW_H
