#include <iostream>
#include <stdlib.h>
using namespace std;

struct Nodo{
    int dato;
    Nodo *siguiente;
};

void insertarLista(Nodo *&, int);
void mostrarLista(Nodo *);
void calcularMayoryMenor(Nodo *);
void calcularSuma(Nodo *);
void calcularPromedio(Nodo *);

int main(){
    Nodo *lista = NULL;
    int dato;
    char respuesta;

    do{
        cout << "Digitame un numero: ";
        cin >> dato;
        insertarLista(lista,dato); //Agregando un nuevo elemento a la lista

        cout << "Desea agregar otro nodo(s/n)";
        cin >> respuesta;
    }while(respuesta == 's' || respuesta == 'S');

    cout << "\nElementos de la lista:\n";
    mostrarLista(lista);
    cout << '\n';
    calcularMayoryMenor(lista);
    cout << '\n';
    calcularSuma(lista);
    cout <<'\n';
    calcularPromedio(lista);
    return 0;
}

//Agregar elementos al final de la lista
void insertarLista(Nodo *&lista, int n){
    Nodo *nuevo_nodo = new Nodo();
    Nodo *aux;

    nuevo_nodo->dato = n;
    nuevo_nodo->siguiente = NULL;

    if(lista ==NULL){ // si la lista esta vacia
        lista  = nuevo_nodo;// agregamos el primer elemento a la lista
    }
    else{
        aux = lista;//aux apunta al inicio de la lista
        while(aux->siguiente != NULL){ // recorrer la lista
            aux = aux->siguiente;//avanzamos posiciones en la lista
        }
        aux->siguiente = nuevo_nodo; //Agrego el nuevo nodo a la lista
    }
    cout << "\tElemento " << n << " agregado a la lista correctamente\n";
}

//Mostrar todos los elementos de la lista
void mostrarLista(Nodo *lista){
    while(lista != NULL){   //Mientras no sea el final de la lista
        cout << lista->dato << "->";
        lista = lista->siguiente;
    }

}

//Calcular el mayor y menor elemento de la lista
void calcularMayoryMenor(Nodo *lista){
    int mayor=0, menor =99999;

    while(lista !=NULL){ //Recorremos la lista
        if((lista->dato) > mayor){ //Calculamos el mayor elemento
            mayor = lista->dato;
        }
        if((lista->dato) < menor){ //Calculamos el menor elemento
            menor = lista->dato;
        }
        lista = lista->siguiente; //Avanzamos una posicion en la lista
    }
    cout << "El mayor elemento es "<< mayor << endl;
    cout << "El menor elemento es " << menor << endl;
}

//calcular suma
void calcularSuma(Nodo *lista){
    int suma = 0;
    while(lista != NULL){
        suma += lista->dato;
        lista = lista->siguiente;
    }
    cout << "La suma total de la lista es: " << suma<<endl;

}

//calcular promedio
void calcularPromedio(Nodo *lista){
    float promedio = 0;
    short cantidad = 0;

    while(lista != NULL){
        promedio += lista->dato;
        cantidad++;
        lista = lista->siguiente;
    }

    cout << "El promedio de numero es: " << promedio/cantidad<<endl;

}