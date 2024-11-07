#include <iostream>
#include <stdlib.h>
using namespace std;

void pedirDatos();
void mostrarMatriz(int **,int,int);
int **puntero_matriz,filas,columnas;

int main(){

    pedirDatos();
    mostrarMatriz(puntero_matriz,filas,columnas);

    for(int i=0;i<filas;i++){
        delete[] puntero_matriz[i];
    }
    delete[] puntero_matriz;

    return 0;
}

void pedirDatos(){
    cout << "ingrese el numero de filas: ";
    cin >> filas;
    cout << "Ingrese el numero de columnas: ";
    cin>> columnas;

    puntero_matriz = new int*[filas];
    for(int i=0;i<filas;i++){
        puntero_matriz[i] = new int[columnas];
    }
    cout << "\nDigitando elementos de la matriz:\n";
    for(int i=0;i<filas;i++){
        for(int j=0;j<columnas;j++){
            cout << "Digite un numero " <<i<<" "<<j<<": ";
            cin >> *(*(puntero_matriz+i)+j);
        }
    }
    
}
void mostrarMatriz(int **puntero_matriz,int filas, int columnas){
    cout << "\n\nMostrando matriz:\n";
    for(int i=0;i<filas;i++){
        for(int j=0;j<columnas;j++){
            cout <<*(*(puntero_matriz+i)+j)<<" ";
        }
        cout <<'\n';
    }
}