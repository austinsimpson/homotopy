#ifndef HOMOTOPYWINDOW_H
#define HOMOTOPYWINDOW_H

#include "ui_HomotopyWindow.h"

class HomotopyWindow : public QMainWindow, private Ui::HomotopyWindow
{
	Q_OBJECT

public:
	HomotopyWindow(QWidget* parent = nullptr);
};

#endif // HOMOTOPYWINDOW_H
