#include "ProportionPresenter.h"

ProportionPresenter::ProportionPresenter()
{
	_a = 200000;
	_b = 100;
	_c = 40000;
	_d = 20;
	_mathOperation = MathOperation::NONE;
}

ProportionPresenter::~ProportionPresenter()
{
	// empty
}

void ProportionPresenter::viewIsReady()
{
	calcProportion();
	calcMathOperation();
}

void ProportionPresenter::aValueChanged(const double& newValue)
{
	_a = newValue;
	calcProportion();
}

void ProportionPresenter::bValueChanged(const double& newValue)
{
	_b = newValue;
	calcProportion();
}

void ProportionPresenter::dValueChanged(const double& newValue)
{
	_d = newValue;
	calcProportion();
}

void ProportionPresenter::mathOperationChanged(const MathOperation& newOperation)
{
	_mathOperation = newOperation;
	calcMathOperation();
}

void ProportionPresenter::calcProportion()
{
	_c = _a * _d / _b;

	view()->updateAValue( QString::number(_a) );
	view()->updateBValue( QString::number(_b) );
	view()->updateCValue( QString::number(_c) );
	view()->updateDValue( QString::number(_d) );
	calcMathOperation();
}

void ProportionPresenter::calcMathOperation()
{
	QString acResult, bdResult;

	switch (_mathOperation)
	{
		case MathOperation::NONE:
			acResult = "";
			bdResult = "";
			break;
		case MathOperation::ADD:
			acResult = QString::number(_a + _c);
			bdResult = QString::number(_b + _d);
			break;
		case MathOperation::SUB:
			acResult = QString::number(_a - _c);
			bdResult = QString::number(_b - _d);
			break;
		case MathOperation::MULT:
		case MathOperation::DIV:
			break;
	}

	view()->updateACValue(acResult);
	view()->updateBDValue(bdResult);
	view()->updateMathOperation(_mathOperation);
}
