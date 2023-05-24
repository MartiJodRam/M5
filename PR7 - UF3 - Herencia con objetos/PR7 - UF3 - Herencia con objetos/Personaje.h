#pragma once
#include  <iostream>

class Personaje
{

private:
	int vida;
	int ataque;
	std::string nombre;
	int posicionX;
	int posicionY;

public:
	//constructor
	Personaje(int pVida, int pAtaque, std::string pNombre, int pPosicionX, int pPosicionY);

	//getters
	int getVida();

	int getAtaque();

	std::string getNombre();

	int getPosicionX();

	int getPosicionY();

	//setters
	void setVida(int pVida);

	void setAtaque(int pAtaque);

	void setNombre(std::string pNombre);

	void setPosicionX(int pPosicionX);

	void setPosicionY(int pPosicionY);

	//metodos propios
	void printStatus();


};
