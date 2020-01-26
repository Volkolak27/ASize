#include "MainWindow.h"
#include "ui_MainWindow.h"

#include "src/Globals/Constants.h"
#include "src/Managers/RoutesManager.h"
#include "src/Modules/AndroidSize/Assembly/AndroidSizeModuleAssembly.h"
#include "src/Modules/GoldenRatio/Assembly/GoldenRatioModuleAssembly.h"
#include "src/Modules/Proportion/Assembly/ProportionModuleAssembly.h"

MainWindow::MainWindow(IMainPresenter* presenter, QWidget* parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
	ui->setupUi(this);
	setAttribute(Qt::WA_DeleteOnClose);
	setWindowFlags(windowFlags() & ~(Qt::WindowMaximizeButtonHint));
	_presenter = presenter;

	setWindowTitle( QString("%1 %2").arg(Constants::appName, Constants::appVersion) );
	ui->tabWidget->setCurrentIndex(0);

	ui->resetButton->setVisible(false); //todo: убрать строку в версии 1.1
}

MainWindow::~MainWindow()
{
	delete ui;
	delete _presenter;
	_presenter = nullptr;
}

void MainWindow::resetToDefault()
{
	//todo: реализовать в версии 1.1
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

		// Создаем виджеты на вкладках
		ProportionWidget* proportionWidget = ProportionModuleAssembly::buildWidget();
		ui->proportionTab->layout()->addWidget(proportionWidget);

		GoldenRatioWidget* goldenRatioWidget = GoldenRatioModuleAssembly::buildWidget();
		ui->goldenRatioTab->layout()->addWidget(goldenRatioWidget);

		AndroidSizeWidget* androidSizeWidget = AndroidSizeModuleAssembly::buildWidget();
		ui->androidTab->layout()->addWidget(androidSizeWidget);

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
