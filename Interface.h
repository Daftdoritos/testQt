
#ifndef DEF_INTERFACE
#define DEF_INTERFACE

#include <QApplication>
#include <QtWidgets>
#include <string>


#include "programme.h"
#include "CommunicationFPGA.h"

using namespace std;



class MainWindow : public QWidget
{
	Q_OBJECT
public:
	MainWindow();
	void Interface1();
	void Interface2();
	public slots:
	void transfer();
	void settruefalse();

private:

	const QString QTgrandeur[4] = { "Petite","Moyenne","Grande","XL" };
	const QString QTcondiments[9] = { "Tomates","Onions","Piments","Epinards","Champignons" ,"Jalapenos","Ananas","Olives","Ail" };
	const QString QTviandes[9] = { "Steak","Pepperoni","Salami","Jambon","Prosciutto","Bacon","Saucisse","Poulet","Anchois" };
	const QString QTfromages[7] = { "Cheddar","Parmesan","Fetta","MontereJack","Provolone","Chevre","Bleu"};
	interface7 pizza;

	QPushButton * m_bouton = new QPushButton("Start", this);
	QPushButton *quit = new QPushButton("Quit", this);

	
	QRadioButton *BOtailles[TAILLE_SIZE];
	
	QCheckBox *BOviandes[TAILLE_VIANDES-1];
	QCheckBox *BOcondiments[TAILLE_CONDIMENTS-1];
	QCheckBox *BOfromages[TAILLE_FROMAGE-1];


	//QRadioButton *petite;
	//QRadioButton *moyenne;
	//QRadioButton *large;
	//QRadioButton *extralarge;

	QCheckBox *tomate;
	QCheckBox *onion;
	QCheckBox *piment;
	QCheckBox *epinard;
	QCheckBox *champignon;
	QCheckBox *jalapenos;
	QCheckBox *ananas;
	QCheckBox *olive;
	QCheckBox *ail;

	//QCheckBox *steak;
	//QCheckBox *pepperoni;
	//QCheckBox *salami;
	//QCheckBox *jambon;
	//QCheckBox *prosciutto;
	//QCheckBox *bacon;
	//QCheckBox *saucisse;
	//QCheckBox *poulet;
	//QCheckBox *anchoix;

	QCheckBox *cheddar;
	QCheckBox *parmesan;
	QCheckBox *fetta;
	QCheckBox *monterejack;
	QCheckBox *provolone;
	QCheckBox *chevre;
	QCheckBox *bleu;


	QGridLayout *lay1;
	QGridLayout *lay2;
	QGridLayout *lay3;
	QGridLayout *lay4;
	QScrollArea *scroll;
	QGroupBox *viande;
	QGroupBox *condiment;
	QGroupBox *grandeur;
	QGroupBox *fromage;

public slots:
	void on_up();
	void on_down();
	void on_tab();
	//void on_left();
	//void on_right();
	void moveFocus(int dy);
	void State();
	
};

#endif