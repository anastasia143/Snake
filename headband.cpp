#include "headband.h"
#include "ui_headband.h"

Headband::Headband(QWidget *parent) :
	QWidget(parent),
	ui(new Ui::Headband)
{
	ui->setupUi(this);
	setWindowTitle("Snake");

	connect(ui->buttonNewGame, SIGNAL(clicked()), this, SLOT(onNewGameClicked()));
	connect(ui->buttonRules, SIGNAL(clicked()), this, SLOT(onRulesClicked()));
	connect(ui->buttonRecords, SIGNAL(clicked()), this, SLOT(onRecordsClicked()));

}

Headband::~Headband()
{
	delete ui;
	delete newGame;
}


void Headband::onNewGameClicked()
{
	this->hide();
	newGame = new MainWindow;
	newGame->show();
}


void Headband::onRulesClicked()
{
	this->hide();
	rules = new Rules;
	connect(rules, SIGNAL(menuPressed()), this, SLOT(onMenuClicked()));
	rules->show();
}


void Headband::onRecordsClicked()
{

}

void Headband::onMenuClicked()
{
	rules->hide();
	this->show();
}
