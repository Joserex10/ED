#include <iostream>
#include <stdlib.h>
using namespace std;
struct Nodo{
    short dato;
    Nodo *siguiente;
};
short dato;
//Prototipos de funcion
void pedirDatos();
bool cola_vacia(Nodo *);
void insertarCola(Nodo *&, Nodo *&, short);
void suprimirCola(Nodo *&, Nodo *&, short &);
int main(){
    Nodo *frente = NULL;
    Nodo *fin = NULL;

    pedirDatos();
    insertarCola(frente,fin,dato);
    cout << '\n';
    pedirDatos();
    insertarCola(frente,fin,dato);
    cout << '\n';
    pedirDatos();
    insertarCola(frente,fin,dato);
    cout << '\n';

    //Eliminar los elementos de la cola
    cout << "Quitando los nodos de la cola...." << endl;
    while(frente != NULL){
        suprimirCola(frente,fin,dato);
        if(frente != NULL){
            cout << dato << " , ";
        }else{
            cout << dato << " . ";
        }
    }

    return 0;
}

void pedirDatos(){
    cout << "Digite un numero: ";
    cin >> dato;
}

void insertarCola(Nodo *&frente, Nodo *&fin, short n){
    Nodo *nuevo_nodo = new Nodo();
    nuevo_nodo->dato = n;
    nuevo_nodo->siguiente = NULL;

    if(cola_vacia(frente)){
        frente = nuevo_nodo;

    }else{
        fin->siguiente = nuevo_nodo;
    }
    fin = nuevo_nodo;
    cout << "\tElemento " << n << " ingresado correctamente";
}
void suprimirCola(Nodo *&frente, Nodo *&fin, short &n){
    n = frente->dato;
    Nodo *aux = frente;

    if(frente == fin){
        frente = NULL;
        fin = NULL;
    }else{
        frente = frente->siguiente;
    }
    delete aux;
}
//Funcion para determinar si la cola esta vacia o no
bool cola_vacia(Nodo *frente){
    return (frente == NULL)? true : false;
}