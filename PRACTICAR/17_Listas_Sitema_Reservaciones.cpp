#include <iostream>
#include <conio.h>
#include <limits>
using namespace std;

short opcion;
struct Nodo{
    int dato;
    Nodo *siguiente;
};
void pedirDatos();
void IngresarLista(Nodo *&, int);
void mostrarLista(Nodo*);
void eliminarElemento(Nodo *&, int);
void menu();

Nodo *lista = NULL;
int main(){

    menu();
    return 0;
}

void IngresarLista(Nodo *&lista, int n){
 Nodo *nuevo_nodo = new Nodo();
 nuevo_nodo->dato = n;

    Nodo *aux1 = lista;
    Nodo *aux2;

    while ((aux1 != NULL) && (aux1->dato < n)){
        aux2 = aux1;
        aux1 = aux1->siguiente;
    }

    if(lista == aux1){
        lista = nuevo_nodo;
    }else{
        aux2->siguiente = nuevo_nodo;

    }

    nuevo_nodo->siguiente = aux1;

    cout << "\nElemento " << n << " Instertado a lista correctamente\n";
}

void menu(){
    int dato;
    do{
        pedirDatos();

        switch (opcion) {
            case 1:
                cout << "Ingrese el numero de la habitacion a reservar: \n";
                cin >> dato;
                IngresarLista(lista,dato);
                cout << '\n';
                system("pause");
                break;
            case 2:
                cout << "\nHabitaciones reservadas:\n";
                mostrarLista(lista);
                cout << '\n';
                system("pause");
                break;
            case 3:
                cout << "Ingrese la reservacion a eliminar: \n";
                cin >> dato;
                eliminarElemento(lista,dato);
                cout << '\n';
                system("pause");
                break;
        }
    }while(opcion != 4);
}

void mostrarLista(Nodo *lista){
    short cantidad = 1;
    while(lista != NULL){
        cout <<cantidad <<" " <<lista->dato<< '\n';
        lista = lista->siguiente;
        cantidad++;
    }

}

void eliminarElemento(Nodo *&lista, int n){

    if(lista != NULL){
        Nodo *aux_borrar;
        Nodo *anterior = NULL;



        aux_borrar = lista;

        //Recorrer la lista
        while((aux_borrar !=NULL) && (aux_borrar->dato !=n)){

            anterior = aux_borrar;
            aux_borrar = aux_borrar->siguiente;
        }

        //El elemento no ha sido encontrado
        if(aux_borrar == NULL){
            cout << "El elemento no ha sido encontrado";
        }
            //El primero elemento es que el vamos a eliminar
        else if(anterior == NULL){
            lista = lista->siguiente;
            delete aux_borrar;
        }

        else{
            anterior->siguiente = aux_borrar->siguiente;
            delete aux_borrar;
        }
    }
}
void pedirDatos(){
    cout << "\t\tMENU\n";
    cout << "1. Ingresar nuevas reservaciones \n";
    cout << "2. Mostrar habitaciones reservadas\n";
    cout << "3. Eliminar reservaciones \n";
    cout << "4. SALIR\n";
    cout << "Ingrese la opcion: \n";
    cin >> opcion;

    while (cin.fail() || opcion != static_cast<int>(opcion)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Debe ingresar solo numeros enteros. Intentelo de nuevo: \n";
        system("pause");
        pedirDatos();
    }


}