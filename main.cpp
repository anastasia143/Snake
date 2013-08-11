#include "mainWindow.h"
#include "headband.h"
#include <QApplication>

int main(int argc, char *argv[])
{

	QApplication a(argc, argv);

	Headband headband;
	headband.show();

	/*MainWindow w;
	w.show();*/
	
	return a.exec();
}
