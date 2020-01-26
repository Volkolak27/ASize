#include "AndroidSizeModuleAssembly.h"

#include "src/Modules/AndroidSize/Presenters/AndroidSizePresenter.h"

AndroidSizeWidget* AndroidSizeModuleAssembly::buildWidget()
{
	AndroidSizePresenter* presenter = new AndroidSizePresenter();

	AndroidSizeWidget* view = new AndroidSizeWidget(presenter);
	presenter->attachView(view);

	return view;
}
