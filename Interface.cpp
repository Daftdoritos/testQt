#include "Interface.h"

Mainwindow::Mainwindow() : QMainWindow()
{
	this->setWindowTitle("pizza");
	//this->setStyleSheet("background-image: url(./spacepizza.png)");
	
	QPixmap bkgnd("./spacepizza.png");
	bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
	QPalette palette;
	palette.setBrush(QPalette::Background, bkgnd);
	this->setPalette(palette);


	// Construction du bouton Start
	m_bouton = new QPushButton("Start", this);

	m_bouton->setFont(QFont("Comic Sans MS", 14));
	m_bouton->setCursor(Qt::PointingHandCursor);
	m_bouton->move(60, 50);

	//Construction du bouton Quit
}
