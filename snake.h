#pragma once
#include <QGraphicsItem>
#include <QGraphicsEllipseItem>

class Snake
{
public:
	Snake()
	{
		balls = new QList<QGraphicsEllipseItem*>;
		direction = 2;
		length = 0;
	}

	QList<QGraphicsEllipseItem*> *balls;
	int direction;
	int length;
	bool isDirectionChanged;
};
