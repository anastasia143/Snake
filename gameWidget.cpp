#include "gameWidget.h"

GameWidget::GameWidget(QWidget *parent)
{
	scene = new QGraphicsScene(this);
	setScene(scene);
	scene->setSceneRect(0, 0, 750, 365);

	createFirstSnake();

	connect(&gameTimer, SIGNAL(timeout()), this, SLOT(snakeMovement()));
	gameTimer.start(300);

	QPen pen(Qt::NoPen);
	QBrush brush(Qt::green);
	apple = createEllipse(10, 10, 14, 14, pen, brush);
	applesCount = 0;
	throwApple();
	scene->addItem(apple);
}

QGraphicsEllipseItem *GameWidget::createEllipse(int x, int y, int w, int h, QPen pen, QBrush brush)
{
	QGraphicsEllipseItem *item = new QGraphicsEllipseItem(x, y, w, h);
	item->setBrush(brush);
	return item;
}

void GameWidget::createFirstSnake()
{
	snake = new Snake;
	QPen pen(Qt::NoPen);
	QBrush brush(Qt::black);
	QGraphicsEllipseItem* item1 = createEllipse(100, 170, 14, 14, pen, brush);
	QGraphicsEllipseItem* item2 = createEllipse(86, 170, 14, 14, pen, brush);
	QGraphicsEllipseItem* item3 = createEllipse(72, 170, 14, 14, pen, brush);
	QGraphicsEllipseItem* item4 = createEllipse(58, 170, 14, 14, pen, brush);
	snake->balls->append(QList<QGraphicsEllipseItem*>() << item1 << item2 << item3 << item4);
	snake->length = 4;
	scene->addItem(item1);
	scene->addItem(item2);
	scene->addItem(item3);
	scene->addItem(item4);
}

void GameWidget::snakeMovement()
{

	int count = snake->length;
	while(count > 1)
	{
		snake->balls->at(count - 1)->setRect(snake->balls->at(count - 2)->rect());
		count--;
	}

	switch(snake->direction)
	{
	case 1:
	{
		int step = 14;
		if ((snake->balls->at(0)->rect().y() - step) < 0)
			step = -365;
		snake->balls->at(0)->setRect(snake->balls->at(0)->rect().x(), (snake->balls->at(0)->rect().y() - step), 14, 14);
		break;
	}
	case 2:
	{
		int step = 14;
		if ((snake->balls->at(0)->rect().x() + step) > 750)
			step = -750;
		snake->balls->at(0)->setRect((snake->balls->at(0)->rect().x() + step), snake->balls->at(0)->rect().y(), 14, 14);
		break;
	}
	case 3:
	{
		int step = 14;
		if ((snake->balls->at(0)->rect().y() - step) > 365)
			step = -365;
		snake->balls->at(0)->setRect(snake->balls->at(0)->rect().x(), (snake->balls->at(0)->rect().y() + step), 14, 14);
		break;
	}
	case 4:
	{
		int step = 14;
		if ((snake->balls->at(0)->rect().x() - step) < 0)
			step = -750;
		snake->balls->at(0)->setRect(snake->balls->at(0)->rect().x() - step, snake->balls->at(0)->rect().y(), 14, 14);
		break;
	}
	}

	count = snake->length;
	while(count > 1)
	{
		count--;
		if (apple->collidesWithItem(snake->balls->at(0)))
			onAppleIntersection();
		if (snake->balls->at(count)->rect() == snake->balls->at(0)->rect())
			emit snakeSelfIntersection();
	}

}

void GameWidget::throwApple()
{
	int x = rand() % 698 + 1;
	int y = rand() % 363 + 1;

	apple->setRect(x, y, 14, 14);
	int count = snake->length;
	while(count > 0)
	{
		count--;
		if(snake->balls->at(0)->collidesWithItem(apple))
			throwApple();
	}
}

void GameWidget::onAppleIntersection()
{
	throwApple();

	emit applesCountChanged(++applesCount);

	QPen pen(Qt::NoPen);
	QBrush brush(Qt::black);
	QGraphicsEllipseItem *item = createEllipse(snake->balls->at(snake->length - 1)->rect().x()
											, snake->balls->at(snake->length - 1)->rect().y(), 14, 14, pen, brush);
	snake->balls->append(item);
	snake->length++;
	scene->addItem(item);
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

void GameWidget::stopGame()
{
	gameTimer.stop();
}

GameWidget::~GameWidget()
{

}
