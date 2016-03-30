TEMPLATE = lib
TARGET = Fen
CONFIG += staticlib
CONFIG += c++11
QT  += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets



#win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../Div/release/ -lDiv
#else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../Div/debug/ -lDiv
#else:unix: LIBS += -L$$OUT_PWD/../Div/ -lDiv

#INCLUDEPATH += $$PWD/../Div
#DEPENDPATH += $$PWD/../Div

#win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../Div/release/libDiv.a
#else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../Div/debug/libDiv.a
#else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../Div/release/Div.lib
#else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../Div/debug/Div.lib
#else:unix: PRE_TARGETDEPS += $$OUT_PWD/../Div/libDiv.a

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../Model/release/ -lModel
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../Model/debug/ -lModel
else:unix: LIBS += -L$$OUT_PWD/../Model/ -lModel

INCLUDEPATH += $$PWD/../Model
DEPENDPATH += $$PWD/../Model

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../Model/release/libModel.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../Model/debug/libModel.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../Model/release/Model.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../Model/debug/Model.lib
else:unix: PRE_TARGETDEPS += $$OUT_PWD/../Model/libModel.a

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../Delegate/release/ -lDelegate
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../Delegate/debug/ -lDelegate
else:unix: LIBS += -L$$OUT_PWD/../Delegate/ -lDelegate

INCLUDEPATH += $$PWD/../Delegate
DEPENDPATH += $$PWD/../Delegate

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../Delegate/release/libDelegate.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../Delegate/debug/libDelegate.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../Delegate/release/Delegate.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../Delegate/debug/Delegate.lib
else:unix: PRE_TARGETDEPS += $$OUT_PWD/../Delegate/libDelegate.a

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../Widget/release/ -lWidget
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../Widget/debug/ -lWidget
else:unix: LIBS += -L$$OUT_PWD/../Widget/ -lWidget

INCLUDEPATH += $$PWD/../Widget
DEPENDPATH += $$PWD/../Widget

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../Widget/release/libWidget.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../Widget/debug/libWidget.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../Widget/release/Widget.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../Widget/debug/Widget.lib
else:unix: PRE_TARGETDEPS += $$OUT_PWD/../Widget/libWidget.a

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../Dialog/release/ -lDialog
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../Dialog/debug/ -lDialog
else:unix: LIBS += -L$$OUT_PWD/../Dialog/ -lDialog

INCLUDEPATH += $$PWD/../Dialog
DEPENDPATH += $$PWD/../Dialog

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../Dialog/release/libDialog.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../Dialog/debug/libDialog.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../Dialog/release/Dialog.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../Dialog/debug/Dialog.lib
else:unix: PRE_TARGETDEPS += $$OUT_PWD/../Dialog/libDialog.a

HEADERS += \
    FenPrincipale.h \
    Fen.h \
    FenMenu.h \
    FenFoundFile.h \
    FenNote.h \
    FenExo.h \
    TabModule.h \
    TabMenu.h \
    TabAbstractModule.h \
    TabClasse.h \
    TabListeEleve.h \
    TabListeGroupe.h \
    TabAbstractTableau.h \
    TabAbstractClasse.h

SOURCES += \
    FenPrincipale.cpp \
    Fen.cpp \
    FenMenu.cpp \
    FenFoundFile.cpp \
    FenNote.cpp \
    FenExo.cpp \
    TabModule.cpp \
    TabMenu.cpp \
    TabAbstractModule.cpp \
    TabClasse.cpp \
    TabListeEleve.cpp \
    TabListeGroupe.cpp \
    TabAbstractTableau.cpp \
    TabAbstractClasse.cpp

unix {
    target.path = /usr/lib
    INSTALLS += target
}
