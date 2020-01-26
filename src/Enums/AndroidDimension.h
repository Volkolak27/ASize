#ifndef ANDROIDDIMENSION_H
#define ANDROIDDIMENSION_H

enum AndroidDimension
{
	LDPI,
	MDPI,
	HDPI,
	XHDPI,
	XXHDPI,
	XXXHDPI
};

class AndroidDimensionHelper
{
	//// Методы
	public:
		static double obtainKoef(const AndroidDimension& dimension);
		static double convert(const double& sourceValue, const AndroidDimension& sourceDimension, const AndroidDimension& targetDimension);
};

#endif // ANDROIDDIMENSION_H
