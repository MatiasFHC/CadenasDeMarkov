#include <iostream>
#include <ctime>
#include <windows.h>
#include <iomanip>
using namespace std;

void gotoxy(int x, int y) {
    COORD p = { x, y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), p);
}

void colores(int color) {
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(h, color);
}

int tabla[20][70] = {
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
};

int tabla2[31][70] = {
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
};

void DibujarTabla() {
    colores(9);
    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 70; j++) {
            switch (tabla[i][j]) {
            case 0:
                cout << char(219);
                break;
            case 1:
                cout << " ";
                break;
            }
        }
        cout << endl;
    }
}

void DibujarTabla2() {
    colores(9);
    for (int i = 0; i < 31; i++) {
        for (int j = 0; j < 70; j++) {
            switch (tabla2[i][j]) {
            case 0:
                cout << char(219);
                break;
            case 1:
                cout << " ";
                break;
            }
        }
        cout << endl;
    }
}

int opcion() {
    int opcion;
    do {
        system("cls");
        DibujarTabla();
        colores(7);
        gotoxy(50, 2); cout << "ClimaNow";
        gotoxy(47, 5); cout << "Elija la opcion: " << endl;
        gotoxy(44, 7); cout << "(1) Desea ingresar la" << endl;
        gotoxy(45, 8); cout << "cantidad de los dias" << endl;
        gotoxy(44, 10); cout << "(2) Desea que sean" << endl;
        gotoxy(42, 11); cout << "generados aleatoriamente" << endl;
        gotoxy(48, 13); cout << "(3) Creditos" << endl;
        gotoxy(48, 15); cout << "(4) Salir" << endl;
        gotoxy(50, 17); cout << "--> ";
        cin >> opcion;
    } while (!(opcion == 1 || opcion == 2 || opcion == 3 || opcion == 4));
    return opcion;
}

void mostrar_opcion(int opcion) {
    DibujarTabla();
    colores(7);
    gotoxy(50, 2); cout << "ClimaNow";
    gotoxy(47, 5); cout << "Elija la opcion: " << endl;
    gotoxy(44, 7); cout << "(1) Desea ingresar la" << endl;
    gotoxy(45, 8); cout << "cantidad de los dias" << endl;
    gotoxy(44, 10); cout << "(2) Desea que sean" << endl;
    gotoxy(42, 11); cout << "generados aleatoriamente" << endl;
    gotoxy(48, 13); cout << "(3) Creditos" << endl;
    gotoxy(48, 15); cout << "(4) Salir" << endl;
    gotoxy(46, 17);  cout << "Opcion escogida: " << opcion << endl;
}

void creditos() {
    DibujarTabla2();
    colores(7);
    gotoxy(50, 2); cout << "Clima Now" << endl;
    gotoxy(43, 4); cout << "Programa para estimar el" << endl;
    gotoxy(43, 5); cout << "clima en una determinada" << endl;
    gotoxy(43, 6); cout << "ciudad empleando Cadenas" << endl;
    gotoxy(49, 7); cout << "de Markov" << endl;

    gotoxy(44, 9); cout << "Universidad Peruana de" << endl;
    gotoxy(45, 10); cout << "Ciencias Aplicadas" << endl;


    gotoxy(48, 12); cout << "Integrantes:" << endl;
    gotoxy(43, 13); cout << "- Angela Adriana Collazos" << endl;
    gotoxy(43, 14); cout << "Zuniga (202213515)" << endl;

    gotoxy(43, 16); cout << "- Juan Eduardo Guerrero" << endl;
    gotoxy(43, 17); cout << "Ojeda (202212754)" << endl;

    gotoxy(43, 19); cout << "- Luciana Valeria Gonzales" << endl;
    gotoxy(43, 20); cout << "Díaz (202213814)" << endl;

    gotoxy(43, 22); cout << "- Matias Fabian Hidalgo" << endl;
    gotoxy(43, 23); cout << "Castillo (U202211900)" << endl;

    gotoxy(43, 25); cout << "- Braulio Joaquin Adriano" << endl;
    gotoxy(43, 26); cout << "Silva Linares (U202210380)" << endl;

    gotoxy(41, 28); cout << " Curso: Matematica discreta" << endl;
    gotoxy(46, 29); cout << " Ciclo 2023 - 01" << endl;
}

void ObtenerDias(int dias, float Lista[]) {
    float num = 0;
    for (int i = 0; i < dias; i++) {
        num = 1 + rand() % (5 - 1);
        Lista[i] = num;
        num = 0;
    }
}

void CantDias(int dias, float Lista[], float& cont1, float& cont2, float& cont3, float& cont4) {
    for (int i = 0; i < dias; i++) {
        if (Lista[i] == 1) {
            cont1 += 1;
        }
        if (Lista[i] == 2) {
            cont2 += 1;
        }
        if (Lista[i] == 3) {
            cont3 += 1;
        }
        if (Lista[i] == 4) {
            cont4 += 1;
        }
    }
}

void MostrarDatos(int dias, float cont1, float cont2, float cont3, float cont4) {
    cout << endl;
    cout << "El numero total de dias es: " << dias << endl;
    cout << "Dias nublados: " << cont1 << "(" << (100 * cont1) / dias << "%)" << endl;
    cout << "Dias parcialmente nublados: " << cont2 << "(" << (100 * cont2) / dias << "%)" << endl;
    cout << "Dias parcialmente soleados: " << cont3 << "(" << (100 * cont3) / dias << "%)" << endl;
    cout << "Dias soleados: " << cont4 << "(" << (100 * cont4) / dias << "%)" << endl;
    cout << endl;
}

void matriz_principal(double matriz_principal[][4], int dias, float Lista[]) {
    float cont1_1 = 0, cont2_1 = 0, cont3_1 = 0, cont4_1 = 0;
    float cont1_2 = 0, cont2_2 = 0, cont3_2 = 0, cont4_2 = 0;
    float cont1_3 = 0, cont2_3 = 0, cont3_3 = 0, cont4_3 = 0;
    float cont1_4 = 0, cont2_4 = 0, cont3_4 = 0, cont4_4 = 0;

    for (int i = 0; i <= dias; i++) {
        if (Lista[i] == 1) {
            if (Lista[i + 1] == 1) {
                cont1_1++;
            }
            if (Lista[i + 1] == 2) {
                cont2_1++;
            }
            if (Lista[i + 1] == 3) {
                cont3_1++;
            }
            if (Lista[i + 1] == 4) {
                cont4_1++;
            }

        }
        if (Lista[i] == 2) {
            if (Lista[i + 1] == 1) {
                cont1_2++;
            }
            if (Lista[i + 1] == 2) {
                cont2_2++;
            }
            if (Lista[i + 1] == 3) {
                cont3_2++;
            }
            if (Lista[i + 1] == 4) {
                cont4_2++;
            }
        }
        if (Lista[i] == 3) {
            if (Lista[i + 1] == 1) {
                cont1_3++;
            }
            if (Lista[i + 1] == 2) {
                cont2_3++;
            }
            if (Lista[i + 1] == 3) {
                cont3_3++;
            }
            if (Lista[i + 1] == 4) {
                cont4_3++;
            }
        }
        if (Lista[i] == 4) {

            if (Lista[i + 1] == 1) {
                cont1_4++;
            }
            if (Lista[i + 1] == 2) {
                cont2_4++;
            }
            if (Lista[i + 1] == 3) {
                cont3_4++;
            }
            if (Lista[i + 1] == 4) {
                cont4_4++;
            }
        }
    }

    matriz_principal[0][0] = (cont1_1 / (cont1_1 + cont2_1 + cont3_1 + cont4_1));
    matriz_principal[1][0] = (cont2_1 / (cont1_1 + cont2_1 + cont3_1 + cont4_1));
    matriz_principal[2][0] = (cont3_1 / (cont1_1 + cont2_1 + cont3_1 + cont4_1));
    matriz_principal[3][0] = (cont4_1 / (cont1_1 + cont2_1 + cont3_1 + cont4_1));

    matriz_principal[0][1] = (cont1_2 / (cont1_2 + cont2_2 + cont3_2 + cont4_2));
    matriz_principal[1][1] = (cont2_2 / (cont1_2 + cont2_2 + cont3_2 + cont4_2));
    matriz_principal[2][1] = (cont3_2 / (cont1_2 + cont2_2 + cont3_2 + cont4_2));
    matriz_principal[3][1] = (cont4_2 / (cont1_2 + cont2_2 + cont3_2 + cont4_2));

    matriz_principal[0][2] = (cont1_3 / (cont1_3 + cont2_3 + cont3_3 + cont4_3));
    matriz_principal[1][2] = (cont2_3 / (cont1_3 + cont2_3 + cont3_3 + cont4_3));
    matriz_principal[2][2] = (cont3_3 / (cont1_3 + cont2_3 + cont3_3 + cont4_3));
    matriz_principal[3][2] = (cont4_3 / (cont1_3 + cont2_3 + cont3_3 + cont4_3));

    matriz_principal[0][3] = (cont1_4 / (cont1_4 + cont2_4 + cont3_4 + cont4_4));
    matriz_principal[1][3] = (cont2_4 / (cont1_4 + cont2_4 + cont3_4 + cont4_4));
    matriz_principal[2][3] = (cont3_4 / (cont1_4 + cont2_4 + cont3_4 + cont4_4));
    matriz_principal[3][3] = (cont4_4 / (cont1_4 + cont2_4 + cont3_4 + cont4_4));

    int n = 0, pn = 0, ps = 0, s = 0;
    cout << "------------------------------" << endl;
    cout << "La matriz estocastica es: " << endl;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            cout << fixed << setprecision(4) << matriz_principal[i][j] << "|";
        }
        cout << endl;
    }
}

void Vector(int dias, float Lista[], float matriz_vector[]) {
    int a1 = 0, a2 = 0, a3 = 0, a4 = 0;
    if (Lista[dias - 1] == 1) {
        a1++;
    }
    if (Lista[dias - 1] == 2) {
        a2++;
    }
    if (Lista[dias - 1] == 3) {
        a3++;
    }
    if (Lista[dias - 1] == 4) {
        a4++;
    }

    if (a1 == 1) {
        matriz_vector[1] = 1;
        matriz_vector[2] = 0;
        matriz_vector[3] = 0;
        matriz_vector[0] = 0;
    }
    if (a2 == 1) {
        matriz_vector[2] = 0;
        matriz_vector[1] = 1;
        matriz_vector[3] = 0;
        matriz_vector[0] = 0;

    }
    if (a3 == 1) {
        matriz_vector[3] = 0;
        matriz_vector[1] = 0;
        matriz_vector[2] = 1;
        matriz_vector[0] = 0;
    }
    if (a4 == 1) {
        matriz_vector[3] = 1;
        matriz_vector[2] = 0;
        matriz_vector[1] = 0;
        matriz_vector[0] = 0;
    }
    cout << "------------------------------" << endl;
    cout << "El vector de probabilidades, que se calcula a patir de hoy dia, es: " << endl;
    for (int i = 0; i < 4; i++) {
        cout << fixed << setprecision(0) << "|" << matriz_vector[i] << "|";
        cout << endl;
    }
    cout << endl;
}

void primer_resultado(double matriz_principal[][4], float matriz_vector[], float primer_resultado[]) {
    for (int i = 0; i < 4; i++) {
        primer_resultado[i] = 0;
        for (int j = 0; j < 4; j++) {
            primer_resultado[i] += matriz_principal[i][j] * matriz_vector[j];
        }
    }
    cout << "El resultado de multiplicar la matriz estocastica por el vector de probabilidades es:" << endl;
    for (int i = 0; i < 4; ++i) {
        cout << fixed << setprecision(4) << "|" << primer_resultado[i] << "|" << endl;
    }
    cout << endl;
    cout << "Por lo tanto, lo mas probable es que al siguiente dia (n+1) sea: " << endl;

    float probabilidad1 = primer_resultado[0];
    int pos = 0;
    for (int i = 0; i < 4; ++i) {
        if (primer_resultado[i] > probabilidad1) {
            pos = 0;
            probabilidad1 = primer_resultado[i];
            pos += i;
        }
    }
    if (pos == 0) {
        cout << "Nublado, con una probabilidad de " << probabilidad1 << endl;
    }
    if (pos == 1) {
        cout << "Parcialmente Nublado, con una probabilidad de " << probabilidad1 << endl;
    }
    if (pos == 2) {
        cout << "Parcialemnte Soleado, con una probabilidad de " << probabilidad1 << endl;
    }
    if (pos == 3) {
        cout << "Soleado, con una probabilidad de " << probabilidad1 << endl;
    }
    cout << endl;
}

void segundo_resultado(double matriz_principal[][4], float matriz_vector[], float segundo_resultado[]) {
    float M2[4][4];
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            M2[i][j] = 0;
            for (int k = 0; k < 4; k++) {
                M2[i][j] += matriz_principal[i][k] * matriz_principal[k][j];
            }
        }
    }
    for (int i = 0; i < 4; i++) {
        segundo_resultado[i] = 0;
        for (int j = 0; j < 4; j++) {
            segundo_resultado[i] += M2[i][j] * matriz_vector[j];
        }
    }
    cout << "El resultado de multiplicar la matriz estocastica por si misma y por el vector de probabilidades es:" << endl;
    for (int i = 0; i < 4; ++i) {
        cout << fixed << setprecision(4) << "|" << segundo_resultado[i] << "|" << endl;
    }
    cout << endl;
    cout << "Por lo tanto, lo mas probable es que al segundo dia (n+2) sea: " << endl;

    float probabilidad1 = segundo_resultado[0];
    int pos = 0;
    for (int i = 0; i < 4; ++i) {
        if (segundo_resultado[i] > probabilidad1) {
            pos = 0;
            probabilidad1 = segundo_resultado[i];
            pos += i;
        }
    }
    if (pos == 0) {
        cout << "Nublado, con una probabilidad de " << probabilidad1 << endl;
    }
    if (pos == 1) {
        cout << "Parcialmente Nublado, con una probabilidad de " << probabilidad1 << endl;
    }
    if (pos == 2) {
        cout << "Parcialemnte Soleado, con una probabilidad de " << probabilidad1 << endl;
    }
    if (pos == 3) {
        cout << "Soleado, con una probabilidad de " << probabilidad1 << endl;
    }
    cout << endl;
}

void tercer_resultado(double matriz_principal[][4], float matriz_vector[], float tercer_resultado[]) {
    float M2[4][4];
    float M3[4][4];
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            M2[i][j] = 0;
            for (int k = 0; k < 4; k++) {
                M2[i][j] += matriz_principal[i][k] * matriz_principal[k][j];
            }
        }
    }

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            M3[i][j] = 0;
            for (int k = 0; k < 4; k++) {
                M3[i][j] += M2[i][k] * matriz_principal[k][j];
            }
        }
    }

    for (int i = 0; i < 4; i++) {
        tercer_resultado[i] = 0;
        for (int j = 0; j < 4; j++) {
            tercer_resultado[i] += M3[i][j] * matriz_vector[j];
        }
    }
    cout << "El resultado de hallar la matriz estocastica al cubo por el vector de probabilidades es:" << endl;
    for (int i = 0; i < 4; ++i) {
        cout << fixed << setprecision(4) << "|" << tercer_resultado[i] << "|" << endl;
    }
    cout << endl;
    cout << "Por lo tanto, lo mas probable es que al tercer dia (n+3) sea: " << endl;

    float probabilidad1 = tercer_resultado[0];
    int pos = 0;
    for (int i = 0; i < 4; ++i) {
        if (tercer_resultado[i] > probabilidad1) {
            pos = 0;
            probabilidad1 = tercer_resultado[i];
            pos += i;
        }
    }
    if (pos == 0) {
        cout << "Nublado, con una probabilidad de " << probabilidad1 << endl;
    }
    if (pos == 1) {
        cout << "Parcialmente Nublado, con una probabilidad de " << probabilidad1 << endl;
    }
    if (pos == 2) {
        cout << "Parcialemnte Soleado, con una probabilidad de " << probabilidad1 << endl;
    }
    if (pos == 3) {
        cout << "Soleado, con una probabilidad de " << probabilidad1 << endl;
    }
    cout << endl;
}

void cuarto_resultado(double matriz_principal[][4], float matriz_vector[], float cuarto_resultado[]) {
    float M2[4][4];
    float M3[4][4];
    float M4[4][4];
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            M2[i][j] = 0;
            for (int k = 0; k < 4; k++) {
                M2[i][j] += matriz_principal[i][k] * matriz_principal[k][j];
            }
        }
    }

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            M3[i][j] = 0;
            for (int k = 0; k < 4; k++) {
                M3[i][j] += M2[i][k] * matriz_principal[k][j];
            }
        }
    }

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            M4[i][j] = 0;
            for (int k = 0; k < 4; k++) {
                M4[i][j] += M3[i][k] * matriz_principal[k][j];
            }
        }
    }

    for (int i = 0; i < 4; i++) {
        cuarto_resultado[i] = 0;
        for (int j = 0; j < 4; j++) {
            cuarto_resultado[i] += M4[i][j] * matriz_vector[j];
        }
    }
    cout << "El resultado de hallar la matriz estocastica a la cuarta por el vector de probabilidades es:" << endl;
    for (int i = 0; i < 4; ++i) {
        cout << fixed << setprecision(4) << "|" << cuarto_resultado[i] << "|" << endl;
    }
    cout << endl;
    cout << "Por lo tanto, lo mas probable es que al cuarto dia (n+4) sea: " << endl;

    float probabilidad1 = cuarto_resultado[0];
    int pos = 0;
    for (int i = 0; i < 4; ++i) {
        if (cuarto_resultado[i] > probabilidad1) {
            pos = 0;
            probabilidad1 = cuarto_resultado[i];
            pos += i;
        }
    }
    if (pos == 0) {
        cout << "Nublado, con una probabilidad de " << probabilidad1 << endl;
    }
    if (pos == 1) {
        cout << "Parcialmente Nublado, con una probabilidad de " << probabilidad1 << endl;
    }
    if (pos == 2) {
        cout << "Parcialemnte Soleado, con una probabilidad de " << probabilidad1 << endl;
    }
    if (pos == 3) {
        cout << "Soleado, con una probabilidad de " << probabilidad1 << endl;
    }
    cout << endl;
}

int opcion_clima() {
    int opcion;
    do {
        system("cls");
        DibujarTabla();
        colores(7);
        gotoxy(47, 2); cout << "Ingrese la opcion: " << endl;
        gotoxy(42, 4); cout << "(1) Clima al siguiente" << endl;
        gotoxy(47, 5); cout << "dia (n+1)" << endl;
        gotoxy(42, 7); cout << "(2) Clima al segundo" << endl;
        gotoxy(47, 8); cout << "dia (n+2)" << endl;
        gotoxy(42, 10); cout << "(3) Clima al tercer" << endl;
        gotoxy(47, 11); cout << "dia (n+3)" << endl;
        gotoxy(42, 13); cout << "(4) Clima al cuarto" << endl;
        gotoxy(47, 14); cout << "dia (n+4)" << endl;
        gotoxy(42, 16); cout << "(5) Volver al menu" << endl;
        gotoxy(42, 18); cout << "--> "; cin >> opcion;
        gotoxy(40, 21);
    } while (!(opcion == 1 || opcion == 2 || opcion == 3 || opcion == 4 || opcion == 5));
    return opcion;
}

void opcion1() {
    int dias;
    do {
        DibujarTabla();
        colores(7);
        gotoxy(46, 8); cout << "Ingrese la cantidad";
        gotoxy(50, 9); cout << "de dias: ";
        cin >> dias;
        system("cls");
    } while (!(dias >= 60 && dias <= 90));
    system("cls");
    float Lista[91];
    float cont1 = 0, cont2 = 0, cont3 = 0, cont4 = 0;

    ObtenerDias(dias, Lista);

    CantDias(dias, Lista, cont1, cont2, cont3, cont4);

    MostrarDatos(dias, cont1, cont2, cont3, cont4);

    double matriz_principa[4][4];
    matriz_principal(matriz_principa, dias, Lista);

    float matriz_vector[4];
    Vector(dias, Lista, matriz_vector);

    system("pause");

    float pri_resultado[4];
    float seg_resultado[4];
    float ter_resultado[4];
    float cua_resultado[4];

    int opcion = 0;
    while (opcion != 6) {
        opcion = opcion_clima();
        if (opcion == 1) {
            system("cls");
            primer_resultado(matriz_principa, matriz_vector, pri_resultado);
            system("pause");
        }
        if (opcion == 2) {
            system("cls");
            segundo_resultado(matriz_principa, matriz_vector, seg_resultado);
            system("pause");
        }
        if (opcion == 3) {
            system("cls");
            tercer_resultado(matriz_principa, matriz_vector, ter_resultado);
            system("pause");
        }
        if (opcion == 4) {
            system("cls");
            cuarto_resultado(matriz_principa, matriz_vector, cua_resultado);
            system("pause");
        }
        if (opcion == 5) {
            system("cls");
            opcion = 6;
        }
    }
}

void opcion2() {
    int N;
    N = 60 + rand() % (91 - 60);

    float Lista[91];
    float cont1 = 0, cont2 = 0, cont3 = 0, cont4 = 0;

    ObtenerDias(N, Lista);

    CantDias(N, Lista, cont1, cont2, cont3, cont4);

    MostrarDatos(N, cont1, cont2, cont3, cont4);

    double matriz_principa[4][4];
    matriz_principal(matriz_principa, N, Lista);

    float matriz_vector[4];
    Vector(N, Lista, matriz_vector);

    system("pause");

    float pri_resultado[4];
    float seg_resultado[4];
    float ter_resultado[4];
    float cua_resultado[4];

    int opcion = 0;
    while (opcion != 6) {
        opcion = opcion_clima();
        if (opcion == 1) {
            system("cls");
            primer_resultado(matriz_principa, matriz_vector, pri_resultado);
            system("pause");
        }
        if (opcion == 2) {
            system("cls");
            segundo_resultado(matriz_principa, matriz_vector, seg_resultado);
            system("pause");
        }
        if (opcion == 3) {
            system("cls");
            tercer_resultado(matriz_principa, matriz_vector, ter_resultado);
            system("pause");
        }
        if (opcion == 4) {
            system("cls");
            cuarto_resultado(matriz_principa, matriz_vector, cua_resultado);
            system("pause");
        }
        if (opcion == 5) {
            system("cls");
            opcion = 6;
        }
    }
}

void opciones() {
    int ops = 0;
    while (ops != 5) {
        ops = opcion();
        gotoxy(0, 21);
        system("pause");
        system("cls");

        mostrar_opcion(ops);
        gotoxy(0, 21);

        system("pause");
        system("cls");
        if (ops == 1) {
            system("cls");
            opcion1();
            system("pause");
            system("cls");
        }
        if (ops == 2) {
            system("cls");
            opcion2();
            system("pause");
            system("cls");
        }
        if (ops == 3) {
            system("cls");
            creditos();
            system("pause");
            system("cls");
        }
        if (ops == 4) {
            system("cls");
            ops = 5;
        }
    }
}

int main() {
    srand(time(NULL));
    opciones();
}