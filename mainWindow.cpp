#include "mainWindow.h"
#include "ui_game.h"

MainWindow::MainWindow(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::MainWindow)
{
	ui->setupUi(this);
	setWindowTitle("Snake");

	levelTimeSeconds = 0;
	levelTimeMinutes = 0;

	gameWidget = new Level_1(parent);
	ui->mainLayout->addWidget(gameWidget);
	gameWidget->activateWindow();

	ui->levelEdit->setText(QString::number(gameWidget->level));

	connect(gameWidget, SIGNAL(snakeSelfIntersection()), this, SLOT(gameOver()));
	connect(gameWidget, SIGNAL(applesCountChanged(int)), this, SLOT(onApplesCountChanged(int)));
	connect(ui->pauseButton, SIGNAL(clicked()), this, SLOT(pauseGame()));
	connect(ui->continueButton, SIGNAL(clicked()), this, SLOT(continueGame()));

	updateTimer.start(1000);
	connect(&updateTimer, SIGNAL(timeout()), this, SLOT(updateTime()));
	gameWidget->setFocus();

	ui->continueButton->setEnabled(false);
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
	ui->levelProgressBar->setValue((apples * 100) / gameWidget->maxApplesOnLevel);
}

void MainWindow::updateTime()
{
	QString secondsZeroAdd;
	QString minutesZeroAdd;

	levelTimeSeconds++;
	if (levelTimeSeconds == 60)
	{
		levelTimeMinutes++;
		levelTimeSeconds = 0;
	}

	if (levelTimeSeconds < 10)
		secondsZeroAdd = "0";
	else
		secondsZeroAdd = "";
	if (levelTimeMinutes < 10)
		minutesZeroAdd = "0";
	else
		minutesZeroAdd = "";

	ui->timer->setText(minutesZeroAdd + QString::number(levelTimeMinutes) + ":" + secondsZeroAdd + QString::number(levelTimeSeconds));
}

void MainWindow::pauseGame()
{
	gameWidget->stopGame();
	updateTimer.stop();
	ui->pauseButton->setEnabled(false);
	ui->continueButton->setEnabled(true);
}

void MainWindow::continueGame()
{
	gameWidget->continueGame();
	updateTimer.start();
	ui->pauseButton->setEnabled(true);
	ui->continueButton->setEnabled(false);
}
