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