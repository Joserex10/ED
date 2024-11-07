#include <iostream>
#include <stdlib.h>
using namespace std;

int cant, *Pcant;

void pedirDatos();
void Ordenar(int * ,int );
void mostrarArreglo(int *, int);

int main(){
    pedirDatos();
    Ordenar(Pcant,cant);
    mostrarArreglo(Pcant , cant);

    delete[] Pcant;

    return 0;
}

void pedirDatos(){

    cout << "Ingrese el numero de datos: "; cin >> cant;

    Pcant =  new int[cant];
    
    for(int i; i<cant;i++){

        cout << "Ingrese el "<<i+1<< " numero: "; cin >> *(Pcant+i);
    }
}
void Ordenar(int *Pcant, int cant){
    int aux;

    for(int i=0; i<cant; i++){
        for(int j=0;j<cant-1;j++){
            if(*(Pcant+j) > *(Pcant+j+1)){
                aux = *(Pcant+j);
                *(Pcant+j) = *(Pcant+j+1);
                *(Pcant+j+1) = aux;
            }
        }
    }
}
void mostrarArreglo(int *Pcant, int cant){
    cout << "\n\nMostrando arreglo ordenado:";
    for(int i=0;i<cant;i++){
        cout << '\n' << *(Pcant+i);
    }
}