/*
* CARLOS FELIPE MONTOYA - 1535038
* DIANA MELISSA MILLARES - 1526062
* VICTOR HUGO ORTEGA - 1532342
*/
#include "mainwindow.h"


#include <stdlib.h>
#include <time.h>
#include <iostream>
using namespace std;

#include <QIntValidator>
#include <QMessageBox>

#define HORSEBLACK 0
#define HORSEWHITE 1

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
    setFixedSize(1024,768);
    displayMainMenu();
    turno = HORSEWHITE;
}

void MainWindow::moverItem(int item, int posX, int posY){
    if(item == 2){
        chessBoardLayout->addWidget(blackHorseLabel, posX, posY);
    }else if(item == 3){
        chessBoardLayout->addWidget(whiteHorseLabel, posX, posY);
    }
}

void MainWindow::eliminarItem(int posX, int posY){
    //cout << "Manzanas " << manzanasTotales << endl;
    for(int i = 36 ; i <= 36+manzanasTotales; i++){
        QLayoutItem *item = chessBoardLayout->itemAt(i);
        QWidget* widget = item->widget();
        ClickableLabel* label = dynamic_cast<ClickableLabel*>(widget);
        //cout << "Pos " << label->getPosX() << " " << label->getposY() << endl;
        if(label->getPosX() == posX && label->getposY() == posY){

            label->setVisible(false);
        }
    }
}

void MainWindow::limpiarCasillas(){
    int posXBlackHorse, posYBlackHorse;
    posXBlackHorse = positionBlack[0];
    posYBlackHorse = positionBlack[1];

    if(posXBlackHorse - 1 >= 0 && posYBlackHorse - 2 >= 0 && tablero[posXBlackHorse-1][posYBlackHorse-2] != 2){
        QLayoutItem *item = chessBoardLayout->itemAtPosition(posXBlackHorse-1, posYBlackHorse-2);
        QWidget* widget = item->widget();
        ClickableLabel* label = dynamic_cast<ClickableLabel*>(widget);
        if(((posXBlackHorse-1)+(posYBlackHorse-2)) % 2)
            label->setStyleSheet("QLabel { background-color : darkGray }");
        else
            label->setStyleSheet("QLabel { background-color : lightGray }");
    }

    if(posXBlackHorse - 1 >= 0 && posYBlackHorse + 2 < 6 && tablero[posXBlackHorse-1][posYBlackHorse+2] != 2){
        QLayoutItem *item = chessBoardLayout->itemAtPosition(posXBlackHorse-1, posYBlackHorse+2);
        QWidget* widget = item->widget();
        ClickableLabel* label = dynamic_cast<ClickableLabel*>(widget);
        if(((posXBlackHorse-1)+(posYBlackHorse+2)) % 2)
            label->setStyleSheet("QLabel { background-color : darkGray }");
        else
            label->setStyleSheet("QLabel { background-color : lightGray }");
    }

    if(posXBlackHorse + 1 < 6 && posYBlackHorse - 2 >= 0 && tablero[posXBlackHorse+1][posYBlackHorse-2] != 2){
        QLayoutItem *item = chessBoardLayout->itemAtPosition(posXBlackHorse+1, posYBlackHorse-2);
        QWidget* widget = item->widget();
        ClickableLabel* label = dynamic_cast<ClickableLabel*>(widget);
        if(((posXBlackHorse+1)+(posYBlackHorse-2)) % 2)
            label->setStyleSheet("QLabel { background-color : darkGray }");
        else
            label->setStyleSheet("QLabel { background-color : lightGray }");
    }

    if(posXBlackHorse + 1 < 6 && posYBlackHorse + 2 < 6 && tablero[posXBlackHorse+1][posYBlackHorse+2] != 2){
        QLayoutItem *item = chessBoardLayout->itemAtPosition(posXBlackHorse+1, posYBlackHorse+2);
        QWidget* widget = item->widget();
        ClickableLabel* label = dynamic_cast<ClickableLabel*>(widget);
        if(((posXBlackHorse+1)+(posYBlackHorse+2)) % 2)
            label->setStyleSheet("QLabel { background-color : darkGray }");
        else
            label->setStyleSheet("QLabel { background-color : lightGray }");
    }

    if(posXBlackHorse - 2 >= 0 && posYBlackHorse - 1 >= 0 && tablero[posXBlackHorse-2][posYBlackHorse-1] != 2){
        QLayoutItem *item = chessBoardLayout->itemAtPosition(posXBlackHorse-2, posYBlackHorse-1);
        QWidget* widget = item->widget();
        ClickableLabel* label = dynamic_cast<ClickableLabel*>(widget);
        if(((posXBlackHorse-2)+(posYBlackHorse-1)) % 2)
            label->setStyleSheet("QLabel { background-color : darkGray }");
        else
            label->setStyleSheet("QLabel { background-color : lightGray }");
    }

    if(posXBlackHorse - 2 >= 0 && posYBlackHorse + 1 < 6 && tablero[posXBlackHorse-2][posYBlackHorse+1] != 2){
        QLayoutItem *item = chessBoardLayout->itemAtPosition(posXBlackHorse-2, posYBlackHorse+1);
        QWidget* widget = item->widget();
        ClickableLabel* label = dynamic_cast<ClickableLabel*>(widget);
        if(((posXBlackHorse-2)+(posYBlackHorse+1)) % 2)
            label->setStyleSheet("QLabel { background-color : darkGray }");
        else
            label->setStyleSheet("QLabel { background-color : lightGray }");
    }

    if(posXBlackHorse + 2 < 6 && posYBlackHorse - 1 >= 0 && tablero[posXBlackHorse+2][posYBlackHorse-1] != 2){
        QLayoutItem *item = chessBoardLayout->itemAtPosition(posXBlackHorse+2, posYBlackHorse-1);
        QWidget* widget = item->widget();
        ClickableLabel* label = dynamic_cast<ClickableLabel*>(widget);
        if(((posXBlackHorse+2)+(posYBlackHorse-1)) % 2)
            label->setStyleSheet("QLabel { background-color : darkGray }");
        else
            label->setStyleSheet("QLabel { background-color : lightGray }");
    }

    if(posXBlackHorse + 2 < 6 && posYBlackHorse + 1 < 6 && tablero[posXBlackHorse+2][posYBlackHorse+1] != 2){
        QLayoutItem *item = chessBoardLayout->itemAtPosition(posXBlackHorse+2, posYBlackHorse+1);
        QWidget* widget = item->widget();
        ClickableLabel* label = dynamic_cast<ClickableLabel*>(widget);
        if(((posXBlackHorse+2)+(posYBlackHorse+1)) % 2)
            label->setStyleSheet("QLabel { background-color : darkGray }");
        else
            label->setStyleSheet("QLabel { background-color : lightGray }");
    }
}

void MainWindow::labelClicked(){
    ClickableLabel * clickedLabel = qobject_cast<ClickableLabel*>(sender()); // retrieve the button you have clicked
    int posX = clickedLabel->getPosX();
    int posY = clickedLabel->getposY();

    if(tablero[posX][posY] == 3){
        return;
    }

    if( (posX == positionBlack[0]-1 && posY == positionBlack[1]-2) || (posX == positionBlack[0]-1 && posY == positionBlack[1]+2) ||
            (posX == positionBlack[0]+1 && posY == positionBlack[1]-2) || (posX == positionBlack[0]+1 && posY == positionBlack[1]+2) ||
                (posX == positionBlack[0]-2 && posY == positionBlack[1]-1) || (posX == positionBlack[0]-2 && posY == positionBlack[1]+1) ||
                    (posX == positionBlack[0]+2 && posY == positionBlack[1]-1) || (posX == positionBlack[0]+2 && posY == positionBlack[1]+1) ){
        limpiarCasillas();
        tablero[positionBlack[0]][positionBlack[1]] = 0;
        positionBlack[0] = posX;
        positionBlack[1] = posY;
        if(tablero[posX][posY] == 1){
            blackApples++;
            eliminarItem(posX,posY);
        }
        tablero[posX][posY] = 2;
        moverItem(2,posX,posY);
        turno = HORSEWHITE;
        if(terminoJuego(tablero)){
            if(puntaje(whiteApples,blackApples) > 0){
                QMessageBox msgBox;
                msgBox.setText("Ganó Blanco");
                msgBox.setWindowTitle("Message");
                msgBox.exec();
                itemsLine->clear();
            }else{
                QMessageBox msgBox;
                msgBox.setText("Ganó Negro");
                msgBox.setWindowTitle("Message");
                msgBox.exec();
                itemsLine->clear();
            }
            chessBoardPanel->hide();
            leftPanel->hide();
            rightPanel->hide();
            displayMainMenu();
            return;
        }
        validarTurno();
    }
}

void MainWindow::drawChessBoard(){

    for (int i = 0, k = 0; i < 6; ++i) {
        for (int j = 0; j < 6; ++j, k++) {

            ClickableLabel *label = new ClickableLabel();

            if((i+j)%2==0)
                label->setStyleSheet("QLabel { background-color : lightGray }");
            else
                label->setStyleSheet("QLabel { background-color : darkGray }");

            label->setPosX(i);
            label->setposY(j);

            connect(label,SIGNAL(clicked()) , this , SLOT(labelClicked()));
            chessBoardLayout->addWidget(label, i, j);

        }
    }
}

void MainWindow::inicializarTablero(){

    bool black = true;
    bool white = true;

    srand(time(NULL));
    tablero.assign(6, vector<int>(6));
    positionBlack.assign(2,0);
    positionWhite.assign(2,0);

    for (int i = 0; i < 6; ++i) {
        for (int j = 0; j < 6; ++j) {
            tablero[i][j] = 0;
        }
    }

    for (int i = 0; i < cantidadItems+2; ++i) {

        int posX = rand()%6;
        int posY = rand()%6;

        if (black && tablero[posX][posY] == 0){
            black= false;
            tablero[posX][posY] = 2;
            positionBlack[0] = posX;
            positionBlack[1] = posY;
            i++;
        }

        if (white && tablero[posX][posY] == 0){
            white= false;
            tablero[posX][posY] = 3;
            positionWhite[0] = posX;
            positionWhite[1] = posY;
            i++;
        }

        if (tablero[posX][posY] == 1 || tablero[posX][posY] == 2|| tablero[posX][posY] == 3)
            i--;
        else
            tablero[posX][posY] = 1;
    }

    for (int i = 0; i < 6; ++i) {
        for (int j = 0; j < 6; ++j) {
            cout << tablero[i][j] << " ";
        }
        cout << endl;
    }

}

void MainWindow::drawObjects(){

    QPixmap blackHorse(":/images/blackHorse.png");
    QPixmap whiteHorse(":/images/whiteHorse.png");
    QPixmap item(":/images/apple.png");

    blackHorseLabel = new ClickableLabel();
    blackHorseLabel->setPixmap(blackHorse);
    connect(blackHorseLabel,SIGNAL(clicked()) , this , SLOT(labelClicked()));

    whiteHorseLabel = new ClickableLabel();
    whiteHorseLabel->setPixmap(whiteHorse);
    connect(whiteHorseLabel,SIGNAL(clicked()) , this , SLOT(labelClicked()));

   // chessBoardLayout->addWidget(blackHorseLabel, 0, 0);
   // chessBoardLayout->addWidget(whiteHorseLabel, 3, 3);
   // chessBoardLayout->addWidget(itemLabel, 5, 5);

    for (int i = 0; i < 6; ++i) {
        for (int j = 0; j < 6; ++j) {

            if (tablero[i][j] == 1) {
                ClickableLabel *itemLabel = new ClickableLabel();
                itemLabel->setPosX(i);
                itemLabel->setposY(j);
                itemLabel->setPixmap(item);
                connect(itemLabel,SIGNAL(clicked()) , this , SLOT(labelClicked()));
                chessBoardLayout->addWidget(itemLabel, i, j);
            }else if (tablero[i][j] == 2){
                blackHorseLabel->setPosX(i);
                blackHorseLabel->setposY(j);
                chessBoardLayout->addWidget(blackHorseLabel, i, j);
            } else if (tablero[i][j] == 3){
                whiteHorseLabel->setPosX(i);
                whiteHorseLabel->setposY(j);
                chessBoardLayout->addWidget(whiteHorseLabel, i, j);
            }
        }
    }
}

bool MainWindow::terminoJuego(vector< vector <int> > tablero){
    for(int i = 0; i < 6; i++){
        for(int j = 0; j < 6; j++){
            if(tablero[i][j] == 1){
                return false;
            }
        }
    }
    return true;
}

int MainWindow::puntaje(int manzanasBlanco, int manzanasNegro){
   return manzanasBlanco - manzanasNegro;
}


nodo MainWindow::minimax(vector< vector<int> > tablero, int manzanasBlanco, int manzanasNegro){
    int mejorMovimiento = -100;
    nodo movimiento;

    int posXWhite, dx;
    int posYWhite, dy;

    int profundidad = 0;

    for(int i = 0; i < 6; i++){
        for(int j = 0; j < 6; j++){
            if(tablero[i][j] == 3){
                posXWhite = i;
                posYWhite = j;
                i = 6;
                break;
            }
        }
    }

    //cout << "Estoy en " << posXWhite << " " << posYWhite << " con P " << profundidad << endl;

    dx = -1;
    dy = -2;

    if(posXWhite+dx >= 0 && posXWhite+dx < 6 && posYWhite+dy>=0 && posYWhite+dy < 6 && tablero[posXWhite+dx][posYWhite+dy] != 2){
        int aux = tablero[posXWhite+dx][posYWhite+dy];
        tablero[posXWhite][posYWhite] = 0;
        if(tablero[posXWhite+dx][posYWhite+dy] == 1){
            manzanasBlanco++;
        }
        tablero[posXWhite+dx][posYWhite+dy] = 3;
        //cout << "Nos movemos a " << posXWhite+dx << " " << posYWhite+dy << endl;
        int valor = busquedaMin(tablero,manzanasBlanco,manzanasNegro,profundidad+1);
        //cout << "Valor " << valor << endl;
        if(valor >= mejorMovimiento){
            mejorMovimiento = valor;
            movimiento.posXBlanco = posXWhite+dx;
            movimiento.posYBlanco = posYWhite+dy;
        }
        tablero[posXWhite+dx][posYWhite+dy] = aux;
        tablero[posXWhite][posYWhite] = 3;
        if(tablero[posXWhite+dx][posYWhite+dy] == 1){
            manzanasBlanco--;
        }
    }

    dx = -1;
    dy = +2;

    if(posXWhite+dx >= 0 && posXWhite+dx < 6 && posYWhite+dy>=0 && posYWhite+dy < 6 && tablero[posXWhite+dx][posYWhite+dy] != 2){
        int aux = tablero[posXWhite+dx][posYWhite+dy];
        tablero[posXWhite][posYWhite] = 0;
        if(tablero[posXWhite+dx][posYWhite+dy] == 1){
            manzanasBlanco++;
        }
        tablero[posXWhite+dx][posYWhite+dy] = 3;
        int valor = busquedaMin(tablero,manzanasBlanco,manzanasNegro,profundidad+1);
        //cout << "Valor " << valor << endl;
        if(valor >= mejorMovimiento){
            mejorMovimiento = valor;
            movimiento.posXBlanco = posXWhite+dx;
            movimiento.posYBlanco = posYWhite+dy;
        }
        tablero[posXWhite+dx][posYWhite+dy] = aux;
        tablero[posXWhite][posYWhite] = 3;
        if(tablero[posXWhite+dx][posYWhite+dy] == 1){
            manzanasBlanco--;
        }
    }

    dx = +1;
    dy = -2;

    if(posXWhite+dx >= 0 && posXWhite+dx < 6 && posYWhite+dy>=0 && posYWhite+dy < 6 && tablero[posXWhite+dx][posYWhite+dy] != 2){
        int aux = tablero[posXWhite+dx][posYWhite+dy];
        tablero[posXWhite][posYWhite] = 0;
        if(tablero[posXWhite+dx][posYWhite+dy] == 1){
            manzanasBlanco++;
        }
        tablero[posXWhite+dx][posYWhite+dy] = 3;
        int valor = busquedaMin(tablero,manzanasBlanco,manzanasNegro,profundidad+1);
        //cout << "Valor " << valor << endl;
        if(valor >= mejorMovimiento){
            mejorMovimiento = valor;
            movimiento.posXBlanco = posXWhite+dx;
            movimiento.posYBlanco = posYWhite+dy;
        }
        tablero[posXWhite+dx][posYWhite+dy] = aux;
        tablero[posXWhite][posYWhite] = 3;
        if(tablero[posXWhite+dx][posYWhite+dy] == 1){
            manzanasBlanco--;
        }
    }

    dx = +1;
    dy = +2;

    if(posXWhite+dx >= 0 && posXWhite+dx < 6 && posYWhite+dy>=0 && posYWhite+dy < 6 && tablero[posXWhite+dx][posYWhite+dy] != 2){
        int aux = tablero[posXWhite+dx][posYWhite+dy];
        tablero[posXWhite][posYWhite] = 0;
        if(tablero[posXWhite+dx][posYWhite+dy] == 1){
            manzanasBlanco++;
        }
        tablero[posXWhite+dx][posYWhite+dy] = 3;
        int valor = busquedaMin(tablero,manzanasBlanco,manzanasNegro,profundidad+1);
        //cout << "Valor " << valor << endl;
        if(valor >= mejorMovimiento){
            mejorMovimiento = valor;
            movimiento.posXBlanco = posXWhite+dx;
            movimiento.posYBlanco = posYWhite+dy;
        }
        tablero[posXWhite+dx][posYWhite+dy] = aux;
        tablero[posXWhite][posYWhite] = 3;
        if(tablero[posXWhite+dx][posYWhite+dy] == 1){
            manzanasBlanco--;
        }
    }

    dx = -2;
    dy = -1;

    if(posXWhite+dx >= 0 && posXWhite+dx < 6 && posYWhite+dy>=0 && posYWhite+dy < 6 && tablero[posXWhite+dx][posYWhite+dy] != 2){
        int aux = tablero[posXWhite+dx][posYWhite+dy];
        tablero[posXWhite][posYWhite] = 0;
        if(tablero[posXWhite+dx][posYWhite+dy] == 1){
            manzanasBlanco++;
        }
        tablero[posXWhite+dx][posYWhite+dy] = 3;
        int valor = busquedaMin(tablero,manzanasBlanco,manzanasNegro,profundidad+1);
        //cout << "Valor " << valor << endl;
        if(valor >= mejorMovimiento){
            mejorMovimiento = valor;
            movimiento.posXBlanco = posXWhite+dx;
            movimiento.posYBlanco = posYWhite+dy;
        }
        tablero[posXWhite+dx][posYWhite+dy] = aux;
        tablero[posXWhite][posYWhite] = 3;
        if(tablero[posXWhite+dx][posYWhite+dy] == 1){
            manzanasBlanco--;
        }
    }

    dx = -2;
    dy = +1;

    if(posXWhite+dx >= 0 && posXWhite+dx < 6 && posYWhite+dy>=0 && posYWhite+dy < 6 && tablero[posXWhite+dx][posYWhite+dy] != 2){
        int aux = tablero[posXWhite+dx][posYWhite+dy];
        tablero[posXWhite][posYWhite] = 0;
        if(tablero[posXWhite+dx][posYWhite+dy] == 1){
            manzanasBlanco++;
        }
        tablero[posXWhite+dx][posYWhite+dy] = 3;
        int valor = busquedaMin(tablero,manzanasBlanco,manzanasNegro,profundidad+1);
        //cout << "Valor " << valor << endl;
        if(valor >= mejorMovimiento){
            mejorMovimiento = valor;
            movimiento.posXBlanco = posXWhite+dx;
            movimiento.posYBlanco = posYWhite+dy;
        }
        tablero[posXWhite+dx][posYWhite+dy] = aux;
        tablero[posXWhite][posYWhite] = 3;
        if(tablero[posXWhite+dx][posYWhite+dy] == 1){
            manzanasBlanco--;
        }
    }

    dx = +2;
    dy = -1;

    if(posXWhite+dx >= 0 && posXWhite+dx < 6 && posYWhite+dy>=0 && posYWhite+dy < 6 && tablero[posXWhite+dx][posYWhite+dy] != 2){
        int aux = tablero[posXWhite+dx][posYWhite+dy];
        tablero[posXWhite][posYWhite] = 0;
        if(tablero[posXWhite+dx][posYWhite+dy] == 1){
            manzanasBlanco++;
        }
        tablero[posXWhite+dx][posYWhite+dy] = 3;
        int valor = busquedaMin(tablero,manzanasBlanco,manzanasNegro,profundidad+1);
        //cout << "Valor " << valor << endl;
        if(valor >= mejorMovimiento){
            mejorMovimiento = valor;
            movimiento.posXBlanco = posXWhite+dx;
            movimiento.posYBlanco = posYWhite+dy;
        }
        tablero[posXWhite+dx][posYWhite+dy] = aux;
        tablero[posXWhite][posYWhite] = 3;
        if(tablero[posXWhite+dx][posYWhite+dy] == 1){
            manzanasBlanco--;
        }
    }

    dx = +2;
    dy = +1;

    if(posXWhite+dx >= 0 && posXWhite+dx < 6 && posYWhite+dy>=0 && posYWhite+dy < 6 && tablero[posXWhite+dx][posYWhite+dy] != 2){
        int aux = tablero[posXWhite+dx][posYWhite+dy];
        tablero[posXWhite][posYWhite] = 0;
        if(tablero[posXWhite+dx][posYWhite+dy] == 1){
            manzanasBlanco++;
        }
        tablero[posXWhite+dx][posYWhite+dy] = 3;
        int valor = busquedaMin(tablero,manzanasBlanco,manzanasNegro,profundidad+1);
        //cout << "Valor " << valor << endl;
        if(valor >= mejorMovimiento){
            mejorMovimiento = valor;
            movimiento.posXBlanco = posXWhite+dx;
            movimiento.posYBlanco = posYWhite+dy;
        }
        tablero[posXWhite+dx][posYWhite+dy] = aux;
        tablero[posXWhite][posYWhite] = 3;
        if(tablero[posXWhite+dx][posYWhite+dy] == 1){
            manzanasBlanco--;
        }
    }
    //cout << "BestMove " << mejorMovimiento << endl;
    return movimiento;
}

int MainWindow::busquedaMax(vector< vector<int> > tablero, int manzanasBlanco, int manzanasNegro, int profundidad){
    if(terminoJuego(tablero)){
        //cout << "W " << manzanasBlanco << " B " << manzanasNegro << endl;
        //cout << "Termine con profundidad" << profundidad << endl;
        return puntaje(manzanasBlanco,manzanasNegro);
    }
    if(profundidad == 8) return puntaje(manzanasBlanco,manzanasNegro);
    int mejorMovimiento = -100;
    nodo movimiento;

    int posXWhite, dx;
    int posYWhite, dy;

    for(int i = 0; i < 6; i++){
        for(int j = 0; j < 6; j++){
            if(tablero[i][j] == 3){
                posXWhite = i;
                posYWhite = j;
                i = 6;
                break;
            }
        }
    }

    dx = -1;
    dy = -2;

    if(posXWhite+dx >= 0 && posXWhite+dx < 6 && posYWhite+dy>=0 && posYWhite+dy < 6 && tablero[posXWhite+dx][posYWhite+dy] != 2){
        int aux = tablero[posXWhite+dx][posYWhite+dy];
        tablero[posXWhite][posYWhite] = 0;
        if(tablero[posXWhite+dx][posYWhite+dy] == 1){
            manzanasBlanco++;
        }
        tablero[posXWhite+dx][posYWhite+dy] = 3;
        int valor = busquedaMin(tablero,manzanasBlanco,manzanasNegro,profundidad+1);
        if(valor >= mejorMovimiento){
            mejorMovimiento = valor;
            movimiento.posXBlanco = posXWhite+dx;
            movimiento.posYBlanco = posYWhite+dy;
        }
        tablero[posXWhite+dx][posYWhite+dy] = aux;
        tablero[posXWhite][posYWhite] = 3;
        if(tablero[posXWhite+dx][posYWhite+dy] == 1){
            manzanasBlanco--;
        }
    }

    dx = -1;
    dy = +2;

    if(posXWhite+dx >= 0 && posXWhite+dx < 6 && posYWhite+dy>=0 && posYWhite+dy < 6 && tablero[posXWhite+dx][posYWhite+dy] != 2){
        int aux = tablero[posXWhite+dx][posYWhite+dy];
        tablero[posXWhite][posYWhite] = 0;
        if(tablero[posXWhite+dx][posYWhite+dy] == 1){
            manzanasBlanco++;
        }
        tablero[posXWhite+dx][posYWhite+dy] = 3;
        int valor = busquedaMin(tablero,manzanasBlanco,manzanasNegro,profundidad+1);
        if(valor >= mejorMovimiento){
            mejorMovimiento = valor;
            movimiento.posXBlanco = posXWhite+dx;
            movimiento.posYBlanco = posYWhite+dy;
        }
        tablero[posXWhite+dx][posYWhite+dy] = aux;
        tablero[posXWhite][posYWhite] = 3;
        if(tablero[posXWhite+dx][posYWhite+dy] == 1){
            manzanasBlanco--;
        }
    }

    dx = +1;
    dy = -2;

    if(posXWhite+dx >= 0 && posXWhite+dx < 6 && posYWhite+dy>=0 && posYWhite+dy < 6 && tablero[posXWhite+dx][posYWhite+dy] != 2){
        int aux = tablero[posXWhite+dx][posYWhite+dy];
        tablero[posXWhite][posYWhite] = 0;
        if(tablero[posXWhite+dx][posYWhite+dy] == 1){
            manzanasBlanco++;
        }
        tablero[posXWhite+dx][posYWhite+dy] = 3;
        int valor = busquedaMin(tablero,manzanasBlanco,manzanasNegro,profundidad+1);
        if(valor >= mejorMovimiento){
            mejorMovimiento = valor;
            movimiento.posXBlanco = posXWhite+dx;
            movimiento.posYBlanco = posYWhite+dy;
        }
        tablero[posXWhite+dx][posYWhite+dy] = aux;
        tablero[posXWhite][posYWhite] = 3;
        if(tablero[posXWhite+dx][posYWhite+dy] == 1){
            manzanasBlanco--;
        }
    }

    dx = +1;
    dy = +2;

    if(posXWhite+dx >= 0 && posXWhite+dx < 6 && posYWhite+dy>=0 && posYWhite+dy < 6 && tablero[posXWhite+dx][posYWhite+dy] != 2){
        int aux = tablero[posXWhite+dx][posYWhite+dy];
        tablero[posXWhite][posYWhite] = 0;
        if(tablero[posXWhite+dx][posYWhite+dy] == 1){
            manzanasBlanco++;
        }
        tablero[posXWhite+dx][posYWhite+dy] = 3;
        int valor = busquedaMin(tablero,manzanasBlanco,manzanasNegro,profundidad+1);
        if(valor >= mejorMovimiento){
            mejorMovimiento = valor;
            movimiento.posXBlanco = posXWhite+dx;
            movimiento.posYBlanco = posYWhite+dy;
        }
        tablero[posXWhite+dx][posYWhite+dy] = aux;
        tablero[posXWhite][posYWhite] = 3;
        if(tablero[posXWhite+dx][posYWhite+dy] == 1){
            manzanasBlanco--;
        }
    }

    dx = -2;
    dy = -1;

    if(posXWhite+dx >= 0 && posXWhite+dx < 6 && posYWhite+dy>=0 && posYWhite+dy < 6 && tablero[posXWhite+dx][posYWhite+dy] != 2){
        int aux = tablero[posXWhite+dx][posYWhite+dy];
        tablero[posXWhite][posYWhite] = 0;
        if(tablero[posXWhite+dx][posYWhite+dy] == 1){
            manzanasBlanco++;
        }
        tablero[posXWhite+dx][posYWhite+dy] = 3;
        int valor = busquedaMin(tablero,manzanasBlanco,manzanasNegro,profundidad+1);
        if(valor >= mejorMovimiento){
            mejorMovimiento = valor;
            movimiento.posXBlanco = posXWhite+dx;
            movimiento.posYBlanco = posYWhite+dy;
        }
        tablero[posXWhite+dx][posYWhite+dy] = aux;
        tablero[posXWhite][posYWhite] = 3;
        if(tablero[posXWhite+dx][posYWhite+dy] == 1){
            manzanasBlanco--;
        }
    }

    dx = -2;
    dy = +1;

    if(posXWhite+dx >= 0 && posXWhite+dx < 6 && posYWhite+dy>=0 && posYWhite+dy < 6 && tablero[posXWhite+dx][posYWhite+dy] != 2){
        int aux = tablero[posXWhite+dx][posYWhite+dy];
        tablero[posXWhite][posYWhite] = 0;
        if(tablero[posXWhite+dx][posYWhite+dy] == 1){
            manzanasBlanco++;
        }
        tablero[posXWhite+dx][posYWhite+dy] = 3;
        int valor = busquedaMin(tablero,manzanasBlanco,manzanasNegro,profundidad+1);
        if(valor >= mejorMovimiento){
            mejorMovimiento = valor;
            movimiento.posXBlanco = posXWhite+dx;
            movimiento.posYBlanco = posYWhite+dy;
        }
        tablero[posXWhite+dx][posYWhite+dy] = aux;
        tablero[posXWhite][posYWhite] = 3;
        if(tablero[posXWhite+dx][posYWhite+dy] == 1){
            manzanasBlanco--;
        }
    }

    dx = +2;
    dy = -1;

    if(posXWhite+dx >= 0 && posXWhite+dx < 6 && posYWhite+dy>=0 && posYWhite+dy < 6 && tablero[posXWhite+dx][posYWhite+dy] != 2){
        int aux = tablero[posXWhite+dx][posYWhite+dy];
        tablero[posXWhite][posYWhite] = 0;
        if(tablero[posXWhite+dx][posYWhite+dy] == 1){
            manzanasBlanco++;
        }
        tablero[posXWhite+dx][posYWhite+dy] = 3;
        int valor = busquedaMin(tablero,manzanasBlanco,manzanasNegro,profundidad+1);
        if(valor >= mejorMovimiento){
            mejorMovimiento = valor;
            movimiento.posXBlanco = posXWhite+dx;
            movimiento.posYBlanco = posYWhite+dy;
        }
        tablero[posXWhite+dx][posYWhite+dy] = aux;
        tablero[posXWhite][posYWhite] = 3;
        if(tablero[posXWhite+dx][posYWhite+dy] == 1){
            manzanasBlanco--;
        }
    }

    dx = +2;
    dy = +1;

    if(posXWhite+dx >= 0 && posXWhite+dx < 6 && posYWhite+dy>=0 && posYWhite+dy < 6 && tablero[posXWhite+dx][posYWhite+dy] != 2){
        int aux = tablero[posXWhite+dx][posYWhite+dy];
        tablero[posXWhite][posYWhite] = 0;
        if(tablero[posXWhite+dx][posYWhite+dy] == 1){
            manzanasBlanco++;
        }
        tablero[posXWhite+dx][posYWhite+dy] = 3;
        int valor = busquedaMin(tablero,manzanasBlanco,manzanasNegro,profundidad+1);
        if(valor >= mejorMovimiento){
            mejorMovimiento = valor;
            movimiento.posXBlanco = posXWhite+dx;
            movimiento.posYBlanco = posYWhite+dy;
        }
        tablero[posXWhite+dx][posYWhite+dy] = aux;
        tablero[posXWhite][posYWhite] = 3;
        if(tablero[posXWhite+dx][posYWhite+dy] == 1){
            manzanasBlanco--;
        }
    }

    return mejorMovimiento;
}

int MainWindow::busquedaMin(vector< vector<int> > tablero, int manzanasBlanco, int manzanasNegro, int profundidad){
    if(terminoJuego(tablero)){
        //cout << "W " << manzanasBlanco << " B " << manzanasNegro << endl;
        //cout << "Termine con profundidad" << profundidad << endl;
        return puntaje(manzanasBlanco, manzanasNegro);
    }
    if(profundidad == 8) return puntaje(manzanasBlanco,manzanasNegro);
    int mejorMovimiento = 100;
    nodo movimiento;

    int posXBlack, dx;
    int posYBlack, dy;

    for(int i = 0; i < 6; i++){
        for(int j = 0; j < 6; j++){
            if(tablero[i][j] == 2){
                posXBlack = i;
                posYBlack = j;
                i = 6;
                break;
            }
        }
    }

    dx = -1;
    dy = -2;

    if(posXBlack+dx >= 0 && posXBlack+dx < 6 && posYBlack+dy>=0 && posYBlack+dy < 6 && tablero[posXBlack+dx][posYBlack+dy] != 3){
        int aux = tablero[posXBlack+dx][posYBlack+dy];
        tablero[posXBlack][posYBlack] = 0;
        if(tablero[posXBlack+dx][posYBlack+dy] == 1){
            manzanasNegro++;
        }
        tablero[posXBlack+dx][posYBlack+dy] = 2;
        int valor = busquedaMax(tablero,manzanasBlanco,manzanasNegro,profundidad+1);
        if(valor <= mejorMovimiento){
            mejorMovimiento = valor;
            movimiento.posXBlanco = posXBlack+dx;
            movimiento.posYBlanco = posYBlack+dy;
        }
        tablero[posXBlack+dx][posYBlack+dy] = aux;
        tablero[posXBlack][posYBlack] = 2;
        if(tablero[posXBlack+dx][posYBlack+dy] == 1){
            manzanasNegro--;
        }
    }

    dx = -1;
    dy = +2;

    if(posXBlack+dx >= 0 && posXBlack+dx < 6 && posYBlack+dy>=0 && posYBlack+dy < 6 && tablero[posXBlack+dx][posYBlack+dy] != 3){
        int aux = tablero[posXBlack+dx][posYBlack+dy];
        tablero[posXBlack][posYBlack] = 0;
        if(tablero[posXBlack+dx][posYBlack+dy] == 1){
            manzanasNegro++;
        }
        tablero[posXBlack+dx][posYBlack+dy] = 3;
        int valor = busquedaMax(tablero,manzanasBlanco,manzanasNegro,profundidad+1);
        if(valor <= mejorMovimiento){
            mejorMovimiento = valor;
            movimiento.posXBlanco = posXBlack+dx;
            movimiento.posYBlanco = posYBlack+dy;
        }
        tablero[posXBlack+dx][posYBlack+dy] = aux;
        tablero[posXBlack][posYBlack] = 3;
        if(tablero[posXBlack+dx][posYBlack+dy] == 1){
            manzanasNegro--;
        }
    }

    dx = +1;
    dy = -2;

    if(posXBlack+dx >= 0 && posXBlack+dx < 6 && posYBlack+dy>=0 && posYBlack+dy < 6 && tablero[posXBlack+dx][posYBlack+dy] != 3){
        int aux = tablero[posXBlack+dx][posYBlack+dy];
        tablero[posXBlack][posYBlack] = 0;
        if(tablero[posXBlack+dx][posYBlack+dy] == 1){
            manzanasNegro++;
        }
        tablero[posXBlack+dx][posYBlack+dy] = 2;
        int valor = busquedaMax(tablero,manzanasBlanco,manzanasNegro,profundidad+1);
        if(valor <= mejorMovimiento){
            mejorMovimiento = valor;
            movimiento.posXBlanco = posXBlack+dx;
            movimiento.posYBlanco = posYBlack+dy;
        }
        tablero[posXBlack+dx][posYBlack+dy] = aux;
        tablero[posXBlack][posYBlack] = 2;
        if(tablero[posXBlack+dx][posYBlack+dy] == 1){
            manzanasNegro--;
        }
    }

    dx = +1;
    dy = +2;

    if(posXBlack+dx >= 0 && posXBlack+dx < 6 && posYBlack+dy>=0 && posYBlack+dy < 6 && tablero[posXBlack+dx][posYBlack+dy] != 3){
        int aux = tablero[posXBlack+dx][posYBlack+dy];
        tablero[posXBlack][posYBlack] = 0;
        if(tablero[posXBlack+dx][posYBlack+dy] == 1){
            manzanasNegro++;
        }
        tablero[posXBlack+dx][posYBlack+dy] = 2;
        int valor = busquedaMax(tablero,manzanasBlanco,manzanasNegro,profundidad+1);
        if(valor <= mejorMovimiento){
            mejorMovimiento = valor;
            movimiento.posXBlanco = posXBlack+dx;
            movimiento.posYBlanco = posYBlack+dy;
        }
        tablero[posXBlack+dx][posYBlack+dy] = aux;
        tablero[posXBlack][posYBlack] = 2;
        if(tablero[posXBlack+dx][posYBlack+dy] == 1){
            manzanasNegro--;
        }
    }

    dx = -2;
    dy = -1;

    if(posXBlack+dx >= 0 && posXBlack+dx < 6 && posYBlack+dy>=0 && posYBlack+dy < 6 && tablero[posXBlack+dx][posYBlack+dy] != 3){
        int aux = tablero[posXBlack+dx][posYBlack+dy];
        tablero[posXBlack][posYBlack] = 0;
        if(tablero[posXBlack+dx][posYBlack+dy] == 1){
            manzanasNegro++;
        }
        tablero[posXBlack+dx][posYBlack+dy] = 2;
        int valor = busquedaMax(tablero,manzanasBlanco,manzanasNegro,profundidad+1);
        if(valor <= mejorMovimiento){
            mejorMovimiento = valor;
            movimiento.posXBlanco = posXBlack+dx;
            movimiento.posYBlanco = posYBlack+dy;
        }
        tablero[posXBlack+dx][posYBlack+dy] = aux;
        tablero[posXBlack][posYBlack] = 2;
        if(tablero[posXBlack+dx][posYBlack+dy] == 1){
            manzanasNegro--;
        }
    }

    dx = -2;
    dy = +1;

    if(posXBlack+dx >= 0 && posXBlack+dx < 6 && posYBlack+dy>=0 && posYBlack+dy < 6 && tablero[posXBlack+dx][posYBlack+dy] != 3){
        int aux = tablero[posXBlack+dx][posYBlack+dy];
        tablero[posXBlack][posYBlack] = 0;
        if(tablero[posXBlack+dx][posYBlack+dy] == 1){
            manzanasNegro++;
        }
        tablero[posXBlack+dx][posYBlack+dy] = 2;
        int valor = busquedaMax(tablero,manzanasBlanco,manzanasNegro,profundidad+1);
        if(valor <= mejorMovimiento){
            mejorMovimiento = valor;
            movimiento.posXBlanco = posXBlack+dx;
            movimiento.posYBlanco = posYBlack+dy;
        }
        tablero[posXBlack+dx][posYBlack+dy] = aux;
        tablero[posXBlack][posYBlack] = 2;
        if(tablero[posXBlack+dx][posYBlack+dy] == 1){
            manzanasNegro--;
        }
    }

    dx = +2;
    dy = -1;

    if(posXBlack+dx >= 0 && posXBlack+dx < 6 && posYBlack+dy>=0 && posYBlack+dy < 6 && tablero[posXBlack+dx][posYBlack+dy] != 3){
        int aux = tablero[posXBlack+dx][posYBlack+dy];
        tablero[posXBlack][posYBlack] = 0;
        if(tablero[posXBlack+dx][posYBlack+dy] == 1){
            manzanasNegro++;
        }
        tablero[posXBlack+dx][posYBlack+dy] = 2;
        int valor = busquedaMax(tablero,manzanasBlanco,manzanasNegro,profundidad+1);
        if(valor <= mejorMovimiento){
            mejorMovimiento = valor;
            movimiento.posXBlanco = posXBlack+dx;
            movimiento.posYBlanco = posYBlack+dy;
        }
        tablero[posXBlack+dx][posYBlack+dy] = aux;
        tablero[posXBlack][posYBlack] = 2;
        if(tablero[posXBlack+dx][posYBlack+dy] == 1){
            manzanasNegro--;
        }
    }

    dx = +2;
    dy = +1;

    if(posXBlack+dx >= 0 && posXBlack+dx < 6 && posYBlack+dy>=0 && posYBlack+dy < 6 && tablero[posXBlack+dx][posYBlack+dy] != 3){
        int aux = tablero[posXBlack+dx][posYBlack+dy];
        tablero[posXBlack][posYBlack] = 0;
        if(tablero[posXBlack+dx][posYBlack+dy] == 1){
            manzanasNegro++;
        }
        tablero[posXBlack+dx][posYBlack+dy] = 2;
        int valor = busquedaMax(tablero,manzanasBlanco,manzanasNegro,profundidad+1);
        if(valor <= mejorMovimiento){
            mejorMovimiento = valor;
            movimiento.posXBlanco = posXBlack+dx;
            movimiento.posYBlanco = posYBlack+dy;
        }
        tablero[posXBlack+dx][posYBlack+dy] = aux;
        tablero[posXBlack][posYBlack] = 2;
        if(tablero[posXBlack+dx][posYBlack+dy] == 1){
            manzanasNegro--;
        }
    }

    return mejorMovimiento;
}

void MainWindow::validarTurno(){
    if(turno == HORSEBLACK){
        int posXBlackHorse, posYBlackHorse;
        posXBlackHorse = positionBlack[0];
        posYBlackHorse = positionBlack[1];

        if(posXBlackHorse - 1 >= 0 && posYBlackHorse - 2 >= 0 && tablero[posXBlackHorse-1][posYBlackHorse-2] != 3){
            QLayoutItem *item = chessBoardLayout->itemAtPosition(posXBlackHorse-1, posYBlackHorse-2);
            QWidget* widget = item->widget();
            ClickableLabel* label = dynamic_cast<ClickableLabel*>(widget);
            label->setStyleSheet("QLabel { background-color : yellow }");
            //cout << "DESDE TURNO " << label->getPosX() << " " << label->getposY() << endl;
        }

        if(posXBlackHorse - 1 >= 0 && posYBlackHorse + 2 < 6 && tablero[posXBlackHorse-1][posYBlackHorse+2] != 3){
            QLayoutItem *item = chessBoardLayout->itemAtPosition(posXBlackHorse-1, posYBlackHorse+2);
            QWidget* widget = item->widget();
            ClickableLabel* label = dynamic_cast<ClickableLabel*>(widget);
            label->setStyleSheet("QLabel { background-color : yellow }");
            //cout << "DESDE TURNO " << label->getPosX() << " " << label->getposY() << endl;
        }

        if(posXBlackHorse + 1 < 6 && posYBlackHorse - 2 >= 0 && tablero[posXBlackHorse+1][posYBlackHorse-2] != 3){
            QLayoutItem *item = chessBoardLayout->itemAtPosition(posXBlackHorse+1, posYBlackHorse-2);
            QWidget* widget = item->widget();
            ClickableLabel* label = dynamic_cast<ClickableLabel*>(widget);
            label->setStyleSheet("QLabel { background-color : yellow }");
            //cout << "DESDE TURNO " << label->getPosX() << " " << label->getposY() << endl;
        }

        if(posXBlackHorse + 1 < 6 && posYBlackHorse + 2 < 6 && tablero[posXBlackHorse+1][posYBlackHorse+2] != 3){
            QLayoutItem *item = chessBoardLayout->itemAtPosition(posXBlackHorse+1, posYBlackHorse+2);
            QWidget* widget = item->widget();
            ClickableLabel* label = dynamic_cast<ClickableLabel*>(widget);
            label->setStyleSheet("QLabel { background-color : yellow }");
            //cout << "DESDE TURNO " << label->getPosX() << " " << label->getposY() << endl;
        }
        if(posXBlackHorse - 2 >= 0 && posYBlackHorse - 1 >= 0 && tablero[posXBlackHorse-2][posYBlackHorse-1] != 3){
            QLayoutItem *item = chessBoardLayout->itemAtPosition(posXBlackHorse-2, posYBlackHorse-1);
            QWidget* widget = item->widget();
            ClickableLabel* label = dynamic_cast<ClickableLabel*>(widget);
            label->setStyleSheet("QLabel { background-color : yellow }");
            //cout << "DESDE TURNO " << label->getPosX() << " " << label->getposY() << endl;
        }

        if(posXBlackHorse - 2 >= 0 && posYBlackHorse + 1 < 6 && tablero[posXBlackHorse-2][posYBlackHorse+1] != 3){
            QLayoutItem *item = chessBoardLayout->itemAtPosition(posXBlackHorse-2, posYBlackHorse+1);
            QWidget* widget = item->widget();
            ClickableLabel* label = dynamic_cast<ClickableLabel*>(widget);
            label->setStyleSheet("QLabel { background-color : yellow }");
            //cout << "DESDE TURNO " << label->getPosX() << " " << label->getposY() << endl;
        }

        if(posXBlackHorse + 2 < 6 && posYBlackHorse - 1 >= 0 && tablero[posXBlackHorse+2][posYBlackHorse-1] != 3){
            QLayoutItem *item = chessBoardLayout->itemAtPosition(posXBlackHorse+2, posYBlackHorse-1);
            QWidget* widget = item->widget();
            ClickableLabel* label = dynamic_cast<ClickableLabel*>(widget);
            label->setStyleSheet("QLabel { background-color : yellow }");
            //cout << "DESDE TURNO " << label->getPosX() << " " << label->getposY() << endl;
        }

        if(posXBlackHorse + 2 < 6 && posYBlackHorse + 1 < 6 && tablero[posXBlackHorse+2][posYBlackHorse+1] != 3){
            QLayoutItem *item = chessBoardLayout->itemAtPosition(posXBlackHorse+2, posYBlackHorse+1);
            QWidget* widget = item->widget();
            ClickableLabel* label = dynamic_cast<ClickableLabel*>(widget);
            label->setStyleSheet("QLabel { background-color : yellow }");
            //cout << "DESDE TURNO " << label->getPosX() << " " << label->getposY() << endl;
        }
        //cout << "End Reach" << endl;
    }else{

        nodo movimiento = minimax(this->tablero, 0, 0);

        cout << "El movimiento es " << movimiento.posXBlanco << " " << movimiento.posYBlanco << endl;

        tablero[positionWhite[0]][positionWhite[1]] = 0;
        int posX = movimiento.posXBlanco;
        int posY = movimiento.posYBlanco;
        positionWhite[0] = posX;
        positionWhite[1] = posY;
        //Sleep(1000);
        if(tablero[posX][posY] == 1){
            whiteApples++;
            eliminarItem(posX,posY);
        }
        whiteVisited[posX][posY] = whiteApples+1;
        tablero[posX][posY] = 3;
        moverItem(3,posX,posY);
        turno = HORSEBLACK;
        if(terminoJuego(tablero)){
            if(puntaje(whiteApples,blackApples) > 0){
                QMessageBox msgBox;
                msgBox.setText("Ganó Blanco");
                msgBox.setWindowTitle("Message");
                msgBox.exec();
                itemsLine->clear();
            }else{
                QMessageBox msgBox;
                msgBox.setText("Ganó Negro");
                msgBox.setWindowTitle("Message");
                msgBox.exec();
                itemsLine->clear();
            }
            chessBoardPanel->hide();
            leftPanel->hide();
            rightPanel->hide();
            displayMainMenu();
            return;
        }
        validarTurno();
    }
}

void MainWindow::drawGUI() {

    leftLayout = new QVBoxLayout;
    leftPanel = new QFrame(this);
    leftPanel->setGeometry(QRect(0,0, 212, 768));
  //  leftPanel->setPalette(palette);
    leftPanel->setStyleSheet("background-color: green;");
    leftPanel->setLayout(leftLayout);
    leftPanel->show();

    chessBoardLayout = new QGridLayout();
    chessBoardPanel = new QFrame(this);
    chessBoardPanel->setGeometry(QRect(213, 68, 600, 600));
    chessBoardPanel->setStyleSheet("background-image: url(:/images/board.png;");
  //  chessBoardPanel->setPalette(palette);
  //  chessBoardPanel->setStyleSheet("background-color: blue;");
    chessBoardPanel->setLayout(chessBoardLayout);
    chessBoardPanel->show();

    rightLayout = new QVBoxLayout;
    rightPanel = new QFrame(this);
    rightPanel->setGeometry(QRect(814, 0, 212, 768));
    rightPanel->setStyleSheet("background-color: red;");
    rightPanel->setLayout(rightLayout);
    rightPanel->show();

    drawChessBoard();
    inicializarTablero();
    drawObjects();
    validarTurno();
}

bool MainWindow::validarItems() {

    int number = 0;
    QString string;

    if(itemsLine->text().isEmpty()){

        QMessageBox msgBox;
        msgBox.setText("You must enter a number.");
        msgBox.setWindowTitle("Warning");
        msgBox.exec();
        return false;
    } else {

        string = itemsLine->text();
        number = string.toInt();

        if (number%2==0) {

            QMessageBox msgBox;
            msgBox.setText("You must enter a odd number.   ");
            msgBox.setWindowTitle("Warning");
            msgBox.exec();
            itemsLine->clear();
            return false;
        } else {
            cantidadItems = number;
            manzanasTotales = number;
            itemsLine->clear();
            return true;
        }
    }
    return false;
}

void MainWindow::start() {

    if (validarItems()) {
        QPalette palette;
        this->setPalette(palette);
        titleText->hide();
        itemsText->hide();
        itemsLine->hide();
        playButton->hide();
        quitButton->hide();
        whiteApples = 0;
        blackApples = 0;
        whiteVisited.assign(6,vector<int>(6,0));
        turno = HORSEWHITE;
        drawGUI();

    }
}

void MainWindow::displayMainMenu() {

    //
    QPixmap fondo(":/images/background.jpg");
    fondo = fondo.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, fondo);
    setPalette(palette);

    //
    QFont titleFont( "Algerian" );
    titleFont.setPointSize( 50 );

    titleText = new QLabel(this);
    titleText->setFont(titleFont);
    titleText->setText("AlphaZero");
    titleText->setObjectName(QString("numberItems"));
    int widthTitleText = 390;
    int heightTitleText = 50;
    int xPosTitle = width()/2 - widthTitleText/2;
    int yPosTitle = 150;
    titleText->setGeometry(QRect(xPosTitle, yPosTitle, widthTitleText, heightTitleText));
    titleText->show();

    //
    QFont itemsFont( "Bavaria" );
    itemsFont.setPointSize( 12 );
    itemsFont.setWeight( QFont::Bold );

    itemsText = new QLabel(this);
    itemsText->setFont(itemsFont);
    itemsText->setText("Cantidad de ítems");
    itemsText->setObjectName(QString("numberItems"));
    itemsText->setGeometry(QRect(440, 300, 200, 25));
    itemsText->show();

    //
    itemsLine = new QLineEdit(this);
    itemsLine->setObjectName(QString("appleLine"));
    itemsLine->setToolTip("Debe ser un número impar");
    itemsLine->setValidator( new QIntValidator(1, 34, this) );
    int widthLineEdit = 200;
    int heightLineEdit = 25;
    int xPosLineEdit = width()/2 - widthLineEdit/2;
    int yPosLineEdit = 330;
    itemsLine->setGeometry(QRect(xPosLineEdit, yPosLineEdit, widthLineEdit, heightLineEdit));
    itemsLine->show();

    //
    playButton = new QPushButton("Play", this);
    int widthPlayButton = 200;
    int heightPlayButton = 50;
    int xPosPlayButton = width()/2 - widthPlayButton/2;
    int yPosPlayButton = 375;
    playButton->setGeometry(QRect(xPosPlayButton, yPosPlayButton, widthPlayButton, heightPlayButton));
    playButton->show();

    connect(playButton,SIGNAL(clicked()) , this , SLOT(start()));

    //
    quitButton = new QPushButton("Quit", this);
    int widthQuitButton = 200;
    int heightQuitButton = 50;
    int xPosQuitButton = width()/2 - widthQuitButton/2;
    int yPosQuitButton = 450;
    quitButton->setGeometry(QRect(xPosQuitButton, yPosQuitButton, widthQuitButton, heightQuitButton));
    quitButton->show();

    connect(quitButton, SIGNAL(clicked()),this,SLOT(close()));
}
