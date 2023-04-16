#include <iostream>
#include "Clase.h"


void inicio(Lancha &lanchitas) {
	string nombre;
	cout << "Empezara la gran carrera de lanchas. Quien sera nuestro participante? \n";
	cin >> nombre;
	lanchitas.setName(nombre);
}

void rondas(Lancha& juego) {
	juego.calculoVelocidad();

	if (juego.getNitro() == true)
	{
		cout << "Quieres usar el nitro? (0 No, 1 Si)";
		int opcion;
		do {
			
			std::cin >> opcion;

			switch (opcion) {
			case 0:

				cout << "Has alcanzado una velocidad de " << juego.getVeolocidad() << endl;
				break;

			case 1:
				juego.setNitro(false);
				int toretto;
				toretto = rand() % 2;
				if (toretto == 0) {
					juego.setVeolocidad(juego.getVeolocidad() / 2);
					cout << "Has alcanzado una velocidad de " << juego.getVeolocidad() << " gracias al nitro" << endl;
				}
				else if (toretto == 1) {
					juego.setVeolocidad(juego.getVeolocidad() * 2);
					cout << "Has alcanzado una velocidad de " << juego.getVeolocidad() << " gracias al nitro" << endl;
				}
				break;

			default:
				cout << "Ponlo correctamente porfavor.\n";
			}
		} while (opcion != 0 && opcion != 1);
	}
	cout << "\n";
}

void distRecorrida(Lancha& distancia) {
	distancia.setDistanciaRecorrida (distancia.getDistanciaRecorrida() + (distancia.getVeolocidad() * 100));
	distancia.printResumenPartida();
}

void ganador(Lancha& Lancha1, Lancha& Lancha2) {
	cout << "\n";
	if (Lancha1.getDistanciaRecorrida() > Lancha2.getDistanciaRecorrida())
	{
		cout << Lancha1.getLanchaName() << " ha ganado la carrera!" << endl;
	}
	else if (Lancha1.getDistanciaRecorrida() < Lancha2.getDistanciaRecorrida())
	{
		cout << Lancha2.getLanchaName() << " ha ganado la carrera!" << endl;
	}
	else if (Lancha1.getDistanciaRecorrida() == Lancha2.getDistanciaRecorrida())
	{
		cout << "Ha habido un empate!" << endl;
	}
	cout << "\n";
}




int main() {
	int turnos = 5;
	srand(time(NULL));

	//Empieza juego
	//Lancha 1
	Lancha Lancha1(0,0,1, "");

	//Lancha 2
	Lancha Lancha2(0,0,1, "");

	//Se introduce el nombre de cada lancha
	inicio(Lancha1);
	inicio(Lancha2);

	//Inicio de los turnos
	do
	{
		rondas(Lancha1);
		rondas(Lancha2);
		distRecorrida(Lancha1);
		distRecorrida(Lancha2);

		turnos = turnos - 1;
	} while (turnos != 0);

	//Comparamos quien ha ganado
	ganador(Lancha1, Lancha2);

	return 0;
}





