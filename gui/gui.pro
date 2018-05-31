SOURCES += \
    main.cpp \
    form.cpp \
    addepisodedialog.cpp \
    serial.cpp \
    serials.cpp

QT += widgets

FORMS += \
    form.ui \
    addepisodedialog.ui

HEADERS += \
    form.h \
    addepisodedialog.h \
    serial.h \
    serials.h

DISTFILES += \
    usersData.txt

QMAKE_CXXFLAGS += -std=c++0x

# qmake variables указать версию компилятора
