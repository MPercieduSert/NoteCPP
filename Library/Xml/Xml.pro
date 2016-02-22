TEMPLATE = lib
TARGET = Xml
CONFIG += staticlib


HEADERS += \
    XmlDoc.h \
    XmlElement.h \
    XmlReader.h \
    XmlWriter.h

SOURCES += \
    XmlDoc.cpp \
    XmlElement.cpp \
    XmlReader.cpp \
    XmlWriter.cpp

unix {
    target.path = /usr/lib
    INSTALLS += target
}
