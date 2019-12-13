#ifndef HOMOTOPYWIDGET_H
#define HOMOTOPYWIDGET_H

#include <QWidget>

class HomotopyWidget : public QWidget
{
	Q_OBJECT
public:
	explicit HomotopyWidget(QWidget* parent = nullptr);

public slots:
	void setTime(qreal time);

protected:
	void paintEvent(QPaintEvent* paintEvent);

private:
	QPointF completePath(qreal time);

	QPointF topHalfOfCircle(qreal time);
	QPointF bottomHalfOfCircle(qreal time);
	QPointF sideLine(qreal time);

	qreal _time;
};

#endif // HOMOTOPYWIDGET_H
