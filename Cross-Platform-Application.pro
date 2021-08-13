QT       += core gui charts

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++14

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

TARGET = Cross-Platform-Application
TEMPLATE = app

SOURCES += main.cpp \
    CpuWidget.cpp \
    MainWindow.cpp \
    MemoryWidget.cpp \
    SysInfo.cpp \
    SysInfoWidget.cpp

HEADERS += MainWindow.h \
    CpuWidget.h \
    MemoryWidget.h \
    SysInfo.h \
    SysInfoWidget.h

windows {
    SOURCES += SysInfoWindowsImpl.cpp
	HEADERS += SysInfoWindowsImpl.h
}


FORMS += MainWindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
