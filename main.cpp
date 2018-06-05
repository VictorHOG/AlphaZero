/*
* CARLOS FELIPE MONTOYA - 1535038
* DIANA MELISSA MILLARES - 1526062
* VICTOR HUGO ORTEGA - 1532342
*/
#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // Add icon
    a.setWindowIcon(QIcon(":/images/iconAppleHorseChess"));

    MainWindow mainWin;
    mainWin.show();

    return a.exec();
}
