//Ejercicio 1: Hacer un programa para agregar numeros enteros a una pila,
//hasta que el usuario lo decida, despues mostrar todos los numeros
//introducidos en la pila

#include <iostream>
#include <stdlib.h>

using namespace std;
struct Nodo{
    short dato;
    Nodo *siguiente;
};

short dato;
short elementos;

void pedirDatos(Nodo *&pila);
void insertarPila(Nodo *&pila, short n);
void eliminarPila(Nodo *&pila, short &n);


int main(){
    Nodo *pila = NULL;
    pedirDatos(pila);
    cout << "\nSACANDO TODOS LOS ELEMENTOS DE LA PILA..." << endl;

    while (pila != NULL){
        eliminarPila(pila,dato);
        if(pila != NULL){
            cout << dato << " , ";
        }else{
            cout << dato << " . ";
        }
    }


    return 0;
}
void pedirDatos(Nodo *&pila){

    cout << "Ingrese la cantidad de elementos a ingresar: " << endl;
    cin >> elementos;

    for(short i =0 ; i <elementos; i++){
        cout << "Ingrese el numero " << i+1 <<": " << endl;
        cin >> dato;
        insertarPila(pila, dato);
    }
}
void insertarPila(Nodo *&pila, short n){
    Nodo *nuevo_nodo = new Nodo();      //Reservar memoria para un Nodo
    nuevo_nodo->dato = n;               //Poner correctamente el dato en el nodo
    nuevo_nodo->siguiente = pila;       //Igualar el puntero a pila
    pila = nuevo_nodo;                  //Igualar pila a nuevo nodo

    cout << "\tEl elemento " << n << " ha sido agregado a pila correctamente..."<<endl;
}
void eliminarPila(Nodo *&pila, short &n){
    Nodo *aux = pila;
    n = aux->dato;
    pila = aux->siguiente;
    delete aux;
}