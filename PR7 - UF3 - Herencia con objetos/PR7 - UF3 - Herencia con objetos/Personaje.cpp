#pragma once
#include "Personaje.h"
#include  <iostream>

//constructor
Personaje::Personaje(int pVida, int pAtaque, std::string pNombre, int pPosicionX, int pPosicionY) {
	vida = pVida;
	ataque = pAtaque;
	nombre = pNombre;
	posicionX = pPosicionX;
	posicionY = pPosicionY;
}

//getters
int Personaje::getVida() {
	return vida;
}

int Personaje::getAtaque() {
	return ataque;
}

std::string Personaje::getNombre() {
	return nombre;
}

int Personaje::getPosicionX() {
	return posicionX;
}

int Personaje::getPosicionY() {
	return posicionY;
}

//setters
void Personaje::setVida(int pVida) {
	vida = pVida;
}

void Personaje::setAtaque(int pAtaque) {
	ataque = pAtaque;
}

void Personaje::setNombre(std::string pNombre) {
	nombre = pNombre;
}

void Personaje::setPosicionX(int pPosicionX) {
	posicionX = pPosicionX;
}

void Personaje::setPosicionY(int pPosicionY) {
	posicionY = pPosicionY;
}

//Metodos propios
void Personaje::printStatus() {
	std::cout << "El nombre del personaje es " << getNombre() << " y tiene una vida de  " << getVida() << std::endl;
}