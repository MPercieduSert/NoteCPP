TEMPLATE = lib
TARGET = Div
CONFIG += staticlib
CONFIG += c++11
QT  += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../Xml/release/ -lXml
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../Xml/debug/ -lXml
else:unix: LIBS += -L$$OUT_PWD/../Xml/ -lXml

INCLUDEPATH += $$PWD/../Xml
DEPENDPATH += $$PWD/../Xml

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../Xml/release/libXml.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../Xml/debug/libXml.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../Xml/release/Xml.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../Xml/debug/Xml.lib
else:unix: PRE_TARGETDEPS += $$OUT_PWD/../Xml/libXml.a

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../Manager/release/ -lManager
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../Manager/debug/ -lManager
else:unix: LIBS += -L$$OUT_PWD/../Manager/ -lManager

INCLUDEPATH += $$PWD/../Manager
DEPENDPATH += $$PWD/../Manager

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../Manager/release/libManager.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../Manager/debug/libManager.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../Manager/release/Manager.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../Manager/debug/Manager.lib
else:unix: PRE_TARGETDEPS += $$OUT_PWD/../Manager/libManager.a


#HEADERS += \
#    ../Entities/Annee.h \
#    ../Entities/Appreciation.h \
#    ../Entities/Attribut.h \
#    ../Entities/Attribut_bareme.h \
#    ../Entities/Attribut_exercice.h \
#    ../Entities/Bareme.h \
#    ../Entities/Classe.h \
#    ../Entities/Commentaire.h \
#    ../Entities/Coefficient.h \
#    ../Entities/Controle.h \
#    ../Entities/Controle_exercice.h \
#    ../Entities/Eleve.h \
#    ../Entities/Eleve_groupe.h \
#    ../Entities/Entity.h \
#    ../Entities/EntityAnnee.h \
#    ../Entities/Exercice.h \
#    ../Entities/Groupe.h \
#    ../Entities/ListEntities.h \
#    ../Entities/Note.h \
#    ../Entities/NumControle.h \
#    ../Entities/Niveau.h \
#    ../Entities/Point.h \
#    ../Entities/Source.h \
#    ../Entities/TypeControle.h \
#    ../Entities/TypeGroupe.h \
#    ../Entities/TypeNiveau.h \
#    ../Manager/AnneeManager.h \
#    ../Manager/AppreciationManager.h \
#    ../Manager/AttributManager.h \
#    ../Manager/Attribut_baremeManager.h \
#    ../Manager/Attribut_exerciceManager.h \
#    ../Manager/BaremeManager.h \
#    ../Manager/ClasseManager.h \
#    ../Manager/CommentaireManager.h \
#    ../Manager/CoefficientManager.h \
#    ../Manager/ControleManager.h \
#    ../Manager/Controle_exerciceManager.h \
#    ../Manager/EleveManager.h \
#    ../Manager/Eleve_groupeManager.h \
#    ../Manager/ExerciceManager.h \
#    ../Manager/GroupeManager.h \
#    ../Manager/NoteManager.h \
#    ../Manager/NumControleManager.h \
#    ../Manager/NiveauManager.h \
#    ../Manager/Manager.h \
#    ../Manager/ManagerAnnee.h \
#    ../Manager/PointManager.h \
#    ../Manager/SourceManager.h \
#    ../Manager/TypeControleManager.h \
#    ../Manager/TypeGroupeManager.h \
#    ../Manager/TypeNiveauManager.h \
    #../Xml/XmlDoc.h \
    #../Xml/XmlElement.h \
    #../Xml/XmlReader.h \
    #../Xml/XmlWriter.h

#SOURCES += \
#    ../Entities/Annee.cpp \
#    ../Entities/Appreciation.cpp \
#    ../Entities/Attribut.cpp \
#    ../Entities/Attribut_bareme.cpp \
#    ../Entities/Attribut_exercice.cpp \
#    ../Entities/Bareme.cpp \
#    ../Entities/Classe.cpp \
#    ../Entities/Commentaire.cpp \
#    ../Entities/Coefficient.cpp \
#    ../Entities/Controle.cpp \
#    ../Entities/Controle_exercice.cpp \
#    ../Entities/Eleve.cpp \
#    ../Entities/Eleve_groupe.cpp \
#    ../Entities/Entity.cpp \
#    ../Entities/EntityAnnee.cpp \
#    ../Entities/Exercice.cpp \
#    ../Entities/Groupe.cpp \
#    ../Entities/ListEntities.cpp \
#    ../Entities/Note.cpp \
#    ../Entities/NumControle.cpp \
#    ../Entities/Niveau.cpp \
#    ../Entities/Point.cpp \
#    ../Entities/Source.cpp \
#    ../Entities/TypeControle.cpp \
#    ../Entities/TypeGroupe.cpp \
#    ../Entities/TypeNiveau.cpp \
#    ../Manager/AnneeManager.cpp \
#    ../Manager/AppreciationManager.cpp \
#    ../Manager/AttributManager.cpp \
#    ../Manager/Attribut_baremeManager.cpp \
#    ../Manager/Attribut_exerciceManager.cpp \
#    ../Manager/BaremeManager.cpp \
#    ../Manager/ClasseManager.cpp \
#    ../Manager/CommentaireManager.cpp \
#    ../Manager/CoefficientManager.cpp \
#    ../Manager/ControleManager.cpp \
#    ../Manager/Controle_exerciceManager.cpp \
#    ../Manager/EleveManager.cpp \
#    ../Manager/Eleve_groupeManager.cpp \
#    ../Manager/ExerciceManager.cpp \
#    ../Manager/GroupeManager.cpp \
#    ../Manager/NoteManager.cpp \
#    ../Manager/NumControleManager.cpp \
#    ../Manager/NiveauManager.cpp \
#    ../Manager/Manager.cpp \
#    ../Manager/ManagerAnnee.cpp \
#    ../Manager/PointManager.cpp \
#    ../Manager/SourceManager.cpp \
#    ../Manager/TypeControleManager.cpp \
#    ../Manager/TypeGroupeManager.cpp \
#    ../Manager/TypeNiveauManager.cpp \
    #../Xml/XmlDoc.cpp \
    #../Xml/XmlElement.cpp \
    #../Xml/XmlReader.cpp \
    #../Xml/XmlWriter.cpp

HEADERS += \
    Bdd.h \
    Config.h \
    FileInterface.h \
    Tree.h \
    TreeItem.h

SOURCES += \
    Bdd.cpp \
    Config.cpp \
    FileInterface.cpp \
    Tree.cpp \
    TreeItem.cpp

unix {
    target.path = /usr/lib
    INSTALLS += target
}


