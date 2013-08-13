#include "gameWidget.h"

GameWidget::GameWidget(QWidget *parent)
{
}

QGraphicsEllipseItem *GameWidget::createEllipse(int x, int y, int w, int h, QPen pen, QBrush brush)
{
	QGraphicsEllipseItem *item = new QGraphicsEllipseItem(x, y, w, h);
	item->setBrush(brush);
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
