#pragma once

#include <QMainWindow>
#include "gameWidget.h"

class Level_1 : public GameWidget
{
	Q_OBJECT

public:
	explicit Level_1(QWidget *parent = 0);
	~Level_1();
	void stopGame();
	void continueGame();

public slots:
	void snakeMovement();
	bool throwApple();

protected:
	void keyPressEvent(QKeyEvent *event);
	void onAppleIntersection();
	void createFirstSnake();
};
