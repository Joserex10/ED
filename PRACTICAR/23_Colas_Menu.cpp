#include <iostream>
#include <stdlib.h>
using namespace std;

struct Nodo{
    char dato;
    Nodo *siguiente;
};

void menu();
void pedirDatos();
void insertarCola(Nodo *&, Nodo *&, char );
void suprimirCola(Nodo *&, Nodo *&, char &);
bool cola_vacia(Nodo *);

char dato;

int main(){
    menu();
    return 0;
}
void menu(){
    short opc;

    Nodo *frente = NULL;
    Nodo *fin = NULL;
    do {
        cout << "\t\tMENU\t\t" << endl;
        cout << "1. Insertar un character a una cola" << endl;
        cout << "2. Mostrar elementos de la cola" << endl;
        cout << "SALIR" << endl;
        cout << "Digite la opcion" << endl;
        cin >> opc;

        switch (opc) {
            case 1:
                pedirDatos();
                insertarCola(frente, fin, dato);
                break;
            case 2:
                cout << "Quitando los nodos de la cola...." << endl;

                while(frente != NULL){
                    suprimirCola(frente,fin,dato);
                    if(frente != NULL){
                        cout << dato << " , ";
                    }
                    else{
                        cout << dato << " . ";
                    }
                }
                cout << '\n';
                system("pause");
                break;
            case 3:
                break;
        }
    }while(opc !=3);
}
void pedirDatos(){
    cout << "Ingrese el caracter a ingresar a la cola" << endl;
    cin >>dato;
}
void insertarCola(Nodo *&frente, Nodo *&fin, char n){
    Nodo *nuevo_nodo = new Nodo();

    nuevo_nodo->dato = n;
    nuevo_nodo->siguiente = NULL;

    if(cola_vacia(frente)){
        frente = nuevo_nodo;

    }else{
        fin->siguiente = nuevo_nodo;
    }
    fin = nuevo_nodo;
}
//Funcion para determinar si la cola esta vacia

bool cola_vacia(Nodo *frente){
    return (frente == NULL)? true : false;
}
void suprimirCola(Nodo *&frente, Nodo *&fin, char &n){
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

