#include "Interface.h"
#include <iostream>
#include "CommunicationFPGA.h"
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
string interface7::chercherGrandeurPizza() {
	return grandeurPizza;
}
void interface7::setgrandeurPizza(string grandeur) {
	grandeurPizza = grandeur;
}
string interface7::chercherGrandeur(int index) {
	return grandeur[index];
}
string interface7::chercherCondiment(int index) {
	return condiments[index];
}
string interface7::chercherViande(int index) {
	return viandes[index];
}
string interface7::chercherFromage(int index) {

	return fromages[index];
}

interface7::interface7() {
	initFPGA();
	positionecran = 0;
	positioncurseur = 0;
	selectionecran();
}   //test

interface7::~interface7()
{

};

void interface7::selectionecran()
{
	switch (positionecran) {
	case 0:
		ecrandacceuil();
		break;
	case 1:
		ecrantaille();
		break;
	}
};

int interface7::detection_phoneme() {

	int can0, can1, can2, can3, Ncan0, Ncan1, Ncan2, Ncan3;
	Ncan0 = 0;
	Ncan1 = 0;
	Ncan2 = 0;
	Ncan3 = 0;
	for (int i = 0; i < 10; i++) {

		fpga.sleep(5);
		fpga.lireRegistre(3, can0);
		fpga.sleep(5);
		fpga.lireRegistre(4, can1);
		fpga.sleep(5);
		fpga.lireRegistre(5, can2);
		fpga.sleep(5);
		fpga.lireRegistre(6, can3);
		fpga.sleep(5);
		if (can0 > 150)
			Ncan0 += 1;
		if (can1 > 150)
			Ncan1 += 1;
		if (can2 > 150)
			Ncan2 += 1;
		if (can3 > 150)
			Ncan3 += 1;
	}





	if (Ncan0 >= aa[0] && Ncan1 >= aa[1] && Ncan2 >= aa[2] && Ncan3 >= aa[3]) {
		fpga.ecrireRegistre(8, 0x10);
		return 1;//a
	}
	if (Ncan0 >= ee[0] && Ncan1 >= ee[1] && Ncan2 >= ee[2] && Ncan3 >= ee[3]) {
		fpga.ecrireRegistre(8, 0x01);
		return 2;//e

	}
	if (Ncan0 >= ii[0] && Ncan1 >= ii[1] && Ncan2 >= ii[2] && Ncan3 >= ii[3]) {
		fpga.ecrireRegistre(7, 0x10);
		return 4;//i
	}
	if (Ncan0 >= er[0] && Ncan1 >= er[1] && Ncan2 >= er[2] && Ncan3 >= er[3]) {
		fpga.ecrireRegistre(7, 0x01);
		return 8;//er (ferme)
	}
	return 0;

	//cout << "reg 1: "<< can0 << " reg 2: "<< can1 << " reg 3: " << can2 << " reg 4: " << can3 << endl;

};

int interface7::interaction() {
	int sortie, reponse, val = 0;
	while (1) {
		fpga.lireRegistre(BTNR, val);
		//fpga.sleep(100);
		if (_kbhit() != 0)
		{
			sortie = _getch();
			return sortie;
		}
		else if (val != 0)
		{
			reponse = detection_phoneme();
			switch (reponse) {
			case 1:
				return 'n';
				break;
			case 2:
				return 's';
				break;
			case 4:
				return 'w';
				break;
			case 8:
				return 'x';
				break;
			default:
				break;
			}
		}
		val = 0;
	}
};

void interface7::ecrandacceuil() {

	int entree;
	//system("cls");
	printf("\n");
	printf("------------------------------------------------------\n");
	printf("Bienvenue chez Uberto pizza (Appuyer sur 'n' pour continuer) \n");
	printf("------------------------------------------------------\n");
	printf("\n");
	printf("appuyer sur 'n' pour demarrer votre commande\n");
	printf("appuyer sur 'x' pour quitter le programme\n");

	entree = interaction();
	switch (entree) {
	case 'n':

		system("cls");
		positioncurseur = 0;
		positionecran = 1;
		selectionecran();
		break;

	case 'x':

		cout << "je quitte";
		exit(EXIT_SUCCESS);
		break;
	default:
		system("cls");
	}
	ecrandacceuil();
}

void interface7::ecranconfirmationcommande() {
	int n;
	int entree;
	//string Condiments = "";

	system("cls");
	cout << "Vous avez commander une pizza de taille " << chercherGrandeurPizza() << " avec les condiments suivant:" << endl;
	prix1 = prix_base;
	for (n = 0; n < TAILLE_CONDIMENTS; n++) {
		if (choisis[n]) {
			cout << chercherCondiment(n) << endl;
			prix1 += prix[n];
		}
		if (choisisViande[n]) {
			cout << chercherViande(n) << endl;
			prix1 += prixViande[n];
		}
	}
	for (n = 0; n < TAILLE_FROMAGE; n++) {

		if (choisisFromage[n]) {
			cout << chercherFromage(n) << endl;
			prix1 += prixFromage[n];
		}
	}

	cout << endl;
	cout << endl;
	cout << endl;
	cout << "Votre total est : $" << prix1 << endl;

	cout << "w : nouvelle commande x : quitter" << endl;
	entree = interaction();
	switch (entree) {
	case 'w':
		for (int i = 0; i < TAILLE_CONDIMENTS; i++) {
			choisisViande[i] = false;
			choisis[i] = false;
		}
		for (int i = 0; i < TAILLE_FROMAGE; i++) {
			choisisFromage[i] = false;

		}
		system("cls");
		positioncurseur = 0;
		ecrandacceuil();

	case 'x':
		exit(EXIT_SUCCESS);
		break;
	}
	ecranconfirmationcommande();

}
void interface7::ecrancondiment() {
	int n;
	int entree;
	//string Condiments ="";
	system("cls");
	cout << "choisisez vos condiments:" << endl;
	for (n = 0; n < TAILLE_CONDIMENTS; n++) {
		if (n == positioncurseur) {
			cout << "=>   ";
		}
		else {
			cout << "     ";
		};

		cout << n << " : " << chercherCondiment(n);
		if (choisis[n] == true) {
			cout << " [ x ]";
		}
		cout << endl;
	}

	cout << endl;
	cout << endl;
	cout << endl;
	cout << "w : haut, s : bas, n : selectionner, x : quitter" << endl;
	entree = interaction();
	switch (entree) {
	case 's':
		if (positioncurseur < TAILLE_CONDIMENTS - 1)
			positioncurseur++;
		break;
	case 'w':
		if (positioncurseur > 0)
			positioncurseur--;
		break;
	case 'n':
		if (positioncurseur == TAILLE_CONDIMENTS - 1) {
			positioncurseur = 0;
			ecranviande();
		}
		else {
			if (!choisis[positioncurseur]) {
				choisis[positioncurseur] = true;
			}
			else
				if (choisis[positioncurseur]) {
					choisis[positioncurseur] = false;
				}

		}
		break;
	case 'x':
		exit(EXIT_SUCCESS);
		break;
	}
	ecrancondiment();
}

void interface7::ecranviande() {
	int n;
	int entree;
	//string Condiments ="";
	system("cls");
	cout << "choisisez vos viandes:" << endl;
	for (n = 0; n < TAILLE_VIANDES; n++) {
		if (n == positioncurseur) {
			cout << "=>   ";
		}
		else {
			cout << "     ";
		};

		cout << n << " : " << chercherViande(n);
		if (choisisViande[n] == true) {
			cout << " [ x ]";
		}
		cout << endl;
	}

	cout << endl;
	cout << endl;
	cout << endl;
	cout << "w : haut, s : bas, n : selectionner, x : quitter" << endl;
	entree = interaction();
	switch (entree) {
	case 's':
		if (positioncurseur < TAILLE_CONDIMENTS - 1)
			positioncurseur++;
		break;
	case 'w':
		if (positioncurseur > 0)
			positioncurseur--;
		break;
	case 'n':
		if (positioncurseur == TAILLE_CONDIMENTS - 1) {
			positioncurseur = 0;
			ecranfromage();
		}
		else {
			if (!choisisViande[positioncurseur]) {
				choisisViande[positioncurseur] = true;
			}
			else
				if (choisisViande[positioncurseur]) {
					choisisViande[positioncurseur] = false;
				}

		}
		break;
	case 'x':
		exit(EXIT_SUCCESS);
		break;
	}
	ecranviande();
}

void interface7::ecranfromage() {
	int n;
	int entree;

	system("cls");
	cout << "choisisez votre fromage:" << endl;
	for (n = 0; n < TAILLE_FROMAGE; n++) {
		if (n == positioncurseur) {
			cout << "=>   ";
		}
		else {
			cout << "     ";
		};

		cout << n << " : " << chercherFromage(n);
		if (choisisFromage[n] == true) {
			cout << " [ x ]";
		}
		cout << endl;
	}

	cout << endl;
	cout << endl;
	cout << endl;
	cout << "w : haut, s : bas, n : selectionner, x : quitter" << endl;
	entree = interaction();
	switch (entree) {
	case 's':
		if (positioncurseur < TAILLE_FROMAGE - 1)
			positioncurseur++;
		break;
	case 'w':
		if (positioncurseur > 0)
			positioncurseur--;
		break;
	case 'n':
		if (positioncurseur == TAILLE_FROMAGE - 1) {
			positioncurseur = 0;
			ecranconfirmationcommande();
		}
		else {
			if (!choisisFromage[positioncurseur]) {
				choisisFromage[positioncurseur] = true;
			}
			else
				if (choisisFromage[positioncurseur]) {
					choisisFromage[positioncurseur] = false;
				}

		}
		break;
	case 'x':
		exit(EXIT_SUCCESS);
		break;
	}
	ecranfromage();
}








void interface7::ecrantaille() {
	int n;
	int entree;
	system("cls");
	cout << "choisisez votre taille:" << endl;
	for (n = 0; n < TAILLE_SIZE; n++) {
		if (n == positioncurseur) {
			cout << "=>   ";
		}
		else {
			cout << "     ";
		};

		cout << n << " : " << chercherGrandeur(n) << endl;
	}

	cout << endl;
	cout << endl;
	cout << endl;
	cout << "w : haut, s : bas, n : selectionner, x : quitter" << endl;
	entree = interaction();
	switch (entree) {
	case 's':
		if (positioncurseur < TAILLE_SIZE - 1)
			positioncurseur++;
		break;
	case 'w':
		if (positioncurseur > 0)
			positioncurseur--;
		break;
	case 'n':
		setgrandeurPizza(chercherGrandeur(positioncurseur));
		prix_base = prix_Grandeur[positioncurseur];
		positioncurseur = 0;
		ecrancondiment();
		break;
	case 'x':
		exit(EXIT_SUCCESS);
		break;
	}
	interface7::ecrantaille();
}

bool interface7::initFPGA()
{
	int val;
	bool lOk = true;

	if (!fpga.estOk())
	{
		cout << fpga.messageErreur() << endl;
		lOk = false;
	}

	if (!fpga.lireRegistre(SWR, val))
	{
		cout << fpga.messageErreur() << endl;
		lOk = false;
	}

	cout << "SW: " << hex << val << endl;

	if (!fpga.lireRegistre(BTNR, val))
	{
		cout << fpga.messageErreur() << endl;
		lOk = false;
	}

	cout << "BTN: " << hex << val << endl;

	val = 0xac;
	if (!fpga.ecrireRegistre(LD, val))
	{
		cout << fpga.messageErreur() << endl;
		lOk = false;
	}

	val = 0xa;
	if (!fpga.ecrireRegistre(AN3, val))
	{
		cout << fpga.messageErreur() << endl;
		lOk = false;
	}

	val++;
	if (!fpga.ecrireRegistre(AN2, val))
	{
		cout << fpga.messageErreur() << endl;
		lOk = false;
	}

	val++;
	if (!fpga.ecrireRegistre(AN1, val))
	{
		cout << fpga.messageErreur() << endl;
		lOk = false;
	}

	val++;

	if (!fpga.ecrireRegistre(AN0, val))
	{
		cout << fpga.messageErreur() << endl;
		lOk = false;
	}

	return lOk;

};


int interface7::lireRegistre(int registre)
{

	int lVal;
	fpga.lireRegistre(registre, lVal);
	//lVal = 127;
	return lVal;
}



//void Interface1