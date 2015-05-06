#ifndef SEMAFORO_H_
#define SEMAFORO_H_

#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/types.h>
#include <string>

class Semaforo {

private:
	int id;
	int valorInicial;

	int inicializar () const;

public:
	Semaforo ( const std::string& nombre,const int valorInicial );
	Semaforo ( const std::string& nombre);
	~Semaforo();

	int p () const; // decrementa
	int v () const; // incrementa
	int vN ( const int n) const; // incrementa N
	void eliminar () const;
};

#endif /* SEMAFORO_H_ */
