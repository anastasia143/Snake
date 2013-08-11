/********************************************************************************
** Form generated from reading UI file 'headband.ui'
**
** Created by: Qt User Interface Compiler version 5.0.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HEADBAND_H
#define UI_HEADBAND_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Headband
{
public:
    QWidget *myWidget;
    QTextBrowser *banner;
    QToolButton *buttonNewGame;
    QToolButton *buttonRules;
    QToolButton *buttonRecords;

    void setupUi(QWidget *Headband)
    {
        if (Headband->objectName().isEmpty())
            Headband->setObjectName(QStringLiteral("Headband"));
        Headband->resize(796, 484);
        Headband->setMinimumSize(QSize(796, 484));
        Headband->setMaximumSize(QSize(796, 484));
        myWidget = new QWidget(Headband);
        myWidget->setObjectName(QStringLiteral("myWidget"));
        myWidget->setGeometry(QRect(530, 100, 120, 80));
        banner = new QTextBrowser(Headband);
        banner->setObjectName(QStringLiteral("banner"));
        banner->setGeometry(QRect(0, 0, 801, 491));
        banner->setMinimumSize(QSize(801, 491));
        banner->setMaximumSize(QSize(801, 491));
        buttonNewGame = new QToolButton(Headband);
        buttonNewGame->setObjectName(QStringLiteral("buttonNewGame"));
        buttonNewGame->setGeometry(QRect(70, 190, 211, 51));
        QFont font;
        font.setFamily(QStringLiteral("Angsana New"));
        font.setPointSize(22);
        font.setBold(false);
        font.setWeight(50);
        buttonNewGame->setFont(font);
        buttonNewGame->setCursor(QCursor(Qt::PointingHandCursor));
        buttonNewGame->setMouseTracking(true);
        buttonNewGame->setAutoFillBackground(false);
        buttonNewGame->setCheckable(false);
        buttonNewGame->setAutoRepeat(false);
        buttonRules = new QToolButton(Headband);
        buttonRules->setObjectName(QStringLiteral("buttonRules"));
        buttonRules->setGeometry(QRect(100, 260, 211, 51));
        buttonRules->setFont(font);
        buttonRules->setCursor(QCursor(Qt::PointingHandCursor));
        buttonRules->setMouseTracking(true);
        buttonRules->setAutoFillBackground(false);
        buttonRules->setCheckable(false);
        buttonRules->setAutoRepeat(false);
        buttonRecords = new QToolButton(Headband);
        buttonRecords->setObjectName(QStringLiteral("buttonRecords"));
        buttonRecords->setGeometry(QRect(130, 330, 211, 51));
        buttonRecords->setFont(font);
        buttonRecords->setCursor(QCursor(Qt::PointingHandCursor));
        buttonRecords->setMouseTracking(true);
        buttonRecords->setAutoFillBackground(false);
        buttonRecords->setCheckable(false);
        buttonRecords->setAutoRepeat(false);

        retranslateUi(Headband);

        QMetaObject::connectSlotsByName(Headband);
    } // setupUi

    void retranslateUi(QWidget *Headband)
    {
        Headband->setWindowTitle(QApplication::translate("Headband", "Form", 0));
        banner->setHtml(QApplication::translate("Headband", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><img src=\"headband.jpg\" /><span style=\" font-size:8pt;\"> </span></p></body></html>", 0));
        buttonNewGame->setText(QApplication::translate("Headband", "New Game", 0));
        buttonNewGame->setShortcut(QString());
        buttonRules->setText(QApplication::translate("Headband", "Rules", 0));
        buttonRules->setShortcut(QString());
        buttonRecords->setText(QApplication::translate("Headband", "Records", 0));
        buttonRecords->setShortcut(QString());
    } // retranslateUi

};

namespace Ui {
    class Headband: public Ui_Headband {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HEADBAND_H
