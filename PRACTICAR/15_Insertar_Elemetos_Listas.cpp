#include <iostream>
#include <conio.h>
using namespace std;

struct Nodo{
    int dato;
    Nodo *siguiente;
};
void menu();
void insertarLista(Nodo *&,int);
void mostrarLista(Nodo *);
void buscarLista(Nodo *, int);
void eliminarElemento(Nodo *&, int);
void eliminarLista(Nodo *&, int &);

Nodo *lista =NULL;
int main(){

    menu();
    return 0;
}
void insertarLista(Nodo *&lista, int n){
    Nodo *nuevo_nodo = new Nodo();
    nuevo_nodo->dato =n;

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
    int opcion, dato;

    do{
        cout << "\t.:MENU.\n";
        cout << "1. Insertar los elementos de la lista\n";
        cout << "2. Mostrar los elementos de la lista\n";
        cout << "3. Buscar elemento\n";
        cout << "4. Eliminar elemento\n";
        cout << "5. Eliminar lista\n";
        cout << "6. Salir\n";
        cout << "opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                cout << "Digite un numero: ";
                cin >> dato;
                insertarLista(lista,dato);
                cout << "\n";
                system("pause");
                break;
            case 2:
                mostrarLista(lista);
                cout << "\n";
                system("pause");
                break;
            case 3:
                cout << "Digite un numero a buscar: ";
                cin >> dato;
                buscarLista(lista,dato);
                cout << "\n";
                system ("pause");
                break;
            case 4:
                cout << "Digite un numero a eliminar: ";
                cin >> dato;
                eliminarElemento(lista,dato);
                cout <<"\n";
                system("pause");
                break;
            case 5:
                while(lista !=NULL){    //Mientras no sea el final de la lista
                    eliminarLista(lista,dato);
                    cout << dato << "->";
                }
                cout << "\n";
                system("pause");
                break;
        }
    }while(opcion != 6);
}

//Mostrar lista
void mostrarLista(Nodo *lista){
    Nodo *actual = new Nodo();
    actual = lista;

    while(actual != NULL){
        cout << actual->dato << "->";
        actual = actual->siguiente;
    }
}
//Buscar lista
void buscarLista(Nodo *lista, int n){
    bool band = false;

    Nodo *actual = new Nodo();
    actual = lista;

    while((actual != NULL) && (actual ->dato <= n)){
        if(actual ->dato == n){
            band = true;
        }
        actual = actual->siguiente;
    }
    if(band == true) {
        cout << "El elemento " << n << " fue encontrado";
    }else{
        cout << "El elemento " << n << " no fue encontrado";
    }
}
//Eliminar nodo
void eliminarElemento(Nodo *&lista, int n){
    //Preguntar si la lista no esta vacia
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
        //El elemento esta en la lista pero no es el primer elemento
        else{
            anterior->siguiente = aux_borrar->siguiente;
            delete aux_borrar;
        }
    }

}
//Dejar vacia la lista
void eliminarLista(Nodo *&lista, int &n){
    Nodo *aux =lista;
    n = aux->dato;
    lista = aux->siguiente;
    delete aux;

}



