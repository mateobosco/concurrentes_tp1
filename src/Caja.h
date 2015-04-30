//
// Created by juan on 29/04/15.
//

#ifndef CONCURRENTES_TP1_CAJA_H
#define CONCURRENTES_TP1_CAJA_H


class Caja {
public:
    Caja();
    virtual ~Caja();
    void run();

    void sumaralTotal(int cantidad);
    int getTotal();

private:
    int total;


};


#endif //CONCURRENTES_TP1_CAJA_H
