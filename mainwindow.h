#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class QLabel;
class QLineEdit;
class QPushButton;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow();

private:
    QLabel* leftTermLabel;
    QLabel* operationLabel;
    QLabel* rightTermLabel;
    QLabel* equalsLabel;
    QLineEdit* resultLineEdit;
    QPushButton* checkButton;
    QLabel* resultLabel;
};

#endif  // MAINWINDOW_H
