#ifndef CECHWINDOW_H
#define CECHWINDOW_H

#include "ui_CechWindow.h"

class CechWindow : public QMainWindow, private Ui::CechWindow
{
	Q_OBJECT

public:
	explicit CechWindow(QWidget *parent = nullptr);
};

#endif // CECHWINDOW_H
