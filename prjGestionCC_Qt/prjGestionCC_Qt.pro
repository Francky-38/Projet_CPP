QT       += core gui
QT       += sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Adresse.cpp \
    Client.cpp \
    Date.cpp \
    Fonctions.cpp \
    GccExeption.cpp \
    Particulier.cpp \
    Professionnel.cpp \
    dialog.cpp \
    main.cpp \
    Mainwindow.cpp

HEADERS += \
    Adresse.h \
    Client.h \
    Date.h \
    GccExeption.h \
    Mainwindow.h \
    Particulier.h \
    Professionnel.h \
    dialog.h \
    entete.h

FORMS += \
    Mainwindow.ui \
    dialog.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    ressources.qrc
