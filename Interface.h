
#ifndef DEF_INTERFACE
#define DEF_INTERFACE

#include <QApplication>
#include <QtWidgets>

#include <string>
#include <vector>
#include <thread>

#include "programme.h"
#include "CommunicationFPGA.h"

using namespace std;



class MainWindow : public QWidget
{
	Q_OBJECT
public:
	MainWindow();
	~MainWindow();
	void Interface1();
	void detectionphoneme();
	void Interface2();
	void batir_path();
	void images_pizza();




	public slots:
	void Interface3();
	void check();
	void transfer();
	void transfer1();
	void transfer2();
	void settruefalse();
	void on_up();
	void on_down();
	//void on_tab();
	void on_enter();
	void on_left();
	void on_right();
	void changeCheck();
	void moveFocus(int dy);
	void Reset();
	void phonemechange(int l);

signals:
	void sigFocus(int a);
	void sigCheck();
	void sigRight();
	void checkphoneme(int d);
	
private:
	std::thread * t1;
	QTextEdit * facture;
	QTextEdit* rules;



	QLabel* phoneme;
	QLabel*	fpgaok;

	float prixtotal;
	float TPS;
	float TVQ;
	bool firsttime = true;
	const int nmax = 1 + TAILLE_CONDIMENTS - 1 + TAILLE_VIANDES - 1 + TAILLE_FROMAGE - 1;

	const QString QTgrandeur[4] = { "Petite","Moyenne","Grande","XL" };
	const QString QTcondiments[9] = { "Tomates","Onions","Piments","Epinards","Champignons" ,"Jalapenos","Ananas","Olives","Ail" };
	const QString QTviandes[9] = { "Steak","Pepperoni","Salami","Jambon","Prosciutto","Bacon","Saucisse","Poulet","Anchois" };
	const QString QTfromages[7] = { "Cheddar","Parmesan","Fetta","MontereyJack","Provolone","Chevre","Bleu" };

	interface7 pizza;
	CommunicationFPGA fpga1;
	QLabel * prixpizza;
	QString s;
	QLabel *remerciement;

	QPushButton * m_bouton;
	QPushButton *quit;
	QPushButton*confirmer;
	QPushButton *reset;
	QPushButton *NextOrder;


	QRadioButton *BOtailles[TAILLE_SIZE];
	QCheckBox *BOviandes[TAILLE_VIANDES - 1];
	QCheckBox *BOcondiments[TAILLE_CONDIMENTS - 1];
	QCheckBox *BOfromages[TAILLE_FROMAGE - 1];

	std::vector<QString> path_image;

	QImage *image[1 + TAILLE_CONDIMENTS - 1 + TAILLE_VIANDES - 1 + TAILLE_FROMAGE - 1];
	QLabel *plotImg[1 + TAILLE_CONDIMENTS - 1 + TAILLE_VIANDES - 1 + TAILLE_FROMAGE - 1];

	QGridLayout *lay1;
	QGridLayout *lay2;
	QGridLayout *lay3;
	QGridLayout*lay4;

	QGroupBox *viande;
	QGroupBox *condiment;
	QGroupBox *grandeur;
	QGroupBox *fromage;

	bool choisistaille[TAILLE_SIZE] = { false, false, false, false };
	bool choisiscondiments[TAILLE_CONDIMENTS - 1] = { false,false, false, false, false, false, false, false, false };
	bool choisisViande[TAILLE_VIANDES - 1] = { false,false, false, false, false, false, false, false, false };
	bool choisisFromage[TAILLE_FROMAGE - 1] = { false, false, false, false, false,false, false };

	double prixFromage[TAILLE_FROMAGE - 1] = { 0.50, 0.50, 0.50, 0.50, 0.50, 0.50, 0.50 };
	double prixCondiment[TAILLE_CONDIMENTS - 1] = { 0.50 , 0.50, 0.50, 0.50, 0.50, 0.50, 0.50, 0.50, 0.50 };
	double prixViande[TAILLE_VIANDES - 1] = { 0.50 , 0.50, 0.50, 0.50, 0.50, 0.50, 0.50, 0.50, 0.50 };
	double prix_Grandeur[TAILLE_SIZE] = { 8.50,10.25,12.50,15.70 };
};

#endif