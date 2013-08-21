#include "level_5.h"
#include "ui_game.h"

Level_5::Level_5(QWidget *parent)
{
	level = 3;
	maxApplesOnLevel = 5;
	levelSpeed = 250;
	walls = new QList<QGraphicsPolygonItem *>;

	scene = new QGraphicsScene(this);
	setScene(scene);
	scene->setSceneRect(0, 0, 750, 365);

	createFirstSnake();

	connect(&gameTimer, SIGNAL(timeout()), this, SLOT(snakeMovement()));
	gameTimer.start(levelSpeed);

	apple = createEllipse(10, 10, 14, 14, QPen(Qt::black), QBrush(Qt::green));
	applesCount = 0;
	drawWalls();

	bool result = throwApple();
	while(result)
		result = throwApple();
	scene->addItem(apple);
}

Level_5::~Level_5()
{
	delete apple;
	delete walls;
	delete scene;
	delete snake;
}

void Level_5::drawWalls()
{
	QColor color;
	color.setRgb(244, 164, 96);

	QList<QPointF> points;
	QGraphicsPolygonItem *polygon1 = createPolygon(points << QPointF(0, 125) << QPointF(14, 125)  <<  QPointF(14, 149) << QPointF(390, 149)
												   << QPointF(390, 90) << QPointF(404, 90) << QPointF(404, 149) << QPointF(436, 149)
												   << QPointF(436, 163) << QPointF(0, 163)
												   , QPen(Qt::black), QBrush(color));
	points.clear();
	QGraphicsPolygonItem *polygon2 = createPolygon(points << QPointF(0, 90) << QPointF(14, 90)  <<  QPointF(14, 14) << QPointF(390, 14)
												   << QPointF(390, 70) << QPointF(404, 70) << QPointF(404, 14) << QPointF(510, 14)
												   << QPointF(510, 0) << QPointF(0, 0)
												   , QPen(Qt::black), QBrush(color));
	points.clear();
	QGraphicsPolygonItem *polygon3 = createPolygon(points << QPointF(590, 0) << QPointF(750, 0)  <<  QPointF(750, 90) << QPointF(736, 90)
												   << QPointF(736, 14) << QPointF(590, 14)
												   , QPen(Qt::black), QBrush(color));
	points.clear();
	QGraphicsPolygonItem *polygon4 = createPolygon(points << QPointF(736, 125) << QPointF(750, 125)  <<  QPointF(750, 163) << QPointF(490, 163)
												   << QPointF(490, 149) << QPointF(736, 149)
												   , QPen(Qt::black), QBrush(color));
	points.clear();
	QGraphicsPolygonItem *polygon5 = createPolygon(points << QPointF(0, 320) << QPointF(0, 200)  <<  QPointF(700, 200) << QPointF(700, 214)
												   << QPointF(364, 214) << QPointF(364, 351) << QPointF(520, 351) << QPointF(520, 365)
												   << QPointF(0, 365) << QPointF(0, 351) << QPointF(350, 351) << QPointF(350, 214)
												   << QPointF(14, 214) << QPointF(14, 320)
												   , QPen(Qt::black), QBrush(color));
	points.clear();
	QGraphicsPolygonItem *polygon6 = createPolygon(points << QPointF(736, 320)  <<  QPointF(736, 214) << QPointF(730, 215)
												   << QPointF(730, 200) << QPointF(750, 200) << QPointF(750, 320)
												   , QPen(Qt::black), QBrush(color));
	points.clear();
	QGraphicsPolygonItem *polygon7 = createPolygon(points << QPointF(570, 351) << QPointF(750, 351) << QPointF(750, 365) << QPointF(570, 365)
												   , QPen(Qt::black), QBrush(color));
	scene->addItem(polygon1);
	scene->addItem(polygon2);
	scene->addItem(polygon3);
	scene->addItem(polygon4);
	scene->addItem(polygon5);
	scene->addItem(polygon6);
	scene->addItem(polygon7);
	walls->append(QList<QGraphicsPolygonItem*>() << polygon1 << polygon2 << polygon3 << polygon4 << polygon5 << polygon6 << polygon7);
}

void Level_5::createFirstSnake()
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

void Level_5::snakeMovement()
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


bool Level_5::throwApple()
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

void Level_5::onAppleIntersection()
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

void Level_5::keyPressEvent(QKeyEvent *event)
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

void Level_5::stopGame()
{
	gameTimer.stop();
}

void Level_5::continueGame()
{
	gameTimer.start();
}



