#include "HilbertCurveWindow.h"

#include <QtGlobal>

HilbertCurveWindow::HilbertCurveWindow
(
	QWidget* parent
):
	QMainWindow(parent)
{
	setupUi(this);

	connect(_iterationsSpinBox, QOverload<int>::of(&QSpinBox::valueChanged), _hilbertCurveWidget, [this](int value)
	{
		_hilbertCurveWidget->setGenerationsCount(value);
		_verticesLabel->setText(QString("Vertices: %1").arg(QString::number(_hilbertCurveWidget->curve().vertices().count())));
	});
}
