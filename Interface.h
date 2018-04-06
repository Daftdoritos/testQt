#ifndef DEF_INTERFACE
#define DEF_INTERFACE

#include <QApplication>
#include <QtWidgets>

class Mainwindow : public QMainWindow // On hérite de QMainWindow (IMPORTANT)
{
public:
	Mainwindow();

private:
	QPushButton * m_bouton=new QPushButton;
	QPushButton*quit = new QPushButton;
};

#endif