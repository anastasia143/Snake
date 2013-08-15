#pragma once

#include <QMainWindow>
#include "gameWidget.h"

class Level_2 : public GameWidget
{
	Q_OBJECT

public:
	explicit Level_2(QWidget *parent = 0);
	~Level_2();
	void stopGame();
	void continueGame();

public slots:
	void snakeMovement();
	void throwApple();

protected:
	void keyPressEvent(QKeyEvent *event);
	void onAppleIntersection();

	//QGraphicsScene *scene;
	//Snake *snake;
	//int applesCount;
	//QTimer gameTimer;
	//QGraphicsEllipseItem *apple;

	void createFirstSnake();
	void drawWalls();
};
