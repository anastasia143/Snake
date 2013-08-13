#include "rules.h"
#include "ui_rules.h"

Rules::Rules(QWidget *parent) :
	QWidget(parent),
	ui(new Ui::Rules)
{
	ui->setupUi(this);
	setWindowTitle("Snake");

	connect(ui->buttonMenu, SIGNAL(clicked()), this, SLOT(onMenuPressed()));
}

Rules::~Rules()
{
	delete ui;
}

void Rules::onMenuPressed()
{
	emit menuPressed();
}
