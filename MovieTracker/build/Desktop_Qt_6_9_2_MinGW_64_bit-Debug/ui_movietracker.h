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
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MovieTracker
{
public:
    QAction *actionOpen;
    QAction *actionSave;
    QWidget *centralwidget;
    QPushButton *pushButton;
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
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(30, 20, 90, 29));
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

        QMetaObject::connectSlotsByName(MovieTracker);
    } // setupUi

    void retranslateUi(QMainWindow *MovieTracker)
    {
        MovieTracker->setWindowTitle(QCoreApplication::translate("MovieTracker", "MovieTracker", nullptr));
        actionOpen->setText(QCoreApplication::translate("MovieTracker", "Open", nullptr));
        actionSave->setText(QCoreApplication::translate("MovieTracker", "Save", nullptr));
        pushButton->setText(QCoreApplication::translate("MovieTracker", "PushButton", nullptr));
        menuFile->setTitle(QCoreApplication::translate("MovieTracker", "File", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MovieTracker: public Ui_MovieTracker {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MOVIETRACKER_H
