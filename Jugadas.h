#pragma once
#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include <iostream>
#include <stdlib.h>   
#include "Menu.h"
#include "Dados.h"
#include "Juego.h"
/*JUGADAS
INT. ENTERO
BOOL. BANDERA
DADOS [] VECTOR 6
STRING. CONJUNTO DE CHARS
*/
int repetidos_Dado(int dados[], int n) {
    int dado = 0;
    for (int i = 0; i < 5; i++) {
        if (dados[i] == n) {
            dado++;
        }
    }
    return dado;
}
bool full(int dados[]) {
    int bandera = 0;
    int bandera1 = 0;
    for (int i = 1; i <= 6; i++) {
        if (repetidos_Dado(dados, i) == 3) {
            bandera++;
        }
    }
    for (int i = 1; i <= 6; i++) {
        if (repetidos_Dado(dados, i) == 2) {
            bandera1++;
        }

    }
    if (bandera == 1 && bandera1 == 1) {
        return true;
    }
    else {
        return false;
    }
}
bool poker(int dados[]) {
    for (int i = 1; i <= 6; i++) {
        if (repetidos_Dado(dados, i) == 4) {
            return true;
        }
    }
    return false;
}
bool generala(int dados[]) {
    for (int i = 1; i <= 6; i++) {
        if (repetidos_Dado(dados, i) == 5) {
            return true;
        }
    }
    return false;
}
bool escalera(int dados[]) {
    int c = 0;
    int n = 0;
    for (int i = 1; i <= 5; i++) {
        if (repetidos_Dado(dados, i) == 1) {
            c++;
        }

    }
    for (int i = 2; i <= 6; i++) {
        if (repetidos_Dado(dados, i) == 1) {
            n++;
        }

    }
    if (c == 5 || n == 5) {
        return true;
    }
    else {
        return false;
    }
}
int trio(int dados[]) {
    for (int i = 1; i <= 6; i++) {
        if (repetidos_Dado(dados, i) == 3) {
            return i;
        }
    }
    return 0;
}
int duo_Doble(int dados[]) {
    bool unduo = false;
    int primerduo;
    for (int i = 1; i <= 6; i++) {
        if (repetidos_Dado(dados, i) == 2) {
            unduo = true;
            primerduo = i;
        }

    }
    if (unduo == true) {
        for (int i = 1; i <= 6; i++) {
            if (repetidos_Dado(dados, i) == 2 && repetidos_Dado(dados, i) != primerduo) {
                if (primerduo > repetidos_Dado(dados, i)) {
                    return primerduo;
                }
                else repetidos_Dado(dados, i);
            }
            else {
                return primerduo;
            }
        }
    }
    return 0;
}
int mayor(int dados[]) {
    int mayor = dados[0];
    for (int i = 0; i < 5; i++) {
        if (mayor < dados[i]) {
            mayor = dados[i];
        }

    }
    return mayor;
}
int trio_duo_mayor(int dados[]) {
    if (trio(dados) * 3 > duo_Doble(dados) * 2 && trio(dados) * 3 > mayor(dados)) {
        return trio(dados) * 3;
    }
    else {
        if (duo_Doble(dados) * 2 > trio(dados) * 3 && duo_Doble(dados) * 2 > mayor(dados)) {
            return duo_Doble(dados) * 2;
        }
        else {
            return mayor(dados);
        }
    }
}