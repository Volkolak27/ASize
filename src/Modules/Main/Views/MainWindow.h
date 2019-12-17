#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "src/Modules/Main/IMainPresenter.h"
#include "src/Modules/Main/IMainView.h"
#include <QMainWindow>

namespace Ui {
	class MainWindow;
}

class MainWindow : public QMainWindow, public IMainView
{
	Q_OBJECT

	//// Свойства
	private:
		Ui::MainWindow* ui;
		IMainPresenter* _presenter;

	//// Методы
	public:
		explicit MainWindow(IMainPresenter* presenter, QWidget* parent = nullptr);
		~MainWindow() override;

		// IMainView interface
		void resetToDefault() override;
		void openAbout() override;
		void closeApp() override;

	protected:
		// QWidget interface
		void showEvent(QShowEvent* event) override;

	private slots:
		void on_exitButton_clicked();
		void on_aboutButton_clicked();
		void on_resetButton_clicked();
};

#endif // MAINWINDOW_H
