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

	batir_path();

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
	m_bouton = new QPushButton("Start", this);
	m_bouton->setFont(QFont("Comic Sans MS", 14));
	quit = new QPushButton("Quit", this);
	quit->setFont(QFont("Comic Sans MS", 14));
	m_bouton->setCursor(Qt::PointingHandCursor);
	quit->setCursor(Qt::PointingHandCursor);
	m_bouton->show();
	quit->show();
	quit->move(0, 380);
	

	QObject::connect(quit, SIGNAL(clicked()), qApp, SLOT(quit()));
	QObject::connect(m_bouton, SIGNAL(clicked()), this, SLOT(transfer()));

}
void MainWindow::transfer() {
	delete m_bouton;
	
	Interface2();

}

void MainWindow::Interface2() {
	reset = new QPushButton("Reset", this);
	reset->setFont(QFont("Comic Sans MS", 14));
	reset->setCursor(Qt::PointingHandCursor);
	reset->move(810, 380);
	reset->show();

	confirmer = new QPushButton("Confirmer la commande", this);
	confirmer->setFont(QFont("Comic Sans MS", 14));
	confirmer->setCursor(Qt::PointingHandCursor);
	confirmer->move(500, 380);
	confirmer->show();

	Ecran2 = true;

	prixpizza = new QLabel("00.00$", this);
	prixpizza->setFont(QFont("Comic Sans MS", 14));
	prixpizza->move(805, 0);
	prixpizza->show();

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

	
	viande = new QGroupBox("Viandes", this);
	grandeur = new QGroupBox("Grandeur", this);
	fromage = new QGroupBox("Fromage", this);
	condiment = new QGroupBox("Condiments", this);

	for (int i = 0; i < TAILLE_SIZE; i++) {
		lay1->addWidget(BOtailles[i], i, 0);
	}
	for (int i = 0; i < TAILLE_VIANDES - 1; i++) {
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
	viande->move(220, 0);

	condiment->setLayout(lay3);
	condiment->move(100, 0);



	fromage->setLayout(lay4);
	fromage->move(325, 0);


	grandeur->show();
	viande->show();
	condiment->show();
	fromage->show();

	lay1->itemAtPosition(0, 0)->widget()->setFocus();


	//this->setStyleSheet("QRadioButton::focus{ background: black; color: white;}");
	this->setStyleSheet("QCheckBox::focus{ background: black; color: white;}"
		"QRadioButton::focus{ background: black; color: white;}");


	settruefalse();

	
	QObject::connect(confirmer, SIGNAL(clicked()), this, SLOT(transfer1()));
	QObject::connect(reset, SIGNAL(clicked()), this, SLOT(Reset()));
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
	int actionphoneme = 0;
	actionphoneme = pizza.detection_phoneme();
	if (actionphoneme == 0) {
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

			
		}

		
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
	for (int i = 0; i < TAILLE_CONDIMENTS - 1; i++) {
		if (BOviandes[i]->isChecked())
		{
			choisisViande[i] = true;
			prixtotal = prixViande[i] + prixtotal;
		}
		else
		{
			choisisViande[i] = false;

			
		}

	
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

			
		}

		
	}
	qInfo() << prixtotal;

	s = QString::number(prixtotal, 'f', 2);
	prixpizza->setText(s + "$");
	prixpizza->show();
	images_pizza();

}

void MainWindow::images_pizza() {
	int pixtaille = 0, nmax;
	int cf = 0, cv = 0, cc = 0;
	bool choix = true;
	nmax = 1 + TAILLE_CONDIMENTS - 1 + TAILLE_VIANDES - 1 + TAILLE_FROMAGE - 1;

	if (!firsttime) {
		for (int n = 0; n < nmax; n++) {
			delete plotImg[n];
		}
	} else {
		for (int n = 0; n < (nmax); n++) {
				image[n] = new QImage(path_image[n]);
		}
	}
	


	if (choisistaille[0]) {
		pixtaille = 200;
	}
	else if (choisistaille[1]) {
		pixtaille = 240;
	}
	else if (choisistaille[2]) {
		pixtaille = 260;
	}
	else if (choisistaille[3]) {
		pixtaille = 300;
	}

	

	for (int n = 0; n < (nmax); n++) {
		if (n == 0) {
			choix = true;
		}
		else if (n < 8) {
			choix = false;
			if (choisisFromage[cf] == true) {
				choix = true;
			}
			cf++;
		}
		else if (n < 17) {
			choix = false;
			if (choisisViande[cv] == true) {
				choix = true;
			}
			cv++;
		}
		else {
			choix = false;
			if (choisiscondiments[cc] == true) {
				choix = true;
			}
			cc++;
		}

		QImage image2;

		if (choix == true) {
			image2 = image[n]->scaled(pixtaille, pixtaille);
		}
		else {
			image2 = image[n]->scaled(0, 0);
		}


		plotImg[n] = new QLabel(this);

		plotImg[n]->setScaledContents(true);
		plotImg[n]->setPixmap(QPixmap::fromImage(image2));
		plotImg[n]->show();
		plotImg[n]->move(550, 50);
	}

	firsttime = false;
	//qInfo() << cf;
	//qInfo() << cv;
	//qInfo() << cc;

}

//void MainWindow::images_pizza() {
//	int pixtaille = 300, nmax;
//	//choisistaille[TAILLE_SIZE]
//	//for
//	nmax = TAILLE_SIZE + TAILLE_CONDIMENTS - 1 + TAILLE_FROMAGE - 1 + TAILLE_FROMAGE - 1;
//	for (int n = 0; n < 3; n++) {
//		if (n == 0) {
//			image[n] = new QImage(path_image[n]);
//		}
//		else if (n == 1) {
//			image[n] = new QImage(path_image[n]);
//		}
//		else {
//			image[n] = new QImage(path_image[n]);
//		}
//		//QImage image("./assets/pain.png");
//		QImage image2 = image[n]->scaled(pixtaille, pixtaille, Qt::KeepAspectRatio);
//		//QImage image2 = image.scaled(0, 0, Qt::KeepAspectRatio);
//		plotImg[n] = new QLabel(this);
//		//QLabel *plotImg = new QLabel(this);
//		plotImg[n]->setScaledContents(true);
//		plotImg[n]->setPixmap(QPixmap::fromImage(image2));
//		plotImg[n]->show();
//		plotImg[n]->move(550, 50);
//	}
//
//}

void MainWindow::Reset() {
	prixtotal = 0;

	if (!firsttime)
		for (int n = 0; n < 1 + TAILLE_CONDIMENTS - 1 + TAILLE_VIANDES - 1 + TAILLE_FROMAGE - 1; n++) {
			delete image[n];
			delete plotImg[n];
		}
	firsttime = true;

	for (int i = 0; i < TAILLE_SIZE; i++) {

		BOtailles[i]->setAutoExclusive(false);
		BOtailles[i]->setChecked(false);
		BOtailles[i]->setAutoExclusive(true);
		choisistaille[i] = false;

	}
	for (int i = 0; i < TAILLE_CONDIMENTS - 1; i++) {
		BOviandes[i]->setChecked(false);
		choisiscondiments[i] = false;
	}
	for (int i = 0; i < TAILLE_VIANDES - 1; i++) {
		BOcondiments[i]->setChecked(false);
		choisisViande[i] = false;
	}
	for (int i = 0; i < TAILLE_FROMAGE - 1; i++) {
		BOfromages[i]->setChecked(false);
		choisisFromage[i] = false;
	}

	prixpizza->setText(QString::number(prixtotal, 'f', 2) + "$");

}

void MainWindow::Interface3() {
	delete prixpizza;
	delete confirmer;
	delete reset;

	for (int i = 0; i < TAILLE_SIZE; i++) {
		delete BOtailles[i];
	}

	for (int i = 0; i < TAILLE_VIANDES - 1; i++) {
		delete BOviandes[i];
	}
	for (int i = 0; i < TAILLE_CONDIMENTS - 1; i++) {
		delete  BOcondiments[i];
	}
	for (int i = 0; i < TAILLE_FROMAGE - 1; i++) {
		delete BOfromages[i];
	}


	delete grandeur;
	delete condiment;
	delete viande;
	delete fromage;


	if (!firsttime)
		for (int n = 0; n < 1 + TAILLE_CONDIMENTS - 1 + TAILLE_VIANDES - 1 + TAILLE_FROMAGE - 1; n++) {
			delete image[n];
			delete plotImg[n];
		}
	firsttime = true;

	QPixmap bkgnd("./spacepizza.png");
	bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
	QPalette palette;
	palette.setBrush(QPalette::Background, bkgnd);
	this->setPalette(palette);

	NextOrder = new QPushButton("Nouvelle Commmande", this);
	NextOrder->setFont(QFont("Comic Sans MS", 14));
	NextOrder->setCursor(Qt::PointingHandCursor);
	NextOrder->move(500, 380);
	NextOrder->show();

	remerciement = new QLabel("Merci d'avoir fait affaire avec WestCoast Custom Pizza (ft. Xzibit)", this);
	remerciement->setFont(QFont("Comic Sans MS", 14));
	remerciement->move(150, 175);
	remerciement->show();

	QObject::connect(NextOrder, SIGNAL(clicked()), this, SLOT(transfer2()));
}

void MainWindow::transfer1() {

	if (!firsttime) {
		for (int n = 0; n < 1 + TAILLE_CONDIMENTS - 1 + TAILLE_VIANDES - 1 + TAILLE_FROMAGE - 1; n++) {
			plotImg[n]->hide();
		}
		for (int n = 0; n < 1 + TAILLE_CONDIMENTS - 1 + TAILLE_VIANDES - 1 + TAILLE_FROMAGE - 1; n++) {
			delete image[n];
			delete plotImg[n];
		}
		firsttime = true;
	}
	Interface3();

}
void MainWindow::transfer2() {


	delete quit;
	delete remerciement;
	delete NextOrder;

	

	Interface1();

}

void MainWindow::batir_path() {
	path_image.push_back("./assets/pain.png");
	qInfo() << "./assets/pain.png";

	for (int i = 0; i < TAILLE_FROMAGE - 1; i++) {
		path_image.push_back("./assets/fromage/" + QTfromages[i] + ".png");
		qInfo() << ("./assets/fromage/" + QTfromages[i] + ".png");
	}

	
	for (int i = 0; i < TAILLE_VIANDES - 1; i++) {
		path_image.push_back("./assets/viande/" + QTviandes[i] + ".png");
		qInfo() << ("./assets/viande/" + QTviandes[i] + ".png");
	}

	for (int i = 0; i < TAILLE_CONDIMENTS - 1; i++) {
		path_image.push_back("./assets/condiment/" + QTcondiments[i] + ".png");
		qInfo() << ("./assets/condiment/" + QTcondiments[i] + ".png");
	}
	for (int i = 0; i < (1 + TAILLE_CONDIMENTS - 1 + TAILLE_VIANDES - 1 + TAILLE_FROMAGE - 1); i++)
		qInfo() << path_image[i];
}