#pragma once

#include <QMainWindow>
#include "gameWidget.h"

class Level_4 : public GameWidget
{
	Q_OBJECT

public:
	explicit Level_4(QWidget *parent = 0);
	~Level_4();
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
	QColor *colorArray;
	void fillColorArray();
};
