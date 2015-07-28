#include "mainwindow.h"

#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>

MainWindow::MainWindow()
{
    QFont fontMath("Arial", 60, QFont::Bold);
    QFont fontCheckButton("Arial", 30, QFont::Bold);

    leftTermLabel = new QLabel("3");
    leftTermLabel->setFont(fontMath);
    operationLabel = new QLabel("+");
    operationLabel->setFont(fontMath);
    rightTermLabel = new QLabel("5");
    rightTermLabel->setFont(fontMath);
    equalsLabel = new QLabel("=");
    equalsLabel->setFont(fontMath);
    resultLineEdit = new QLineEdit;
    resultLineEdit->setFont(fontMath);

    checkButton = new QPushButton(tr("Check my result!"));
    checkButton->setFont(fontCheckButton);

    resultLabel = new QLabel("");

    QHBoxLayout *mathLayout = new QHBoxLayout;
    mathLayout->addWidget(leftTermLabel);
    mathLayout->addWidget(operationLabel);
    mathLayout->addWidget(rightTermLabel);
    mathLayout->addWidget(equalsLabel);
    mathLayout->addWidget(resultLineEdit);

    QVBoxLayout *totalLayout = new QVBoxLayout;
    totalLayout->addLayout(mathLayout);
    totalLayout->addWidget(checkButton);
    totalLayout->addWidget(resultLabel);

    QWidget* mainWidget = new QWidget();
    mainWidget->setLayout(totalLayout);

    setCentralWidget(mainWidget);
    setWindowTitle(tr("QSchoolIsCool: your personal school stuff trainer!"));

    //createActions();
    //createMenus();
    //createContextMenu();
    //createToolBars();
    //createStatusBar();

    //readSettings();

    //findDialog = 0;

    //setWindowIcon(QIcon(":/images/icon.png"));
    //setCurrentFile("");
}
