#include <QApplication>

#include "src/Managers/RoutesManager.h"

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);

	QApplication::setWindowIcon( QIcon(":/app/appicon") );
	RoutesManager::instance().mainWindowNeedTo(RouteOperation::OPEN);

	return a.exec();
}
