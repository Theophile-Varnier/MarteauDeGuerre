QT += widgets\
      xml

HEADERS += \
    unite.h \
    creerlistearmee.h \
    figurine.h \
    joingameform.h \
    lancementwindows.h \
    livrearmee.h \
    personnage.h \
    regiment.h \
    sorcier.h \
    common.h \
    optiongroupbox.h

SOURCES += \
    unite.cpp \
    creerlistearmee.cpp \
    figurine.cpp \
    joingameform.cpp \
    lancementwindows.cpp \
    livrearmee.cpp \
    main.cpp \
    personnage.cpp \
    regiment.cpp \
    sorcier.cpp \
    optiongroupbox.cpp

OTHER_FILES += \
    xml/ArmeesDisponibles.xml \
    xml/common/ArmesMagiques.xml \
    xml/armees/HautsElfes/Unites.xml \
    xml/armees/OrquesetGobelins/Unites.xml
