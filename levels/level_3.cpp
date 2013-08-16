#include "level_3.h"
#include "ui_game.h"

Level_3::Level_3(QWidget *parent)
{
	level = 3;
	maxApplesOnLevel = 1;
	levelSpeed = 250;
	walls = new QList<QGraphicsPolygonItem *>;

	scene = new QGraphicsScene(this);
	setScene(scene);
	scene->setSceneRect(0, 0, 750, 365);

	createFirstSnake();

	connect(&gameTimer, SIGNAL(timeout()), this, SLOT(snakeMovement()));
	gameTimer.start(levelSpeed);
	connect(&timerForApples, SIGNAL(timeout()), this, SLOT(throwApple()));
	timerForApples.start(7000);

	apple = createEllipse(10, 10, 14, 14, QPen(Qt::black), QBrush(Qt::green));
	applesCount = 0;
	drawWalls();

	bool result = throwApple();
	while(result)
		result = throwApple();
	scene->addItem(apple);
}

Level_3::~Level_3()
{
	delete apple;
	delete walls;
	delete scene;
	delete snake;
}

void Level_3::drawWalls()
{
	QColor color;
	color.setRgb(244, 164, 96);

	QList<QPointF> points;
	QGraphicsPolygonItem *polygon1 = createPolygon(points << QPointF(200, 75) << QPointF(214, 75)  <<  QPointF(214, 315) << QPointF(200, 315)
												   , QPen(Qt::black), QBrush(color));
	points.clear();
	QGraphicsPolygonItem *polygon2 = createPolygon(points << QPointF(525, 75) << QPointF(539, 75)  <<  QPointF(539, 315) << QPointF(525, 315)
												   , QPen(Qt::black), QBrush(color));
	points.clear();
	QGraphicsPolygonItem *polygon3 = createPolygon(points << QPointF(265, 180) << QPointF(265, 166)  <<  QPointF(475, 166) << QPointF(475, 180)
												   , QPen(Qt::black), QBrush(color));
	scene->addItem(polygon1);
	scene->addItem(polygon2);
	scene->addItem(polygon3);
	walls->append(QList<QGraphicsPolygonItem*>() << polygon1 << polygon2 << polygon3);
}

void Level_3::createFirstSnake()
{
	snake = new Snake;
	QGraphicsEllipseItem* item1 = createEllipse(100, 170, 14, 14, QPen(Qt::black), QBrush(Qt::black));
	QGraphicsEllipseItem* item2 = createEllipse(86, 170, 14, 14, QPen(Qt::black), QBrush (Qt::darkGray));
	QGraphicsEllipseItem* item3 = createEllipse(72, 170, 14, 14, QPen(Qt::black), QBrush (Qt::darkGray));
	QGraphicsEllipseItem* item4 = createEllipse(58, 170, 14, 14, QPen(Qt::black), QBrush (Qt::darkGray));
	snake->balls->append(QList<QGraphicsEllipseItem*>() << item1 << item2 << item3 << item4);
	snake->length = 4;
	scene->addItem(item1);
	scene->addItem(item2);
	scene->addItem(item3);
	scene->addItem(item4);
}

void Level_3::snakeMovement()
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
			step = -377;
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
		{
			if (applesCount + 1 == maxApplesOnLevel)
			{
				emit levelPassed(3);
				return;
			}
			else
				onAppleIntersection();
		}
		if (snake->balls->at(count)->rect() == snake->balls->at(0)->rect())
			emit gameOver();
	}

	count = walls->length();
	while(count > 0)
	{
		count--;
		if (snake->balls->at(0)->collidesWithItem(walls->at(count)))
			emit gameOver();
			//emit wallsIntersection();
	}
}


bool Level_3::throwApple()
{
	int x = rand() % 696 + 1;
	int y = rand() % 363 + 1;

	apple->setRect(x, y, 14, 14);
	int count = snake->length;
	while(count > 0)
	{
		count--;
		if(snake->balls->at(count)->collidesWithItem(apple))
			return 1;
	}
	count = walls->length();
	while(count > 0)
	{
		count--;
		if(walls->at(count)->collidesWithItem(apple))
			return 1;
	}

	return 0;
}

void Level_3::onAppleIntersection()
{
	bool result = throwApple();
	while (result)
		result = throwApple();
	emit applesCountChanged(++applesCount);

	QGraphicsEllipseItem *item = createEllipse(snake->balls->at(snake->length - 1)->rect().x()
					, snake->balls->at(snake->length - 1)->rect().y(), 14, 14, QPen(Qt::black), QBrush(Qt::darkGray));
	snake->balls->append(item);
	snake->length++;
	scene->addItem(item);
}

void Level_3::keyPressEvent(QKeyEvent *event)
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

void Level_3::stopGame()
{
	gameTimer.stop();
}

void Level_3::continueGame()
{
	gameTimer.start();
}


