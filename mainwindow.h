#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class QAction;
class QLabel;
class QLineEdit;
class QMenu;
class QPushButton;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow();

    void createActions();
    void createMenus();

private slots:
    void about();
    void handleCheckButtonPressed();
    QChar createRandomOperationChar();

private:

    static const int MAX_OPERAND_VALUE = 10;

    QChar operationChar;

    QLabel* leftTermLabel;
    QLabel* operationLabel;
    QLabel* rightTermLabel;
    QLabel* equalsLabel;
    QLineEdit* resultLineEdit;
    QPushButton* checkButton;
    QLabel* resultLabel;
    
    QMenu* fileMenu;
    QMenu* helpMenu;
    QAction* exitAction;
    QAction* aboutAction;
};

#endif  // MAINWINDOW_H
