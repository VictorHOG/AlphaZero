
#include "mainwindow.h"
#include "clickablelabel.h"

#include <stdlib.h>
#include <time.h>
#include <iostream>
using namespace std;

#include <QIntValidator>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {

    setFixedSize(1024,768);
    displayMainMenu();
}

void MainWindow::labelClicked(){
    cout << "Hola" << x() << endl;

}

void MainWindow::drawChessBoard(){

    for (int i = 0; i < 6; ++i) {
        for (int j = 0; j < 6; ++j) {

            ClickableLabel *label = new ClickableLabel();

            if((i+j)%2==0)
                label->setStyleSheet("QLabel { background-color : lightGray }");
            else
                label->setStyleSheet("QLabel { background-color : darkGray }");

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
            i++;
        }

        if (white && tablero[posX][posY] == 0){
            white= false;
            tablero[posX][posY] = 3;
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

    ClickableLabel *blackHorseLabel = new ClickableLabel();
    blackHorseLabel->setPixmap(blackHorse);
    connect(blackHorseLabel,SIGNAL(clicked()) , this , SLOT(labelClicked()));

    ClickableLabel *whiteHorseLabel = new ClickableLabel();
    whiteHorseLabel->setPixmap(whiteHorse);
    connect(whiteHorseLabel,SIGNAL(clicked()) , this , SLOT(labelClicked()));

   // chessBoardLayout->addWidget(blackHorseLabel, 0, 0);
   // chessBoardLayout->addWidget(whiteHorseLabel, 3, 3);
   // chessBoardLayout->addWidget(itemLabel, 5, 5);

    for (int i = 0; i < 6; ++i) {
        for (int j = 0; j < 6; ++j) {

            if (tablero[i][j] == 1) {
                ClickableLabel *itemLabel = new ClickableLabel();
                itemLabel->setPixmap(item);
                connect(itemLabel,SIGNAL(clicked()) , this , SLOT(labelClicked()));
                chessBoardLayout->addWidget(itemLabel, i, j);
            }else if (tablero[i][j] == 2){
                chessBoardLayout->addWidget(blackHorseLabel, i, j);
            } else if (tablero[i][j] == 3){
                chessBoardLayout->addWidget(whiteHorseLabel, i, j);
            }
        }
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
