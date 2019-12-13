#include "CechComplex.h"

#include <math.h>

CechComplex::CechComplex()
{
	_epsilon = 0.01;
}

const QVector<QPoint>& CechComplex::points() const
{
	return _points;
}

qreal CechComplex::epsilon() const
{
	return _epsilon;
}

void CechComplex::setPoints
(
	const QVector<QPoint>& points
)
{
	_points = points;
	generateMembers();
}

void CechComplex::setEpsilon
(
	qreal epsilon
)
{
	if (epsilon > 0)
	{
		_epsilon = epsilon;
		generateMembers();
	}
}

void CechComplex::generateMembers()
{
	_members.clear();
	for (const QPoint& firstPoint : _points)
	{
		QVector<QPoint> sigma;
		for (QPoint& otherPoint : _points)
		{
			auto directionVector = firstPoint - otherPoint;
			auto distance = sqrt(QPoint::dotProduct(directionVector, directionVector));
			if (distance < 2 * _epsilon)
			{
				sigma.append(otherPoint);
			}
		}
		if (_members.contains(sigma) == false)
		{
			_members.append(sigma);
		}
	}
}

const QVector<QVector<QPoint>>& CechComplex::members()
{
	return _members;
}

