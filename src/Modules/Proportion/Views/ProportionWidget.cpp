#include "ProportionWidget.h"
#include "ui_ProportionWidget.h"

ProportionWidget::ProportionWidget(IProportionPresenter* presenter, QWidget* parent) : QWidget(parent), ui(new Ui::ProportionWidget)
{
	ui->setupUi(this);
	setAttribute(Qt::WA_DeleteOnClose);
	setWindowFlags(windowFlags() & ~(Qt::WindowMaximizeButtonHint));
	_presenter = presenter;
}

ProportionWidget::~ProportionWidget()
{
	delete ui;
	delete _presenter;
	_presenter = nullptr;
}

void ProportionWidget::updateAValue(const QString& value)
{
	ui->aValue->setText(value);
}

void ProportionWidget::updateBValue(const QString& value)
{
	ui->bValue->setText(value);
}

void ProportionWidget::updateCValue(const QString& value)
{
	ui->cValue->setText(value);
}

void ProportionWidget::updateDValue(const QString& value)
{
	ui->dValue->setText(value);
}

void ProportionWidget::updateACValue(const QString& value)
{
	ui->acValue->setText(value);
}

void ProportionWidget::updateBDValue(const QString& value)
{
	ui->bdValue->setText(value);
}

void ProportionWidget::updateMathOperation(const MathOperation& operationType)
{
	switchMathOperationTo(operationType);
}

void ProportionWidget::toBack()
{
	// empty
}

void ProportionWidget::showEvent(QShowEvent* event)
{
	if (!event) return;

	if (_isFirstShow)
	{
		_isFirstShow = false;
		_presenter->viewIsReady();
	}
}

void ProportionWidget::switchMathOperationTo(const MathOperation& mathOperation)
{
	ui->addButton->setChecked(false);
	ui->subButton->setChecked(false);

	switch (mathOperation)
	{
		case MathOperation::NONE:
		case MathOperation::MULT:
		case MathOperation::DIV:
			break; // empty
		case MathOperation::ADD:
			ui->addButton->setChecked(true);
			break;
		case MathOperation::SUB:
			ui->subButton->setChecked(true);
			break;
	}
}

void ProportionWidget::on_aValue_textEdited(const QString& arg1)
{
	bool isOk;
	double value = arg1.toDouble(&isOk);

	if (isOk) { _presenter->aValueChanged(value); }
}

void ProportionWidget::on_bValue_textEdited(const QString& arg1)
{
	bool isOk;
	double value = arg1.toDouble(&isOk);

	if (isOk) { _presenter->bValueChanged(value); }
}

void ProportionWidget::on_dValue_textEdited(const QString& arg1)
{
	bool isOk;
	double value = arg1.toDouble(&isOk);

	if (isOk) { _presenter->dValueChanged(value); }
}

void ProportionWidget::on_addButton_clicked()
{
	MathOperation mathOperation =
			ui->addButton->isChecked() ? MathOperation::ADD : MathOperation::NONE;

	switchMathOperationTo(mathOperation);
	_presenter->mathOperationChanged(mathOperation);
}

void ProportionWidget::on_subButton_clicked()
{
	MathOperation mathOperation =
			ui->subButton->isChecked() ? MathOperation::SUB : MathOperation::NONE;

	switchMathOperationTo(mathOperation);
	_presenter->mathOperationChanged(mathOperation);
}
