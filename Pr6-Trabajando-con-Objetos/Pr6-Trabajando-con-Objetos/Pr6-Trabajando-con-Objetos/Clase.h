#pragma once
#include <iostream>
#include <string>
#include <string>
using namespace std;

class Lancha
{
private:
	int velocidad;
	int distanciaRecorrida;
	bool nitro;
	string lanchaName;

public:
	//constructor
	Lancha(int pVelocidad, int pDistanciaRecorrida, bool pNitro, string pLanchaName);

	//getters
	int getVeolocidad();
	int getDistanciaRecorrida();
	bool getNitro();
	string getLanchaName();

	//setters
	void setVeolocidad( int pVelocidad);
	void setDistanciaRecorrida(int pDistanciaRecorrida);
	void setNitro(bool pNitro);
	void setName(string planchaName);

	//Metodos propios
	void printResumenPartida();
	void calculoVelocidad();
};
