lessThan(QT_MAJOR_VERSION, 5) | lessThan(QT_MINOR_VERSION, 6) {
    error("You need at least Qt 5.6.")
}

QT += core
QT -= gui

CONFIG += c++11

TARGET = TeklaProfileMapper
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp

include ("../defaults.pri")
include ("../src/includes.pri")
include ("gitversion.pri")
