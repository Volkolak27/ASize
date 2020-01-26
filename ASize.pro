#--------------------------------------------------#
#                                                  #
# Project created by QtCreator 2019-12-07T19:37:45 #
# by binaryUnicorn                                 #
#                                                  #
#--------------------------------------------------#
QT += core gui widgets
TARGET = ASize
TEMPLATE = app
DEFINES += QT_DEPRECATED_WARNINGS
CONFIG += c++11
QMAKE_LFLAGS += -no-pie

# Копирование папки в директорию сборки
#copydata.commands = $(COPY_DIR) $$PWD/data $$OUT_PWD
#first.depends = $(first) copydata
#export(first.depends)
#export(copydata.commands)
#QMAKE_EXTRA_TARGETS += first copydata


# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

SOURCES += \
		main.cpp \
		src/Enums/AndroidDimension.cpp \
		src/Globals/Constants.cpp \
		src/Managers/RoutesManager.cpp \
		src/Modules/About/Assembly/AboutModuleAssembly.cpp \
		src/Modules/About/Presenters/AboutPresenter.cpp \
		src/Modules/About/Views/AboutWindow.cpp \
		src/Modules/AndroidSize/Assembly/AndroidSizeModuleAssembly.cpp \
		src/Modules/AndroidSize/Presenters/AndroidSizePresenter.cpp \
		src/Modules/AndroidSize/Views/AndroidSizeWidget.cpp \
		src/Modules/GoldenRatio/Assembly/GoldenRatioModuleAssembly.cpp \
		src/Modules/GoldenRatio/Presenters/GoldenRatioPresenter.cpp \
		src/Modules/GoldenRatio/Views/GoldenRatioWidget.cpp \
		src/Modules/Main/Assembly/MainModuleAssembly.cpp \
		src/Modules/Main/Views/MainWindow.cpp \
		src/Modules/Main/Presenters/MainPresenter.cpp \
		src/Modules/Proportion/Assembly/ProportionModuleAssembly.cpp \
		src/Modules/Proportion/Presenters/ProportionPresenter.cpp \
		src/Modules/Proportion/Views/ProportionWidget.cpp \
		src/Pattern/BaseView.cpp

HEADERS += \
		src/Enums/AndroidDimension.h \
		src/Enums/GoldenRatioPart.h \
		src/Enums/MathOperation.h \
		src/Globals/Constants.h \
		src/Managers/RoutesManager.h \
		src/Modules/About/Assembly/AboutModuleAssembly.h \
		src/Modules/About/IAboutPresenter.h \
		src/Modules/About/IAboutView.h \
		src/Modules/About/Presenters/AboutPresenter.h \
		src/Modules/About/Views/AboutWindow.h \
		src/Modules/AndroidSize/Assembly/AndroidSizeModuleAssembly.h \
		src/Modules/AndroidSize/IAndroidSizePresenter.h \
		src/Modules/AndroidSize/IAndroidSizeView.h \
		src/Modules/AndroidSize/Presenters/AndroidSizePresenter.h \
		src/Modules/AndroidSize/Views/AndroidSizeWidget.h \
		src/Modules/GoldenRatio/Assembly/GoldenRatioModuleAssembly.h \
		src/Modules/GoldenRatio/IGoldenRatioPresenter.h \
		src/Modules/GoldenRatio/IGoldenRatioView.h \
		src/Modules/GoldenRatio/Presenters/GoldenRatioPresenter.h \
		src/Modules/GoldenRatio/Views/GoldenRatioWidget.h \
		src/Modules/Main/Assembly/MainModuleAssembly.h \
		src/Modules/Main/Views/MainWindow.h \
		src/Modules/Main/IMainPresenter.h \
		src/Modules/Main/IMainView.h \
		src/Modules/Main/Presenters/MainPresenter.h \
		src/Modules/Proportion/Assembly/ProportionModuleAssembly.h \
		src/Modules/Proportion/IProportionPresenter.h \
		src/Modules/Proportion/IProportionView.h \
		src/Modules/Proportion/Presenters/ProportionPresenter.h \
		src/Modules/Proportion/Views/ProportionWidget.h \
		src/Pattern/BasePresenter.h \
		src/Pattern/BaseView.h \
		src/Pattern/IMvpPresenter.h \
		src/Pattern/IMvpView.h

FORMS += \
		src/Modules/About/Views/AboutWindow.ui \
		src/Modules/AndroidSize/Views/AndroidSizeWidget.ui \
		src/Modules/GoldenRatio/Views/GoldenRatioWidget.ui \
		src/Modules/Main/Views/MainWindow.ui \
		src/Modules/Proportion/Views/ProportionWidget.ui

RESOURCES += \
	resources.qrc
