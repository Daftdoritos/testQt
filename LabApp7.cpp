#include <QtWidgets/QApplication>
#include <QtWidgets>
#include "Interface.h"
#include "programme.h"

using namespace std;



int main(int argc, char **argv)
{
	QApplication app(argc, argv);

	MainWindow* window = new MainWindow;
	window->show();

	
	
	return app.exec();
}