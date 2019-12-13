#include "HilbertCurve.h"

HilbertCurve::HilbertCurve
(
	int numberOfGenerations
):
	_previousNumberOfGenerations(0xFFFFFF)
{
	if (numberOfGenerations > 0)
	{
		generate(numberOfGenerations);
	}
}

HilbertCurve::HilbertCurve
(
	const HilbertCurve& other
)
{
	_vertices = other._vertices;
	_previousNumberOfGenerations = other._previousNumberOfGenerations;
	_center = other._center;
}

HilbertCurve::~HilbertCurve()
{
	_vertices.clear();
	_vertices.shrink_to_fit();
}

const QVector<QPointF>& HilbertCurve::vertices() const
{
	return _vertices;
}

void HilbertCurve::generate
(
	int numberOfIterations
)
{
	if (numberOfIterations != _previousNumberOfGenerations)
	{
		if (numberOfIterations > 0 && numberOfIterations < _previousNumberOfGenerations)
		{
			_vertices.clear();
			_vertices.append(QPointF(-1.0 / 4, -1.0 / 4));
			_vertices.append(QPointF(-1.0 / 4, 1.0 / 4));
			_vertices.append(QPointF(1.0 / 4, 1.0 / 4));
			_vertices.append(QPointF(1.0 / 4, -1.0 / 4));
			_previousNumberOfGenerations = 1;
		}

		int index = _previousNumberOfGenerations;
		while (index < numberOfIterations)
		{
			HilbertCurve topLeft = duplicate(1.0/2, QPointF(-0.25, .25));
			HilbertCurve topRight = duplicate(1.0/2, QPointF(0.25, 0.25));
			HilbertCurve bottomLeft = duplicate(1.0/2, QPointF(-0.25, -0.25));
			HilbertCurve bottomRight = duplicate(1.0/2, QPointF(0.25, -0.25));
			bottomLeft.flip(FlipAxis::AboutTopRightBottomLeft);
			bottomRight.flip(FlipAxis::AboutTopLeftBottomRight);

			_vertices.clear();
			_vertices.append(bottomLeft.vertices());
			_vertices.append(topLeft.vertices());
			_vertices.append(topRight.vertices());
			_vertices.append(bottomRight.vertices());
			index++;
		}

		_previousNumberOfGenerations = numberOfIterations;
	}
}

HilbertCurve HilbertCurve::duplicate
(
	double scale,
	QPointF offset
)	const
{
	HilbertCurve result;
	result._vertices = QVector<QPointF>(_vertices);
	result._center = offset;
	for (QPointF& point : result._vertices)
	{
		point = scale * point + offset;
	}
	return result;
}

int HilbertCurve::degree() const
{
	return _previousNumberOfGenerations;
}

void HilbertCurve::flip
(
	FlipAxis axis
)
{
	for (QPointF& vertice : _vertices)
	{
		vertice = vertice - _center;
		if (axis == FlipAxis::AboutTopLeftBottomRight)
		{
			qreal x = vertice.x();
			vertice.ry() *= -1;
			vertice.rx() = vertice.y();
			vertice.ry() = x;
		}
		else
		{
			qreal x = vertice.x();
			vertice.rx() *= -1;
			vertice.rx() = vertice.y();
			vertice.ry() = x;
		}
		vertice = vertice + _center;
	}
	if (axis == FlipAxis::AboutTopLeftBottomRight)
	{
		std::reverse(_vertices.begin(), _vertices.end());
	}
}
