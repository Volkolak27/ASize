#ifndef IANDROIDSIZEVIEW_H
#define IANDROIDSIZEVIEW_H

#include "src/Pattern/BaseView.h"
#include <QString>

class IAndroidSizeView : public BaseView
{
	public:
		virtual void updateLdpiValue(const QString& value) = 0;
		virtual void updateMdpiValue(const QString& value) = 0;
		virtual void updateHdpiValue(const QString& value) = 0;
		virtual void updateXHdpiValue(const QString& value) = 0;
		virtual void updateXXHdpiValue(const QString& value) = 0;
		virtual void updateXXXHdpiValue(const QString& value) = 0;
		virtual void needToResetToDefault() = 0;
};

#endif // IANDROIDSIZEVIEW_H
