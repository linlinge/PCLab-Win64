/********************************************************************************
** Form generated from reading UI file 'formgraph.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORMGRAPH_H
#define UI_FORMGRAPH_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FormGraph
{
public:

    void setupUi(QWidget *FormGraph)
    {
        if (FormGraph->objectName().isEmpty())
            FormGraph->setObjectName(QStringLiteral("FormGraph"));
        FormGraph->resize(679, 485);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(FormGraph->sizePolicy().hasHeightForWidth());
        FormGraph->setSizePolicy(sizePolicy);
        FormGraph->setAcceptDrops(true);

        retranslateUi(FormGraph);

        QMetaObject::connectSlotsByName(FormGraph);
    } // setupUi

    void retranslateUi(QWidget *FormGraph)
    {
        FormGraph->setWindowTitle(QApplication::translate("FormGraph", "Form", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class FormGraph: public Ui_FormGraph {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORMGRAPH_H
