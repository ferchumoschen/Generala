#pragma once
#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include <iostream>
/*GOTOXY X Horizontal;Y Vertical*/
using namespace std;
void gotoxy(int x, int y) {
    HANDLE hCon;
    hCon = GetStdHandle(STD_OUTPUT_HANDLE); /*Controladores que identifican la salida de coordenadas*/
    COORD dwPos;
    dwPos.X = x;
    dwPos.Y = y;
    SetConsoleCursorPosition(hCon, dwPos); /*Establece la posicion final del cursor*/
}
void pintar_bordes() {
    for (int i = 1; i < 120; i++) {
        gotoxy(i, 1); printf("%c", 205);
        gotoxy(i, 30); printf("%c", 205);
    };
    for (int i = 1; i < 30; i++) {
        gotoxy(1, i); printf("%c", 186);
        gotoxy(119, i); printf("%c", 186);
    };
    gotoxy(1, 1); printf("%c", 201);
    gotoxy(1, 30); printf("%c", 200);
    gotoxy(119, 1); printf("%c", 187);
    gotoxy(119, 30); printf("%c", 188);
};
char menu(string cosito[], int opciones) {
    int Y;
    pintar_bordes();
    for (int i = 0; i < opciones; i++)
    {
        Y = (i * 2) + 2;
        gotoxy(2, (i * 2) + 2); cout << cosito[i]; //escribe el menu
    }
            char tecla = _getch();//obtiene el valor de la tecla pulsada
            return tecla;
}
void cuadrado(int x, int y) {
    for (int i = x+1; i < x+60; i++) {
        gotoxy(i, y+1); printf("%c", 205);
        gotoxy(i, y+15); printf("%c", 205);
    };
    for (int i = y+1; i < y+15; i++) {
        gotoxy(x+1, i); printf("%c", 186);
        gotoxy(x+59, i); printf("%c", 186);
    };
    gotoxy(x+1, y+1); printf("%c", 201);
    gotoxy(x+1, y+15); printf("%c", 200);
    gotoxy(x+59, y+1); printf("%c", 187);
    gotoxy(x+59, y+15); printf("%c", 188);
};
