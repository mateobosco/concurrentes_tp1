//
// Created by juan on 05/05/15.
//

#include "ZappiFactory.h"

ZappiFactory::ZappiFactory(){

}
ZappiFactory::~ZappiFactory(){

}

Zappi* ZappiFactory::generarZappiRandom(){
    Pizza Napolitana ;
    Napolitana.nombre = "Grande de Napolitana";
    Napolitana.duracion = 15;
    Napolitana.precio = 120;
    Pizza Muzzarella;
    Muzzarella.nombre = "Grande de Muzzarella";
    Muzzarella.duracion = 10;
    Muzzarella.precio = 100;
    Pizza Fugazetta;
    Fugazetta.nombre = "Grande de Fugazetta";
    Fugazetta.duracion = 20;
    Fugazetta.precio = 160;
    std::vector<Pizza> vectorGustos;
    vectorGustos.push_back(Napolitana);
    vectorGustos.push_back(Muzzarella);
    vectorGustos.push_back(Fugazetta);
    int posicion =(rand() % 3);
    Pizza elegida = vectorGustos[posicion];
    Zappi* zappi = new Zappi(elegida.nombre, elegida.duracion, elegida.precio);
    return zappi;
}
