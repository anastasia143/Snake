#pragma once

#include <QMainWindow>
#include <QTime>
#include <QTimeEdit>
#include "levels/level_1.h"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
	Q_OBJECT
	
public:
	explicit MainWindow(QWidget *parent = 0);
	~MainWindow();

public slots:
	void onApplesCountChanged(int apples);
	void gameOver();
	void updateTime();
	void pauseGame();
	void continueGame();
	
protected:
	Ui::MainWindow *ui;
	GameWidget *gameWidget;

	int levelTimeSeconds;
	int levelTimeMinutes;
	QTimer updateTimer;
};
