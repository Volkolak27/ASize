#include "MainWindow.h"
#include "ui_MainWindow.h"

#include "src/Globals/Constants.h"
#include "src/Managers/RoutesManager.h"

MainWindow::MainWindow(IMainPresenter* presenter, QWidget* parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
	ui->setupUi(this);
	setAttribute(Qt::WA_DeleteOnClose);
	setWindowFlags(windowFlags() & ~(Qt::WindowMaximizeButtonHint));
	_presenter = presenter;

	setWindowTitle( QString("%1 %2").arg(Constants::appName, Constants::appVersion) );
}

MainWindow::~MainWindow()
{
	delete ui;
	delete _presenter;
	_presenter = nullptr;
}

void MainWindow::resetToDefault()
{
	//todo: rel
}

void MainWindow::openAbout()
{
	RoutesManager::instance().openAboutWindow();
	RoutesManager::instance().mainWindowNeedTo(RouteOperation::HIDE);
}

void MainWindow::closeApp()
{
	close();
}

void MainWindow::showEvent(QShowEvent* event)
{
	if (!event) return;

	if (_isFirstShow)
	{
		_isFirstShow = false;
		_presenter->viewIsReady();
	}
}

void MainWindow::on_exitButton_clicked()
{
	_presenter->closeAppAction();
}

void MainWindow::on_aboutButton_clicked()
{
	_presenter->toAbout();
}

void MainWindow::on_resetButton_clicked()
{
	_presenter->resetToDefaultAction();
}
