#ifndef HILBERTCURVEWIDGET_H
#define HILBERTCURVEWIDGET_H

#include <QWidget>

#include "HilbertCurve.h"

class HilbertCurveWidget : public QWidget
{
	Q_OBJECT
public:
	HilbertCurveWidget(QWidget* parent = nullptr);

	void paintEvent(QPaintEvent* paintEvent);


	const HilbertCurve& curve() const;

public slots:
	void setGenerationsCount(int generations);

private:
	HilbertCurve _hilbertCurve;
};

#endif // HILBERTCURVEWIDGET_H
