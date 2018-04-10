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
	shortcut = new QShortcut(QKeySequence(Qt::Key_Return), this,
		SLOT(on_enter()));
	shortcut = new QShortcut(QKeySequence(Qt::Key_Left), this,
		SLOT(on_left()));
	shortcut = new QShortcut(QKeySequence(Qt::Key_Right), this,
		SLOT(on_right()));

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

	//scroll = new QScrollArea(this);
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


	//this->setStyleSheet("QRadioButton::focus{ background: black; color: white;}");
	this->setStyleSheet("QCheckBox::focus{ background: black; color: white;}"
					"QRadioButton::focus{ background: black; color: white;}");


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

void MainWindow::on_enter()
{
	if (Ecran2 == false) {
		return;
	}

	int idex1 = lay1->indexOf(qApp->focusWidget());
	int idex2 = lay2->indexOf(qApp->focusWidget());
	int idex3 = lay3->indexOf(qApp->focusWidget());
	int idex4 = lay4->indexOf(qApp->focusWidget());
	if (idex1 != -1) {
		lay3->itemAtPosition(0, 0)->widget()->setFocus();
	}
	if (idex3 != -1) {
		lay2->itemAtPosition(0, 0)->widget()->setFocus();
	}
	if (idex2 != -1) {
		lay4->itemAtPosition(0, 0)->widget()->setFocus();
	}
	if (idex4 != -1) {
		lay1->itemAtPosition(0, 0)->widget()->setFocus();
	}
}
void MainWindow::on_right()
{
	if (Ecran2 == false) {
		return;
	}
	int idex1 = lay1->indexOf(qApp->focusWidget());
	int idex2 = lay2->indexOf(qApp->focusWidget());
	int idex3 = lay3->indexOf(qApp->focusWidget());
	int idex4 = lay4->indexOf(qApp->focusWidget());
	if (idex1 != -1) {
		lay3->itemAtPosition(0, 0)->widget()->setFocus();
	}
	if (idex3 != -1) {
		lay2->itemAtPosition(0, 0)->widget()->setFocus();
	}
	if (idex2 != -1) {
		lay4->itemAtPosition(0, 0)->widget()->setFocus();
	}
	if (idex4 != -1) {
		lay1->itemAtPosition(0, 0)->widget()->setFocus();
	}
}
void MainWindow::on_left()
{
	if (Ecran2 == false) {
		return;
	}
	int idex1 = lay1->indexOf(qApp->focusWidget());
	int idex2 = lay2->indexOf(qApp->focusWidget());
	int idex3 = lay3->indexOf(qApp->focusWidget());
	int idex4 = lay4->indexOf(qApp->focusWidget());
	if (idex3 != -1) {
		lay1->itemAtPosition(0, 0)->widget()->setFocus();
	}
	if (idex2 != -1) {
		lay3->itemAtPosition(0, 0)->widget()->setFocus();
	}
	if (idex4 != -1) {
		lay2->itemAtPosition(0, 0)->widget()->setFocus();
	}
	if (idex1 != -1) {
		lay4->itemAtPosition(0, 0)->widget()->setFocus();
	}
}





void MainWindow::moveFocus(int dy)
{
	if (Ecran2 == false) {
		return;
	}

	if (qApp->focusWidget() == 0)
		return;
	int idx1 = lay1->indexOf(qApp->focusWidget());
	int idx2 = lay2->indexOf(qApp->focusWidget());
	int idx3 = lay3->indexOf(qApp->focusWidget());
	int idx4 = lay4->indexOf(qApp->focusWidget());
	if (idx1 == -1 && idx2 == -1 && idx4 == -1 && idx3 == -1)
		return;
	if (idx1 != -1) {
	int r, c, rowSpan, colSpan;
	lay1->getItemPosition(idx1, &r, &c, &rowSpan, &colSpan);
	QLayoutItem* layoutItem = lay1->itemAtPosition(r + dy, 0);
	if (layoutItem == 0)
		return;
	layoutItem->widget()->setFocus();
	}
	else if (idx2 != -1) {
		int r, c, rowSpan, colSpan;
		lay2->getItemPosition(idx2, &r, &c, &rowSpan, &colSpan);
		QLayoutItem* layoutItem = lay2->itemAtPosition(r + dy, 0);
		if (layoutItem == 0)
			return;
		layoutItem->widget()->setFocus();
	}
	else if (idx3 != -1) {
		int r, c, rowSpan, colSpan;
		lay3->getItemPosition(idx3, &r, &c, &rowSpan, &colSpan);
		QLayoutItem* layoutItem = lay3->itemAtPosition(r + dy, 0);
		if (layoutItem == 0)
			return;
		layoutItem->widget()->setFocus();
	}
	else if (idx4 != -1) {
		int r, c, rowSpan, colSpan;
		lay4->getItemPosition(idx4, &r, &c, &rowSpan, &colSpan);
		QLayoutItem* layoutItem = lay4->itemAtPosition(r + dy, 0);
		if (layoutItem == 0)
			return;
		layoutItem->widget()->setFocus();
	}
	
}
/*void State() {

}*/

void MainWindow::settruefalse() {
	for (int i = 0; i < TAILLE_SIZE; i++) {

		QObject::connect(BOtailles[i], SIGNAL(clicked()), this, SLOT(check()));
	}
	for (int i = 0; i <TAILLE_VIANDES - 1; i++) {

		QObject::connect(BOviandes[i], SIGNAL(clicked()), this, SLOT(check()));
	}
	for (int i = 0; i <TAILLE_CONDIMENTS - 1; i++) {

		QObject::connect(BOcondiments[i], SIGNAL(clicked()), this, SLOT(check()));
	}
	for (int i = 0; i <TAILLE_FROMAGE - 1; i++) {

		QObject::connect(BOfromages[i], SIGNAL(clicked()), this, SLOT(check()));
	}
	
}

void MainWindow::check() {
	prixtotal = 0;
	for (int i = 0; i < TAILLE_SIZE; i++) {
		if (BOtailles[i]->isChecked())
		{
			choisistaille[i] = true;
			prixtotal = prix_Grandeur[i] + prixtotal;
		}
		else
		{
			choisistaille[i] = false;
			
			//qApp->quit();
		}
	
		//qInfo()<< choisistaille[i];
	}
	for (int i = 0; i < TAILLE_CONDIMENTS - 1; i++) {
		if (BOcondiments[i]->isChecked())
		{
			choisiscondiments[i] = true;
			prixtotal = prixCondiment[i] + prixtotal;
		}
		else
		{
			choisiscondiments[i] = false;
		}

	}
	for (int i = 0; i <  TAILLE_CONDIMENTS - 1; i++) {
		if (BOviandes[i]->isChecked())
		{
			choisisViande[i] = true;
			prixtotal = prixViande[i] + prixtotal;
		}
		else
		{
			choisisViande[i] = false;

			//qApp->quit();
		}

		//qInfo() << choisisViande[i];
	}
	for (int i = 0; i < TAILLE_FROMAGE - 1; i++) {
		if (BOfromages[i]->isChecked())
		{
			choisisFromage[i] = true;
			prixtotal = prixFromage[i] + prixtotal;
		}
		else
		{
			choisisFromage[i] = false;

			//qApp->quit();
		}

		//qInfo() << choisisFromage[i];
	}
	qInfo() << prixtotal;

}