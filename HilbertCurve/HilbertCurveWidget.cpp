#include "HilbertCurveWidget.h"

#include <QPainter>

HilbertCurveWidget::HilbertCurveWidget
(
	QWidget* parent
):
	QWidget(parent),
	_hilbertCurve(1)
{

}

void HilbertCurveWidget::setGenerationsCount(int generations)
{
	_hilbertCurve.generate(generations);
	update();
}

const HilbertCurve& HilbertCurveWidget::curve() const
{
	return _hilbertCurve;
}

void HilbertCurveWidget::paintEvent
(
	QPaintEvent* paintEvent
)
{
	Q_UNUSED(paintEvent);

	QPainter painter;
	painter.begin(this);
	painter.setWindow(QRect(-1, -1, 2, 2));


	painter.fillRect(painter.window(), QBrush("cornflower blue"));
	QPolygonF polygon(_hilbertCurve.vertices());
	QPainterPath path;

	QPen pen = painter.pen();
	pen.setWidthF(0);
	painter.setPen(pen);

	path.addPolygon(polygon);
	painter.drawPath(path);

	painter.end();
}
