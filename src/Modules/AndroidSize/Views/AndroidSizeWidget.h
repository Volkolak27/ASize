#ifndef ANDROIDSIZEWIDGET_H
#define ANDROIDSIZEWIDGET_H

#include "src/Enums/AndroidDimension.h"
#include "src/Modules/AndroidSize/IAndroidSizePresenter.h"
#include "src/Modules/AndroidSize/IAndroidSizeView.h"
#include <QWidget>

namespace Ui {
	class AndroidSizeWidget;
}

class AndroidSizeWidget : public QWidget, public IAndroidSizeView
{
	Q_OBJECT

	//// Свойства
	private:
		Ui::AndroidSizeWidget* ui;
		IAndroidSizePresenter* _presenter;

	//// Методы
	public:
		explicit AndroidSizeWidget(IAndroidSizePresenter* presenter, QWidget* parent = nullptr);
		~AndroidSizeWidget() override;

		// IAndroidSizeView interface
		void updateLdpiValue(const QString& value) override;
		void updateMdpiValue(const QString& value) override;
		void updateHdpiValue(const QString& value) override;
		void updateXHdpiValue(const QString& value) override;
		void updateXXHdpiValue(const QString& value) override;
		void updateXXXHdpiValue(const QString& value) override;
		void needToResetToDefault() override;

	protected:
		// QWidget interface
		void showEvent(QShowEvent* event) override;

	private:
		void copyValueFrom(const AndroidDimension& dimension);

	private slots:
		void on_ldpiValue_textEdited(const QString& arg1);
		void on_mdpiValue_textEdited(const QString& arg1);
		void on_hdpiValue_textEdited(const QString& arg1);
		void on_xhdpiValue_textEdited(const QString& arg1);
		void on_xxhdpiValue_textEdited(const QString& arg1);
		void on_xxxhdpiValue_textEdited(const QString& arg1);
		void on_ldpiCopyButton_clicked();
		void on_mdpiCopyButton_clicked();
		void on_hdpiCopyButton_clicked();
		void on_xhdpiCopyButton_clicked();
		void on_xxhdpiCopyButton_clicked();
		void on_xxxhdpiCopyButton_clicked();
};

#endif // ANDROIDSIZEWIDGET_H
