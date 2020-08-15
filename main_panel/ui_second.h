/********************************************************************************
** Form generated from reading UI file 'second.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SECOND_H
#define UI_SECOND_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Second
{
public:
    QLabel *label;

    void setupUi(QWidget *Second)
    {
        if (Second->objectName().isEmpty())
            Second->setObjectName(QStringLiteral("Second"));
        Second->resize(797, 575);
        label = new QLabel(Second);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(160, 270, 54, 12));

        retranslateUi(Second);

        QMetaObject::connectSlotsByName(Second);
    } // setupUi

    void retranslateUi(QWidget *Second)
    {
        Second->setWindowTitle(QApplication::translate("Second", "Form", Q_NULLPTR));
        label->setText(QApplication::translate("Second", "TextLabel", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Second: public Ui_Second {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SECOND_H
