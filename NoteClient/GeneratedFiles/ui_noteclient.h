/********************************************************************************
** Form generated from reading UI file 'noteclient.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NOTECLIENT_H
#define UI_NOTECLIENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_NoteClientClass
{
public:
    QWidget *centralWidget;
    QFormLayout *formLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *titleLabel;
    QLineEdit *titleLineEdit;
    QPushButton *selectFileButton;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *codeButton;
    QSpacerItem *horizontalSpacer;
    QLabel *fontsizeLabel;
    QSpinBox *fontsizeSpinBox;
    QSlider *fontsizeHorizontalSlider;
    QLabel *codeLabel;
    QTextEdit *codeTextEdit;
    QLabel *contentLabel;
    QTextEdit *contentTextEdit;
    QPushButton *geneButton;
    QPushButton *clearButton;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *NoteClientClass)
    {
        if (NoteClientClass->objectName().isEmpty())
            NoteClientClass->setObjectName(QStringLiteral("NoteClientClass"));
        NoteClientClass->resize(491, 713);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(NoteClientClass->sizePolicy().hasHeightForWidth());
        NoteClientClass->setSizePolicy(sizePolicy);
        centralWidget = new QWidget(NoteClientClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        formLayout = new QFormLayout(centralWidget);
        formLayout->setSpacing(6);
        formLayout->setContentsMargins(11, 11, 11, 11);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        titleLabel = new QLabel(centralWidget);
        titleLabel->setObjectName(QStringLiteral("titleLabel"));

        horizontalLayout->addWidget(titleLabel);

        titleLineEdit = new QLineEdit(centralWidget);
        titleLineEdit->setObjectName(QStringLiteral("titleLineEdit"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(1);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(titleLineEdit->sizePolicy().hasHeightForWidth());
        titleLineEdit->setSizePolicy(sizePolicy1);
        titleLineEdit->setStyleSheet(QStringLiteral("backgroud-color: yellow;"));

        horizontalLayout->addWidget(titleLineEdit);

        selectFileButton = new QPushButton(centralWidget);
        selectFileButton->setObjectName(QStringLiteral("selectFileButton"));

        horizontalLayout->addWidget(selectFileButton);


        formLayout->setLayout(0, QFormLayout::SpanningRole, horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        codeButton = new QPushButton(centralWidget);
        codeButton->setObjectName(QStringLiteral("codeButton"));
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(codeButton->sizePolicy().hasHeightForWidth());
        codeButton->setSizePolicy(sizePolicy2);
        codeButton->setCheckable(true);

        horizontalLayout_2->addWidget(codeButton);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        fontsizeLabel = new QLabel(centralWidget);
        fontsizeLabel->setObjectName(QStringLiteral("fontsizeLabel"));

        horizontalLayout_2->addWidget(fontsizeLabel);

        fontsizeSpinBox = new QSpinBox(centralWidget);
        fontsizeSpinBox->setObjectName(QStringLiteral("fontsizeSpinBox"));
        fontsizeSpinBox->setMinimum(8);
        fontsizeSpinBox->setMaximum(20);
        fontsizeSpinBox->setValue(10);

        horizontalLayout_2->addWidget(fontsizeSpinBox);

        fontsizeHorizontalSlider = new QSlider(centralWidget);
        fontsizeHorizontalSlider->setObjectName(QStringLiteral("fontsizeHorizontalSlider"));
        fontsizeHorizontalSlider->setMinimum(8);
        fontsizeHorizontalSlider->setMaximum(20);
        fontsizeHorizontalSlider->setValue(10);
        fontsizeHorizontalSlider->setOrientation(Qt::Horizontal);

        horizontalLayout_2->addWidget(fontsizeHorizontalSlider);


        formLayout->setLayout(1, QFormLayout::SpanningRole, horizontalLayout_2);

        codeLabel = new QLabel(centralWidget);
        codeLabel->setObjectName(QStringLiteral("codeLabel"));

        formLayout->setWidget(2, QFormLayout::LabelRole, codeLabel);

        codeTextEdit = new QTextEdit(centralWidget);
        codeTextEdit->setObjectName(QStringLiteral("codeTextEdit"));
        QSizePolicy sizePolicy3(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy3.setHorizontalStretch(3);
        sizePolicy3.setVerticalStretch(3);
        sizePolicy3.setHeightForWidth(codeTextEdit->sizePolicy().hasHeightForWidth());
        codeTextEdit->setSizePolicy(sizePolicy3);

        formLayout->setWidget(3, QFormLayout::SpanningRole, codeTextEdit);

        contentLabel = new QLabel(centralWidget);
        contentLabel->setObjectName(QStringLiteral("contentLabel"));
        sizePolicy2.setHeightForWidth(contentLabel->sizePolicy().hasHeightForWidth());
        contentLabel->setSizePolicy(sizePolicy2);

        formLayout->setWidget(4, QFormLayout::LabelRole, contentLabel);

        contentTextEdit = new QTextEdit(centralWidget);
        contentTextEdit->setObjectName(QStringLiteral("contentTextEdit"));
        QSizePolicy sizePolicy4(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy4.setHorizontalStretch(2);
        sizePolicy4.setVerticalStretch(2);
        sizePolicy4.setHeightForWidth(contentTextEdit->sizePolicy().hasHeightForWidth());
        contentTextEdit->setSizePolicy(sizePolicy4);

        formLayout->setWidget(5, QFormLayout::SpanningRole, contentTextEdit);

        geneButton = new QPushButton(centralWidget);
        geneButton->setObjectName(QStringLiteral("geneButton"));
        sizePolicy2.setHeightForWidth(geneButton->sizePolicy().hasHeightForWidth());
        geneButton->setSizePolicy(sizePolicy2);

        formLayout->setWidget(6, QFormLayout::LabelRole, geneButton);

        clearButton = new QPushButton(centralWidget);
        clearButton->setObjectName(QStringLiteral("clearButton"));
        sizePolicy2.setHeightForWidth(clearButton->sizePolicy().hasHeightForWidth());
        clearButton->setSizePolicy(sizePolicy2);

        formLayout->setWidget(6, QFormLayout::FieldRole, clearButton);

        NoteClientClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(NoteClientClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 491, 26));
        NoteClientClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(NoteClientClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        NoteClientClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(NoteClientClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        NoteClientClass->setStatusBar(statusBar);
        toolBar = new QToolBar(NoteClientClass);
        toolBar->setObjectName(QStringLiteral("toolBar"));
        NoteClientClass->addToolBar(Qt::TopToolBarArea, toolBar);

        retranslateUi(NoteClientClass);
        QObject::connect(codeButton, SIGNAL(toggled(bool)), codeTextEdit, SLOT(setVisible(bool)));
        QObject::connect(codeButton, SIGNAL(toggled(bool)), NoteClientClass, SLOT(setCodeButtonText(bool)));
        QObject::connect(codeButton, SIGNAL(toggled(bool)), codeLabel, SLOT(setVisible(bool)));
        QObject::connect(fontsizeSpinBox, SIGNAL(valueChanged(int)), fontsizeHorizontalSlider, SLOT(setValue(int)));
        QObject::connect(fontsizeHorizontalSlider, SIGNAL(valueChanged(int)), fontsizeSpinBox, SLOT(setValue(int)));
        QObject::connect(fontsizeHorizontalSlider, SIGNAL(valueChanged(int)), NoteClientClass, SLOT(setFont(int)));

        QMetaObject::connectSlotsByName(NoteClientClass);
    } // setupUi

    void retranslateUi(QMainWindow *NoteClientClass)
    {
        NoteClientClass->setWindowTitle(QApplication::translate("NoteClientClass", "NoteClient", 0));
        titleLabel->setText(QApplication::translate("NoteClientClass", "Title :", 0));
        selectFileButton->setText(QApplication::translate("NoteClientClass", "Select", 0));
        codeButton->setText(QApplication::translate("NoteClientClass", "Showcode >>", 0));
        fontsizeLabel->setText(QApplication::translate("NoteClientClass", "Fontsize :", 0));
        codeLabel->setText(QApplication::translate("NoteClientClass", "Code :", 0));
        contentLabel->setText(QApplication::translate("NoteClientClass", "Content :", 0));
        geneButton->setText(QApplication::translate("NoteClientClass", "Generate", 0));
        clearButton->setText(QApplication::translate("NoteClientClass", "Clear", 0));
        toolBar->setWindowTitle(QApplication::translate("NoteClientClass", "toolBar", 0));
    } // retranslateUi

};

namespace Ui {
    class NoteClientClass: public Ui_NoteClientClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NOTECLIENT_H
