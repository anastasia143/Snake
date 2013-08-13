/********************************************************************************
** Form generated from reading UI file 'rules.ui'
**
** Created by: Qt User Interface Compiler version 5.0.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RULES_H
#define UI_RULES_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Rules
{
public:
    QTextBrowser *banner;
    QToolButton *buttonMenu;

    void setupUi(QWidget *Rules)
    {
        if (Rules->objectName().isEmpty())
            Rules->setObjectName(QStringLiteral("Rules"));
        Rules->resize(796, 484);
        banner = new QTextBrowser(Rules);
        banner->setObjectName(QStringLiteral("banner"));
        banner->setGeometry(QRect(0, 0, 801, 491));
        banner->setMinimumSize(QSize(801, 491));
        banner->setMaximumSize(QSize(801, 491));
        buttonMenu = new QToolButton(Rules);
        buttonMenu->setObjectName(QStringLiteral("buttonMenu"));
        buttonMenu->setGeometry(QRect(110, 380, 211, 51));
        QFont font;
        font.setFamily(QStringLiteral("Angsana New"));
        font.setPointSize(22);
        font.setBold(false);
        font.setWeight(50);
        buttonMenu->setFont(font);
        buttonMenu->setCursor(QCursor(Qt::PointingHandCursor));
        buttonMenu->setMouseTracking(true);
        buttonMenu->setAutoFillBackground(false);
        buttonMenu->setCheckable(false);
        buttonMenu->setAutoRepeat(false);

        retranslateUi(Rules);

        QMetaObject::connectSlotsByName(Rules);
    } // setupUi

    void retranslateUi(QWidget *Rules)
    {
        Rules->setWindowTitle(QApplication::translate("Rules", "Form", 0));
        banner->setHtml(QApplication::translate("Rules", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><img src=\"rules.jpg\" /><span style=\" font-size:8pt;\"> </span></p></body></html>", 0));
        buttonMenu->setText(QApplication::translate("Rules", "Menu", 0));
        buttonMenu->setShortcut(QString());
    } // retranslateUi

};

namespace Ui {
    class Rules: public Ui_Rules {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RULES_H
