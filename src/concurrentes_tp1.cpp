#include <unistd.h>

#include "Configuracion.h"
#include "Pizzeria.h"

using namespace std;

int main(int argc, char** argv) {
	int pid = getpid();
	Logger::Instance()->loggearBool = false;
	if(strcmp(argv[1], "-l") == 0){
		Logger::Instance()->loggearBool = true;
	}
	else{
		Logger::Instance()->log(Logger::ERROR," Parametro recibido incorrento, ingrese '-l' para modo debug ");
	}
	if(argc >2){
		Logger::Instance()->log(Logger::ERROR," Cantidad de parametros incorrecta, ingrese '-l' para modo debug ");
	}


	Configuracion c = Configuracion("config.dat");

	Pizzeria p = Pizzeria(argc > 1);
	Pizzeria p = Pizzeria();
	if (getpid() == pid) p.crearCaja();
	if (getpid() == pid) p.crearGeneradorLlamados();
	if (getpid() == pid) p.crearRecepcionistas(c.getCantRecepcionistas());
	if (getpid() == pid) p.crearCocineros(c.getCantCocineros());
	if (getpid() == pid) p.crearHornos(c.getCantHornos());
	if (getpid() == pid) p.crearCadetes(c.getCantCadetes());
	if (getpid() == pid) p.crearSupervisora(c.getTiempoSupervisora());
	if (getpid() == pid) p.run();

	return 0;
}
