#include "EnemigoFinal.h"

//constructor
EnemigoFinal::EnemigoFinal(int pVida, int pAtaque, std::string pNombre, int pPosicionX, int pPosicionY, int pMegaPatada, int pSuperLanza)
    : Personaje(pVida, pAtaque, pNombre, pPosicionX, pPosicionY)
{
    megaPatada = pMegaPatada;
    superLanza = pSuperLanza;
}

//getters
int EnemigoFinal::getMegaPatada()
{
    return megaPatada;
}

int EnemigoFinal::getSuperLanza()
{
    return superLanza;
}

//setters
void EnemigoFinal::setMegaPatada(int pMegaPatada)
{
    megaPatada = pMegaPatada;
}

void EnemigoFinal::setSuperLanza(int pSuperLanza)
{
    superLanza = pSuperLanza;
}

//metodos propios
void EnemigoFinal::ejecutarMegaPatada()
{
    std::cout << "El enemigo final ha usado la MEGAPATADA" << std::endl;
}

void EnemigoFinal::ejecutarSuperLanza()
{
    std::cout << "El enemigo finalha usado la SUPERLANZA" << std::endl;
}
