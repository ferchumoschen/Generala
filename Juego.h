#pragma once


#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include <iostream>
#include <stdlib.h>   
#include "Menu.h"
#include "Dados.h"
#include "Jugadas.h"
using namespace std;

void barrita() {
    cout << "---------------------------------------------------------------------------------------------------------------------"<<endl;
}
/*BARRITA SEPARADORA LINDA ESTETICAMENTE*/
bool seguirLanzando() {
    char j;
    bool teclaIncorrecta = true; /*BANDERA INCORRECTA ENTRA COMO VERDADERO*/
    gotoxy(2, 16); cout << "Desea seguir lanzando? (s / n) ";
    cin >> j;
    cout << endl;
    if (j == 's' || j == 'S') { /*DEVUELVE UN VALOR VERDADERO EN CASO DE SEGUIR LANZANDO*/
        return true;
    }
    else if (j == 'n'||j == 'N') { /*DEVUELVE UN VALOR FALSO EN CASO DE NO SEGUIR LANZANDO*/
        return false;
    }
    else {
        teclaIncorrecta = true; /*BANDERA INCORRECTA ENTRA COMO VERDADERO*/
        while (teclaIncorrecta == true) { /*ENTRA AL WHILE SIEMPRE QUE SIGA SIENDO VERDADERO*/
            gotoxy(2, 15); barrita();
            gotoxy(2, 16); cout << "Esa opcion no es aceptable.";
            gotoxy(2, 17); cout << "por favor, volver a ingresar un digito valido." << endl;
            gotoxy(2, 18); barrita();
            gotoxy(2, 19); cout << "Desea seguir lanzando? (s / n) ";
            cin >> j;
            cout << endl;
            if (j == 's' || j == 'S') {
                return true;  /*DEVUELVE UN VALOR VERDADERO EN CASO DE SEGUIR LANZANDO*/
                teclaIncorrecta = false; /*BANDERA INCORRECTA CAMBIA A FALSO (Y ASI SALE DEL WHILE) */
            }
            else if (j == 'n' || j == 'N') {
                return false;  /*DEVUELVE UN VALOR FALSO EN CASO DE NO SEGUIR LANZANDO*/
                teclaIncorrecta = false; /*BANDERA INCORRECTA CAMBIA A FALSO (Y ASI SALE DEL WHILE) */
            }
           gotoxy(2, 19); cout << "                                                                                                                     ";//para borrar la lo que se escriba cuando se pregunta si desea volver a tirar (linea 36) pero sin borrar toda la pantalla
            }
    }
    return false;
}
/*SEGUIR LANZANDO*/
string pedir_nombre(bool nombre_primer_jugador) { /*EL BOOL NOMBRE_PRIMER_JUGADOR SIRVE PARA PEDIR UNO O DOS PLAYER*/
    string nombre;
    if (nombre_primer_jugador == true) { /*SI EL BOOL ES TRUE*/
        gotoxy(2, 4); cout << "Ingresar el nombre del jugador" << endl;
        gotoxy(2, 6); cin >> nombre;
        return nombre; /*RETORNA EL NOMBRE*/
    }
    if (nombre_primer_jugador == false) { /*SI EL BOOL ES FALSE*/
            gotoxy(2, 4); cout << "Ingresar el nombre del segundo jugador" << endl;
            gotoxy(2, 6); cin >> nombre;
            return nombre; /*RETORNA EL NOMBRE*/
        }
    return nombre; /*RETORNA EL NOMBRE*/
    }  
/*PEDIR NOMBRE*/
void  menu_lanzamientos(string nombre, int ronda, int puntos, int turno, int dados[]) { /*LOS PARAMETROS SEGUN LAS VARIABLES QUE DECLARE*/
    pintar_bordes();
    gotoxy(2, 2); cout << "Turno de: " << nombre;
    gotoxy(50, 2); cout << "Ronda Numero " << ronda;
    gotoxy(100, 2); cout << "Puntaje Total: " << puntos << endl;
    gotoxy(2, 3); barrita();
    gotoxy(2, 4); cout << "Lanzamiento Numero: " << turno;
    cout << endl;
    gotoxy(2, 5); barrita();
    dibujar_dados(dados, 7);
    cout << endl;
    cout << endl;
} 
/*MENU E/ LANZAMIENTOS*/
void menu_entre_rondas2p(string nombreActual, string nombreSiguiente, int ronda, int puntosActual, int puntosSiguiente, int turno, int dadosActuales[]) {/*LOS PARAMETROS SEGUN LAS VARIABLES QUE DECLARE*/
    pintar_bordes();
    gotoxy(48, 2); cout << "los dados quedaron asi" << endl;
    gotoxy(2, 3); barrita();
    dibujar_dados(dadosActuales, 6);
    gotoxy(2, 15); barrita();
    gotoxy(48, 16); cout << "Ronda Numero= " << ronda << endl;
    gotoxy(2, 17); barrita();
    gotoxy(48, 18); cout << "Proximo turno es de= " << nombreSiguiente << endl;
    gotoxy(2, 19); barrita();
    gotoxy(48, 20); cout << "Puntaje de= " << nombreActual << " : " << puntosActual << endl;
    gotoxy(48, 21); cout << "Puntaje de= " << nombreSiguiente << " : " << puntosSiguiente << endl;
    gotoxy(2, 22); barrita();
    gotoxy(2, 24); system("pause");
    system("cls");
}
/*MENU E/ RONDAS 2 JUGADORES*/
void pantallaGanoConGeneralaServida() {
    gotoxy(2, 15); barrita();
    gotoxy(2, 17); barrita();
    gotoxy(2, 16); system("pause");
    system("cls");
    cout << endl;
    cout << endl;
    pintar_bordes();
    cuadrado(30, 4);
    gotoxy(47, 10); cout << "Hiciste la generala servida!!" << endl;
    gotoxy(51, 11); cout << "GANASTE EL JUEGO!!" << endl;
    gotoxy(53, 12); cout << "FELICIDADES!!" << endl;
    gotoxy(2, 20); barrita();
    gotoxy(2, 22); barrita();
    gotoxy(2, 21); system("pause");
    system("cls");
}
/*PANTALLA FINAL GANADOR GENERALA*/
int pedirRondas() {
    char opcion_dado;
    int cant_rondas=10;
    system("cls");
    gotoxy(2, 5); barrita();
    pintar_bordes();
    gotoxy(2, 2); cout << "Para ingresar cantidad de rondas, ingresar 1" << endl;
    gotoxy(2, 4); cout << "Para ingresar rondas predefinidas, ingresar 0 (10 rondas)" << endl;
    gotoxy(2, 6); cin >> opcion_dado;
    if (opcion_dado == '1') {
        gotoxy(2, 8); cout << "Ingresar la cantidad de rondas" << endl;
        gotoxy(2, 10); cin >> cant_rondas;
    }
    else if (opcion_dado == '0') { /*POR DEFECTO GUARDA 10*/
        system("cls");
        pintar_bordes();
        gotoxy(2, 2); cout << "Usted eligio la opcion 0";
        gotoxy(2, 2); cout << "la cantidad de rondas por defecto es 10";
        
    }
    else {
        while (opcion_dado != '1' && opcion_dado != '0') { /*PIDE UNA OPCION CORRECTA (1 O 0)*/
            cant_rondas = 10;
            system("cls");
            gotoxy(2, 7); barrita();
            gotoxy(2, 9); barrita();
            pintar_bordes();
            gotoxy(2, 2); cout << "por favor ingresar un digito valido." << endl;
            gotoxy(2, 4); cout << "Para ingresar cantidad de rondas, ingresar 1" << endl;
            gotoxy(2, 6); cout << "Para ingresar rondas predefinidas, ingresar 0 (10 rondas)" << endl;
            gotoxy(2, 8); cin >> opcion_dado;
            if (opcion_dado == '1') {
                gotoxy(2, 11); barrita();
                gotoxy(2, 13); barrita();
                pintar_bordes();
                gotoxy(2, 10); cout << "Ingresar la cantidad de rondas" << endl;
                gotoxy(2, 12); cin >> cant_rondas;
            }
            else if (opcion_dado == '0') {
                system("cls");
                pintar_bordes();
                gotoxy(2, 2); cout << "Usted eligio la opcion 0";
                gotoxy(2, 2); cout << "la cantidad de rondas por defecto es 10";
               
            }
        }
    }
    return cant_rondas;
}
/*CANTIDAD DE RONDAS*/
void modoUnJugador(int &mayorPuntuacion,int &rondasMayorPuntuacion,string &mayorNombre,
bool &seguirEjecutandoJuego,bool &ganoConPrimeraGenerala,bool &puntuacionMaximaFueConGeneralaServida){
    bool modojuego_singular = true;
    system("cls");
        int puntaje;    //PUNTAJE ES LA PUNTUACION POR RONDA
        bool juegoterminado = false;
        int ronda = 0;
        int puntos = 0;  //PUNTOS ES EL PUNTAJE TOTAL
        int dados[5];
        int j;
        system("cls");
        gotoxy(2, 5); barrita();
        gotoxy(2, 7); barrita();
        pintar_bordes();
        gotoxy(2, 2); cout << "Bienvenido al Juego solitario" << endl;
        string nombre = pedir_nombre(true);
        //-------------------------------------------------------------------------------------------
        int cant_rondas = pedirRondas();//Funcion que retorna el valor de lo que dice su nombre
        //-------------------------------------------------------------------------------------------
        system("cls");
        while (ronda != cant_rondas && juegoterminado == false) {
            int turno = 0;
            ronda++;
            turno++;
            bool seguir = true;
            for (int i = 0; i < 5; i++) {
                dados[i] = (rand() % 6) + 1;
            }
            while (turno < 3 && seguir) {
                puntaje = 0;
                //----------------------------------------------------
                menu_lanzamientos(nombre, ronda, puntos, turno, dados);
                //----------------------------------------------------
                if (generala(dados) && turno == 1) {

                    //--------------------------------
                    pantallaGanoConGeneralaServida();//esta funcion, hace lo que su nombre dice
                    //--------------------------------
                    ganoConPrimeraGenerala = true;
                    juegoterminado = true;
                    seguir = false;
                }
                else
                {
                    turno++;
                    gotoxy(2, 14); cout << "Lanzamiento Numero: " << turno;
                    cout << endl;
                    gotoxy(2, 15); barrita();
                    cout << endl;
                    if (!seguirLanzando())
                    {
                        seguir = false;
                    }
                    else
                    {
                        gotoxy(2, 18); cout << "cuantos dados? ";
                        cin >> j;
                        cout << endl;
                        int dados_tirar = 19;
                        for (int i = 0; i < j; i++) {
                            int f;
                            gotoxy(2, dados_tirar); cout << "cual dado desea tirar? ";
                            dados_tirar++;
                            cin >> f;
                            dados[f - 1] = rand() % 6 + 1;
                        }
                    }
                }
                system("cls");
            }
            //termina el while por turno
            pintar_bordes();
            gotoxy(47, 2); cout << "los dados quedaron asi" << endl;
            gotoxy(2, 3); barrita();
            dibujar_dados(dados, 6);
            cout << endl;
            cout << endl;
            gotoxy(2, 13); barrita();
            if (generala(dados) == true) {
                puntaje = puntaje + 50;
                puntos = puntos + puntaje;
                }
            else {
                if (poker(dados) == true) {
                        puntaje = puntaje + 40;
                        puntos = puntos + puntaje;
                    }
                    else {
                        if (full(dados) == true) {
                            puntaje = puntaje + 30;
                            puntos = puntos + puntaje;
                        }
                        else {
                            if (escalera(dados) == true) {
                                puntaje = puntaje + 25;
                                puntos = puntos + puntaje;
                            }
                            else {
                                puntaje = puntaje + trio_duo_mayor(dados);
                                puntos = puntos + puntaje;
                            }
                        }
                    }
                }
            gotoxy(46, 14); cout << "Ronda Numero= " << ronda << endl;
            gotoxy(2, 15); barrita();
            gotoxy(46, 16); cout << "Nombre= " << nombre << endl;
            gotoxy(2, 17); barrita();
            gotoxy(46, 18); cout << "Tu puntaje de la ronda es= " << puntaje << endl;
            gotoxy(2, 19); barrita();
            gotoxy(2, 20); system("pause");
            system("cls");

        } //termino de while

        pintar_bordes();
        cuadrado(30,4);
        gotoxy(39, 6); cout << "Terminaste tu partida de Generala solitario" << endl;
        gotoxy(48, 10); cout << "Puntos totales ganados= " << puntos << endl;
        gotoxy(51, 13); cout << "Rondas totales= " << ronda << endl;
        gotoxy(2, 21); barrita();
        gotoxy(2, 22); cout << "Para volver al menu principal presione 1, presione 2 para salir" << endl;
        gotoxy(2, 23); barrita();

       if (ganoConPrimeraGenerala==true)
        {
            mayorNombre = nombre;
            mayorPuntuacion = puntos;
            rondasMayorPuntuacion = ronda;
            puntuacionMaximaFueConGeneralaServida = true;
        }
        else {
            if (puntos > mayorPuntuacion && puntuacionMaximaFueConGeneralaServida == false) {
            mayorNombre = nombre;
            mayorPuntuacion = puntos;
            rondasMayorPuntuacion = ronda;
        }
}
                char tecla = _getch();
                if (tecla == '1') {
                    system("cls");
                }
                else if (tecla == '2') {
                    seguirEjecutandoJuego = false;
                }
                else {
                    cout << "Tecla invalida, hasta luego" << endl;
                    system("pause");
                    seguirEjecutandoJuego = false;
                }
}
/*JUEGO DE 1*/
void modoDosJugadores(int& mayorPuntuacion, int& rondasMayorPuntuacion, string& mayorNombre,
    bool& seguirEjecutandoJuego, bool& ganoConPrimeraGenerala, bool& puntuacionMaximaFueConGeneralaServida) {
    bool modojuego_singular = false;
    system("cls");
    int puntaje = 0;   //PUNTAJE ES LA PUNTUACION POR RONDA
    int puntaje2 = 0;
    bool juegoterminado = false;
    int ronda = 0;
    int cant_rondas = 10;
    int puntos = 0;  //PUNTOS ES EL PUNTAJE TOTAL
    int puntos2 = 0;
    int dados[5];
    int dados2[5];
    int j;
    gotoxy(2, 5); barrita();
    gotoxy(2, 7); barrita();
    pintar_bordes();
    gotoxy(2, 2); cout << "Bienvenido al Juego de dos jugadores" << endl;
    string nombre = pedir_nombre(true);
    system("cls");
    gotoxy(2, 5); barrita();
    gotoxy(2, 7); barrita();
    pintar_bordes();
    string nombre2 = pedir_nombre(false);
    //-------------------------------------------------------------------------------------------
    cant_rondas=pedirRondas();//Funcion que retorna el valor de lo que dice su nombre
    //-------------------------------------------------------------------------------------------
    system("cls");
    //-------------------------------------------------------------------------------------------
    //-------------------------------------------------------------------------------------------
    //-------------------------------------------------------------------------------------------
    //-------------------------------------------------------------------------------------------
    while (ronda != cant_rondas && juegoterminado == false) {
        int turno = 0;
        ronda++;
        turno++;
        bool seguir = true;
        //carga los dados del jugador 1
        for (int i = 0; i < 5; i++) {
            dados[i] = (rand() % 6) + 1;
        }
        //dados los dados del jugador 2
        for (int i = 0; i < 5; i++) {
            dados2[i] = (rand() % 6) + 1;
        }
        //-------------------------------------------------------------------------------------------
        //-------------------------------------------------------------------------------------------
        //while  turno 1
        //-------------------------------------------------------------------------------------------
        //-------------------------------------------------------------------------------------------
        while (turno < 3 && seguir) {
            puntaje = 0;
            //----------------------------------------------------
            menu_lanzamientos(nombre, ronda, puntos, turno, dados);
            //----------------------------------------------------
            if (generala(dados) && turno == 1) {
                //--------------------------------
                pantallaGanoConGeneralaServida();//esta funcion, muestra lo que te imaginas viendo su nombre
                //--------------------------------
                ganoConPrimeraGenerala = true;
                juegoterminado = true;
                seguir = false;
            }
            else
            {
                turno++;
                gotoxy(2, 14); cout << "Lanzamiento Numero: " << turno;
                gotoxy(2, 15); barrita();
                if (!seguirLanzando())
                {
                    seguir = false;
                }
                else
                {
                    gotoxy(2, 18); cout << "cuantos dados? ";
                    cin >> j;
                    cout << endl;
                    int dados_tirar = 19;
                    for (int i = 0; i < j; i++) {
                        int f;
                        gotoxy(2, dados_tirar); cout << "cual dado desea tirar? ";
                        dados_tirar++;
                        cin >> f;
                        dados[f - 1] = rand() % 6 + 1;
                    }
                }
            }
            system("cls");
        }
        //-------------------------------------------------------------------------------------------
        //-------------------------------------------------------------------------------------------
        //termina while por turno1
        //-------------------------------------------------------------------------------------------
        //-------------------------------------------------------------------------------------------
        if (generala(dados) == true) {
            puntaje = puntaje + 50;
            puntos = puntos + puntaje;
        }
        else {
            if (poker(dados) == true) {
                puntaje = puntaje + 40;
                puntos = puntos + puntaje;
            }
            else {
                if (full(dados) == true) {
                    puntaje = puntaje + 30;
                    puntos = puntos + puntaje;
                }
                else {
                    if (escalera(dados) == true) {
                        puntaje = puntaje + 25;
                        puntos = puntos + puntaje;
                    }
                    else {
                        puntaje = puntaje + trio_duo_mayor(dados);
                        puntos = puntos + puntaje;
                    }


                }
            }
        }
        //-------------------------------------------------------------------------------------------
        menu_entre_rondas2p(nombre, nombre2, ronda, puntos, puntos2, turno, dados);
        //-------------------------------------------------------------------------------------------

        //-------------------------------------------------------------------------------------------
        //-------------------------------------------------------------------------------------------
        //while  turno 2
        //-------------------------------------------------------------------------------------------
        //-------------------------------------------------------------------------------------------
        seguir = true;
        turno = 1;
        while (turno < 3 && seguir) {
            puntaje2 = 0;
            //----------------------------------------------------
            menu_lanzamientos(nombre2, ronda, puntos2, turno, dados2);
            //----------------------------------------------------

            if (generala(dados2) && turno == 1) {
                //--------------------------------
                pantallaGanoConGeneralaServida();//esta funcion, hace lo que su nombre dice
                //--------------------------------
                ganoConPrimeraGenerala = true;
                juegoterminado = true;
                seguir = false;
            }
            else
            {
                turno++;
                gotoxy(2, 14); cout << "Lanzamiento Numero: " << turno;
                cout << endl;
                gotoxy(2, 15); barrita();
                cout << endl;
                if (!seguirLanzando())
                {
                    seguir = false;
                }
                else
                {
                    gotoxy(2, 18); cout << "cuantos dados? ";
                    cin >> j;
                    cout << endl;
                    int dados_tirar = 19;
                    int f;
                    for (int i = 0; i < j; i++) {
                        gotoxy(2, dados_tirar); cout << "cual dado desea tirar? ";
                        dados_tirar++;
                        cin >> f;
                        dados2[f - 1] = rand() % 6 + 1;
                    }
                }
            }
            system("cls");
        }
        //-------------------------------------------------------------------------------------------
        //-------------------------------------------------------------------------------------------
        //-------------------------------------------------------------------------------------------
        //termina while por turno2
        //-------------------------------------------------------------------------------------------
        //-------------------------------------------------------------------------------------------
        //-------------------------------------------------------------------------------------------
        if (generala(dados2) == true) {
            puntaje2 = puntaje2 + 50;
            puntos2 = puntos2 + puntaje2;
        }
        else {
            if (poker(dados2) == true) {
                puntaje2 = puntaje2 + 40;
                puntos2 = puntos2 + puntaje2;
            }
            else {
                if (full(dados2) == true) {
                    puntaje2 = puntaje2 + 30;
                    puntos2 = puntos2 + puntaje2;
                }
                else {
                    if (escalera(dados2) == true) {
                        puntaje2 = puntaje2 + 25;
                        puntos2 = puntos2 + puntaje2;
                    }
                    else {
                        puntaje2 = puntaje2 + trio_duo_mayor(dados2);
                        puntos2 = puntos2 + puntaje2;
                    }
                }
            }
        }
        // ------------------------termina-el-segundo-jugador----------------------------------------
        menu_entre_rondas2p(nombre2, nombre, ronda, puntos2, puntos, turno, dados2);
        //-------------------------------------------------------------------------------------------
    }
        //-------------------------------------------------------------------------------------------
        //-------------------------------------------------------------------------------------------
        //-------------------------------------------------------------------------------------------
        //-------------------------------------------------------------------------------------------
        //Termino de la generala de 2 jugadores
        pintar_bordes();
        cuadrado(30, 4);
        gotoxy(37, 7); cout << "Termino la partida de Generala Dos Jugadores" << endl;
        gotoxy(35, 10); cout << "Jugador= " << nombre << endl;
        gotoxy(35, 11); cout << "Puntos totales ganados del primer jugador= " << puntos << endl;
        gotoxy(35, 14); cout << "Jugador= " << nombre2 << endl;
        gotoxy(35, 15); cout << "Puntos totales ganados del segundo jugador= " << puntos2 << endl;
        gotoxy(51, 18); cout << "Rondas totales= " << ronda << endl;
        gotoxy(2, 20); barrita();
        gotoxy(2, 22); barrita();
        gotoxy(2, 21); system("pause");
        
        system("cls");
        
        string nombre_ganador2p;
        int puntuacion_ganador2p;
        /*FINAL GANADOR*/
        pintar_bordes();
        if (puntos > puntos2) {
            cuadrado(30, 4);
            gotoxy(46, 10); cout << "El ganador es el Jugador: " << nombre << endl;
            gotoxy(54, 12); cout << "Felicidades!!!" << endl;
            nombre_ganador2p = nombre;
            puntuacion_ganador2p = puntos;
        }
        else if (puntos == puntos2) {
            cuadrado(30, 4);
            gotoxy(54, 10); cout << "Hubo un empate" << endl;
            gotoxy(40, 12); cout << "Jueguense otra y denme de comer por favor" << endl;
            nombre_ganador2p = nombre + " y " + nombre2;
            puntuacion_ganador2p = puntos;
        }
        else {
            cuadrado(30, 4);
            gotoxy(46, 10); cout << "El ganador es el Jugador: " << nombre2 << endl;
            gotoxy(54, 12); cout << "Felicidades!!!" << endl;
            nombre_ganador2p = nombre2;
            puntuacion_ganador2p = puntos2;
        }
        gotoxy(2, 20); barrita();
        gotoxy(2, 21); cout << "Para volver al menu principal presione 1, presione 2 para salir" << endl;
        gotoxy(2, 22); barrita();

        if (ganoConPrimeraGenerala == true)
        {
            mayorNombre = nombre_ganador2p;
            mayorPuntuacion = puntuacion_ganador2p;
            rondasMayorPuntuacion = ronda;
            puntuacionMaximaFueConGeneralaServida = true;
        }
        else {
            if (puntuacion_ganador2p > mayorPuntuacion && puntuacionMaximaFueConGeneralaServida == false) {
                mayorNombre = nombre_ganador2p;
                mayorPuntuacion = puntuacion_ganador2p;
                rondasMayorPuntuacion = ronda;
            }
        }
                char tecla = _getch();
                if (tecla == '1') {
                    system("cls");
                }
                else if (tecla == '2') {
                    seguirEjecutandoJuego = false;
                }
                else {
                    gotoxy(2, 15); cout << "Tecla invalida, hasta luego" << endl;
                    system("pause");
                    seguirEjecutandoJuego = false;
                }
}
/*JUEGO DE 2*/
void mostrarMayorPuntuacion(string mayorNombre,int mayorPuntuacion,int rondasMayorPuntuacion,bool &seguirEjecutandoJuego) {
    system("cls");
    pintar_bordes();
    cuadrado(30,4);
    gotoxy(2, 2); barrita();
    gotoxy(30, 3); cout << "La persona con el puntaje mas alto de ambos modos de juego es= " << endl;
    gotoxy(2, 4); barrita();
    gotoxy(48, 9); cout << "Nombre= " << mayorNombre << endl;
    gotoxy(48, 11); cout << "Su puntuacion es= " << mayorPuntuacion << endl;
    gotoxy(48, 13); cout << "En la cantidad de rondas= " << rondasMayorPuntuacion << endl;
    gotoxy(2, 20); barrita();
    gotoxy(2, 21); cout << "Para volver al menu principal presione 1, presione 2 para salir" << endl;
    gotoxy(2, 22); barrita();
            char tecla = _getch();
            if (tecla == '1') {
                system("cls");
                seguirEjecutandoJuego = true;
            }
            else if (tecla == '2') {
                system("cls");
                seguirEjecutandoJuego = false;
            }
            else {
                gotoxy(2, 22); cout << "Tecla invalida, hasta luego" << endl;
                gotoxy(2, 23); system("pause");
                seguirEjecutandoJuego = false;
            }
}
/*PUNTUACION MAS ALTA*/
void instrucciones() {
    gotoxy(2, 2); cout << "Reglamentos del Juego" << endl;
    gotoxy(2, 3); barrita();
    gotoxy(2, 4); cout << "El objetivo del juego es sacar Generala Servida, u obtener la puntuacion mas alta de un conjunto de rondas" << endl;
    gotoxy(2, 5); cout << "establecidas. Una ronda puede estar compuesta por hasta tres lanzamientos por jugador. Un lanzamiento" << endl;
    gotoxy(2, 6); cout << "consiste en tirar los cinco dados y evaluar sus valores para determinar el puntaje. En caso que el" << endl;
    gotoxy(2, 7); cout << "jugador lo  considere puede volver a tirar todos a algunos de los dados en dos oportunidades mas. El" << endl;
    gotoxy(2, 8); cout << "sistema preguntara si quiere volver a lanzar, y si la respuesta es si, preguntara cuales son los dados" << endl;
    gotoxy(2, 9); cout << "que quiere elegir para volver a tirar. El puntaje de un lanzamiento esta determinado por una serie de" << endl;
    gotoxy(2, 10); cout << "de reglas que figuran en la seccion Combinaciones ganadoras. El puntaje obtenido se suma al puntaje" << endl;
    gotoxy(2, 11); cout << "anterior del jugador. Si un jugador saca Generala en el primer tiro gana la partida." << endl;
    gotoxy(2, 12); barrita();
    gotoxy(2, 13); cout << "|          Combinacion               | Nombre jugada |                Puntaje otorgado             |    " << endl;
    gotoxy(2, 14); barrita();
    gotoxy(2, 15); cout << "|    1 o mas dados con valor 1       |   Juego de 1  | Suma de la cantidad de dados con el valor 1 |" <<endl;
    gotoxy(2, 16); cout << "|    1 o mas dados con valor 2       |   Juego de 2  | Suma de la cantidad de dados con el valor 2 |" << endl;
    gotoxy(2, 17); cout << "|    1 o mas dados con valor 3       |   Juego de 3  | Suma de la cantidad de dados con el valor 3 |" << endl;
    gotoxy(2, 18); cout << "|    1 o mas dados con valor 4       |   Juego de 4  | Suma de la cantidad de dados con el valor 4 |" << endl;
    gotoxy(2, 19); cout << "|    1 o mas dados con valor 5       |   Juego de 5  | Suma de la cantidad de dados con el valor 5 |" << endl;
    gotoxy(2, 20); cout << "|    1 o mas dados con valor 6       |   Juego de 6  | Suma de la cantidad de dados con el valor 6 |" << endl;
    gotoxy(2, 21); barrita();
    gotoxy(2, 22); cout << "|    5 dados en orden creciente      |    Escalera   |                     25                      |" << endl;
    gotoxy(2, 23); cout << "|     (1,2,3,4,5)/(2,3,4,5,6)        |               |                                             |" << endl;
    gotoxy(2, 24); cout << "|3 dados iguales, mas otros 2 iguales|    Full       |                     30                      |" << endl;
    gotoxy(2, 25); cout << "|     (3,3,3,2,2)/(1,1,4,4,4)        |               |                                             |" << endl;
    gotoxy(2, 26); cout << "|      4 dados iguales               |    Poker      |                     40                      |" << endl;
    gotoxy(2, 27); cout << "|     (3,3,3,3,2), (1,4,4,4,4)       |               |                                             |" << endl;
    gotoxy(2, 28); cout << "|      5 dados con el mismo valor    |    Generala   |                     50                      |" << endl;
    gotoxy(2, 29); cout << "|     (1,1,1,1,1) , (6,6,6,6,6)      |               |                                             |" << endl;
    pintar_bordes(); 
}
/*INSTRUCCIONES*/