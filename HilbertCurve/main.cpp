#include "HilbertCurveWindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	HilbertCurveWindow w;
	w.show();

	return a.exec();
}
