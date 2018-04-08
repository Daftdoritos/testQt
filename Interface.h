#ifndef DEF_INTERFACE
#define DEF_INTERFACE

#include <QApplication>
#include <QtWidgets>


class MainWindow : public QMainWindow
{
Q_OBJECT
public:
	MainWindow();
	void Interface1();
	void Interface2();
public slots:
	void transfer();
private:
	QPushButton * m_bouton=new QPushButton("Start", this);
	QPushButton*quit = new QPushButton("Quit", this);
	QCheckBox *checkbox;
	
};




#endif