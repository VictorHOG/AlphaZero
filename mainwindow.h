#ifndef MAINWINDOW_H
#define MAINWINDOW_H


#include <QGridLayout>

#include <QLabel>
#include <QLineEdit>
#include <QMainWindow>
#include <QPushButton>

#include <vector>
using namespace std;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);

    void drawChessBoard();
    void displayMainMenu();
    void drawGUI();
    void drawObjects();

    bool validarItems();
    void inicializarTablero();

public slots:
    void start();
    void labelClicked();

private:
    QFrame *leftPanel;
    QFrame *chessBoardPanel;
    QFrame *rightPanel;

    QVBoxLayout *leftLayout;
    QGridLayout *chessBoardLayout;
    QVBoxLayout *rightLayout;

    QLabel *titleText;
    QLabel *itemsText;
    QLineEdit *itemsLine;
    QPushButton *playButton;
    QPushButton *quitButton;

    int cantidadItems;
    vector < vector <int> > tablero;
};

#endif // MAINWINDOW_H
