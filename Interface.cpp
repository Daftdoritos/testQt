#include "Interface.h"

Mainwindow::Mainwindow() : QMainWindow()
{
	this->setWindowTitle("pizza");
	this->setFixedSize(1000,500 );
	//this->setStyleSheet("background-image: url(./spacepizza.png)");
	
	QPixmap bkgnd("./Pimpmypizz.png");
	bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
	QPalette palette;
	palette.setBrush(QPalette::Background, bkgnd);
	this->setPalette(palette);


	// Construction du bouton Start
	
	m_bouton = new QPushButton("Start", this);
	quit = new QPushButton("Quit", this);
	m_bouton->setFont(QFont("Comic Sans MS", 14));
	quit->setFont(QFont("Comic Sans MS", 14));
	m_bouton->setCursor(Qt::PointingHandCursor);
	quit->setCursor(Qt::PointingHandCursor);

	quit->move(0, 50);

	//m_bouton->move(60, 50);

	//Construction du bouton Quit
}
