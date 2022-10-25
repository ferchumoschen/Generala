#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <ctime>
/* LIBRERIAS USO:
- CSTIME PARA LOS DADOS RANDOM.
- IOSTREAM LA TIPICA (PARA QUE FUNCIONE UN PROGRAMA)
- CSTDLIB PRINCIPALMENTE PARA EL USO DE SYSTEM
- CSTDIO UTILIZAMOS PARA EL FPRINT PRINCIPALMENTE*/
using namespace std;

#include "Juego.h"
#include "Menu.h"
#include "Dados.h"
/** DENTRO DEL MAIN TENEMOS EL MENU PRINCIPAL, LOS SWITCH QUE ABREN CADA OPCION DEL MENU*/
int main() {
    system("mode con: cols=121 lines=31");
    srand((unsigned int)time(NULL));
    string cosito[5];
    int mayorPuntuacion = 0;
    int rondasMayorPuntuacion = 0;
    string mayorNombre;
    bool seguirEjecutandoJuego = true;
    bool ganoConPrimeraGenerala = false;
    bool puntuacionMaximaFueConGeneralaServida = false;
    while (seguirEjecutandoJuego) {
    cosito[0] = "presione 1 para iniciar el juego en modo 1 jugador";
    cosito[1] = "presione 2 para iniciar el juego en modo 2 jugadores";
    cosito[2] = "presione 3 para ver las instrucciones";
    cosito[3] = "presione 4 para ver la puntuacion mas alta";
    cosito[4] = "presione 0 para salir";
    gotoxy(5, 29); cout << "Alejo Tomas Clifton Goldney";
    gotoxy(55, 29); cout << "Alexander Popp";
    gotoxy(100, 29); cout << "Fernando Moschen";
    marco_dado(104, 1);
    gotoxy(106, 3); cout << "Version";
    gotoxy(108, 4); cout << "2.1";
    gotoxy(106, 5); cout << "UTN-FRGP";
    switch (menu(cosito, 5)) {
    case '1': {
        
       modoUnJugador(mayorPuntuacion,
        rondasMayorPuntuacion,
        mayorNombre,
        seguirEjecutandoJuego,
        ganoConPrimeraGenerala,
        puntuacionMaximaFueConGeneralaServida);
        
    }
        break;
    case '2': {
        modoDosJugadores(mayorPuntuacion,
            rondasMayorPuntuacion,
            mayorNombre,
            seguirEjecutandoJuego,
            ganoConPrimeraGenerala,
            puntuacionMaximaFueConGeneralaServida);
    }
        break;
    case '3': {
        system("cls");
        instrucciones();
        system("pause");
        system("cls");
    }
        break;
    case '4': {
        mostrarMayorPuntuacion(mayorNombre, mayorPuntuacion, rondasMayorPuntuacion, seguirEjecutandoJuego);
    }
        break;
    case '0': {
        gotoxy(2, 20); cout << "Hasta luego" << endl;
        return 0;
    }
    default:{
        gotoxy(2, 21); cout << "seleccione por favor del 0 al 4, gracias" << endl;
    }
    }
    
    }
    return 0;
    
}
