#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
using namespace std;

char nombreUsuario[30];
int contandoVocales(char *);

void pedirDatos();


int main(){

    pedirDatos();
    cout << "El numero de vocales del nombre es: " <<contandoVocales(nombreUsuario) << endl;
    return 0;
}

void pedirDatos(){
    cout << "Ingrese su nombre: "; cin.getline(nombreUsuario,30,'\n');
    strupr(nombreUsuario); //CAMBIA NOMBRE A MAYUSCULA
}

int contandoVocales(char *nombre){
    int cont = 0;

    while(*nombre){ //mientras nombre no sea nulo
        switch(*nombre){
            case 'A':
            case 'E':
            case 'I':
            case 'O':
            case 'U': cont ++;
        }
        nombre++; //Avanza las posiciones del arreglo
    }
    return  cont;
}