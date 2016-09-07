CONFIG += c++11

HEADERS += \
    $$PWD/profile.h \
    $$PWD/gttransformedprofile.h \
    $$PWD/profileinconfiguration.h \
    $$PWD/teklaprofiletransformer.h \
    $$PWD/profilemapper.h \
    $$PWD/teklaprofilemapper.h \
    $$PWD/fileprofilemapper.h \
    $$PWD/filewriter.h

SOURCES += \
    $$PWD/gttransformedprofile.cpp \
    $$PWD/profileinconfiguration.cpp \
    $$PWD/teklaprofiletransformer.cpp \
    $$PWD/teklaprofilemapper.cpp \
    $$PWD/fileprofilemapper.cpp \
    $$PWD/filewriter.cpp
