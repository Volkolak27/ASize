#include "ProportionModuleAssembly.h"

#include "src/Modules/Proportion/Presenters/ProportionPresenter.h"

ProportionWidget* ProportionModuleAssembly::buildWidget()
{
	ProportionPresenter* presenter = new ProportionPresenter();

	ProportionWidget* view = new ProportionWidget(presenter);
	presenter->attachView(view);

	return view;
}
