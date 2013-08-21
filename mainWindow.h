#pragma once

#include <QMainWindow>
#include <QTime>
#include <QTimeEdit>
#include "levels/level_1.h"
#include "levels/level_2.h"
#include "levels/level_3.h"
#include "levels/level_4.h"
#include "levels/level_5.h"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
	Q_OBJECT
	
public:
	explicit MainWindow(QWidget *newParent = 0);
	~MainWindow();

public slots:
	void onApplesCountChanged(int apples);
	void onGameOver();
	void updateTime();
	void pauseGame();
	void continueGame();
	void onLevelPassed(int);
	
protected:
	Ui::MainWindow *ui;
	GameWidget *gameWidget;
	QWidget *parent;

	int levelTimeSeconds;
	int levelTimeMinutes;
	QTimer updateTimer;
};
