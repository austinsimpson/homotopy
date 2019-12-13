#ifndef CECHWIDGET_H
#define CECHWIDGET_H

#include <QWidget>

#include "CechComplex.h"

class CechWidget : public QWidget
{
public:
	CechWidget(QWidget* parent);

	void paintEvent(QPaintEvent* paintEvent);

public slots:
	void setEpsilon(qreal epsilon);
	void setPoints(QVector<QPoint> points);

private:
	void generateRandomPoints();

	CechComplex _cechComplex;
};

#endif // CECHWIDGET_H
