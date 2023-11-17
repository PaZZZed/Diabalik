/********************************************************************************
** Form generated from reading UI file 'option.ui'
**
** Created by: Qt User Interface Compiler version 5.12.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OPTION_H
#define UI_OPTION_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Option
{
public:
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QRadioButton *rbV;
    QRadioButton *rbN;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QSpacerItem *horizontalSpacer;
    QComboBox *cbTaille;
    QPushButton *pushButton;

    void setupUi(QWidget *Option)
    {
        if (Option->objectName().isEmpty())
            Option->setObjectName(QString::fromUtf8("Option"));
        Option->resize(400, 300);
        layoutWidget = new QWidget(Option);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(50, 50, 261, 131));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(layoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        rbV = new QRadioButton(layoutWidget);
        rbV->setObjectName(QString::fromUtf8("rbV"));

        horizontalLayout->addWidget(rbV);

        rbN = new QRadioButton(layoutWidget);
        rbN->setObjectName(QString::fromUtf8("rbN"));

        horizontalLayout->addWidget(rbN);


        verticalLayout->addLayout(horizontalLayout);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_2->addWidget(label_2);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        cbTaille = new QComboBox(layoutWidget);
        cbTaille->addItem(QString());
        cbTaille->addItem(QString());
        cbTaille->addItem(QString());
        cbTaille->setObjectName(QString::fromUtf8("cbTaille"));

        horizontalLayout_2->addWidget(cbTaille);


        verticalLayout->addLayout(horizontalLayout_2);

        pushButton = new QPushButton(Option);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(260, 220, 61, 31));

        retranslateUi(Option);
        QObject::connect(pushButton, SIGNAL(clicked()), Option, SLOT(ouverture()));

        QMetaObject::connectSlotsByName(Option);
    } // setupUi

    void retranslateUi(QWidget *Option)
    {
        Option->setWindowTitle(QApplication::translate("Option", "Form", nullptr));
        label->setText(QApplication::translate("Option", "Mode:", nullptr));
        rbV->setText(QApplication::translate("Option", "Variante", nullptr));
        rbN->setText(QApplication::translate("Option", "Normal", nullptr));
        label_2->setText(QApplication::translate("Option", "Taille du plateau: ", nullptr));
        cbTaille->setItemText(0, QApplication::translate("Option", "5", nullptr));
        cbTaille->setItemText(1, QApplication::translate("Option", "7", nullptr));
        cbTaille->setItemText(2, QApplication::translate("Option", "9", nullptr));

        pushButton->setText(QApplication::translate("Option", "ok", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Option: public Ui_Option {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OPTION_H
