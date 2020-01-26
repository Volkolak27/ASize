#include "GoldenRatioWidget.h"
#include "ui_GoldenRatioWidget.h"

GoldenRatioWidget::GoldenRatioWidget(IGoldenRatioPresenter* presenter, QWidget* parent) : QWidget(parent), ui(new Ui::GoldenRatioWidget)
{
	ui->setupUi(this);
	setAttribute(Qt::WA_DeleteOnClose);
	setWindowFlags(windowFlags() & ~(Qt::WindowMaximizeButtonHint));
	_presenter = presenter;
}

GoldenRatioWidget::~GoldenRatioWidget()
{
	delete ui;
	delete _presenter;
	_presenter = nullptr;
}

void GoldenRatioWidget::updateSourceValue(const QString& value)
{
	ui->sourceValue->setText(value);
}

void GoldenRatioWidget::updateRatioPart(const GoldenRatioPart& goldenRatioPart)
{
	int indexForSelect = 0;

	switch (goldenRatioPart)
	{
		case GoldenRatioPart::LONG:
			indexForSelect = 0;
			break;
		case GoldenRatioPart::SHORT:
			indexForSelect = 1;
			break;
		case GoldenRatioPart::WHOLE:
			indexForSelect = 2;
			break;
	}

	ui->type->setCurrentIndex(indexForSelect);
}

void GoldenRatioWidget::updateShortValue(const QString& value)
{
	ui->shortValue->setText(value);
}

void GoldenRatioWidget::updateLongValue(const QString& value)
{
	ui->longValue->setText(value);
}

void GoldenRatioWidget::updateWholeValue(const QString& value)
{
	ui->wholeValue->setText(value);
}

void GoldenRatioWidget::showEvent(QShowEvent* event)
{
	if (!event) return;

	if (_isFirstShow)
	{
		_isFirstShow = false;
		_presenter->viewIsReady();
	}
}

void GoldenRatioWidget::on_sourceValue_textEdited(const QString& arg1)
{
	bool isOk;
	double value = arg1.toDouble(&isOk);

	if (isOk) { _presenter->sourceValueChanged(value); }
}

void GoldenRatioWidget::on_type_currentIndexChanged(int index)
{
	GoldenRatioPart partForSelect;

	switch (index)
	{
		case GoldenRatioPart::LONG:
			partForSelect = GoldenRatioPart::LONG;
			break;
		case GoldenRatioPart::SHORT:
			partForSelect = GoldenRatioPart::SHORT;
			break;
		case GoldenRatioPart::WHOLE:
			partForSelect = GoldenRatioPart::WHOLE;
			break;
	}

	_presenter->ratioPartChanged(partForSelect);
}
