#pragma once
#include "Clase.h"
#include <iostream>
using namespace std;

//Constructor
Lancha::Lancha(int pVelocidad, int pDistanciaRecorrida, bool pNitro, string pLanchaName) {
	velocidad = pVelocidad;
	distanciaRecorrida = pDistanciaRecorrida;
	nitro = pNitro;
	lanchaName = pLanchaName;
}

//Getters
	int Lancha::getVeolocidad() {
		return velocidad;
	}

	int Lancha::getDistanciaRecorrida() {
		return distanciaRecorrida;
	}

	bool Lancha::getNitro() {
		return nitro;
	}

	string Lancha::getLanchaName() {
		return lanchaName;
	}
	


//Setters

  void Lancha::setVeolocidad(int pVelocidad) {
	  velocidad = pVelocidad;
   }

  void Lancha::setDistanciaRecorrida(int pDistanciaRecorrida) {
	  distanciaRecorrida = pDistanciaRecorrida;
  }

  void Lancha::setNitro(bool pNitro) {
	  nitro = pNitro;
  }

  void Lancha::setName(string pLanchaName) {
	  lanchaName = pLanchaName;
  }

//Metodo propio
  void Lancha::printResumenPartida() {
	 cout << "La lancha " << getLanchaName() << " , ha recorrido una distancia de  " << getDistanciaRecorrida() << " metros. "  "\n";
  }
  
  void Lancha::calculoVelocidad() {
	  cout << "\n";
	  int dado = 0;

	  dado = rand() % 6;

	  //calculo velocidad
	  setVeolocidad(getVeolocidad() + (dado + 1));
  }
  
