#include "Interface.h"
#include <iostream>
using namespace std;
Mainwindow::Mainwindow() : QMainWindow()
{
	this->setWindowTitle("pizza");
	this->setFixedSize(885,412 );
	//this->setStyleSheet("background-image: url(./spacepizza.png)");
	
	QPixmap bkgnd("./Pimpmypizz.png");
	bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
	QPalette palette;
	palette.setBrush(QPalette::Background, bkgnd);
	this->setPalette(palette);


	// Construction des deux boutons Start Quit
	
	m_bouton->setFont(QFont("Comic Sans MS", 14));
	quit->setFont(QFont("Comic Sans MS", 14));
	m_bouton->setCursor(Qt::PointingHandCursor);
	quit->setCursor(Qt::PointingHandCursor);
	
	quit->move(0, 50);
	
	QObject::connect(quit, SIGNAL(clicked()), qApp, SLOT(quit()));
	QObject::connect(m_bouton, SIGNAL(clicked()), this, SLOT(transfer()));
	
}

void Mainwindow::transfer() {
	delete m_bouton;
	
	Taillewindow();

}


Taillewindow::Taillewindow() :QMainWindow() {
		
	QPushButton*j = new QPushButton("hello",this);




}
