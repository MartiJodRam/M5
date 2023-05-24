#include <iostream>
#include "Personaje.h"
#include <string>
#include "EnemigoFinal.h"
#include <cstdlib>
#include <ctime>
#include <Windows.h>

using namespace std;

const int FILAS = 5;
const int COLUMNAS = 10;

void inicio(Personaje& hero) {
    string nombre;
    cout << "Has llegado al tablero de batalla. Como te llamas?" << endl;
    cin >> nombre;
    hero.setNombre(nombre);
}

void dibujarTablero(char tablero[FILAS][COLUMNAS], Personaje& hero, EnemigoFinal& enemigoFinal, Personaje villanos[4]) {
    cout << endl;

    for (int i = 0; i < FILAS; i++) {
        for (int j = 0; j < COLUMNAS; j++) {
            if (i == hero.getPosicionY() && j == hero.getPosicionX()) {
                cout << hero.getNombre()[0] << " ";
            }
            else if (i == enemigoFinal.getPosicionY() && j == enemigoFinal.getPosicionX()) {
                cout << "E ";
            }
            else {
                bool esVillano = false;
                for (int k = 0; k < 4; k++) {
                    if (i == villanos[k].getPosicionY() && j == villanos[k].getPosicionX()) {
                        cout << "V ";
                        esVillano = true;
                        break;
                    }
                }
                if (!esVillano) {
                    cout << "_ ";
                }
            }
        }
        cout << endl;
    }
}

void batalla(Personaje& heroe, Personaje& villano) {
    int protecciones = 3;
    cout << "Hay un villano!\n";
    cout << "Comienza la batalla!\n";

    while (heroe.getVida() > 0 && villano.getVida() > 0) {
        int opcion;
        do {
            cout << "Que quieres hacer?\n";
            cout << "1. Atacar\n";
            cout << "2. Proteccion\n";
            cout << "Tienes " << heroe.getVida() << " puntos de vida." << endl;
            cin >> opcion;
        } while (opcion != 1 && opcion != 2);

        switch (opcion) {
        case 1:
            villano.setVida(villano.getVida() - heroe.getAtaque());
            cout << "Has atacado al villano. Vida del villano: " << villano.getVida() << endl;
            cout << "Este te atacará con toda su rabia." << endl;
            heroe.setVida(heroe.getVida() - villano.getAtaque());
            cout << "Te queda " << heroe.getVida() << " puntos de vida." << endl;
            break;

        case 2:
            if (protecciones > 0) {
                cout << "Te has protegido del ataque del villano. No has recibido daño.\n";
                protecciones--;
            }
            else {
                cout << "Ya no tienes protecciones disponibles.\n";
                cout << "Lanzarás un ataque y recibirás daño.\n";
                heroe.setVida(heroe.getVida() - villano.getAtaque());
                cout << "Vida del héroe: " << heroe.getVida() << endl;
            }
            break;

        default:
            cout << "Opción inválida. Se realizará un ataque por defecto.\n";
            villano.setVida(villano.getVida() - heroe.getAtaque());
            cout << "Has atacado al villano. Vida del villano: " << villano.getVida() << endl;
            heroe.setVida(heroe.getVida() - villano.getAtaque());
            cout << "Te queda " << heroe.getVida() << " puntos de vida." << endl;
            break;
        }
    }

    if (heroe.getVida() > 0) {
        cout << "WOW que victoria." << endl;

        if (heroe.getVida() < 1000) {
            int incrementoVida = heroe.getVida() * 0.25; // Incremento del 25%
            int nuevaVida = heroe.getVida() + incrementoVida;

            if (nuevaVida > 1000) {
                heroe.setVida(1000); // Establecer la vida máxima
            }
            else {
                heroe.setVida(nuevaVida);
            }
        }
    }
}

void movimiento(Personaje& hero, char tablero[FILAS][COLUMNAS], int salida_fila, int salida_col, EnemigoFinal& enemigoFinal, Personaje villanos[4]) {
    int direccion;
    do {
        cout << "Hacia donde te quieres mover? Arriba (1), abajo (2), derecha (3) o izquierda (4)" << endl;
        cin >> direccion;

        int nuevaX = hero.getPosicionX();
        int nuevaY = hero.getPosicionY();

        switch (direccion) {
        case 1:  // Arriba
            if (nuevaY > 0) {
                nuevaY--;
            }
            else {
                cout << "Movimiento inválido. Intenta de nuevo." << endl;
                continue;
            }
            break;
        case 2:  // Abajo
            if (nuevaY < FILAS - 1) {
                nuevaY++;
            }
            else {
                cout << "Movimiento inválido. Intenta de nuevo." << endl;
                continue;
            }
            break;
        case 3:  // Derecha
            if (nuevaX < COLUMNAS - 1) {
                nuevaX++;
            }
            else {
                cout << "Movimiento inválido. Intenta de nuevo." << endl;
                continue;
            }
            break;
        case 4:  // Izquierda
            if (nuevaX > 0) {
                nuevaX--;
            }
            else {
                cout << "Movimiento inválido. Intenta de nuevo." << endl;
                continue;
            }
            break;
        default:
            cout << "Selección inválida. Intenta de nuevo." << endl;
            continue;
        }

        // Verificar si la nueva posición coincide con la salida
        if (nuevaY == salida_fila && nuevaX == salida_col) {
            cout << "¡Felicidades! Has encontrado la salida y has ganado el juego." << endl;
            return;
        }

        // Verificar si la nueva posición coincide con el enemigo final
        if (nuevaY == enemigoFinal.getPosicionY() && nuevaX == enemigoFinal.getPosicionX()) {
            cout << "¡Encontraste al enemigo final! ¡Prepárate para la batalla!" << endl;
            batalla(hero, enemigoFinal);
            if (enemigoFinal.getVida() <= 0) {
                cout << "¡Has derrotado al enemigo final! ¡Has ganado el juego!" << endl;
                return;
            }
            if (hero.getVida() <= 0) {
                cout << "Has sido derrotado. ¡Fin del juego!" << endl;
                break;
            }
        }

        // Verificar si la nueva posición coincide con un enemigo simple
        for (int i = 0; i < 4; i++) {
            if (nuevaY == villanos[i].getPosicionY() && nuevaX == villanos[i].getPosicionX()) {
                cout << "¡Encontraste a un enemigo simple! ¡Prepárate para la batalla!" << endl;
                batalla(hero, villanos[i]);
                if (hero.getVida() <= 0) {
                    cout << "Has sido derrotado. ¡Fin del juego!" << endl;
                    break;
                }
            }
        }

        // Actualizar la posición del personaje principal en el tablero
        tablero[hero.getPosicionY()][hero.getPosicionX()] = '_';
        hero.setPosicionX(nuevaX); // Establecer la nueva posición en el atributo posicionX usando el método setPosicionX
        hero.setPosicionY(nuevaY); // Establecer la nueva posición en el atributo posicionY usando el método setPosicionY
        tablero[hero.getPosicionY()][hero.getPosicionX()] = hero.getNombre()[0];

        dibujarTablero(tablero, hero, enemigoFinal, villanos);

    } while (true);
}

int main() {
    srand(time(NULL));

    Personaje hero(1009, 100, "", 0, 0);
    EnemigoFinal enemigoFinal(1200, 50, "Enemigo Final", rand() % COLUMNAS, FILAS - 1, 150, 100);
    Personaje villanos[4] = {
        Personaje(50, 5, "Villano 1", rand() % COLUMNAS, rand() % FILAS),
        Personaje(50, 5, "Villano 2", rand() % COLUMNAS, rand() % FILAS),
        Personaje(50, 5, "Villano 3", rand() % COLUMNAS, rand() % FILAS),
        Personaje(50, 5, "Villano 4", rand() % COLUMNAS, rand() % FILAS)
    };

    int salida_fila = FILAS - 1;
    int salida_col = rand() % COLUMNAS;


    char tablero[FILAS][COLUMNAS];

    for (int i = 0; i < FILAS; i++) {
        for (int j = 0; j < COLUMNAS; j++) {
            tablero[i][j] = '_';
        }
    }

    tablero[salida_fila][salida_col] = 'S';  // S representa la salida
    tablero[hero.getPosicionY()][hero.getPosicionX()] = hero.getNombre()[0];
    tablero[enemigoFinal.getPosicionY()][enemigoFinal.getPosicionX()] = 'E';

    for (int i = 0; i < 4; i++) {
        tablero[villanos[i].getPosicionY()][villanos[i].getPosicionX()] = 'V';
    }

    inicio(hero);
    dibujarTablero(tablero, hero, enemigoFinal, villanos);
    movimiento(hero, tablero, salida_fila, salida_col, enemigoFinal, villanos);
    
    return 0;
    system("cls");
}

