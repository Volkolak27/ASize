#include "GoldenRatioModuleAssembly.h"

#include "src/Modules/GoldenRatio/Presenters/GoldenRatioPresenter.h"

GoldenRatioWidget* GoldenRatioModuleAssembly::buildWidget()
{
	GoldenRatioPresenter* presenter = new GoldenRatioPresenter();

	GoldenRatioWidget* view = new GoldenRatioWidget(presenter);
	presenter->attachView(view);

	return view;
}
