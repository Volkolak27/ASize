#include "AboutModuleAssembly.h"

#include "src/Modules/About/Presenters/AboutPresenter.h"

AboutWindow* AboutModuleAssembly::buildWindow()
{
	AboutPresenter* presenter = new AboutPresenter();

	AboutWindow* view = new AboutWindow(presenter);
	presenter->attachView(view);

	return view;
}
