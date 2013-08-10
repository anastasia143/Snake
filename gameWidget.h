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
	void stopGame();

signals:
	void applesCountChanged(int);
	void snakeSelfIntersection();
	void wallsIntersection();

public slots:
	void snakeMovement();
	void throwApple();

protected:
	void keyPressEvent(QKeyEvent *event);
	void onAppleIntersection();

private:
	QGraphicsScene *scene;
	Snake *snake;
	int applesCount;
	QTimer gameTimer;
	QGraphicsEllipseItem *apple;

	QGraphicsEllipseItem *createEllipse(int x, int y, int w, int h, QPen pen, QBrush brush);
	void createFirstSnake();
};
