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
	int applesCount;

signals:
	void applesCountChanged(int);
	void gameOver();
	//void wallsIntersection();
	void levelPassed(int);

protected:
	void keyPressEvent(QKeyEvent *event);
	void virtual onAppleIntersection() = 0;
	void virtual snakeMovement() = 0;
	bool virtual throwApple() = 0;

	QGraphicsScene *scene;
	Snake *snake;

	QTimer gameTimer;
	QGraphicsEllipseItem *apple;
	QList<QGraphicsPolygonItem *> *walls;

	QGraphicsEllipseItem *createEllipse(int x, int y, int w, int h, QPen pen = QPen(Qt::black), QBrush brush = QBrush(Qt::blue));
	QGraphicsPolygonItem *createPolygon(QList<QPointF> points, QPen pen = QPen(Qt::black), QBrush brush = QBrush(Qt::blue));
	virtual void createFirstSnake() = 0;
};
