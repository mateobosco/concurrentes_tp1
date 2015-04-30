//
// Created by juan on 29/04/15.
//

#include "Supervisora.h"

Supervisora::Supervisora() {


}

Supervisora::~Supervisora() {


}

void Supervisora::run(){
    this->changeName("TP - Supervisora");
    while (sigint_handler.getGracefulQuit() == 0){
        //Zappi* pizzaHorneada = new Zappi("",0);
        //size_t len = sizeof(Zappi);
        //std::cout << "CADETE: Espero para leer"<<getpid() << std::endl;
//
      //  if(leidos == len){
        //    std::cout<< "CADETE : leo una pizza"<<std::endl;
    //    }

  //      delete pizzaHorneada;
    }


}
