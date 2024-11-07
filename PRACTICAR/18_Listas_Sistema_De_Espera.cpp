#include <iostream>
#include <conio.h>
using namespace std;

struct Nodo{
    string nombre;
    Nodo *siguiente;
};

void IngresarLista(Nodo *&, string);
void mostrarLista(Nodo*);
void eliminarElemento(Nodo *&, string);
void menu();


Nodo *lista = NULL;
int main(){

    menu();
    return 0;
}

void IngresarLista(Nodo *&lista, string n){ //INGRESAR A LA LISTA ITEMS ORDENADAMENTE
    Nodo *nuevo_nodo = new Nodo();
    nuevo_nodo->nombre = n;                  //Dato ingresado(ejemplo1: 10)(ejemplo2: 20)

    Nodo *aux1 = lista;                 //Igualamos aux1 a lista (ejemplo1: como la lista es null aux 1 es null) (ejemplo2: la lista ya no esta null por lo que aux es igual a 10)
    Nodo *aux2;

    while(aux1 != NULL){ //Mientras que aux 1 no sea null y que el dato de aux 1 sea menor a el dato ingresado(ejemplo1: como aux 1 es null no entra)(ejemplo2: si entra)
        aux2 = aux1;                            // ponemos que aux 2 sea igual a aux 1 (ejemplo2: aux 2 es igual a aux 1 osea los 2 estan en 10)
        aux1 = aux1->siguiente;                 // avanzamos aux 1 al siguiente nodo o a null (ejemplo2: movemos el aux 1 de 10 a NULL y aux 2 se queda en 10)
    }

    if(lista == aux1){                          // si la lista es igual a aux 1(ejemplo1: la lista es igual a aux 1 por que los 2 son null por lo que si entra)(ejemplo2: no entra)
        lista = nuevo_nodo;                     // lista seria igual al dato ingresado(ejemplo1: El numero 10 esta al inicio de la lista)
    }else{
        aux2->siguiente = nuevo_nodo;           // si no aux 2 se avanza al siguiente y se convierte en el dato ingresado
        // (ejemplo2: el aux 2 que apuntaba a 10 hacemos que su siguiente sea 20 por lo que aux 2 apunta a 20 y aux 1 tambien apunta a 20)
    }

    nuevo_nodo->siguiente = aux1;               // hacemos que el nodo donde esta ingresado el numero mande a aux 1 a que sea null(ejemplo1: como lista ya apunta al nodo 10 decimos que aux 1 apunte al siguiente osea null)
    //(ejemplo2: Ahora el numero 20 su siguiente que es NULL hacemos que aux 1 apunte ahi por lo que aux 1 es NULL )
    cout << "\nElemento " << n << " Instertado a lista correctamente\n";
}

void menu(){
    short opcion;
    string nombre;


    do{
        cout << "\t\tMENU\n";
        cout << "1. Ingresar Clientes \n";
        cout << "2. Mostrar Clientes en cola\n";
        cout << "3. Eliminar clientes\n";
        cout << "4. SALIR\n";
        cout << "Ingrese la opcion: \n";
        cin >> opcion;

        cin.ignore();

        switch (opcion) {
            case 1:
                cout << "Ingrese el Nombre del Cliente: \n";
                getline(cin,nombre);
                IngresarLista(lista,nombre);
                cout << '\n';
                system("pause");
                break;
            case 2:
                cout << "\nClientes en cola (En orden de prioridad): \n";
                mostrarLista(lista);
                cout << '\n';
                system("pause");
                break;
            case 3:
                cout << "\nIngrese el nombre del cliente a eliminar: \n";
                getline(cin,nombre);
                eliminarElemento(lista,nombre);
                cout << '\n';
                system("pause");
                break;

        }
    }while(opcion != 4);
}

void mostrarLista(Nodo *lista){
    short cantidad = 1;
    while(lista != NULL){           //Mientras no sea el final de la lista
        cout << cantidad << " " <<lista->nombre<< '\n'; //Muestra los datos
        lista = lista->siguiente;   //Avanza en la lista
        cantidad++;
    }
}

void eliminarElemento(Nodo *&lista, string n){

    if(lista != NULL){
        Nodo *aux_borrar;
        Nodo *anterior = NULL;

        //Nuestra lista tiene 10 y 20 pero lista apunta a 10, y queremos borrar el 20
        aux_borrar = lista;//Igualamos aux_borrar a la lista(ejemplo1: lista apunta a 10 entonces aux borrar apunta a 10)

        //Recorrer la lista
        while((aux_borrar !=NULL) && (aux_borrar->nombre !=n)){//Mientras aux_borrar no sea null y el numero ingresado sea diferente al numero que apunta aux_borrar
            //(ejemplo1: como aux borrar es diferente de null y como aux_borrar es diferente de 20 por que aux_borrar es 10 entonces entra
            anterior = aux_borrar;                           //hacemos que anterior sea aux_borrar(ejemplo1: ahora anterior apunta a 10 igual que aux_borrar
            aux_borrar = aux_borrar->siguiente;              //hacemos que aux borrar ahora apunte al siguiente nodo(ejemplo1: ahora aux_borrar apunta a 20 y anterior sigue apuntando a 10
        }

        //El elemento no ha sido encontrado
        if(aux_borrar == NULL){                              //si aux_borrar es igual a null
            cout << "El elemento no ha sido encontrado";    // no se encontro el elemento a borrar
        }
            //El primero elemento es que el vamos a eliminar
        else if(anterior == NULL){                          // si anterior es igual a null
            lista = lista->siguiente;                       // lista avanza al siguiente nodo
            delete aux_borrar;                              // eliminamos el numero
        }
            //El elemento esta en la lista pero no es el primer elemento
        else{
            anterior->siguiente = aux_borrar->siguiente;    //hacemos anterior avance al nodo siguiente de auxborrar(ejemplo1: )
            delete aux_borrar;
        }
    }
}

