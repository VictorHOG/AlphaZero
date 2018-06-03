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
