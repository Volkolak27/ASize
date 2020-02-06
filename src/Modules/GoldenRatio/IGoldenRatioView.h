#ifndef IGOLDENRATIOVIEW_H
#define IGOLDENRATIOVIEW_H

#include "src/Enums/GoldenRatioPart.h"
#include "src/Pattern/BaseView.h"
#include <QString>

class IGoldenRatioView : public BaseView
{
	public:
		virtual void updateSourceValue(const QString& value) = 0;
		virtual void updateRatioPart(const GoldenRatioPart& goldenRatioPart) = 0;
		virtual void updateShortValue(const QString& value) = 0;
		virtual void updateLongValue(const QString& value) = 0;
		virtual void updateWholeValue(const QString& value) = 0;
		virtual void needToResetToDefault() = 0;
};

#endif // IGOLDENRATIOVIEW_H
