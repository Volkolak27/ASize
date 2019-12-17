#include "RoutesManager.h"

#include "src/Modules/About/Assembly/AboutModuleAssembly.h"
#include "src/Modules/Main/Assembly/MainModuleAssembly.h"

RoutesManager& RoutesManager::instance()
{
	static RoutesManager instance = RoutesManager();
	return instance;
}

void RoutesManager::mainWindowNeedTo(const RouteOperation& operation)
{
	switch (operation)
	{
		case RouteOperation::OPEN:
			if (!_mainWindow) { _mainWindow = MainModuleAssembly::buildWindow(); }
			_mainWindow->move(120, 120);
			_mainWindow->show();
			break;

		case RouteOperation::CLOSE:
			if (_mainWindow)
			{
				_mainWindow->close();
				delete _mainWindow;
				_mainWindow = nullptr;
			}
			break;

		case RouteOperation::HIDE:
			if (_mainWindow) { _mainWindow->hide(); }
			break;
	}
}

void RoutesManager::openAboutWindow()
{
	AboutWindow* aboutWindow = AboutModuleAssembly::buildWindow();
	aboutWindow->move(120, 120);
	aboutWindow->show();
}

RoutesManager::RoutesManager()
{
	// empty
}

RoutesManager::~RoutesManager()
{
	// empty
}
