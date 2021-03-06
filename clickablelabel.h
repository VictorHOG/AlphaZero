/*
* CARLOS FELIPE MONTOYA - 1535038
* DIANA MELISSA MILLARES - 1526062
* VICTOR HUGO ORTEGA - 1532342
*/
#ifndef CLICKABLELABEL_H
#define CLICKABLELABEL_H

#include <QLabel>

class ClickableLabel : public QLabel {
    Q_OBJECT

public:
    explicit ClickableLabel(QWidget* parent = Q_NULLPTR, Qt::WindowFlags f = Qt::WindowFlags());
    ~ClickableLabel();

    void setPosX(int x);
    void setposY(int y);
    int getPosX();
    int getposY();

signals:
    void clicked();

protected:
    void mousePressEvent(QMouseEvent* event);

private:
    int posX;
    int posY;
};

#endif // CLICKABLELABEL_H
