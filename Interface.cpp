#include "Interface.h"

Mainwindow::Mainwindow() : QWidget()
{
	this->setWindowTitle("pizza");
	this->setStyleSheet("background-image: url(./spacepizza.png)");
	// Construction du bouton
	m_bouton = new QPushButton("Pimp mon bouton !", this);

	m_bouton->setFont(QFont("Comic Sans MS", 14));
	m_bouton->setCursor(Qt::PointingHandCursor);
	m_bouton->move(60, 50);
}
