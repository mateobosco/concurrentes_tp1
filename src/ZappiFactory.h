//
// Created by juan on 05/05/15.
//

#ifndef CONCURRENTES_TP1_ZAPPIFACTORY_H
#define CONCURRENTES_TP1_ZAPPIFACTORY_H

#include <stdlib.h>
#include <vector>

#include "Zappi.h"


typedef struct TipoPizza{
    std::string	nombre ;
    int duracion ;
    int precio;
} Pizza;

class ZappiFactory {

public:
    ZappiFactory();
    virtual ~ZappiFactory();
    Zappi* generarZappiRandom();

private:

};


#endif //CONCURRENTES_TP1_ZAPPIFACTORY_H
