#include "mainwindow.h"

#include <QIntValidator>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {

    setFixedSize(1024,768);
    displayMainMenu();
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
