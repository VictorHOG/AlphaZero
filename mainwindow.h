#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QLabel>
#include <QLineEdit>
#include <QMainWindow>
#include <QPushButton>

#include <vector>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);

    void displayMainMenu();
    void drawGUI();

    bool validarItems();

public slots:
    void start();

private:
    QFrame *leftPanel;
    QFrame *chessBoardPanel;
    QFrame *rightPanel;

    QLabel *titleText;
    QLabel *itemsText;
    QLineEdit *itemsLine;
    QPushButton *playButton;
    QPushButton *quitButton;



    int cantidadItems;
  //  vector < vector <int> > tablero;
};

#endif // MAINWINDOW_H
