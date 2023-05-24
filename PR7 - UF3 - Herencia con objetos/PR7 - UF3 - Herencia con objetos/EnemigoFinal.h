#pragma once
#include <iostream>
#include "Personaje.h"

class EnemigoFinal : public Personaje
{
private:
    int megaPatada;
    int superLanza;

public:
    //constructor
    EnemigoFinal(int pVida, int pAtaque, std::string pNombre, int pPosicionX, int pPosicionY, int pMegaPatada, int pSuperLanza);

    //getters
    int getMegaPatada();
    int getSuperLanza();

    //setters
    void setMegaPatada(int pMegaPatada);
    void setSuperLanza(int pSuperLanza);

    //metodos propios
    void ejecutarMegaPatada();
    void ejecutarSuperLanza();
};
