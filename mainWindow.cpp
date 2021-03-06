#include "mainWindow.h"
#include "ui_game.h"

MainWindow::MainWindow(QWidget *newParent) :
	QMainWindow(newParent),
	ui(new Ui::MainWindow)
{
	ui->setupUi(this);
	setWindowTitle("Snake. Level 1: \"Easy game\" ");

	parent = newParent;
	levelTimeSeconds = 0;
	levelTimeMinutes = 0;

	gameWidget = new Level_1(parent);
	ui->mainLayout->addWidget(gameWidget);

	ui->levelEdit->setText(QString::number(gameWidget->level));
	ui->applesEdit->setText("0");

	connect(gameWidget, SIGNAL(gameOver()), this, SLOT(onGameOver()));
	connect(gameWidget, SIGNAL(applesCountChanged(int)), this, SLOT(onApplesCountChanged(int)));
	connect(gameWidget, SIGNAL(levelPassed(int)), this, SLOT(onLevelPassed(int)));

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

void MainWindow::onGameOver()
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

void MainWindow::onLevelPassed(int level)
{
	ui->mainLayout->removeWidget(gameWidget);
	gameWidget->stopGame();
	//gameWidget->destroy();
	gameWidget->close();
	delete gameWidget;

	GameWidget *newGameWidget;
	switch(level)
	{
	case 1:
	{
		setWindowTitle("Snake. Level 2: \"Locked up\" ");
		newGameWidget = new Level_2(parent);
		break;
	}
	case 2:
	{
		setWindowTitle("Snake. Level 3: \"Fast apples\" ");
		newGameWidget = new Level_3(parent);
		break;
	}
	case 3:
	{
		setWindowTitle("Snake. Level 4: \"Color madness\" ");
		newGameWidget = new Level_4(parent);
		break;
	}
	case 4:
	{
		setWindowTitle("Snake. Level 5: \"Rooms\" ");
		newGameWidget = new Level_5(parent);
		break;
	}
	}
	gameWidget = newGameWidget;
	ui->mainLayout->addWidget(gameWidget);
	gameWidget->show();
	gameWidget->setFocus();

	connect(gameWidget, SIGNAL(gameOver()), this, SLOT(onGameOver()));
	connect(gameWidget, SIGNAL(applesCountChanged(int)), this, SLOT(onApplesCountChanged(int)));
	connect(gameWidget, SIGNAL(levelPassed(int)), this, SLOT(onLevelPassed(int)));

	ui->levelEdit->setText(QString::number(gameWidget->level));
	gameWidget->applesCount = 0;
	onApplesCountChanged(0);
	levelTimeMinutes = 0;
	levelTimeSeconds = 0;
}
