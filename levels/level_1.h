#pragma once

#include <QMainWindow>
#include "gameWidget.h"
#include "level_1.h"

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
	void throwApple();

protected:
	void keyPressEvent(QKeyEvent *event);
	void onAppleIntersection();

	QGraphicsScene *scene;
	Snake *snake;
	int applesCount;
	QTimer gameTimer;
	QGraphicsEllipseItem *apple;

	void createFirstSnake();
};
