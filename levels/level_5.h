#pragma once

#include <QMainWindow>
#include "gameWidget.h"

class Level_5 : public GameWidget
{
	Q_OBJECT

public:
	explicit Level_5(QWidget *parent = 0);
	~Level_5();
	void stopGame();
	void continueGame();

public slots:
	void snakeMovement();
	bool throwApple();

protected:
	void keyPressEvent(QKeyEvent *event);
	void onAppleIntersection();
	void createFirstSnake();
	void drawWalls();

private:
};
