
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
private:
	QPushButton * m_bouton = new QPushButton("Start", this);
	QPushButton*quit = new QPushButton("Quit", this);

	QCheckBox *petite;
	QCheckBox *moyenne;
	QCheckBox *large;
	QCheckBox *extralarge;

	QCheckBox *tomate;
	QCheckBox *onion;
	QCheckBox *piment;
	QCheckBox *epinard;
	QCheckBox *champignon;
	QCheckBox *jalapenos;
	QCheckBox *ananas;
	QCheckBox *olive;
	QCheckBox *ail;

	QCheckBox *steak;
	QCheckBox *pepperoni;
	QCheckBox *salami;
	QCheckBox *jambon;
	QCheckBox *prosciutto;
	QCheckBox *bacon;
	QCheckBox *saucisse;
	QCheckBox *poulet;
	QCheckBox *anchoix;

	QCheckBox *cheddar;
	QCheckBox *parmesan;
	QCheckBox *fetta;
	QCheckBox *monterejack;
	QCheckBox *provolone;
	QCheckBox *chevre;
	QCheckBox *bleu;


	QGridLayout *lay1;
	QVBoxLayout *lay2;
	QVBoxLayout *lay3;
	QVBoxLayout *lay4;
	QScrollArea *scroll;
	QGroupBox *viande;
	QGroupBox *condiment;
	QGroupBox *grandeur;
	QGroupBox *fromage;

public slots:
	void on_up();
	void on_down();
	//void on_left();
	//void on_right();
	void moveFocus(int dy);
};

#endif