/********************************************************************************
** Form generated from reading UI file 'game.ui'
**
** Created by: Qt User Interface Compiler version 5.0.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GAME_H
#define UI_GAME_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionNew_Game;
    QAction *actionRules;
    QAction *actionRecords;
    QWidget *centralWidget;
    QProgressBar *levelProgressBar;
    QLabel *label;
    QLabel *label_2;
    QTextEdit *applesEdit;
    QTextEdit *levelEdit;
    QTextBrowser *miniSnake;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *mainLayout;
    QTextEdit *timer;
    QToolButton *pauseButton;
    QToolButton *continueButton;
    QMenuBar *menuBar;
    QMenu *menuMenu;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(784, 483);
        actionNew_Game = new QAction(MainWindow);
        actionNew_Game->setObjectName(QStringLiteral("actionNew_Game"));
        actionRules = new QAction(MainWindow);
        actionRules->setObjectName(QStringLiteral("actionRules"));
        actionRecords = new QAction(MainWindow);
        actionRecords->setObjectName(QStringLiteral("actionRecords"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        levelProgressBar = new QProgressBar(centralWidget);
        levelProgressBar->setObjectName(QStringLiteral("levelProgressBar"));
        levelProgressBar->setGeometry(QRect(610, 10, 161, 31));
        levelProgressBar->setValue(0);
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(470, 10, 61, 31));
        QFont font;
        font.setPointSize(11);
        label->setFont(font);
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(350, 10, 61, 31));
        label_2->setFont(font);
        applesEdit = new QTextEdit(centralWidget);
        applesEdit->setObjectName(QStringLiteral("applesEdit"));
        applesEdit->setGeometry(QRect(530, 10, 61, 31));
        QFont font1;
        font1.setPointSize(12);
        applesEdit->setFont(font1);
        applesEdit->setReadOnly(true);
        levelEdit = new QTextEdit(centralWidget);
        levelEdit->setObjectName(QStringLiteral("levelEdit"));
        levelEdit->setEnabled(true);
        levelEdit->setGeometry(QRect(400, 10, 61, 31));
        levelEdit->setFont(font1);
        levelEdit->setReadOnly(true);
        miniSnake = new QTextBrowser(centralWidget);
        miniSnake->setObjectName(QStringLiteral("miniSnake"));
        miniSnake->setGeometry(QRect(10, 0, 61, 61));
        miniSnake->setFrameShape(QFrame::NoFrame);
        miniSnake->setFrameShadow(QFrame::Plain);
        verticalLayoutWidget = new QWidget(centralWidget);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(10, 60, 761, 371));
        mainLayout = new QVBoxLayout(verticalLayoutWidget);
        mainLayout->setSpacing(6);
        mainLayout->setContentsMargins(11, 11, 11, 11);
        mainLayout->setObjectName(QStringLiteral("mainLayout"));
        mainLayout->setContentsMargins(0, 0, 0, 0);
        timer = new QTextEdit(centralWidget);
        timer->setObjectName(QStringLiteral("timer"));
        timer->setGeometry(QRect(250, 10, 61, 31));
        timer->setFont(font1);
        timer->setReadOnly(true);
        pauseButton = new QToolButton(centralWidget);
        pauseButton->setObjectName(QStringLiteral("pauseButton"));
        pauseButton->setGeometry(QRect(90, 10, 71, 31));
        continueButton = new QToolButton(centralWidget);
        continueButton->setObjectName(QStringLiteral("continueButton"));
        continueButton->setGeometry(QRect(170, 10, 71, 31));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 784, 21));
        menuMenu = new QMenu(menuBar);
        menuMenu->setObjectName(QStringLiteral("menuMenu"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuMenu->menuAction());
        menuMenu->addAction(actionNew_Game);
        menuMenu->addAction(actionRules);
        menuMenu->addAction(actionRecords);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        actionNew_Game->setText(QApplication::translate("MainWindow", "New Game", 0));
        actionRules->setText(QApplication::translate("MainWindow", "Rules", 0));
        actionRecords->setText(QApplication::translate("MainWindow", "Records", 0));
        label->setText(QApplication::translate("MainWindow", "Apples:", 0));
        label_2->setText(QApplication::translate("MainWindow", "Level:", 0));
        levelEdit->setHtml(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:12pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", 0));
        miniSnake->setHtml(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><img src=\"miniSnake.jpg\" /></p></body></html>", 0));
        pauseButton->setText(QApplication::translate("MainWindow", "Pause", 0));
        continueButton->setText(QApplication::translate("MainWindow", "Continue", 0));
        menuMenu->setTitle(QApplication::translate("MainWindow", "Menu", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAME_H
