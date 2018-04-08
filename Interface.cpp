#include "Interface.h"
#include <iostream>
using namespace std;

MainWindow::MainWindow() {
	Interface1();

	//Interface2();
}

void MainWindow::Interface1() 
{
	this->setWindowTitle("pizza");
	this->setFixedSize(885,412 );
	//this->setStyleSheet("background-image: url(./Pimpmypizz.png)");
	
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
	//this->show();
	
	QObject::connect(quit, SIGNAL(clicked()), qApp, SLOT(quit()));
	QObject::connect(m_bouton, SIGNAL(clicked()), this, SLOT(transfer()));

}
void MainWindow::transfer(){
	delete m_bouton;

	Interface2();

}

void MainWindow::Interface2() {
	QPixmap bkgnd("./yellowfont.png");
	bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
	QPalette palette;
	palette.setBrush(QPalette::Background, bkgnd);
	this->setPalette(palette);

	layout = new QGridLayout;
	
	peperonni= new QCheckBox("Peperonni", this);
	poivrons = new QCheckBox("Poivrons", this);
	champignons = new QCheckBox("Champignons", this);

	layout->addWidget(peperonni, 0, 0);
	layout->addWidget(poivrons, 0, 1);
	layout->addWidget(champignons, 1, 0);


	this->setLayout(layout);

	


	this->show();




	//this->show();

}



//void Interface1