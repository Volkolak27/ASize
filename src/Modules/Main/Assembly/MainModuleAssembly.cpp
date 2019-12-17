#include "MainModuleAssembly.h"

#include "src/Modules/Main/Presenters/MainPresenter.h"

MainWindow* MainModuleAssembly::buildWindow()
{
	MainPresenter* presenter = new MainPresenter();

	MainWindow* view = new MainWindow(presenter);
	presenter->attachView(view);

	return view;
}
