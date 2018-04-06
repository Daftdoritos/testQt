
#include <QtWidgets/QApplication>
#include <QtWidgets>
#include <Interface.h>
/*#include <iostream>
#include <QTextEdit>
#include <QLabel>
#include <Qlayout>
#include <QPushButton>
#include <QFont>
#include <QIcon>*/
using namespace std;



int main(int argc, char **argv)
{
	QApplication app(argc, argv);

	/*QWidget* window= new QWidget;
	window->setWindowTitle("pizza");
	window->setStyleSheet("background-image: url(./PizzaMilano.png)");


	QPushButton *button = new QPushButton("Hello World", window);
	//button->setGeometry(10, 10, 80, 30);
	button->move(100, 100);
	button->setToolTip("Execute");
	button->setFont(QFont("Courier"));
	window->show();*/
	Mainwindow* window=new Mainwindow;
	window->show();
	
	
	




	return app.exec();
}