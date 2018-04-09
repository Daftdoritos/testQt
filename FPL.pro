TEMPLATE     = vcapp
TARGET       = LabApp7
CONFIG      += warn_on qt debug_and_release windows console
HEADERS     += Interface.h
SOURCES     += LabApp7.cpp Interface.cpp
LIBS        += CommunicationFPGA.lib
QT += widgets
