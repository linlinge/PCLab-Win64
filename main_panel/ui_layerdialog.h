/********************************************************************************
** Form generated from reading UI file 'layerdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LAYERDIALOG_H
#define UI_LAYERDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_layerDialog
{
public:
    QTreeWidget *treeWidget;
    QPlainTextEdit *plainTextEdit;

    void setupUi(QWidget *layerDialog)
    {
        if (layerDialog->objectName().isEmpty())
            layerDialog->setObjectName(QStringLiteral("layerDialog"));
        layerDialog->setWindowModality(Qt::NonModal);
        layerDialog->resize(354, 635);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(layerDialog->sizePolicy().hasHeightForWidth());
        layerDialog->setSizePolicy(sizePolicy);
        QPalette palette;
        QBrush brush(QColor(199, 237, 204, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Base, brush);
        QBrush brush1(QColor(255, 255, 255, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        layerDialog->setPalette(palette);
        layerDialog->setAutoFillBackground(false);
        treeWidget = new QTreeWidget(layerDialog);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem();
        __qtreewidgetitem->setText(0, QStringLiteral("1"));
        treeWidget->setHeaderItem(__qtreewidgetitem);
        treeWidget->setObjectName(QStringLiteral("treeWidget"));
        treeWidget->setGeometry(QRect(10, 0, 331, 331));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(treeWidget->sizePolicy().hasHeightForWidth());
        treeWidget->setSizePolicy(sizePolicy1);
        plainTextEdit = new QPlainTextEdit(layerDialog);
        plainTextEdit->setObjectName(QStringLiteral("plainTextEdit"));
        plainTextEdit->setGeometry(QRect(10, 350, 331, 271));
        plainTextEdit->setReadOnly(true);

        retranslateUi(layerDialog);

        QMetaObject::connectSlotsByName(layerDialog);
    } // setupUi

    void retranslateUi(QWidget *layerDialog)
    {
        layerDialog->setWindowTitle(QApplication::translate("layerDialog", "Form", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class layerDialog: public Ui_layerDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LAYERDIALOG_H
