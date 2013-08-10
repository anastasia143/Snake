#pragma once

#include <QMainWindow>
#include "gameWidget.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
	Q_OBJECT
	
public:
	explicit MainWindow(QWidget *parent = 0);
	~MainWindow();

signals:

public slots:
	void onApplesCountChanged(int apples);
	void gameOver();
	
private:
	Ui::MainWindow *ui;
	GameWidget *gameWidget;
	int maxApplesOnLevel;
	int level;
};
