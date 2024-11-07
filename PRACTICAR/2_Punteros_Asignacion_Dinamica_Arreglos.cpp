#include <iostream>
#include <stdlib.h>
using namespace std;

int numCalif, *PnumCalif;

void pedirNotas();
void mostrarNotas();

int main(){
    pedirNotas();
    mostrarNotas();

    delete[] PnumCalif;

    return 0;
}

void pedirNotas(){
    cout << "Ingrese en numero de calificaciones: ";
    cin >> numCalif;

    PnumCalif = new int [numCalif];

    for( int i = 0; i<numCalif; i++){
        cout << "Ingrese una nota : ";
        cin >> PnumCalif[i];
    }
}

void mostrarNotas(){
    for(int i=0; i<numCalif; i++){
        cout <<PnumCalif[i] <<'\n';
    }
}
    