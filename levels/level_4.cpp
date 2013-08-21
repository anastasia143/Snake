#include "level_4.h"
#include "ui_game.h"

Level_4::Level_4(QWidget *parent)
{
	level = 4;
	maxApplesOnLevel = 1;
	levelSpeed = 300;
	walls = new QList<QGraphicsPolygonItem *>;
	colorArray = new QColor[21];
	fillColorArray();

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

Level_4::~Level_4()
{
	delete apple;
	delete walls;
	delete scene;
	delete snake;
}

void Level_4::drawWalls()
{
	QColor color;
	color.setRgb(244, 164, 96);

	QList<QPointF> points;
	QGraphicsPolygonItem *polygon1 = createPolygon(points << QPointF(250, 100) << QPointF(264, 100)  <<  QPointF(264, 114) << QPointF(250, 114)
												   , QPen(Qt::black), QBrush(color));
	points.clear();
	QGraphicsPolygonItem *polygon2 = createPolygon(points << QPointF(0, 0) << QPointF(0, 14)  <<  QPointF(14, 14) << QPointF(14, 0)
												   , QPen(Qt::black), QBrush(color));
	points.clear();
	QGraphicsPolygonItem *polygon3 = createPolygon(points << QPointF(170, 234) << QPointF(184, 234)  <<  QPointF(184, 220) << QPointF(170, 220)
												   , QPen(Qt::black), QBrush(color));
	points.clear();
	QGraphicsPolygonItem *polygon4 = createPolygon(points << QPointF(581, 267) << QPointF(581, 281)  <<  QPointF(595, 281) << QPointF(595, 267)
												   , QPen(Qt::black), QBrush(color));
	points.clear();
	QGraphicsPolygonItem *polygon5 = createPolygon(points << QPointF(640, 150) << QPointF(654, 150)  <<  QPointF(654, 164) << QPointF(640, 164)
												   , QPen(Qt::black), QBrush(color));
	points.clear();
	QGraphicsPolygonItem *polygon6 = createPolygon(points << QPointF(550, 50) << QPointF(564, 50)  <<  QPointF(564, 64) << QPointF(550, 64)
												   , QPen(Qt::black), QBrush(color));
	points.clear();
	QGraphicsPolygonItem *polygon7 = createPolygon(points << QPointF(50, 50) << QPointF(64, 50)  <<  QPointF(64, 64) << QPointF(50, 64)
												   , QPen(Qt::black), QBrush(color));
	points.clear();
	QGraphicsPolygonItem *polygon8 = createPolygon(points << QPointF(60, 330) << QPointF(74, 330)  <<  QPointF(74, 344) << QPointF(60, 344)
												   , QPen(Qt::black), QBrush(color));
	points.clear();
	QGraphicsPolygonItem *polygon9 = createPolygon(points << QPointF(750, 365) << QPointF(736, 351)  <<  QPointF(736, 14) << QPointF(750, 0)
												   , QPen(Qt::black), QBrush(color));
	scene->addItem(polygon1);
	scene->addItem(polygon2);
	scene->addItem(polygon3);
	scene->addItem(polygon4);
	scene->addItem(polygon5);
	scene->addItem(polygon6);
	scene->addItem(polygon7);
	scene->addItem(polygon8);
	scene->addItem(polygon9);
	walls->append(QList<QGraphicsPolygonItem*>() << polygon1 << polygon2 << polygon3 << polygon4 << polygon5 << polygon6 << polygon7 << polygon8 << polygon9);
}

void Level_4::createFirstSnake()
{
	snake = new Snake;
	QGraphicsEllipseItem* item1 = createEllipse(100, 170, 14, 14, QPen(Qt::black), QBrush(Qt::black));
	QGraphicsEllipseItem* item2 = createEllipse(86, 170, 14, 14, QPen(Qt::black), QBrush (QColor(255, 0, 0)));
	QGraphicsEllipseItem* item3 = createEllipse(72, 170, 14, 14, QPen(Qt::black), QBrush (QColor(238, 130, 238)));
	QGraphicsEllipseItem* item4 = createEllipse(58, 170, 14, 14, QPen(Qt::black), QBrush (QColor(255, 255, 0)));
	snake->balls->append(QList<QGraphicsEllipseItem*>() << item1 << item2 << item3 << item4);
	snake->length = 4;
	scene->addItem(item1);
	scene->addItem(item2);
	scene->addItem(item3);
	scene->addItem(item4);
}

void Level_4::snakeMovement()
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
				emit levelPassed(4);
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


bool Level_4::throwApple()
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

void Level_4::onAppleIntersection()
{
	bool result = throwApple();
	while (result)
		result = throwApple();

	emit applesCountChanged(++applesCount);

	int randomColor = rand() % 21;
	QGraphicsEllipseItem *item = createEllipse(snake->balls->at(snake->length - 1)->rect().x()
											   , snake->balls->at(snake->length - 1)->rect().y(), 14, 14, QPen(Qt::black), QBrush(colorArray[randomColor]));
	snake->balls->append(item);
	snake->length++;
	scene->addItem(item);
}

void Level_4::keyPressEvent(QKeyEvent *event)
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

void Level_4::stopGame()
{
	gameTimer.stop();
}

void Level_4::continueGame()
{
	gameTimer.start();
}

void Level_4::fillColorArray()
{
	colorArray[0] = QColor(220, 20, 60); // Crimson
	colorArray[1] = QColor(255, 0, 0); // Red
	colorArray[2] = QColor(255, 20, 147); // DeepPink
	colorArray[3] = QColor(255, 127, 80); // Coral
	colorArray[4] = QColor(255, 165, 0); // Orange
	colorArray[5] = QColor(238, 130, 238); // Violet
	colorArray[6] = QColor(153, 50, 204); // DarkOrchid
	colorArray[7] = QColor(106, 90, 205); // SlateBlue
	colorArray[8] = QColor(124, 252, 0); // LawnGreen
	colorArray[9] = QColor(0, 250, 154); // MediumSpringGreen
	colorArray[10] = QColor(50, 205, 50); // LimeGreen
	colorArray[11] = QColor(255, 255, 0); // Yellow
	colorArray[12] = QColor(0, 255, 255); // Aqua
	colorArray[13] = QColor(176, 224, 230); // PowderBlue
	colorArray[14] = QColor(0, 0, 255); // Blue
	colorArray[15] = QColor(255, 235, 205); // BlanchedAlmond
	colorArray[16] = QColor(188, 143, 143); // RosyBrown
	colorArray[17] = QColor(240, 230, 140); // Khaki
	colorArray[18] = QColor(216, 191, 216); // Thistle
	colorArray[19] = QColor(255, 69, 0); // OrangeRed
	colorArray[20] = QColor(255, 182, 193); // LightPink
}


