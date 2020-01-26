#include "GoldenRatioPresenter.h"

GoldenRatioPresenter::GoldenRatioPresenter()
{
	_sourceValue = 0;
	_goldenRatioPart = GoldenRatioPart::LONG;
}

GoldenRatioPresenter::~GoldenRatioPresenter()
{
	// empty
}

void GoldenRatioPresenter::viewIsReady()
{
	view()->updateShortValue("");
	view()->updateRatioPart(GoldenRatioPart::LONG);
	view()->updateLongValue("");
	view()->updateShortValue("");
	view()->updateWholeValue("");
}

void GoldenRatioPresenter::sourceValueChanged(const double& newValue)
{
	_sourceValue = newValue;
	calcGoldenRatio();
}

void GoldenRatioPresenter::ratioPartChanged(const GoldenRatioPart& goldenRatioPart)
{
	_goldenRatioPart = goldenRatioPart;
	calcGoldenRatio();
}

void GoldenRatioPresenter::calcGoldenRatio()
{
	const double longKoef = 0.61803399;
	const double shortKoef = 0.38196601;

	double longValue = 0.0;
	double shortValue = 0.0;
	double wholeValue = 0.0;

	switch (_goldenRatioPart)
	{
		case GoldenRatioPart::LONG:
			longValue = _sourceValue;
			shortValue = _sourceValue * shortKoef / longKoef;
			wholeValue = _sourceValue / longKoef;
			break;
		case GoldenRatioPart::SHORT:
			longValue = _sourceValue * longKoef / shortKoef;
			shortValue = _sourceValue;
			wholeValue = _sourceValue / shortKoef;
			break;
		case GoldenRatioPart::WHOLE:
			longValue = _sourceValue * longKoef;
			shortValue = _sourceValue * shortKoef;
			wholeValue = _sourceValue;
			break;
	}

	view()->updateLongValue(QString::number(longValue));
	view()->updateShortValue(QString::number(shortValue));
	view()->updateWholeValue(QString::number(wholeValue));
}
