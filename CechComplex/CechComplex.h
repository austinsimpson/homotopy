#ifndef CECHCOMPLEX_H
#define CECHCOMPLEX_H

#include <QVector>
#include <QPoint>

class CechComplex
{
public:
	CechComplex();

	const QVector<QVector<QPoint>>& members();
	const QVector<QVector<QPoint>>& components();
	const QVector<QPoint>& points() const;
	qreal epsilon() const;

	void setPoints(const QVector<QPoint>& points);
	void setEpsilon(qreal epsilon);
private:
	void generateMembers();
	void generateComponents();

	QVector<QVector<QPoint>> _members;
	QVector<QVector<QPoint>> _components;

	QVector<QPoint> _points;
	qreal _epsilon;
};

#endif // CECHCOMPLEX_H
