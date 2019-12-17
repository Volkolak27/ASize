#ifndef ROUTESMANAGER_H
#define ROUTESMANAGER_H

#include "src/Modules/Main/Views/MainWindow.h"

enum RouteOperation
{
	OPEN,
	CLOSE,
	HIDE
};

class RoutesManager
{
	//// Свойства
	private:
		MainWindow* _mainWindow;

	//// Методы
	public:
		static RoutesManager& instance();
		void mainWindowNeedTo(const RouteOperation& operation);
		void openAboutWindow();

	// Блокировки и запреты для Одиночки
	private:
		explicit RoutesManager();
		~RoutesManager();
		RoutesManager(RoutesManager const&);
		RoutesManager& operator=(RoutesManager const&);
};

#endif // ROUTESMANAGER_H
