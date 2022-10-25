#pragma once
#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include <iostream>

using namespace std;
/*%C Para caracteres*/
void marco_dado(int x, int y) {
    gotoxy(x, y + 1); printf("%c%c%c%c%c%c%c%c%c%c%c", 201, 205, 205, 205, 205, 205, 205, 205, 205, 205, 187);
    gotoxy(x, y + 2); printf("%c         %c", 186, 186);
    gotoxy(x, y + 3); printf("%c         %c", 186, 186);
    gotoxy(x, y + 4); printf("%c         %c", 186, 186);
    gotoxy(x, y + 5); printf("%c%c%c%c%c%c%c%c%c%c%c", 200, 205, 205, 205, 205, 205, 205, 205, 205, 205, 188);

}
void dibujar_dados(int dados[],int y) {
    
    int x = 30;

    for (int i = 0; i < 5; i++) {

        marco_dado(x, y); //se dibuja el marco del dado

        switch (dados[i]) {//se llena el dado con los puntitos correspondientes
        case 1: {
           gotoxy(x + 5, y + 3); printf("%c", 254); 
            break;
        }
        case 2: {
           gotoxy(x + 7, y + 2); printf("%c", 254);
            gotoxy(x + 3, y + 4); printf("%c", 254);
            break;
        }
        case 3: {
            gotoxy(x + 7, y + 2); printf("%c", 254);
            gotoxy(x + 5, y + 3); printf("%c", 254);
            gotoxy(x + 3, y + 4); printf("%c", 254);
            break;
        }
        case 4: {
            gotoxy(x + 7, y + 2); printf("%c", 254);
            gotoxy(x + 7, y + 4); printf("%c", 254);
            gotoxy(x + 3, y + 2); printf("%c", 254);
            gotoxy(x + 3, y + 4); printf("%c", 254);
            break;
        }
        case 5: {
            gotoxy(x + 7, y + 2); printf("%c", 254);
            gotoxy(x + 7, y + 4); printf("%c", 254);
            gotoxy(x + 5, y + 3); printf("%c", 254);
            gotoxy(x + 3, y + 2); printf("%c", 254);
            gotoxy(x + 3, y + 4); printf("%c", 254);
            break;
        }
        case 6: {
            gotoxy(x + 7, y + 2); printf("%c", 254);
            gotoxy(x + 7, y + 4); printf("%c", 254);
            gotoxy(x + 7, y + 3); printf("%c", 254);
            gotoxy(x + 3, y + 3); printf("%c", 254);
            gotoxy(x + 3, y + 2); printf("%c", 254);
            gotoxy(x + 3, y + 4); printf("%c", 254);
            break;
        }

        }
        x += 11;

    }
    cout << endl;
}