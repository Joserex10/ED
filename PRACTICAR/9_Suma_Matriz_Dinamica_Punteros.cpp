#include <iostream>
#include <stdlib.h>
using namespace std;

void pedirDatos();
void sumarMatrices(int **, int **, int, int);
void mostrarMatrizResultante(int **, int, int);

int **puntero_matriz1, **puntero_matriz2, filas, columnas;

int main(){
    pedirDatos();
    sumarMatrices(puntero_matriz1,puntero_matriz2, filas, columnas);
    mostrarMatrizResultante(puntero_matriz1, filas, columnas);

    //liberando memoria matriz 2
    for(int i=0;i<filas;i++){
        delete[] puntero_matriz2[i];
    }
    delete puntero_matriz2;

    //liberar memoria matriz 1
    for(int i=0;i<filas;i++){
        delete[] puntero_matriz1[i];
    }
    delete puntero_matriz1;
    

    return 0;
}
void pedirDatos(){
    cout << "Ingrese el numero de filas: ";
    cin >> filas;
    cout << "Ingrese el numero de columnas: ";
    cin >> columnas;

    //reservar memoria primera matriz
    puntero_matriz1 = new int*[filas]; // reservar memoria filas
    for(int i=0;i<filas;i++){
        puntero_matriz1[i] = new int[columnas]; //reservar memoria columnas
    }
    cout << "\nDigite los elementos de la primera matriz:\n";
    for(int i=0;i<filas;i++){
        for(int j=0;j<columnas;j++){
            cout << "Digite un numero" << i << " " << j << ": ";
            cin >> *(*(puntero_matriz1+i)+j);
        }
    }

    //reservar memoria segunda matriz
    puntero_matriz2 = new int*[filas]; // reservar memoria filas
    for(int i=0;i<filas;i++){
        puntero_matriz2[i] = new int[columnas]; //reservar memoria columnas
    }
    cout << "\nDigite los elementos de la segunda matriz:\n";
    for(int i=0;i<filas;i++){
        for(int j=0;j<columnas;j++){
            cout << "Digite un numero" << i << " " << j << ": ";
            cin >> *(*(puntero_matriz2+i)+j);
        }
    }
}

void sumarMatrices(int **puntero_matriz1,int **puntero_matriz2, int filas, int columnas){

    for(int i=0;i<filas;i++){
        for(int j=0;j<columnas;j++){
            *(*(puntero_matriz1+i)+j) += *(*(puntero_matriz2+i)+j);
        }
    }
}

void mostrarMatrizResultante(int **, int filas, int columnas){
    cout << "\nLa suma de las 2 matrices es: \n";
    for(int i=0; i< filas; i++){
        for(int j=0; j<filas; j++){
            cout << *(*(puntero_matriz1+i)+j)<<" ";
        }
        cout << "\n";
    }
}