
#ifndef DEF_PROGRAMME
#define DEF_PROGRAMME

#include <string> 
#include <QApplication>
#include <QtWidgets>

#include "Interface.h"
#include "CommunicationFPGA.h"


using namespace std;

#define TAILLE_SIZE 4
#define TAILLE_CONDIMENTS 10
#define TAILLE_VIANDES 10
#define TAILLE_FROMAGE 8

class interface7 {
public:
	interface7();
	~interface7();

	bool initFPGA();
	void selectionecran();
	int interaction();
	void ecrandacceuil();
	void ecrantaille();
	int lireRegistre(int registre);
	void ecrancondiment();
	void ecranviande();
	void ecranfromage();
	void ecranconfirmationcommande();
	int detection_phoneme();
	string chercherGrandeur(int index);
	string chercherCondiment(int index);
	string chercherViande(int index);
	string chercherFromage(int index);
	void setgrandeurPizza(string grandeur);
	string chercherGrandeurPizza();
	//double calcul_prix();
	double prix1;
	double prix_base;

	const QString QTgrandeur[4] = { "petite","moyenne","grande","XL" };
	const QString QTcondiments[10] = { "Tomates","Onions","Piments","Epinards","Champignons" ,"Jalapenos","Ananas","Olives","Ail", "Confirmer la selection" };
	const QString QTviandes[10] = { "Steak","Pepperoni","Salami","Jambon","Prosciutto","Bacon","Saucisse","Poulet","Anchois","Confirmer la selections" };

private:
	//enum Registre { SW = 8, BTN = 9, LD = 10, AN0 = 11, AN1 = 12, AN2 = 13, AN3 = 14 };
	enum Registre { BTN = 9, LD = 10, SWR = 1, BTNR = 0, AN0 = 11, AN1 = 12, AN2 = 13, AN3 = 14 };
	string grandeur[4] = { "petite","moyenne","grande","XL" };
	string condiments[10] = { "Tomates","Onions","Piments","Epinards","Champignons" ,"Jalapenos","Ananas","Olives","Ail", "Confirmer la selection" };
	string viandes[10] = { "Steak","Pepperoni","Salami","Jambon","Prosciutto","Bacon","Saucisse","Poulet","Anchois","Confirmer la selections" };
	int aa[4] = { 6,0,0,0 };
	int ee[4] = { 0,6,0,0 };
	int ii[4] = { 0,0,6,0 };
	int er[4] = { 0,0,0,6 };

	bool choisis[TAILLE_CONDIMENTS] = { false,false, false, false, false, false, false, false, false, false };
	bool choisisViande[TAILLE_CONDIMENTS] = { false,false, false, false, false, false, false, false, false, false };
	bool choisisFromage[TAILLE_FROMAGE] = { false, false, false, false, false,false, false, false };
	double prixFromage[TAILLE_FROMAGE] = { 0.50, 0.50, 0.50, 0.50, 0.50, 0.50, 0.50, 0 };
	double prix[TAILLE_CONDIMENTS] = { 0.50 , 0.50, 0.50, 0.50, 0.50, 0.50, 0.50, 0.50, 0.50,0 };
	double prixViande[TAILLE_CONDIMENTS] = { 0.50 , 0.50, 0.50, 0.50, 0.50, 0.50, 0.50, 0.50, 0.50,0 };
	double prix_Grandeur[TAILLE_SIZE] = { 8.50,10.25,12.50,15.70 };
	string grandeurPizza;
	int positionecran;
	int positioncurseur;
	
	CommunicationFPGA fpga;
	string fromages[8] = { "Cheddar","Parmesan","Fetta","MontereJack","Provolone","Chevre","Bleu","confirmer la selection" };
};



#endif