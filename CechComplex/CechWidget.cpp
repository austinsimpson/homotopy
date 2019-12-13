#include "CechWidget.h"

#include <QPainter>

#include <math.h>

const int maxWidth = 500;
const int maxHeight = 500;

CechWidget::CechWidget
(
	QWidget* parent
):
	QWidget(parent)
{
	_cechComplex.setEpsilon(90.0);
	generateRandomPoints();
}


void CechWidget::setEpsilon(qreal epsilon)
{
	_cechComplex.setEpsilon(epsilon);
	update();
}

void CechWidget::setPoints(QVector<QPoint> points)
{
	_cechComplex.setPoints(points);
	update();
}


void CechWidget::generateRandomPoints()
{
	QVector<QPoint> points;
	srand(time(0));
	for (int i = 0; i < 20; i++)
	{
		points.append(QPoint(rand() % maxWidth, rand() % maxHeight));
		//points.append(QPoint(250 + 250 * cos(2 * 3.1415 * i / 40), 250 + 250 * sin(2 * 3.1415 * i / 40)));
	}

	_cechComplex.setPoints(points);
	update();
}

void CechWidget::paintEvent(QPaintEvent* paintEvent)
{
	Q_UNUSED(paintEvent);

	QPainter painter;
	painter.begin(this);
	QTransform transform;
	qreal scaledWidth = (qreal)width() / maxWidth;
	qreal scaledHeight = (qreal)height() / maxHeight;
	qreal scale = scaledWidth < scaledHeight ? scaledWidth : scaledHeight;
	transform.scale(scale, scale);

	auto toFill = geometry().translated(-x(), -y());
	painter.fillRect(toFill, QColor("cornflower blue"));

	painter.setTransform(transform);
	QPen pen = painter.pen();
	pen.setWidth(5);
	painter.setPen(pen);

	for (auto point : _cechComplex.points())
	{
		painter.drawPoint(point);
	}

	for (auto member : _cechComplex.members())
	{
		QColor color(0, 0, 0, 10);
		QPolygon poly(member);
		QPainterPath path;
		path.addPolygon(poly);
		pen.setWidth(1);
		pen.setStyle(Qt::DashLine);
		pen.setColor(Qt::black);
		painter.strokePath(path, pen);
		painter.fillPath(path, QBrush(color));
	}

	painter.end();
}
