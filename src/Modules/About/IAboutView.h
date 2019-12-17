#ifndef IABOUTVIEW_H
#define IABOUTVIEW_H

#include "src/Pattern/BaseView.h"
#include <QString>

class IAboutView : public BaseView
{
	public:
		virtual void updateVersion(const QString& version) = 0;
		virtual void updateEmail(const QString& email) = 0;
		virtual void toEmail(const QString& email) = 0;
		virtual void toAboutQt() = 0;
		virtual void toBack() = 0;
};

#endif // IABOUTVIEW_H
