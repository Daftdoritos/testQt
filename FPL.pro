TEMPLATE     = vcapp
TARGET       = LabApp7
CONFIG      += warn_on qt debug_and_release windows console
HEADERS     += Interface.h programme.h CommunicationFPGA.h
SOURCES     += LabApp7.cpp Interface.cpp programme.cpp
LIBS        += CommunicationFPGA.lib
QT += widgets
win32:RC_ICONS += ./assets/pimpmypizzaico.ico