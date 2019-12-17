#include "AboutPresenter.h"

#include "src/Globals/Constants.h"

AboutPresenter::AboutPresenter()
{
	// empty
}

AboutPresenter::~AboutPresenter()
{
	// empty
}

void AboutPresenter::viewIsReady()
{
	view()->updateVersion(Constants::appVersion);
	view()->updateEmail(Constants::emailForFeedback);
}

void AboutPresenter::sendEmailAction()
{
	view()->toEmail(Constants::emailForFeedback);
}

void AboutPresenter::aboutQtAction()
{
	view()->toAboutQt();
}

void AboutPresenter::backAction()
{
	view()->toBack();
}
