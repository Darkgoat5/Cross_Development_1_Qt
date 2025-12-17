/********************************************************************************
** Form generated from reading UI file 'movietracker.ui'
**
** Created by: Qt User Interface Compiler version 6.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MOVIETRACKER_H
#define UI_MOVIETRACKER_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MovieTracker
{
public:
    QAction *actionOpen;
    QAction *actionSave;
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout_2;
    QPushButton *pushButton;
    QHBoxLayout *horizontalLayout;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QHBoxLayout *horizontalLayout_3;
    QListWidget *listWidget;
    QWidget *page_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QComboBox *comboBox;
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer;
    QPushButton *pushButton_3;
    QPushButton *pushButton_2;
    QMenuBar *menubar;
    QMenu *menuFile;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MovieTracker)
    {
        if (MovieTracker->objectName().isEmpty())
            MovieTracker->setObjectName("MovieTracker");
        MovieTracker->resize(800, 600);
        actionOpen = new QAction(MovieTracker);
        actionOpen->setObjectName("actionOpen");
        actionSave = new QAction(MovieTracker);
        actionSave->setObjectName("actionSave");
        centralwidget = new QWidget(MovieTracker);
        centralwidget->setObjectName("centralwidget");
        verticalLayout_2 = new QVBoxLayout(centralwidget);
        verticalLayout_2->setObjectName("verticalLayout_2");
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName("pushButton");

        verticalLayout_2->addWidget(pushButton);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName("stackedWidget");
        page = new QWidget();
        page->setObjectName("page");
        horizontalLayout_3 = new QHBoxLayout(page);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        listWidget = new QListWidget(page);
        listWidget->setObjectName("listWidget");

        horizontalLayout_3->addWidget(listWidget);

        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName("page_2");
        horizontalLayout_2 = new QHBoxLayout(page_2);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        label = new QLabel(page_2);
        label->setObjectName("label");

        horizontalLayout_2->addWidget(label);

        comboBox = new QComboBox(page_2);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName("comboBox");

        horizontalLayout_2->addWidget(comboBox);

        stackedWidget->addWidget(page_2);

        horizontalLayout->addWidget(stackedWidget);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        pushButton_3 = new QPushButton(centralwidget);
        pushButton_3->setObjectName("pushButton_3");

        verticalLayout->addWidget(pushButton_3);

        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName("pushButton_2");

        verticalLayout->addWidget(pushButton_2);


        horizontalLayout->addLayout(verticalLayout);


        verticalLayout_2->addLayout(horizontalLayout);

        MovieTracker->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MovieTracker);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 25));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName("menuFile");
        MovieTracker->setMenuBar(menubar);
        statusbar = new QStatusBar(MovieTracker);
        statusbar->setObjectName("statusbar");
        MovieTracker->setStatusBar(statusbar);

        menubar->addAction(menuFile->menuAction());
        menuFile->addAction(actionOpen);
        menuFile->addAction(actionSave);

        retranslateUi(MovieTracker);

        stackedWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MovieTracker);
    } // setupUi

    void retranslateUi(QMainWindow *MovieTracker)
    {
        MovieTracker->setWindowTitle(QCoreApplication::translate("MovieTracker", "MovieTracker", nullptr));
        actionOpen->setText(QCoreApplication::translate("MovieTracker", "Open", nullptr));
        actionSave->setText(QCoreApplication::translate("MovieTracker", "Save", nullptr));
        pushButton->setText(QCoreApplication::translate("MovieTracker", "Add New Movie", nullptr));
        label->setText(QCoreApplication::translate("MovieTracker", "select color:", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("MovieTracker", "Yellow", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("MovieTracker", "Red", nullptr));
        comboBox->setItemText(2, QCoreApplication::translate("MovieTracker", "Green", nullptr));
        comboBox->setItemText(3, QCoreApplication::translate("MovieTracker", "Blue", nullptr));

        pushButton_3->setText(QCoreApplication::translate("MovieTracker", "Switch page", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MovieTracker", "Delete selected", nullptr));
        menuFile->setTitle(QCoreApplication::translate("MovieTracker", "File", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MovieTracker: public Ui_MovieTracker {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MOVIETRACKER_H
