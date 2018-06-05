#include "clickablelabel.h"

ClickableLabel::ClickableLabel(QWidget* parent, Qt::WindowFlags f) : QLabel(parent) {

}

ClickableLabel::~ClickableLabel() {}

void ClickableLabel::mousePressEvent(QMouseEvent* event) {
    emit clicked();
}

void ClickableLabel::setPosX(int x){
    posX = x;
}

void ClickableLabel::setposY(int y){
    posY = y;
}

int ClickableLabel::getPosX(){
    return posX;
}

int ClickableLabel::getposY(){
    return posY;
}
