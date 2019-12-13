#include "CechWindow.h"

CechWindow::CechWindow
(
	QWidget* parent
):
	QMainWindow(parent)
{
	setupUi(this);

	connect(_epsilonSlider, &QSlider::valueChanged, [this] (int value)
	{
		qreal realValue = (qreal) value / this->_epsilonSlider->maximum();
		realValue *= this->_complexWidget->width();
		_complexWidget->setEpsilon(realValue);
	});
}
