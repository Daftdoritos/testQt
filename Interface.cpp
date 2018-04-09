#include "Interface.h"
#include "programme.h"
#include "CommunicationFPGA.h"

#include <iostream>
#include <stdlib.h>
#include <iostream>
#include <conio.h>
#include <string>
#include <chrono>
using namespace std;

MainWindow::MainWindow() {
	Interface1();

	//Interface2();
}

void MainWindow::Interface1()
{
	this->setWindowTitle("pizza");
	this->setFixedSize(885, 412);
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
	quit->move(0, 380);
	//this->show();

	QObject::connect(quit, SIGNAL(clicked()), qApp, SLOT(quit()));
	QObject::connect(m_bouton, SIGNAL(clicked()), this, SLOT(transfer()));

}
void MainWindow::transfer() {
	delete m_bouton;

	Interface2();

}

void MainWindow::Interface2() {
	QPixmap bkgnd("./yellowfont.png");
	bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
	QPalette palette;
	palette.setBrush(QPalette::Background, bkgnd);
	this->setPalette(palette);

	lay1 = new QVBoxLayout;
	lay2 = new QVBoxLayout;
	lay3 = new QVBoxLayout;
	lay4 = new QVBoxLayout;
	petite = new QCheckBox("Petite", this);
	moyenne = new QCheckBox("Moyenne", this);
	large = new QCheckBox("Large", this);
	extralarge = new QCheckBox("Extra-Large", this);

	tomate = new QCheckBox("Tomates", this);
	onion = new QCheckBox("Onions", this);
	piment = new QCheckBox("Piments", this);
	epinard = new QCheckBox("Epinards", this);
	champignon = new QCheckBox("Champignon", this);
	jalapenos = new QCheckBox("Jalapenos", this);
	ananas = new QCheckBox("Ananas", this);
	olive = new QCheckBox("Olives", this);
	ail = new QCheckBox("Ail", this);

	steak = new QCheckBox("Steak", this);
	pepperoni = new QCheckBox("Pepperoni", this);
	salami = new QCheckBox("Salami", this);
	prosciutto = new QCheckBox("Prosciutto", this);
	bacon = new QCheckBox("Bacon", this);
	jambon = new QCheckBox("Jambon", this);
	saucisse = new QCheckBox("Saucisse", this);
	poulet = new QCheckBox("Poulet", this);
	anchoix = new QCheckBox("Anchoix", this);

	cheddar = new QCheckBox("Cheddar", this);
	parmesan = new QCheckBox("Parmesan", this);
	fetta = new QCheckBox("Fetta", this);
	monterejack = new QCheckBox("MoontereJack", this);
	provolone = new QCheckBox("Provolone", this);
	chevre = new QCheckBox("Chevre", this);
	bleu = new QCheckBox("Bleu", this);


	scroll = new QScrollArea(this);
	viande = new QGroupBox("Viandes", this);
	grandeur = new QGroupBox("Grandeur", this);
	fromage = new QGroupBox("Fromage", this);
	condiment = new QGroupBox("Condiments", this);

	lay1->addWidget(petite);
	lay1->addWidget(moyenne);
	lay1->addWidget(large);
	lay1->addWidget(extralarge);

	grandeur->setLayout(lay1);

	lay2->addWidget(steak);
	lay2->addWidget(pepperoni);
	lay2->addWidget(salami);
	lay2->addWidget(prosciutto);
	lay2->addWidget(bacon);
	lay2->addWidget(jambon);
	lay2->addWidget(poulet);
	lay2->addWidget(anchoix);
	viande->setLayout(lay2);
	viande->move(210, 0);

	lay3->addWidget(tomate);
	lay3->addWidget(onion);
	lay3->addWidget(piment);
	lay3->addWidget(epinard);
	lay3->addWidget(champignon);
	lay3->addWidget(jalapenos);
	lay3->addWidget(ananas);
	lay3->addWidget(olive);
	lay3->addWidget(ail);
	condiment->setLayout(lay3);
	condiment->move(110, 0);

	lay4->addWidget(cheddar);
	lay4->addWidget(parmesan);
	lay4->addWidget(fetta);
	lay4->addWidget(monterejack);
	lay4->addWidget(provolone);
	lay4->addWidget(chevre);
	lay4->addWidget(bleu);

	fromage->setLayout(lay4);
	fromage->move(310, 0);

	//groupbox->move(0,0);
	grandeur->show();
	viande->show();
	condiment->show();
	fromage->show();
	/*scroll->setWidget(peperonni);
	scroll->show();*/
	this->show();

}