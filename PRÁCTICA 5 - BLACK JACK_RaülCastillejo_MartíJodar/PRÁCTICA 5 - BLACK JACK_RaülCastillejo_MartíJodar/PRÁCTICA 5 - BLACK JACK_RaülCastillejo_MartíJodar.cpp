#include <iostream>
using namespace std;


//Variables Jugador 1
string ludopataName;
int puntosJugador;
bool ludopataSigueJugando = true;

//Variables Casino
string croupiereName = "Javi";
int casinoPoints;
bool croupiereSigueJugando = true;

//baraja
int baraja[4][13];
int valorCarta[4][13];


void iniciBaraja(int(&arrayBaraja)[4][13], int(&arrayCarta)[4][13]) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 13; j++) {
            arrayBaraja[i][j] = 1;
            if (j > 0 && j < 10) {
                arrayCarta[i][j] = j + 1;
            }
            else if (j >= 10 && j < 14) {
                arrayCarta[i][j] = 10;
            }
        }
    }
}

void startGame() {
    cout << "Bienvendido a la sala de BlackJack del Salon Recreativo de CataJod, \n";
    cout << "yo soy el Croupiere " << croupiereName << " , tu quien eres? (introduce tu nombre): \n";
    cin >> ludopataName;
    cout << "\n";
}

void repartoCartasJugador(int& totalPoints, int(&arrayBaraja)[4][13], int(&arrayCarta)[4][13], int numJugadas, string nomJugador, bool& SigueJugando) {
    int palos = 0;
    int num = 0;
    int valor = 0;
    string palo;
    for (int cartasRepartidas = 0; cartasRepartidas < numJugadas; cartasRepartidas++) {
        palos = rand() % 4;
        num = rand() % 13;
        if (palos == 0) {
            palo = "picas";
        }
        else if (palos == 1) {
            palo = "corazones";
        }
        else if (palos == 2) {
            palo = "treboles";
        }
        else if (palos == 3) {
            palo = "diamantes";
        }
        if (arrayBaraja[palos][num] == 1) {
            if (num == 0) {
                cout << "Te ha salido un As\n";
                cout << "¿Que valor quieres que tenga el As?, 1 o 11 \n";
                int opcion;
                do {
                    cin >> opcion;
                    switch (opcion) {
                    case 1:
                        arrayCarta[palos][num] = 1;
                        break;
                    case 11:
                        arrayCarta[palos][num] = 11;
                        break;
                    default:
                        cout << "Bobolon eso no es un valor que pueda tener el As, dame otro\n";
                    }
                } while (opcion != 1 && opcion != 11);
            }
            valor = arrayCarta[palos][num];
            totalPoints = totalPoints + valor;
            arrayBaraja[palos][num] = 0;
            cout << "A " << nomJugador << " le ha salido un " << valor << " de " << palo << "\n";
            cout << "y tiene un total de " << totalPoints << " puntos \n";
            if (totalPoints >= 21) {
                SigueJugando = false;
            }
        }
        else if (arrayBaraja[palos][num] == 0) {
            cartasRepartidas--;
        }
    }
}

void repartoCartasCroupier(int& totalPoints, int(&arrayBaraja)[4][13], int(&arrayCarta)[4][13], int numJugadas, string nomJugador, bool& SigueJugando) {
    int palos = 0;
    int num = 0;
    int valor = 0;
    string palo;
    for (int cartasRepartidas = 0; cartasRepartidas < numJugadas; cartasRepartidas++) {
        palos = rand() % 4;
        num = rand() % 13;
        if (palos == 0) {
            palo = "picas";
        }
        else if (palos == 1) {
            palo = "corazones";
        }
        else if (palos == 2) {
            palo = "treboles";
        }
        else if (palos == 3) {
            palo = "diamantes";
        }
        if (arrayBaraja[palos][num] == 1) {
            if (num == 0) {
                cout << "Le ha salido un As a la casa \n";
                if (totalPoints + 11 <= 21) {
                    arrayCarta[palos][num] = 11;
                }
                else if (totalPoints + 11 > 21) {
                    arrayCarta[palos][num] = 1;
                }
            }
            valor = arrayCarta[palos][num];
            totalPoints = totalPoints + valor;
            arrayBaraja[palos][num] = 0;
            cout << "A " << nomJugador << " le ha salido un " << valor << " de " << palo << "\n";
            cout << "y tiene un total de " << totalPoints << " puntos \n";
            if (totalPoints >= 21 || (ludopataSigueJugando = false && totalPoints >= puntosJugador)) {
                SigueJugando = false;
            }
        }
        else if (arrayBaraja[palos][num] == 0) {
            cartasRepartidas--;
        }
    }
}

void seguirJugando(bool& SigueJugando) {
    cout << ludopataName << ", quieres seguir jugando?\n";
    int opcion;
    do {
        cout << "[1] Si\n";
        cout << "[2] No\n";
        cin >> opcion;
        switch (opcion) {
        case 1:
            repartoCartasJugador(puntosJugador, baraja, valorCarta, 1, ludopataName, ludopataSigueJugando);
            break;
        case 2:
            SigueJugando = false;
            break;
        default:
            cout << "Bobolon eso no es opcion\n";
        }
    } while (opcion != 1 && opcion != 2);
}

void revisarGanador(string nomJugador) {
    if ((puntosJugador = 21 && (casinoPoints > 21 || casinoPoints < 21)) || (puntosJugador < 21 && casinoPoints > 21)) {
        cout << nomJugador << " ha ganado al casino, " << "\n";
        cout << "FELICIDADES!!" << "\n";
    }
    else if (casinoPoints == 21 && puntosJugador == 21) {
        cout << nomJugador << " ha empatado al casino, " << "\n";
        cout << "cositas del trap... " << "\n";
    }
    else if (puntosJugador > 21 || (puntosJugador < 21 && (puntosJugador < casinoPoints))) {
        cout << nomJugador << " ha perdido contra el casino, " << "\n";
        cout << "gastate mas dinero otro dia. " << "\n";
    }
    else { cout << "Eso no es un resltado posible\n"; }
}

int main()
{
    srand(time(NULL));
    startGame();
    iniciBaraja(baraja, valorCarta);
    repartoCartasJugador(puntosJugador, baraja, valorCarta, 2, ludopataName, ludopataSigueJugando);
    while ((ludopataSigueJugando && croupiereSigueJugando) || puntosJugador <= 21) {
        if (croupiereSigueJugando) {
            repartoCartasCroupier(casinoPoints, baraja, valorCarta, 1, croupiereName, croupiereSigueJugando);
        }
        if (ludopataSigueJugando = true) {
            seguirJugando(ludopataSigueJugando);
        }
    }
    revisarGanador(ludopataName);
}