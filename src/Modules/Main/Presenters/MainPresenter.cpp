#include "MainPresenter.h"

MainPresenter::MainPresenter()
{
	// empty
}

MainPresenter::~MainPresenter()
{
	// empty
}

void MainPresenter::viewIsReady()
{
	// empty
}

void MainPresenter::resetToDefaultAction()
{
	view()->resetToDefault();
}

void MainPresenter::toAbout()
{
	view()->openAbout();
}

void MainPresenter::closeAppAction()
{
	view()->closeApp();
}
