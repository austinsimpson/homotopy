#ifndef HILBERTCURVEWINDOW_H
#define HILBERTCURVEWINDOW_H

#include "ui_HilbertCurveWindow.h"

class HilbertCurveWindow : public QMainWindow,
						   private Ui::HilbertCurveWindow
{
	Q_OBJECT

public:
	explicit HilbertCurveWindow(QWidget* parent = nullptr);
};

#endif // HILBERTCURVEWINDOW_H
