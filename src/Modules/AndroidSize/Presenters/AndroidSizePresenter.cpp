#include "AndroidSizePresenter.h"

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

void AndroidSizePresenter::ldpiValueChanged(const double& newValue)
{
	calcSizes(newValue, AndroidDimension::LDPI);
}

void AndroidSizePresenter::mdpiValueChanged(const double& newValue)
{
	calcSizes(newValue, AndroidDimension::MDPI);
}

void AndroidSizePresenter::hdpiValueChanged(const double& newValue)
{
	calcSizes(newValue, AndroidDimension::HDPI);
}

void AndroidSizePresenter::xhdpiValueChanged(const double& newValue)
{
	calcSizes(newValue, AndroidDimension::XHDPI);
}

void AndroidSizePresenter::xxhdpiValueChanged(const double& newValue)
{
	calcSizes(newValue, AndroidDimension::XXHDPI);
}

void AndroidSizePresenter::xxxhdpiValueChanged(const double& newValue)
{
	calcSizes(newValue, AndroidDimension::XXXHDPI);
}

void AndroidSizePresenter::resetToDefaultAction()
{
	resetToDefault();
}

void AndroidSizePresenter::calcSizes(const double& fromValue, const AndroidDimension& fromDimension)
{
	if (fromDimension != AndroidDimension::LDPI)
	{
		view()->updateLdpiValue(
			QString::number( AndroidDimensionHelper::convert(fromValue, fromDimension, AndroidDimension::LDPI) )
		);
	}
	if (fromDimension != AndroidDimension::MDPI)
	{
		view()->updateMdpiValue(
			QString::number( AndroidDimensionHelper::convert(fromValue, fromDimension, AndroidDimension::MDPI) )
		);
	}
	if (fromDimension != AndroidDimension::HDPI)
	{
		view()->updateHdpiValue(
			QString::number( AndroidDimensionHelper::convert(fromValue, fromDimension, AndroidDimension::HDPI) )
		);
	}
	if (fromDimension != AndroidDimension::XHDPI)
	{
		view()->updateXHdpiValue(
			QString::number( AndroidDimensionHelper::convert(fromValue, fromDimension, AndroidDimension::XHDPI) )
		);
	}
	if (fromDimension != AndroidDimension::XXHDPI)
	{
		view()->updateXXHdpiValue(
			QString::number( AndroidDimensionHelper::convert(fromValue, fromDimension, AndroidDimension::XXHDPI) )
		);
	}
	if (fromDimension != AndroidDimension::XXXHDPI)
	{
		view()->updateXXXHdpiValue(
			QString::number( AndroidDimensionHelper::convert(fromValue, fromDimension, AndroidDimension::XXXHDPI) )
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
