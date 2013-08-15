#include "gameWidget.h"

GameWidget::GameWidget(QWidget *parent)
{
}

QGraphicsEllipseItem *GameWidget::createEllipse(int x, int y, int w, int h, QPen pen, QBrush brush)
{
	QGraphicsEllipseItem *item = new QGraphicsEllipseItem(x, y, w, h);
	item->setBrush(brush);
	item->setPen(pen);
	return item;
}

QGraphicsPolygonItem *GameWidget::createPolygon(QList<QPointF> points, QPen pen, QBrush brush)
{
	QPolygonF polygon;
	int count = 0;
	int length = points.length();
	while(count < length)
	{
		polygon << points[count];
		count++;
	}
	QGraphicsPolygonItem *item = new QGraphicsPolygonItem(polygon);
	item->setBrush(brush);
	item->setPen(pen);
	return item;
}


void GameWidget::keyPressEvent(QKeyEvent *event)
{
	switch(event->key())
	{
	case Qt::Key_Up:
	{
		if (snake->direction != 3)
			snake->direction = 1;
		break;
	}
	case Qt::Key_Down:
	{
		if (snake->direction != 1)
			snake->direction = 3;
		break;
	}
	case Qt::Key_Left:
	{
		if (snake->direction != 2)
			snake->direction = 4;
		break;
	}
	case Qt::Key_Right:
	{
		if (snake->direction != 4)
			snake->direction = 2;
		break;
	}
	default:
		QGraphicsView::keyPressEvent(event);
	}
	snake->isDirectionChanged = true;
}


GameWidget::~GameWidget()
{
}
