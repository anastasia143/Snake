#pragma once

#include <QMainWindow>
#include "gameWidget.h"
#include "mainWindow.h"

namespace Ui {
class Headband;
}

class Headband : public QWidget
{
	Q_OBJECT

public:
	explicit Headband(QWidget *parent = 0);
	~Headband();

signals:

public slots:
	void onNewGameClicked();
	void onRulesClicked();
	void onRecordsClicked();

private:
	Ui::Headband *ui;
	MainWindow newGame;

};
