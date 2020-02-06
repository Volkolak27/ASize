#ifndef IPROPORTIONVIEW_H
#define IPROPORTIONVIEW_H

#include "src/Enums/MathOperation.h"
#include "src/Pattern/BaseView.h"
#include <QString>

class IProportionView : public BaseView
{
	public:
		virtual void updateAValue(const QString& value) = 0;
		virtual void updateBValue(const QString& value) = 0;
		virtual void updateCValue(const QString& value) = 0;
		virtual void updateDValue(const QString& value) = 0;
		virtual void updateACValue(const QString& value) = 0;
		virtual void updateBDValue(const QString& value) = 0;
		virtual void updateMathOperation(const MathOperation& operationType) = 0;
		virtual void needToResetToDefault() = 0;
};

#endif // IPROPORTIONVIEW_H
