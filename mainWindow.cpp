#include "mainWindow.h"
#include "ui_game.h"

MainWindow::MainWindow(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::MainWindow)
{
	ui->setupUi(this);
	setWindowTitle("Snake");


	gameWidget = new GameWidget(parent);
	ui->mainLayout->addWidget(gameWidget);
	gameWidget->activateWindow();
	//bool x = gameWidget->isActiveWindow();

	ui->levelEdit->setText("1");
	level = 1;
	maxApplesOnLevel = 20;

	connect(gameWidget, SIGNAL(snakeSelfIntersection()), this, SLOT(gameOver()));
	connect(gameWidget, SIGNAL(applesCountChanged(int)), this, SLOT(onApplesCountChanged(int)));
	gameWidget->setFocus();
}

MainWindow::~MainWindow()
{
	delete gameWidget;
	delete ui;
}

void MainWindow::gameOver()
{
	gameWidget->stopGame();
}

void MainWindow::onApplesCountChanged(int apples)
{
	ui->applesEdit->setText(QString::number(apples));
	int t = (apples * 100);
	int g = t / maxApplesOnLevel;
	ui->levelProgressBar->setValue((apples * 100) / maxApplesOnLevel);
}
