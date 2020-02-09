#include "GoldenRatioPresenter.h"

#include "src/Utils/ProportionUtil.h"

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
	resetToDefault();
}

void GoldenRatioPresenter::sourceValueChanged(const double& newValue, const GoldenRatioPart& newGoldenRatioPart)
{
	_sourceValue = newValue;
	_goldenRatioPart = newGoldenRatioPart;
	calcGoldenRatio();
}

void GoldenRatioPresenter::resetToDefaultAction()
{
	resetToDefault();
}

void GoldenRatioPresenter::resetToDefault()
{
	_sourceValue = 0;
	_goldenRatioPart = GoldenRatioPart::LONG;

	view()->updateSourceValue("");
	view()->updateRatioPart(_goldenRatioPart);
	view()->updateLongValue("");
	view()->updateShortValue("");
	view()->updateWholeValue("");
}

void GoldenRatioPresenter::calcGoldenRatio()
{
	const double longKoef  = 0.61803399;
	const double shortKoef = 0.38196601;
	const double wholeKoef = 1.00000000;

	double longValue = 0.0;
	double shortValue = 0.0;
	double wholeValue = 0.0;

	switch (_goldenRatioPart)
	{
		case GoldenRatioPart::LONG:
			longValue = _sourceValue;
			shortValue = ProportionUtil::solveProportion(_sourceValue, longKoef, shortKoef);
			wholeValue = ProportionUtil::solveProportion(_sourceValue, longKoef, wholeKoef);
			break;
		case GoldenRatioPart::SHORT:
			longValue = ProportionUtil::solveProportion(_sourceValue, shortKoef, longKoef);
			shortValue = _sourceValue;
			wholeValue = ProportionUtil::solveProportion(_sourceValue, shortKoef, wholeKoef);
			break;
		case GoldenRatioPart::WHOLE:
			longValue = ProportionUtil::solveProportion(_sourceValue, wholeKoef, longKoef);
			shortValue = ProportionUtil::solveProportion(_sourceValue, wholeKoef, shortKoef);
			wholeValue = _sourceValue;
			break;
	}

	view()->updateLongValue(QString::number(longValue));
	view()->updateShortValue(QString::number(shortValue));
	view()->updateWholeValue(QString::number(wholeValue));
}
