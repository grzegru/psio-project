TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        GameMenu.cpp \
        Points.cpp \
        background.cpp \
        bird.cpp \
        bonus.cpp \
        collisions.cpp \
        gameover.cpp \
        ground.cpp \
        main.cpp \
        pipes.cpp
        INCLUDEPATH += "C:\QT\SFML-2.5.1/include"


        LIBS += -L"C:\QT\SFML-2.5.1/lib"
        CONFIG(debug, debug|release){
        LIBS += -lsfml-audio-d -lsfml-graphics-d -lsfml-network-d -lsfml-system-d -lsfml-window-d
        } else {
        LIBS += -lsfml-audio -lsfml-graphics -lsfml-network -lsfml-system -lsfml-window
        }

HEADERS += \
    GameMenu.h \
    Points.h \
    background.h \
    bird.h \
    bonus.h \
    collisions.h \
    gameover.h \
    ground.h \
    pipes.h
