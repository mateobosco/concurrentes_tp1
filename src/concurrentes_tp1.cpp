#include <unistd.h>

#include "Configuracion.h"
#include "Pizzeria.h"

using namespace std;

int main(int argc, char** argv) {
	int pid = getpid();

	Configuracion c = Configuracion("config.dat");

	Pizzeria p = Pizzeria(argc > 1);
	if (getpid() == pid) p.crearCaja();
	if (getpid() == pid) p.crearGeneradorLlamados();
	if (getpid() == pid) p.crearRecepcionistas(c.getCantRecepcionistas());
	if (getpid() == pid) p.crearCocineros(c.getCantCocineros());
	if (getpid() == pid) p.crearHornos(c.getCantHornos());
	if (getpid() == pid) p.crearCadetes(c.getCantCadetes());
	if (getpid() == pid) p.crearSupervisora(c.getTiempoSupervisora());
	if (getpid() == pid) p.run();

	cout<<"FINALIZA EL PROGRAMA"<<endl;
	return 0;
}
