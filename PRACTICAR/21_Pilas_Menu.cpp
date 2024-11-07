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
void mostrarPila(Nodo *pila);
void menu(Nodo *&pila);


int main(){
    Nodo *pila =NULL;
    menu(pila);
}

void menu(Nodo *&pila){
    unsigned short opcion;
    do{
        cout << "\t\tMENU\t\t";
        cout <<"\n1. Insertar una caracter a la pila" << endl;
        cout << "2. Mostrar todos los elementos de la pila" << endl;
        cout << "3. Eliminar pila" << endl;
        cout << "4. SALIR" << endl;
        cout << "Ingrese la opcion: " << endl;
        cin >> opcion;
        switch (opcion) {
            case 1:
                pedirDatos(pila);
                cout << "\n";
                system("pause");
                break;
            case 2:
                mostrarPila(pila);
                cout << "\n";
                system("pause");
                break;
            case 3:
                while(pila!= NULL){
                    eliminarPila(pila,dato);
                    if(pila != NULL){
                        cout << dato << " , ";
                    }
                    else cout << dato << " . ";
                }
                cout << "\n";
                system("pause");
                break;

        }

    }while(opcion !=4);

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
void mostrarPila(Nodo *pila){
    cout << "ELEMENTOS EN LA PILA: " << endl;
    for(short i = 0; i <elementos ; i++){
            cout << pila->dato << "\n";
            pila = pila->siguiente;

    }
}