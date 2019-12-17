#include "AboutWindow.h"
#include "ui_AboutWindow.h"

#include "src/Managers/RoutesManager.h"
#include <QClipboard>
#include <QDesktopServices>
#include <QMessageBox>
#include <QUrl>

AboutWindow::AboutWindow(IAboutPresenter* presenter, QWidget* parent) : QWidget(parent), ui(new Ui::AboutWindow)
{
	ui->setupUi(this);
	setAttribute(Qt::WA_DeleteOnClose);
	setWindowFlags(windowFlags() & ~(Qt::WindowMaximizeButtonHint));
	_presenter = presenter;
}

AboutWindow::~AboutWindow()
{
	delete ui;
	delete _presenter;
	_presenter = nullptr;
}

void AboutWindow::updateVersion(const QString& version)
{
	ui->bottomDesc->setText(version);
}

void AboutWindow::updateEmail(const QString& email)
{
	_email = email;
	ui->mailButton->setText(_email);
}

void AboutWindow::toEmail(const QString& email)
{
	QDesktopServices::openUrl(QUrl("mailto:" + email, QUrl::TolerantMode));
}

void AboutWindow::toAboutQt()
{
	QMessageBox::aboutQt(this);
}

void AboutWindow::toBack()
{
	RoutesManager::instance().mainWindowNeedTo(RouteOperation::OPEN);
}

void AboutWindow::showEvent(QShowEvent* event)
{
	if (!event) return;

	if (_isFirstShow)
	{
		_isFirstShow = false;
		_presenter->viewIsReady();
	}
}

void AboutWindow::closeEvent(QCloseEvent* event)
{
	if (!event) return;
	_presenter->backAction();
}

void AboutWindow::on_mailButton_clicked()
{
	_presenter->sendEmailAction();
}

void AboutWindow::on_copyMailButton_clicked()
{
	QClipboard* clipboard = QApplication::clipboard();
	clipboard->setText(_email);
}

void AboutWindow::on_aboutButton_clicked()
{
	_presenter->aboutQtAction();
}
