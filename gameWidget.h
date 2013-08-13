#pragma once
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QList>
#include <QtGui>
#include <QTimer>
#include <QKeyEvent>
#include "snake.h"

class GameWidget : public QGraphicsView
{
	Q_OBJECT
public:
	explicit GameWidget(QWidget *parent = 0);
	~GameWidget();
	void virtual stopGame() = 0;
	void virtual continueGame() = 0;
	int level;
	int maxApplesOnLevel;
	int levelSpeed;

signals:
	void applesCountChanged(int);
	void snakeSelfIntersection();
	void wallsIntersection();
	void levelIsPassed(int);

protected:
	void keyPressEvent(QKeyEvent *event);
	void virtual onAppleIntersection() = 0;
	void virtual snakeMovement() = 0;
	void virtual throwApple() = 0;

	QGraphicsScene *scene;
	Snake *snake;
	int applesCount;
	QTimer gameTimer;
	QGraphicsEllipseItem *apple;

	QGraphicsEllipseItem *createEllipse(int x, int y, int w, int h, QPen pen, QBrush brush);
	virtual void createFirstSnake() = 0;
};
