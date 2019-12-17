#ifndef ABOUTWINDOW_H
#define ABOUTWINDOW_H

#include "src/Modules/About/IAboutPresenter.h"
#include "src/Modules/About/IAboutView.h"
#include <QWidget>

namespace Ui {
	class AboutWindow;
}

class AboutWindow : public QWidget, public IAboutView
{
	Q_OBJECT

	//// Свойства
	private:
		Ui::AboutWindow* ui;
		IAboutPresenter* _presenter;
		QString _email;

	//// Методы
	public:
		explicit AboutWindow(IAboutPresenter* presenter, QWidget* parent = nullptr);
		~AboutWindow() override;

		// IAboutView interface
		void updateVersion(const QString& version) override;
		void updateEmail(const QString& email) override;
		void toEmail(const QString& email) override;
		void toAboutQt() override;
		void toBack() override;

	protected:
		// QWidget interface
		void showEvent(QShowEvent* event) override;
		void closeEvent(QCloseEvent* event) override;

	private slots:
		void on_mailButton_clicked();
		void on_copyMailButton_clicked();
		void on_aboutButton_clicked();
};

#endif // ABOUTWINDOW_H
