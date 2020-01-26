#ifndef PROPORTIONWIDGET_H
#define PROPORTIONWIDGET_H

#include "src/Modules/Proportion/IProportionPresenter.h"
#include "src/Modules/Proportion/IProportionView.h"
#include <QWidget>

namespace Ui {
	class ProportionWidget;
}

class ProportionWidget : public QWidget, public IProportionView
{
	Q_OBJECT

	//// Свойства
	private:
		Ui::ProportionWidget* ui;
		IProportionPresenter* _presenter;

	//// Методы
	public:
		explicit ProportionWidget(IProportionPresenter* presenter, QWidget* parent = nullptr);
		~ProportionWidget() override;

		// IProportionView interface
		void updateAValue(const QString& value) override;
		void updateBValue(const QString& value) override;
		void updateCValue(const QString& value) override;
		void updateDValue(const QString& value) override;
		void updateACValue(const QString& value) override;
		void updateBDValue(const QString& value) override;
		void updateMathOperation(const MathOperation& operationType) override;
		void toBack() override;

	protected:
		// QWidget interface
		void showEvent(QShowEvent* event) override;

	private:
		void switchMathOperationTo(const MathOperation& mathOperation);

	private slots:
		void on_aValue_textEdited(const QString& arg1);
		void on_bValue_textEdited(const QString& arg1);
		void on_dValue_textEdited(const QString& arg1);
		void on_addButton_clicked();
		void on_subButton_clicked();
};

#endif // PROPORTIONWIDGET_H
