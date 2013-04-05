TARGET = gui_tests
CONFIG += console
CONFIG -= app_bundle
TEMPLATE = app

ROOT_DIR = ../..
DEPENDENCIES = qt_tstfrm map gui indexer graphics storage platform geometry coding base expat freetype fribidi protobuf tomcrypt jansson

include($$ROOT_DIR/common.pri)

QT *= opengl gui core

win32 {
  LIBS *= -lopengl32 -lshell32
  win32-g++: LIBS *= -lpthread
}
macx*: LIBS *= "-framework Foundation"

SOURCES += \
    ../../testing/testingmain.cpp \
    gui_tests.cpp

