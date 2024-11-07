/**Members:

Maquen Caisan, Fabian				2311685

Morales Silva, Omar Jean Piere		2313215

Sanchez Hinostroza, Lian Andrew		2212287

Riva Ramos, Renato Sebastian		2311263

Vallejos Cabada, Jose Maria			2210473
*/

#include <iostream>
#include <limits>
#include <stdlib.h>
#include <string.h>
#include <ctime>
using namespace std;
int tamano;
int maximo = 999;
int n, *arr;
int i, posicionActual, valorPosicion , numero;
int numeros[] = {};



/*---------------------------FUNCIONES GENERALES--------------------------------VERIFICADO*/
// Funcion para validar el ingreso de digitos
int validarDigito(int& n){
    while (cin.fail() ||  n <= 0) {
        cout << "Error: El valor introducido no es valido."<< endl;
        cin.clear(); // Limpiar el estado de error
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Descartar la entrada incorrecta
        cout << "Por favor, introduzca un numero valido: "; cin >> n;
    }
    return n;
}
// Función para pedir el ingreso del tamaño del arreglo y los datos del mismo
void pedirDatos() {
    cout << "Ingresa el tamano del arreglo: "; cin>>n;
    validarDigito(n);
    arr = new int[n]; // Creacion del arreglo con el tamaño ingresado

    for (int i = 0; i < n; i++) { // Recorrer cada elemento del arreglo para asignarle un valor manualmente
        cout << "Ingrese el elemento #" << i << ": "; cin >> arr[i];
        validarDigito(arr[i]);
    }
    cout << endl;
}

/*-----------------------------------------------------------------------------VERIFICADO*/

//Option Menu
int menuOpciones(){
    short opc;
    char numero[maximo];

    do{

        cout<<"\n\t\t***MENU DE ORDENAMIENTOS***\n"<<endl;;
        cout<<"\t1. Buscar Elemento "<<endl;
        cout<<"\t2. Buscar Elemento (Busqueda Binaria)"<<endl;
        cout<<"\t3. Arreglo Ascendente-Descendente (Burbuja)"<<endl;
        cout<<"\t4. Ordenamiento (Insercion)"<<endl;
        cout<<"\t5. Ordenamiento (MergeSort)"<<endl;
        cout<<"\t0. Salir"<<endl;
        do{
            cout<<"\n\t-> Ingrese una opcion: [ ]\b\b";
            cin>>numero;
        }while(isdigit(numero[0])==0);
        opc = atoi(numero);
    }while(opc<1 || opc>5);
    return opc;
}

/*---------------------------1--------------------------------VERIFICADO*/
//Funcion Bubble sort o burbuja -- E1
void bubbleSort() {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Intercambiar arr[j] y arr[j+1]
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

//Funcion de busqueda binaria --E1
int busquedaBinaria(int elemento) {
    int inicio = 0;
    int fin = n - 1;

    while (inicio <= fin) {
        int medio = inicio + (fin - inicio) / 2;

        if (arr[medio] == elemento) {
            return medio; // Elemento encontrado en el índice 'medio'
        } else if (arr[medio] < elemento) {
            inicio = medio + 1; // Buscar en la mitad derecha
        } else {
            fin = medio - 1; // Buscar en la mitad izquierda
        }
    }

    return -1; // Elemento no encontrado
}
void resultadoE1() {
    pedirDatos(); // Pedir al usuario los datos del array y el tamaño
    // Ordenar el arreglo usando Bubble Sort
    bubbleSort();
    int elemento;
    cout << "Ingrese el elemento a buscar: ";
    cin >> elemento;
    validarDigito(elemento);

    int indice = busquedaBinaria(elemento);

    if (indice != -1) {
        cout << "Elemento encontrado en el indice: " << indice << endl;
    } else {
        cout << "Elemento no encontrado en el arreglo." << endl;
    }

}

/*---------------------------2--------------------------------NO VERIFICADO*/





/*---------------------------3--------------------------------VERIFICADO*/

// Función para ordenar un arreglo en orden ascendente usando el algoritmo de ordenamiento burbuja
void burbujaAscendente() {
    int temp;
    for(int i = 0; i < numero - 1; i++) {
        for(int j = 0; j < numero - 1 - i; j++) {
            if(numeros[j] > numeros[j + 1]) {
                temp = numeros[j];
                numeros[j] = numeros[j + 1];
                numeros[j + 1] = temp;
            }
        }
    }
}
void burbujaDescendente() {
    int temp;
    for(int i = 0; i < numero - 1; i++) {
        for(int j = 0; j < numero - 1 - i; j++) {
            if(numeros[j] < numeros[j + 1]) {
                temp = numeros[j];
                numeros[j] = numeros[j + 1];
                numeros[j + 1] = temp;
            }
        }
    }
}
void mostrarArreglo(){
    for(int i=0;i<numero;i++){
        cout << '\n' << numeros[i];
    }
}

/*---------------------------4--------------------------------VERIFICADO*/

void pedirElementos(){
    cout << "Ingrese el numero de elementos: " << endl;
    cin >> numero;  //Ingresar a cantidad de elementos del arreglo

    while (cin.fail() || numero != static_cast<int>(numero) || numero<0 || numero == 0) {  // Verificar si los valores ingresados son números enteros
        cin.clear(); // Limpiar el estado de error del flujo de entrada
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Descartar la entrada inválida hasta la nueva línea
        cout << "Debe ingresar solo numeros enteros. Intentelo de nuevo: " <<endl;
        pedirElementos(); // Volver a pedir los datos
    }

}
void pedirDatosI(){
    for(i=0;i<numero;i++){      //Mientras que i sea menor a la cantidad de elementos
        fflush(stdin);     //Limpiar buffer de entrada
        cout << "Ingrese el numero " << i+1 << ": " << endl;
        cin >> numeros[i];  //Ingresar cada numero del arreglo
    }
}
void ordenInsercion(){
    for(i=0;i<numero;i++){
        posicionActual=i;       //Inicializamos la posicion actual en i
        valorPosicion = numeros[i]; //Insertamos el numero[i] en ValorPosicion

        while((posicionActual > 0) && (numeros[posicionActual-1] >valorPosicion)){  //Mientgras que la posicion actual sea mayor a 0 y el numero en la posicion anterior sea mayor a la posicion actual
            numeros[posicionActual] = numeros[posicionActual-1];    // Movemos el número en la posición actual una posición hacia la derecha
            posicionActual--;       //Disminuimos la posicion actual en 1
        }
        numeros[posicionActual] = valorPosicion; //Insertamos el valor en la posicion actual
    }
    cout << ("Orden Ascendente") << endl;
    for(i=0;i<numero;i++){
        cout << ("%d" ,numeros[i]); //Imprimimos cada numero ya ordenado del arreglo
        cout<<"\n";
    }
    cout << "\n\n\n\n";

}

/*---------------------------5--------------------------------NO VERIFICADO*/

// Funcion merge: para unir dos subarreglos ordenados.
void merge(int arr[], int inicio, int mitad, int final) {
    int i, j, k;
    int elementosIzq = mitad - inicio + 1; // Calcula la cantidad de elementos en el subarreglo izquierdo.
    int elementosDer = final - mitad; // Calcula la cantidad de elementos en el subarreglo derecho.

    // Se crean dos arreglos temporales para almacenar los subarreglos izquierdo y derecho.
    int izquierda[elementosIzq];
    int derecha[elementosDer];

    // Se copian los datos de los subarreglos en los arreglos temporales.
    for (i = 0; i < elementosIzq; i++) {
        izquierda[i] = arr[inicio + i];
    }
    for (j = 0; j < elementosDer; j++) {
        derecha[j] = arr[mitad + 1 + j];
    }

    // Se reinician los indices para el recorrido de los arreglos temporales y el arreglo original.
    i = 0;
    j = 0;
    k = inicio;

    // Se mezclan los elementos de los subarreglos izquierdo y derecho en el arreglo original.
    while (i < elementosIzq && j < elementosDer) {
        if (izquierda[i] <= derecha[j]) {
            arr[k] = izquierda[i];
            i++;
        } else {
            arr[k] = derecha[j];
            j++;
        }
        k++;
    }

    // Se copian los elementos restantes del subarreglo derecho, si es que los hay.
    while (j < elementosDer) {
        arr[k] = derecha[j];
        j++;
        k++;
    }

    // Se copian los elementos restantes del subarreglo izquierdo, si es que los hay.
    while (i < elementosIzq) {
        arr[k] = izquierda[i];
        i++;
        k++;
    }
}
// Funcion mergeSort recursiva: para dividir y ordenar el arreglo
void mergeSort(int arr[], int inicio, int fin) {
    if (inicio < fin) {
        int mitad = inicio + (fin - inicio) / 2; // Se calcula el punto medio del arreglo.

        // Se ordenan recursivamente las mitades izquierda y derecha del arreglo.
        mergeSort(arr, inicio, mitad);
        mergeSort(arr, mitad + 1, fin);

        // Se mezclan las mitades ordenadas.
        merge(arr, inicio, mitad, fin);
    }
}
// Funcion para imprimir el arreglo
void imprimeArreglo(int arr[]) {
    cout << "------IMPRESION ARREGLO------" << endl;
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n-----------------------------\n" << endl;
}


/*---------------------------MAIN--------------------------------*/

int main() {

    int n, opc, a, b;
    int arr[tamano];


    do{
        system("cls");
        opc=menuOpciones();
        switch(opc){
            case 1:
            resultadoE1();
                cout << "\n";
                system("pause");
                break;
            case 2:
                cout << "\n";
                pedirDatos();

                system("pause");
                break;
            case 3:
                pedirElementos();
                pedirDatosI();
                burbujaAscendente();
                cout << "Mostrando Arreglo ordenado Ascendentemente...." << endl;
                mostrarArreglo();
                burbujaDescendente();
                cout << "\nMostrando Arreglo ordenado Descendentemente...." << endl;
                mostrarArreglo();
                cout << "\n";
                system("pause");
                break;

            case 4:
                pedirElementos();
                pedirDatosI();       //Funcion que pide al usuario digitar cada elemento del arreglo segun la cantidad ingresada
                ordenInsercion();   //Funcion de ordenamiento mediante insercion
                cout << "\n";
                system("pause");
                break;

            case 5:
                pedirDatos(); // Pedir al usuario los datos del array y el tamaño
                mergeSort(arr, 0, n - 1); // Llamar a la función mergeSort para ordenar el arreglo
                cout << "Arreglo ordenado mediante Merge Sort: ";
                imprimeArreglo(arr); // Imprimir el arreglo ordenado
                cout << "\n";
                system("pause");
                break;
        }
    }while(opc !=0 );

}
