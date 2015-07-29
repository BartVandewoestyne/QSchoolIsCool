#include "mainwindow.h"

#include <QAction>
#include <QDebug>
#include <QLabel>
#include <QMenu>
#include <QMenuBar>
#include <QMessageBox>
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
    connect(checkButton, SIGNAL(clicked()), this, SLOT(handleCheckButtonPressed()));

    resultLabel = new QLabel(tr("Press the check button to check your result..."));
    resultLabel->setFont(fontCheckButton);
    resultLabel->setAlignment(Qt::AlignCenter);

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

    createActions();
    createMenus();
    //createContextMenu();
    //createToolBars();
    //createStatusBar();

    //readSettings();

    //findDialog = 0;

    //setWindowIcon(QIcon(":/images/icon.png"));
    //setCurrentFile("");
}


void MainWindow::createActions()
{
    exitAction = new QAction(tr("E&xit"), this);
    exitAction->setShortcut(tr("Ctrl+Q"));
    exitAction->setStatusTip(tr("Exit the application"));
    connect(exitAction, SIGNAL(triggered()), this, SLOT(close()));

    aboutAction = new QAction(tr("&About"), this);
    //aboutAction->setStatusTip(tr("Show the application's About box"));
    connect(aboutAction, SIGNAL(triggered()), this, SLOT(about()));
}


void MainWindow::createMenus()
{
    fileMenu = menuBar()->addMenu(tr("&File"));
    fileMenu->addAction(exitAction);

    helpMenu = menuBar()->addMenu(tr("&Help"));
    helpMenu->addAction(aboutAction);
}

void MainWindow::about()
{
     QMessageBox::about(this, tr("About QSchoolIsCool"),
            tr("<h2>QSchoolIsCool 0.0</h2>"
               "<p>Copyright &copy; 2015 Bart Vandewoestyne"
               "<p>QSchoolIsCool is the personal school trainer "
               "for your kids that you've always have been dreaming of!"));
}

void MainWindow::handleCheckButtonPressed()
{
    int op1 = (leftTermLabel->text()).toInt();
    int op2 = (rightTermLabel->text()).toInt();
    int userResult = (resultLineEdit->text()).toInt();
    
    if (op1 + op2 == userResult)
    {
        resultLabel->setText(tr("Correct!"));
    }
    else
    {
        resultLabel->setText(tr("Wrong! %1 + %2 = %3").arg(op1).arg(op2).arg(op1+op2));
    }

    const int maxInt = 10;
    op1 = qrand() % maxInt;
    op2 = qrand() % maxInt;
    leftTermLabel->setText(QString::number(op1));
    rightTermLabel->setText(QString::number(op2));

    resultLineEdit->clear();
}

