#-------------------------------------------------
#
# Project created by QtCreator 2016-04-06T12:22:11
#
#-------------------------------------------------

QMAKE_CPPFLAGS *= $(shell dpkg-buildflags --get CPPFLAGS)
QMAKE_CFLAGS   *= $(shell dpkg-buildflags --get CFLAGS)
QMAKE_CXXFLAGS *= $(shell dpkg-buildflags --get CXXFLAGS)
QMAKE_LFLAGS   *= $(shell dpkg-buildflags --get LDFLAGS)

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = mx-debian-backports-installer
TEMPLATE = app


SOURCES += main.cpp \
    versionnumber.cpp \
    mainwindow.cpp

HEADERS  += mainwindow.h \
    versionnumber.h

FORMS    += mainwindow.ui

TRANSLATIONS += translations/mx-debian-backports-installer_ca.ts \
                translations/mx-debian-backports-installer_de.ts \
                translations/mx-debian-backports-installer_el.ts \
                translations/mx-debian-backports-installer_es.ts \
                translations/mx-debian-backports-installer_fr.ts \
                translations/mx-debian-backports-installer_it.ts \
                translations/mx-debian-backports-installer_ja.ts \
                translations/mx-debian-backports-installer_nl.ts \
                translations/mx-debian-backports-installer_pl.ts \
                translations/mx-debian-backports-installer_ro.ts \
                translations/mx-debian-backports-installer_ru.ts \
                translations/mx-debian-backports-installer_sv.ts
