#include "interface.h"
#include "programme.h"
#include "CommunicationFPGA.h"

#include <iostream>
#include <stdlib.h>
#include <iostream>
#include <conio.h>
#include <string>
#include <chrono>
using namespace std;
bool Ecran2 = false;

MainWindow::MainWindow() {

	QShortcut * shortcut;

	shortcut = new QShortcut(QKeySequence(Qt::Key_Up), this,
		SLOT(on_up()));
	shortcut = new QShortcut(QKeySequence(Qt::Key_Down), this,
		SLOT(on_down()));
	shortcut = new QShortcut(QKeySequence(Qt::Key_Tab), this,
		SLOT(on_tab()));

	

	Interface1();

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
	Ecran2 = true;
	QPixmap bkgnd("./yellowfont.png");
	bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
	QPalette palette;
	palette.setBrush(QPalette::Background, bkgnd);
	this->setPalette(palette);

	lay1 = new QGridLayout;
	lay2 = new QGridLayout;
	lay3 = new QGridLayout;
	lay4 = new QGridLayout;

	for (int i = 0; i < TAILLE_SIZE; i++) {
		BOtailles[i] = new QRadioButton(QTgrandeur[i], this);
	}

	for (int i = 0; i < TAILLE_VIANDES - 1; i++) {
		BOviandes[i] = new QCheckBox(QTviandes[i], this);
	}
	for (int i = 0; i < TAILLE_CONDIMENTS - 1; i++) {
		BOcondiments[i] = new QCheckBox(QTcondiments[i], this);
	}
	for (int i = 0; i < TAILLE_FROMAGE - 1; i++) {
		BOfromages[i] = new QCheckBox(QTfromages[i], this);
	}

	scroll = new QScrollArea(this);
	viande = new QGroupBox("Viandes", this);
	grandeur = new QGroupBox("Grandeur", this);
	fromage = new QGroupBox("Fromage", this);
	condiment = new QGroupBox("Condiments", this);

	for (int i = 0; i < TAILLE_SIZE; i++) {
		lay1->addWidget(BOtailles[i], i, 0);
	}
	for (int i = 0; i < TAILLE_VIANDES-1; i++) {
		lay2->addWidget(BOviandes[i], i, 0);
	}
	for (int i = 0; i < TAILLE_CONDIMENTS - 1; i++) {
		lay3->addWidget(BOcondiments[i], i, 0);
	}
	for (int i = 0; i < TAILLE_FROMAGE - 1; i++) {
		lay4->addWidget(BOfromages[i], i, 0);
	}

	grandeur->setLayout(lay1);


	viande->setLayout(lay2);
	viande->move(210, 0);

	condiment->setLayout(lay3);
	condiment->move(110, 0);



	fromage->setLayout(lay4);
	fromage->move(310, 0);


	grandeur->show();
	viande->show();
	condiment->show();
	fromage->show();
	
	
	lay1->itemAtPosition(0,0)->widget()->setFocus();

	this->setStyleSheet("QCheckBox::focus{ background: black; color: white;}");
	this->setStyleSheet("QRadioButton::focus{ background: black; color: white;}");


	settruefalse();
}

void MainWindow::on_up()
{
	moveFocus(-1);
}

void MainWindow::on_down()
{
	moveFocus(1);
}
void MainWindow::on_tab()
{
	int actionphoneme=0;
	actionphoneme = pizza.detection_phoneme();
	if (actionphoneme ==0) {
		qDebug() << "aucun phoneme detecte";
	}
	if (actionphoneme == 1) {
		qDebug() << "aa detecte";
	}
	if (actionphoneme == 2) {
		qDebug() << "ee detecte";
	}
	if (actionphoneme == 4) {
		qDebug() << "ii detecte";
	}
	if (actionphoneme == 8) {
		qDebug() << "er detecte";
	}
}


void MainWindow::moveFocus(int dy)
{
	if (Ecran2 == false) {
		return;
	}
	if (qApp->focusWidget() == 0)
		return;
	int idx = lay1->indexOf(qApp->focusWidget());
	if (idx == -1)
		return;
	int r, c, rowSpan, colSpan;
	lay1->getItemPosition(idx, &r, &c, &rowSpan, &colSpan);
	QLayoutItem* layoutItem = lay1->itemAtPosition(r + dy, 0);
	if (layoutItem == 0)
		return;
	layoutItem->widget()->setFocus();
}
/*void State() {
	if(BOtailles[0]::checkedButton()){
		qDebug() << "er detecte";
	}
	else {
		qDebug() << "er detecte";
	}
}*/
void MainWindow::settruefalse() {
	for (int i = 0; i < TAILLE_SIZE; i++) {

		QObject::connect(BOtailles[i], SIGNAL(clicked()), qApp, SLOT(check()));
	}
	for (int i = 0; i <TAILLE_VIANDES - 1; i++) {

		QObject::connect(BOviandes[i], SIGNAL(clicked()), qApp, SLOT(check()));
	}
	for (int i = 0; i <TAILLE_CONDIMENTS - 1; i++) {

		QObject::connect(BOcondiments[i], SIGNAL(clicked()), qApp, SLOT(chech()));
	}
	for (int i = 0; i <TAILLE_FROMAGE - 1; i++) {

		QObject::connect(BOfromages[i], SIGNAL(clicked()), qApp, SLOT(check()));
	}
}

void MainWindow::check() {
	/*for (int i = 0; i < TAILLE_SIZE; i++) {
		if (BOtailles[i]->isChecked())
		{
			

		}
		else 
		
	}*/



}