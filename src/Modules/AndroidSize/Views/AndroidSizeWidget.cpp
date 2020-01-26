#include "AndroidSizeWidget.h"
#include "ui_AndroidSizeWidget.h"

#include <QClipboard>

AndroidSizeWidget::AndroidSizeWidget(IAndroidSizePresenter* presenter, QWidget* parent) : QWidget(parent), ui(new Ui::AndroidSizeWidget)
{
	ui->setupUi(this);
	setAttribute(Qt::WA_DeleteOnClose);
	setWindowFlags(windowFlags() & ~(Qt::WindowMaximizeButtonHint));
	_presenter = presenter;
}

AndroidSizeWidget::~AndroidSizeWidget()
{
	delete ui;
	delete _presenter;
	_presenter = nullptr;
}

void AndroidSizeWidget::updateLdpiValue(const QString& value)
{
	ui->ldpiValue->setText(value);
}

void AndroidSizeWidget::updateMdpiValue(const QString& value)
{
	ui->mdpiValue->setText(value);
}

void AndroidSizeWidget::updateHdpiValue(const QString& value)
{
	ui->hdpiValue->setText(value);
}

void AndroidSizeWidget::updateXHdpiValue(const QString& value)
{
	ui->xhdpiValue->setText(value);
}

void AndroidSizeWidget::updateXXHdpiValue(const QString& value)
{
	ui->xxhdpiValue->setText(value);
}

void AndroidSizeWidget::updateXXXHdpiValue(const QString& value)
{
	ui->xxxhdpiValue->setText(value);
}

void AndroidSizeWidget::showEvent(QShowEvent* event)
{
	if (!event) return;

	if (_isFirstShow)
	{
		_isFirstShow = false;
		_presenter->viewIsReady();
	}
}

void AndroidSizeWidget::copyValueFrom(const AndroidDimension& dimension)
{
	QString textForCopy;

	switch (dimension)
	{
		case AndroidDimension::LDPI:
			textForCopy = ui->ldpiValue->text();
			break;
		case AndroidDimension::MDPI:
			textForCopy = ui->mdpiValue->text();
			break;
		case AndroidDimension::HDPI:
			textForCopy = ui->hdpiValue->text();
			break;
		case AndroidDimension::XHDPI:
			textForCopy = ui->xhdpiValue->text();
			break;
		case AndroidDimension::XXHDPI:
			textForCopy = ui->xxhdpiValue->text();
			break;
		case AndroidDimension::XXXHDPI:
			textForCopy = ui->xxxhdpiValue->text();
			break;
	}

	QClipboard* clipboard = QApplication::clipboard();
	clipboard->setText(textForCopy);
}

void AndroidSizeWidget::on_ldpiValue_textEdited(const QString& arg1)
{
	bool isOk;
	double value = arg1.toDouble(&isOk);

	if (isOk) { _presenter->ldpiValueChanged(value); }
}

void AndroidSizeWidget::on_mdpiValue_textEdited(const QString& arg1)
{
	bool isOk;
	double value = arg1.toDouble(&isOk);

	if (isOk) { _presenter->mdpiValueChanged(value); }
}

void AndroidSizeWidget::on_hdpiValue_textEdited(const QString& arg1)
{
	bool isOk;
	double value = arg1.toDouble(&isOk);

	if (isOk) { _presenter->hdpiValueChanged(value); }
}

void AndroidSizeWidget::on_xhdpiValue_textEdited(const QString& arg1)
{
	bool isOk;
	double value = arg1.toDouble(&isOk);

	if (isOk) { _presenter->xhdpiValueChanged(value); }
}

void AndroidSizeWidget::on_xxhdpiValue_textEdited(const QString& arg1)
{
	bool isOk;
	double value = arg1.toDouble(&isOk);

	if (isOk) { _presenter->xxhdpiValueChanged(value); }
}

void AndroidSizeWidget::on_xxxhdpiValue_textEdited(const QString& arg1)
{
	bool isOk;
	double value = arg1.toDouble(&isOk);

	if (isOk) { _presenter->xxxhdpiValueChanged(value); }
}

void AndroidSizeWidget::on_ldpiCopyButton_clicked()
{
	copyValueFrom(AndroidDimension::LDPI);
}

void AndroidSizeWidget::on_mdpiCopyButton_clicked()
{
	copyValueFrom(AndroidDimension::MDPI);
}

void AndroidSizeWidget::on_hdpiCopyButton_clicked()
{
	copyValueFrom(AndroidDimension::HDPI);
}

void AndroidSizeWidget::on_xhdpiCopyButton_clicked()
{
	copyValueFrom(AndroidDimension::XHDPI);
}

void AndroidSizeWidget::on_xxhdpiCopyButton_clicked()
{
	copyValueFrom(AndroidDimension::XXHDPI);
}

void AndroidSizeWidget::on_xxxhdpiCopyButton_clicked()
{
	copyValueFrom(AndroidDimension::XXXHDPI);
}
