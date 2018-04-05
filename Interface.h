#ifndef DEF_INTERFACE
#define DEF_INTERFACE

#include <QApplication>
#include <QtWidgets>

class Mainwindow : public QWidget // On hérite de QWidget (IMPORTANT)
{
public:
	Mainwindow();

private:
	QPushButton * m_bouton;
};

#endif