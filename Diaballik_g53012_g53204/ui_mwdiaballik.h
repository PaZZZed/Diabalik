/********************************************************************************
** Form generated from reading UI file 'mwdiaballik.ui'
**
** Created by: Qt User Interface Compiler version 5.12.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MWDIABALLIK_H
#define UI_MWDIABALLIK_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MWDiaballik
{
public:
    QAction *action_Nouveau;
    QAction *action_Quitter;
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QLabel *lbPlayer;
    QLabel *selected;
    QGraphicsView *graphicsView;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton_3;
    QPushButton *pushButton;
    QMenuBar *menubar;
    QMenu *menuOption;

    void setupUi(QMainWindow *MWDiaballik)
    {
        if (MWDiaballik->objectName().isEmpty())
            MWDiaballik->setObjectName(QString::fromUtf8("MWDiaballik"));
        MWDiaballik->resize(800, 600);
        action_Nouveau = new QAction(MWDiaballik);
        action_Nouveau->setObjectName(QString::fromUtf8("action_Nouveau"));
        action_Quitter = new QAction(MWDiaballik);
        action_Quitter->setObjectName(QString::fromUtf8("action_Quitter"));
        centralwidget = new QWidget(MWDiaballik);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        lbPlayer = new QLabel(centralwidget);
        lbPlayer->setObjectName(QString::fromUtf8("lbPlayer"));

        verticalLayout->addWidget(lbPlayer);

        selected = new QLabel(centralwidget);
        selected->setObjectName(QString::fromUtf8("selected"));

        verticalLayout->addWidget(selected);

        graphicsView = new QGraphicsView(centralwidget);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));

        verticalLayout->addWidget(graphicsView);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        pushButton_3 = new QPushButton(centralwidget);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));

        horizontalLayout->addWidget(pushButton_3);

        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        horizontalLayout->addWidget(pushButton);


        verticalLayout->addLayout(horizontalLayout);

        MWDiaballik->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MWDiaballik);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 22));
        menubar->setNativeMenuBar(false);
        menuOption = new QMenu(menubar);
        menuOption->setObjectName(QString::fromUtf8("menuOption"));
        MWDiaballik->setMenuBar(menubar);

        menubar->addAction(menuOption->menuAction());
        menuOption->addAction(action_Quitter);

        retranslateUi(MWDiaballik);
        QObject::connect(pushButton, SIGNAL(clicked()), MWDiaballik, SLOT(swap()));
        QObject::connect(pushButton_3, SIGNAL(clicked()), MWDiaballik, SLOT(fairPlay()));

        QMetaObject::connectSlotsByName(MWDiaballik);
    } // setupUi

    void retranslateUi(QMainWindow *MWDiaballik)
    {
        MWDiaballik->setWindowTitle(QApplication::translate("MWDiaballik", "MWDiaballik", nullptr));
        action_Nouveau->setText(QApplication::translate("MWDiaballik", "&Nouveau", nullptr));
        action_Quitter->setText(QApplication::translate("MWDiaballik", "&Quitter", nullptr));
        lbPlayer->setText(QApplication::translate("MWDiaballik", "Player: GOLD", nullptr));
        selected->setText(QApplication::translate("MWDiaballik", "Selected :", nullptr));
        pushButton_3->setText(QApplication::translate("MWDiaballik", "anti-jeu", nullptr));
        pushButton->setText(QApplication::translate("MWDiaballik", "swap", nullptr));
        menuOption->setTitle(QApplication::translate("MWDiaballik", "Option", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MWDiaballik: public Ui_MWDiaballik {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MWDIABALLIK_H
