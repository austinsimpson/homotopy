#ifndef HILBERTCURVE_H
#define HILBERTCURVE_H

#include <QVector>
#include <QPointF>

class HilbertCurve
{
public:
	enum FlipAxis
	{
		AboutTopLeftBottomRight,
		AboutTopRightBottomLeft
	};

	HilbertCurve(int numberOfGenerations = 0);
	HilbertCurve(const HilbertCurve& other);
	~HilbertCurve();

	void generate(int numberOfIterations);
	const QVector<QPointF>& vertices() const;

	HilbertCurve duplicate(double scale = 0, QPointF offset = QPointF(0.0, 0.0)) const;
	void flip(FlipAxis axis);

	int degree() const;

private:
	QVector<QPointF> _vertices;
	QPointF _center;
	int _previousNumberOfGenerations;
};

#endif // HILBERTCURVE_H
