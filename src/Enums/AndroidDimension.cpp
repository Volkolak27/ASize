#include "AndroidDimension.h"

double AndroidDimensionHelper::obtainKoef(const AndroidDimension& dimension)
{
	double koef = 0.0;

	switch (dimension)
	{
		case AndroidDimension::LDPI:
			koef = 0.75;
			break;
		case AndroidDimension::MDPI:
			koef = 1.00;
			break;
		case AndroidDimension::HDPI:
			koef = 1.50;
			break;
		case AndroidDimension::XHDPI:
			koef = 2.00;
			break;
		case AndroidDimension::XXHDPI:
			koef = 3.00;
			break;
		case AndroidDimension::XXXHDPI:
			koef = 4.00;
			break;
	}

	return koef;
}

double AndroidDimensionHelper::convert(const double& sourceValue, const AndroidDimension& sourceDimension, const AndroidDimension& targetDimension)
{
	return sourceValue * AndroidDimensionHelper::obtainKoef(targetDimension) / AndroidDimensionHelper::obtainKoef(sourceDimension);
}
