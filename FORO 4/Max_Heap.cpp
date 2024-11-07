#include <iostream>
#include <vector>
#include <limits>

using namespace std;

void heapify(vector<int> &heap, int n, int i) {
    int grande = i; // Inicializar el más grande como raíz
    int izq = 2 * i + 1; // Hijo izquierdo
    int der = 2 * i + 2; // Hijo derecho

    if (izq < n && heap[izq] > heap[grande]){
        grande = izq;
    }
    if (der < n && heap[der] > heap[grande]){
        grande = der;
    }
    if (grande != i) {
        swap(heap[i], heap[grande]);
        heapify(heap, n, grande);
    }
}

void buildMaxHeap(vector<int>& heap) {
    int n = heap.size();
    for (int i = n / 2 - 1; i >= 0; i--){
        heapify(heap, n, i);
    }
}

void printHeap(const vector<int>& heap) {
    for (int i = 0; i < heap.size(); ++i){
        cout << heap[i] << " ";
    }
    cout << '\n';
}

void pedirDatos(vector<int>& numeros) {
    int elementos;
    cout << "Ingrese la cantidad de elementos: " << endl;
    cin >> elementos;

    while (cin.fail() || elementos != static_cast<int>(elementos) || elementos<0 || elementos == 0) {  // Verificar si los valores ingresados son números enteros
        cin.clear(); // Limpiar el estado de error del flujo de entrada
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Descartar la entrada inválida hasta la nueva línea
        cout << "Debe ingresar solo numeros enteros. Intentelo de nuevo: " <<endl;
        cin >> elementos; // Volver a pedir los datos
    }

    numeros.resize(elementos); // Redimensionar el vector
    for (int i = 0; i < elementos; ++i) {
        cout << "Ingrese el numero " << i + 1 << ": ";
        cin >> numeros[i];
    }
}

int main() {
    vector<int> numeros;
    pedirDatos(numeros);

    buildMaxHeap(numeros);

    cout << "Arreglo Max Heap: ";
    printHeap(numeros);

    return 0;
}


/*
 * Inicio del programa

 * Funcion heapify(heap, n, i)
    grande <- i  // Inicializar el más grande como raíz
    izq <- 2 * i + 1  // Hijo izquierdo
    der <- 2 * i + 2  // Hijo derecho

    Si izq < n Y heap[izq] > heap[grande] Entonces
        grande <- izq
    Fin Si

    Si der < n Y heap[der] > heap[grande] Entonces
        grande <- der
    Fin Si

    Si grande != i Entonces
        intercambiar(heap[i], heap[grande])
        heapify(heap, n, grande)
    Fin Si
Fin Funcion

Funcion buildMaxHeap(heap)
    n <- tamaño de heap
    Para i desde n / 2 - 1 hasta 0 hacer
        heapify(heap, n, i)
    Fin Para
Fin Funcion

Funcion printHeap(heap)
    Para i desde 0 hasta tamaño de heap - 1 hacer
        imprimir heap[i]
    Fin Para
    imprimir nueva línea
Fin Funcion

Funcion pedirDatos(numeros)
    imprimir "Ingrese la cantidad de elementos:"
    leer elementos

    Mientras elementos no es un entero válido o es menor o igual a 0 hacer
        limpiar error de entrada
        descartar entrada inválida hasta nueva línea
        imprimir "Debe ingresar solo números enteros. Inténtelo de nuevo:"
        leer elementos
    Fin Mientras

    redimensionar numeros a tamaño elementos
    Para i desde 0 hasta elementos - 1 hacer
        imprimir "Ingrese el número ", i + 1, ":"
        leer numeros[i]
    Fin Para
Fin Funcion

Inicio
    numeros <- lista vacía
    pedirDatos(numeros)

    buildMaxHeap(numeros)

    imprimir "Arreglo Max Heap: "
    printHeap(numeros)
Fin

Fin del programa
*/