#include "AndroidSizePresenter.h"

#include "src/Utils/QStringParserUtil/QStringParserUtil.h"

AndroidSizePresenter::AndroidSizePresenter()
{
	// empty
}

AndroidSizePresenter::~AndroidSizePresenter()
{
	// empty
}

void AndroidSizePresenter::viewIsReady()
{
	resetToDefault();
}

void AndroidSizePresenter::ldpiValueChanged(const QString& newValue)
{
	calcSizes(newValue, AndroidDimension::LDPI);
}

void AndroidSizePresenter::mdpiValueChanged(const QString& newValue)
{
	calcSizes(newValue, AndroidDimension::MDPI);
}

void AndroidSizePresenter::hdpiValueChanged(const QString& newValue)
{
	calcSizes(newValue, AndroidDimension::HDPI);
}

void AndroidSizePresenter::xhdpiValueChanged(const QString& newValue)
{
	calcSizes(newValue, AndroidDimension::XHDPI);
}

void AndroidSizePresenter::xxhdpiValueChanged(const QString& newValue)
{
	calcSizes(newValue, AndroidDimension::XXHDPI);
}

void AndroidSizePresenter::xxxhdpiValueChanged(const QString& newValue)
{
	calcSizes(newValue, AndroidDimension::XXXHDPI);
}

void AndroidSizePresenter::resetToDefaultAction()
{
	resetToDefault();
}

void AndroidSizePresenter::calcSizes(const QString& fromValue, const AndroidDimension& fromDimension)
{
	QList<PartOfString> parts = QStringParserUtil::makePartsFromString(fromValue);

	if (fromDimension != AndroidDimension::LDPI)
	{
		view()->updateLdpiValue(
			QStringParserUtil::makeStringFromParts(
				QStringParserUtil::multiplyDigitPartsBy(parts, AndroidDimensionHelper::obtainKoef(AndroidDimension::LDPI) / AndroidDimensionHelper::obtainKoef(fromDimension))
			)
		);
	}

	if (fromDimension != AndroidDimension::MDPI)
	{
		view()->updateMdpiValue(
			QStringParserUtil::makeStringFromParts(
				QStringParserUtil::multiplyDigitPartsBy(parts, AndroidDimensionHelper::obtainKoef(AndroidDimension::MDPI) / AndroidDimensionHelper::obtainKoef(fromDimension))
			)
		);
	}

	if (fromDimension != AndroidDimension::HDPI)
	{
		view()->updateHdpiValue(
			QStringParserUtil::makeStringFromParts(
				QStringParserUtil::multiplyDigitPartsBy(parts, AndroidDimensionHelper::obtainKoef(AndroidDimension::HDPI) / AndroidDimensionHelper::obtainKoef(fromDimension))
			)
		);
	}

	if (fromDimension != AndroidDimension::XHDPI)
	{
		view()->updateXHdpiValue(
			QStringParserUtil::makeStringFromParts(
				QStringParserUtil::multiplyDigitPartsBy(parts, AndroidDimensionHelper::obtainKoef(AndroidDimension::XHDPI) / AndroidDimensionHelper::obtainKoef(fromDimension))
			)
		);
	}

	if (fromDimension != AndroidDimension::XXHDPI)
	{
		view()->updateXXHdpiValue(
			QStringParserUtil::makeStringFromParts(
				QStringParserUtil::multiplyDigitPartsBy(parts, AndroidDimensionHelper::obtainKoef(AndroidDimension::XXHDPI) / AndroidDimensionHelper::obtainKoef(fromDimension))
			)
		);
	}

	if (fromDimension != AndroidDimension::XXXHDPI)
	{
		view()->updateXXXHdpiValue(
			QStringParserUtil::makeStringFromParts(
				QStringParserUtil::multiplyDigitPartsBy(parts, AndroidDimensionHelper::obtainKoef(AndroidDimension::XXXHDPI) / AndroidDimensionHelper::obtainKoef(fromDimension))
			)
		);
	}
}

void AndroidSizePresenter::resetToDefault()
{
	view()->updateLdpiValue("");
	view()->updateMdpiValue("");
	view()->updateHdpiValue("");
	view()->updateXHdpiValue("");
	view()->updateXXHdpiValue("");
	view()->updateXXXHdpiValue("");
}
