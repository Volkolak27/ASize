#include <QApplication>

#include "src/Managers/RoutesManager.h"
#include <QFontDatabase>

int main(int argc, char* argv[])
{
	QApplication a(argc, argv);

	QFontDatabase::addApplicationFont(":/fonts/ubuntuR");
	qApp->setFont(QFont("Ubuntu", 11, QFont::Normal, false));

	QApplication::setWindowIcon( QIcon(":/app/appicon") );
	RoutesManager::instance().mainWindowNeedTo(RouteOperation::OPEN);

	return a.exec();
}
