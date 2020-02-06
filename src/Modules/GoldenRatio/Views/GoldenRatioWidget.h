#ifndef GOLDENRATIOWIDGET_H
#define GOLDENRATIOWIDGET_H

#include "src/Modules/GoldenRatio/IGoldenRatioPresenter.h"
#include "src/Modules/GoldenRatio/IGoldenRatioView.h"
#include <QWidget>

namespace Ui {
	class GoldenRatioWidget;
}

class GoldenRatioWidget : public QWidget, public IGoldenRatioView
{
	Q_OBJECT

	//// Свойства
	private:
		Ui::GoldenRatioWidget* ui;
		IGoldenRatioPresenter* _presenter;

	//// Методы
	public:
		explicit GoldenRatioWidget(IGoldenRatioPresenter* presenter, QWidget* parent = nullptr);
		~GoldenRatioWidget() override;

		// IGoldenRatioView interface
		void updateSourceValue(const QString& value) override;
		void updateRatioPart(const GoldenRatioPart& goldenRatioPart) override;
		void updateShortValue(const QString& value) override;
		void updateLongValue(const QString& value) override;
		void updateWholeValue(const QString& value) override;
		void needToResetToDefault() override;

	protected:
		// QWidget interface
		void showEvent(QShowEvent* event) override;

	private:
		void checkValues();

	private slots:
		void on_sourceValue_textEdited(const QString& arg1);
		void on_type_currentIndexChanged(int index);
};

#endif // GOLDENRATIOWIDGET_H
