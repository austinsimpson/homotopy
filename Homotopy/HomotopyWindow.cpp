#include "HomotopyWindow.h"

HomotopyWindow::HomotopyWindow
(
	QWidget* parent
):
	QMainWindow(parent)
{
	setupUi(this);

	connect(this->_timeSlider, &QSlider::valueChanged, [this](int value)
	{
		qreal percentage = (qreal) value / this->_timeSlider->maximum();
		_homotopyWidget->setTime(percentage);
	});
}
