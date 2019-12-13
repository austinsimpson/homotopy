#include "HomotopyWindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	HomotopyWindow w;
	w.show();

	return a.exec();
}
