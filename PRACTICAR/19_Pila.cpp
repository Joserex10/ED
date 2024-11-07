#include <iostream>
#include <stdlib.h>
using namespace std;

struct Nodo{
    short dato;
    Nodo *siguiente;
};
short dato;
void pedirDatos(Nodo *&);
void agregarPila(Nodo *&,short ); // prototipo
void sacarPila(Nodo *&, short &);

int main(){
    Nodo *pila = NULL;
    pedirDatos(pila);

    cout << "Sacar elementos de la pila...." << endl;

    while(pila != NULL){ //mientras no sea el final de la pila
        sacarPila(pila,dato);   //Saca el dato
        if(pila != NULL){
            cout << dato << " , ";        //Imprime el dato y una ,
        }
    }
    cout << dato <<" . ";                   //Imprime un punto significando que ya no hay elementos

    return 0;
}
void pedirDatos(Nodo *&pila){
    cout << "Digite un numero: ";
    cin >>dato;
    agregarPila(pila,dato);
    cout << "Digite otro numero: ";
    cin >> dato;
    agregarPila(pila,dato);
    cout << "Digite otro numero: ";
    cin >> dato;
    agregarPila(pila,dato);
}

void agregarPila(Nodo *&pila, short n){
    Nodo *nuevo_nodo = new Nodo();  //Reservar memoria para un Nodo
    nuevo_nodo->dato =n;            //Poner correctamente el dato en el nodo
    nuevo_nodo->siguiente = pila;   //Igualar el puntero a pila
    pila = nuevo_nodo;              //Igualar pila a nuevo nodo

    cout << "Elemento " << n << " agregado a pila correctamente..." << endl;
}

void sacarPila(Nodo *&pila, short &n){
    Nodo *aux = pila;               //Crear una variable aux
    n = aux->dato;                  //Hacer que n sea igual a aux->dato
    pila = aux->siguiente;          //Igualar pila a aux->siguiente
    delete aux;                     // Eliminamos aux
}