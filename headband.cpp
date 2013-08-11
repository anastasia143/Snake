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
}


void Headband::onNewGameClicked()
{
	this->hide();
	newGame.show();
}


void Headband::onRulesClicked()
{

}


void Headband::onRecordsClicked()
{

}
