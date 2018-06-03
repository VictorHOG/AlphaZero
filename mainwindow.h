#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QLabel>
#include <QLineEdit>
#include <QMainWindow>
#include <QPushButton>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);

    void displayMainMenu();

    bool validarItems();

public slots:
    void start();

private:
    QLabel *titleText;
    QLabel *itemsText;
    QLineEdit *itemsLine;
    QPushButton *playButton;
    QPushButton *quitButton;
};

#endif // MAINWINDOW_H
