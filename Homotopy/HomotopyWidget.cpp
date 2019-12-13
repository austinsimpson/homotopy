#include "HomotopyWidget.h"

#include <QPainter>
#include <QDebug>

#include <math.h>

const qreal kRadius = 50.0;
const int kTimeSamples = 1000;

HomotopyWidget::HomotopyWidget(QWidget* parent) : QWidget(parent), _time(0.0)
{

}

void HomotopyWidget::paintEvent(QPaintEvent* paintEvent)
{
	Q_UNUSED(paintEvent);

	QPainter painter;
	painter.begin(this);
	painter.fillRect(QRectF(0,0, width(), height()), QBrush(QColor("cornflower blue")));
	painter.translate(QPointF(width() / 2, height() / 2));
	painter.scale(1, -1.0);

	QPen pen = painter.pen();
	pen.setColor(QColor(0,0,0));
	pen.setWidth(5);

	QPolygonF polygon;
	for (qreal time = 0; time < 1 + _time; time += 2.0/kTimeSamples)
	{
		polygon.append(completePath(time));
	}

	painter.drawPolygon(polygon);


	painter.end();
}

QPointF HomotopyWidget::completePath(qreal time)
{
	if (time < 1.0/2)
	{
		return topHalfOfCircle(time);
	}
	else if (time < 1)
	{
		return bottomHalfOfCircle(time);
	}
	else if (time <= 2)
	{
		return sideLine(time);
	}
	return QPointF(0, 0);
}

void HomotopyWidget::setTime(qreal time)
{
	if (time != _time)
	{
		_time = time;
		update();
	}
}


QPointF HomotopyWidget::topHalfOfCircle
(
	qreal time
)
{
	return QPointF(kRadius*(1 - 4 * time), sqrt((kRadius * kRadius) - pow(kRadius*(1 - 4*time), 2)));
}

QPointF HomotopyWidget::bottomHalfOfCircle
(
	qreal time
)
{
	return QPointF(kRadius * (4 * time - 3), -sqrt((kRadius * kRadius) - pow(kRadius * (4 * time - 3), 2)));
}

QPointF HomotopyWidget::sideLine
(
	qreal time
)
{
	return QPointF(kRadius*(time), 0);
}
