//
// Created by juan on 29/04/15.
//

#include "Caja.h"

Caja::Caja(){
    this->total = 0;
}

Caja::~Caja() {

}


void Caja::sumarAlTotal(int cantidad){
    this->total+=cantidad;
}

int Caja::getTotal(){
    return this->total;
}
