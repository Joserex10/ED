#include <iostream>
using namespace std;

struct Nodo{
    int dato;
    Nodo *der;
    Nodo *izq;
    Nodo *padre;
};

//Prototipos de las funciones
void menu();
Nodo *crearNodo(int, Nodo *);
void insertarNodo(Nodo *&, int, Nodo *);
void mostrarArbol(Nodo *, int);
bool busqueda(Nodo *, int);
void preOrden(Nodo *);
void inOrden(Nodo *);
void postOrden(Nodo *);
void eliminar(Nodo *,int);
void eliminarNodo(Nodo *);
Nodo *minimo(Nodo *);
void reemplazar(Nodo *, Nodo*);
void destruirNodo(Nodo *);

Nodo *arbol =NULL;

int main(){
    menu();

    return 0;
}

//Funcion de menu
void menu(){
    int dato,opcion,contador = 0;

    do{
        cout << "\t.:MENU:." <<endl;
        cout << "1. Insertar un nuevo nodo" << endl;
        cout << "2. Mostrar Arbol" << endl;
        cout << "3. Buscar Elemento" << endl;
        cout << "4. Mostrar Arbol en PreOrden" << endl;
        cout << "5. Mostrar Arbol en InOrden" << endl;
        cout << "6. Mostrar Arbol en PostOrden" << endl;
        cout << "7. Eliminar un nodo del arbol" << endl;
        cout << "8. Salir" << endl;
        cout << "Opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                cout << "Digite un numero: " << endl;
                cin >> dato;
                insertarNodo(arbol,dato,NULL);
                cout << '\n';
                system("pause");
                break;
            case 2:
                cout << "\nMostrando el arbol completo:\n\n";
                mostrarArbol(arbol,contador);
                cout << '\n';
                system("pause");
                break;
            case 3:
                cout << "\nDigite el elemento a buscar"<<endl;
                cin >> dato;
                if(busqueda(arbol,dato) == true){
                    cout << "\nEl elemento " << dato << " ha sido encontrado en el arbol" <<endl;
                }else{
                    cout << "\nEl elemento " << dato << " no ha sido encontrado" <<endl;
                }
                cout << '\n';
                system("pause");
                break;
            case 4:
                cout << "\nMostrando arbol en PreOrden..." << endl;
                preOrden(arbol);
                cout << '\n';
                system("pause");
                break;
            case 5:
                cout << "\nMostrando arbol en InOrden..." << endl;
                inOrden(arbol);
                cout << '\n';
                system("pause");
                break;
            case 6:
                cout << "\nMostrando arbol en PostOrden..." << endl;
                postOrden(arbol);
                cout << '\n';
                system("pause");
                break;
            case 7:
                cout << "\nDigite el numero a eliminar: ";
                cin >> dato;
                eliminar(arbol,dato);
                cout << '\n';
                system("pause");
                break;
        }


    } while(opcion != 8);
}

//Funcion crear un nuevo nodo
Nodo *crearNodo(int n, Nodo *padre){
    Nodo *nuevo_nodo = new Nodo();

    nuevo_nodo->dato = n;
    nuevo_nodo->der = NULL;
    nuevo_nodo->izq = NULL;
    nuevo_nodo->padre = padre;

    return nuevo_nodo;
}

//Funcion para insertar elementos en el arbol
void insertarNodo(Nodo *&arbol, int n, Nodo *padre){
    if(arbol == NULL){ //Si el arbol esta vacio
        Nodo *nuevo_nodo = crearNodo(n,padre);
        arbol = nuevo_nodo;
    }
    else{ //Si el arbol tiene un nodo o mas
        int valorRaiz = arbol->dato; //Obtenemos el valor de la raiz
        if(n < valorRaiz){
            insertarNodo(arbol->izq,n,arbol); // Si el elemento es menor a la raiz, insertamos en izq
        }
        else{
            insertarNodo(arbol->der,n,arbol); //Si el elemento es mayor a la raiz, insertamos en der
        }
    }
}

//Funcion para mostrar Arbol completo
void mostrarArbol(Nodo *arbol, int contador){
    if(arbol == NULL){ //Si el arbol esta vacio
        return;
    }else{
        mostrarArbol(arbol->der,contador+1);
        for(int i = 0;i < contador; i++){
            cout << "    ";
        }
        cout << arbol->dato << endl;
        mostrarArbol(arbol->izq,contador+1);
    }
}

//Funcion para buscar un elemento en el arbol
bool busqueda(Nodo *arbol, int n){
    if(arbol == NULL){
        return false;
    }else if(arbol->dato == n){
        return true;
    }else if(n < arbol->dato){
        return busqueda(arbol->izq,n);
    }else{
        return busqueda(arbol->der,n);
    }
}

//Funcion Mostrar Arbol PreOrden(Raiz,Izq,Der)
void preOrden(Nodo *arbol){
    if(arbol == NULL){
        return;
    }else{
        cout << arbol->dato << " - ";
        preOrden(arbol->izq);
        preOrden(arbol->der);
    }
}

//Funcion Mostrar Arbol InOrden(Izq,raiz,Der)
void inOrden(Nodo *arbol){
    if(arbol == NULL){
        return;
    }else{
        inOrden(arbol->izq);
        cout << arbol->dato << " - ";
        inOrden(arbol->der);
    }
}

//Funcion Mostrar Arbol PostOrden(Izq,Der,Raiz)
void postOrden(Nodo *arbol){
    if(arbol == NULL){
        return;
    }else{
        postOrden(arbol->izq);
        postOrden(arbol->der);
        cout << arbol->dato << " - ";

    }
}

//Funcion eliminar un nodo del arbol
void eliminar(Nodo *arbol, int n){
    if(arbol == NULL){//si el arbol esta vacio
        return;
    }else if(n < arbol->dato){ //si el valor es menor
        eliminar(arbol->izq,n); //busca por la izq
    }else if(n > arbol->dato){ //si el valor es mayor
        eliminar(arbol->der,n); //busca por la der
    }else{ //si ya encontraste el valor
        eliminarNodo(arbol);
    }
}

//Funcion para determinar el nodo mas izq posible
Nodo *minimo(Nodo *arbol){
    if(arbol == NULL){//si el arbol esta vacio
        return NULL; //retornamos NULL
    }if(arbol->izq){ //si tiene hijo izq
        return minimo(arbol->izq); //buscamos la parte mas izq posible
    }else{ //si no tiene hijo izq
        return arbol; //retornamos el mismo arbol
    }
}

//Funcion reemplazar dos nodos
void reemplazar(Nodo *arbol,Nodo *nuevoNodo){
    if(arbol->padre){ //si tiene padre
        //arbol->padre hay que asignarle su nuevo hijo
        if(arbol->dato == arbol->padre->izq->dato){
            arbol->padre->izq = nuevoNodo;
        }else if(arbol->dato == arbol->padre->der->dato){
            arbol->padre->der = nuevoNodo;
        }
    }if(nuevoNodo){
        //Procedemos a asignarle su nuevo padre
        nuevoNodo->padre = arbol->padre;
    }
}

//Funcion para destruir un nodo
void destruirNodo(Nodo *nodo){
    nodo->izq = NULL;
    nodo->der = NULL;
    delete nodo;
}

//Funcion para eliminar el nodo encontrado
void eliminarNodo(Nodo *nodoEliminar){
    if(nodoEliminar->izq && nodoEliminar->der){ //si el nodo tiene hijo izq y der
        Nodo *menor = minimo(nodoEliminar->der);
        nodoEliminar->dato = menor->dato;
        eliminarNodo(menor);
    }else if(nodoEliminar->izq){ //si tiene hijo izq
        reemplazar(nodoEliminar,nodoEliminar->izq);
        destruirNodo(nodoEliminar);
    }else if(nodoEliminar->der){ //Tiene hijo derecho
        reemplazar(nodoEliminar,nodoEliminar->der);
        destruirNodo(nodoEliminar);
    }else{ //No tiene hijos
        reemplazar(nodoEliminar,NULL);
        destruirNodo(nodoEliminar);
    }
}
