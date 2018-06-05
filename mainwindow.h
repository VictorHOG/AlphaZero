/*
* CARLOS FELIPE MONTOYA - 1535038
* DIANA MELISSA MILLARES - 1526062
* VICTOR HUGO ORTEGA - 1532342
*/
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "clickablelabel.h"
#include <nodo.h>
#include <cstdlib>
#include <unistd.h>
#include <QGridLayout>

#include <QLabel>
#include <QLineEdit>
#include <QMainWindow>
#include <QPushButton>

#include <vector>

#include <utility>
using namespace std;
typedef pair<int,int> ii;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);

    void drawChessBoard();
    void displayMainMenu();
    void drawGUI();
    void drawObjects();
    void validarJugadaBlanco(int posX, int posY, nodo &jugada, nodo &mejorNodo);
    void validarJugadaNegro(int posX, int posY, nodo &jugada, nodo &mejorNodo);
    nodo minimax(vector < vector <int> > tablero, int manzanasBlanco, int manzanasNegro);
    int busquedaMax(vector < vector <int> > tablero, int manzanasBlanco, int manzanasNegro, int profundidad);
    int busquedaMin(vector < vector <int> > tablero, int manzanasBlanco, int manzanasNegro, int profundidad);
    void validarTurno();
    bool validarItems();
    void inicializarTablero();
    void limpiarCasillas();
    void moverItem(int item, int posX, int posY);
    bool terminoJuego(vector < vector <int> > tablero);
    void eliminarItem(int posX, int posY);
    int puntaje(int manzanasBlanco, int manzanasNegro);

public slots:
    void start();
    void labelClicked();

private:
    vector< vector<int> > whiteVisited;

    QFrame *leftPanel;
    QFrame *chessBoardPanel;
    QFrame *rightPanel;

    QVBoxLayout *leftLayout;
    QGridLayout *chessBoardLayout;
    QVBoxLayout *rightLayout;

    ClickableLabel *blackHorseLabel;
    ClickableLabel *whiteHorseLabel;

    QLabel *titleText;
    QLabel *itemsText;
    QLineEdit *itemsLine;
    QPushButton *playButton;
    QPushButton *quitButton;

    int cantidadItems;
    vector < vector <int> > tablero;
    vector<int> positionBlack;
    vector<int> positionWhite;

    vector<ClickableLabel> apples;

    int manzanasTotales;
    int whiteApples;
    int blackApples;

    bool turno;
};

#endif // MAINWINDOW_H
