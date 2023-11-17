/********************************************************************************
** Form generated from reading UI file 'gameoverwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GAMEOVERWINDOW_H
#define UI_GAMEOVERWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GameOverWindow
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QHBoxLayout *horizontalLayout;
    QPushButton *pbClose;
    QPushButton *pbReplay;

    void setupUi(QWidget *GameOverWindow)
    {
        if (GameOverWindow->objectName().isEmpty())
            GameOverWindow->setObjectName(QString::fromUtf8("GameOverWindow"));
        GameOverWindow->resize(400, 300);
        verticalLayout = new QVBoxLayout(GameOverWindow);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(GameOverWindow);
        label->setObjectName(QString::fromUtf8("label"));
        label->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        pbClose = new QPushButton(GameOverWindow);
        pbClose->setObjectName(QString::fromUtf8("pbClose"));

        horizontalLayout->addWidget(pbClose);

        pbReplay = new QPushButton(GameOverWindow);
        pbReplay->setObjectName(QString::fromUtf8("pbReplay"));

        horizontalLayout->addWidget(pbReplay);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(GameOverWindow);
        QObject::connect(pbReplay, SIGNAL(clicked()), GameOverWindow, SLOT(replay()));

        QMetaObject::connectSlotsByName(GameOverWindow);
    } // setupUi

    void retranslateUi(QWidget *GameOverWindow)
    {
        GameOverWindow->setWindowTitle(QApplication::translate("GameOverWindow", "Form", nullptr));
        label->setText(QApplication::translate("GameOverWindow", "TextLabel", nullptr));
        pbClose->setText(QApplication::translate("GameOverWindow", "Quitter", nullptr));
        pbReplay->setText(QApplication::translate("GameOverWindow", "Recommencer", nullptr));
    } // retranslateUi

};

namespace Ui {
    class GameOverWindow: public Ui_GameOverWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAMEOVERWINDOW_H
