/*
* CARLOS FELIPE MONTOYA - 1535038
* DIANA MELISSA MILLARES - 1526062
* VICTOR HUGO ORTEGA - 1532342
*/

#include "nodo.h"

nodo::nodo() {
    beneficio = profundidad = posXNegro = posYNegro = manzanasNegro = manzanasNegro = posXBlanco = posYBlanco = 0;
}

bool nodo::operator <(const nodo& B) const{
    return beneficio > B.beneficio;
}

nodo nodo::operator =(const nodo &B){
    this->posXNegro = B.posXNegro;
    this->posYNegro = B.posYNegro;
    this->posXBlanco = B.posXBlanco;
    this->posYBlanco = B.posYBlanco;
    this->profundidad = B.profundidad;
    this->manzanasNegro = B.manzanasNegro;
    this->manzanasBlanco = B.manzanasBlanco;
    this->beneficio = B.beneficio;
    return B;
}

