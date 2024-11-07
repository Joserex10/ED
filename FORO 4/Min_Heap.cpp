#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
using namespace std;

void ingresar_tamano(int& tamano) {
    cout << "Ingrese el tamaño del array: ";
    cin >> tamano;
    while (cin.fail() || tamano != static_cast<int>(tamano) || tamano == 0 || tamano < 0 ) {  // Verificar si los valores ingresados son números enteros
        cin.clear(); // Limpiar el estado de error del flujo de entrada
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Descartar la entrada inválida hasta la nueva línea
        cout << "Debe ingresar solo números enteros. Inténtelo de nuevo:\n ";
        ingresar_tamano(tamano);
    }
}

void completar_array(vector<int>& array) {
    cout << "Ingresa los elementos del array:" << endl;
    for (int i = 0; i < array.size(); ++i) {
        cout << "Elemento " << i + 1 << ": ";
        cin >> array[i];
    }
}

class Heap {
public:
    static void heapify(vector<int>& input, int n, int i) {
        int largest = i; // inicializo largest como la raíz
        int l = 2 * i + 1; // izquierda = 2*i + 1
        int r = 2 * i + 2; // derecha = 2*i + 2

        if (l < n && input[l] > input[largest]) {// si el hijo izquierdo es más grande que la raíz
            largest = l;
        }

        if (r < n && input[r] > input[largest]) {// si el hijo derecho es más grande que largest hasta ahora
            largest = r;
        }

        if (largest != i) {// si largest no es la raíz
            swap(input[i], input[largest]);
            heapify(input, n, largest);// Recursivamente heapificar el subárbol afectado
        }
    }

    static void sortHeap(vector<int>& input) {
        int n = input.size();

        // Construyo el heap (reorganizar el arreglo)
        for (int i = n / 2 - 1; i >= 0; i--)
            heapify(input, n, i);

        // Extraigo un elemento del heap uno por uno
        for (int i = n - 1; i >= 0; i--) {
            // Mover la raíz actual al final
            swap(input[0], input[i]);

            // Llamo heapify en el heap reducido
            heapify(input, i, 0);
        }
    }

    static vector<int> main(vector<int> input) {
        sortHeap(input);
        return input;
    }
};

int main() {

    int tamano;

    ingresar_tamano(tamano);//llamo a funcion para ingresar un dato 

    vector<int> input(tamano);//ese dato lo meto en esta funcion en la que le ingresto el tamaño deseado

    completar_array(input);//aqui lo completo
    // ejemplo vector<int> input = {12, 11, 13, 5, 6, 7};

    vector<int> sorted = Heap::main(input);  //aqui ya utilizamos el heap de mi inicio

    cout << "Sorted array is: ";
    for (int i : sorted) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}

//Seudocodigo


/*

Inicio del Programa

     * Funcion ingresar_tamano(tamano)
    Imprimir "Ingrese el tamaño del array: "
    Leer tamano
    Mientras tamano no es un entero válido o es menor o igual a 0 hacer
        Limpiar estado de error de entrada
        Descartar entrada inválida hasta nueva línea
        Imprimir "Debe ingresar solo números enteros. Inténtelo de nuevo: "
        ingresar_tamano(tamano)
    Fin Mientras
Fin Funcion

Funcion completar_array(array)
    Imprimir "Ingresa los elementos del array:"
    Para i desde 0 hasta tamaño de array - 1 hacer
        Imprimir "Elemento ", i + 1, ": "
        Leer array[i]
    Fin Para
Fin Funcion

Clase Heap
    Funcion estático heapify(input, n, i)
        largest <- i  // Inicializar largest como la raíz
        l <- 2 * i + 1  // Hijo izquierdo
        r <- 2 * i + 2  // Hijo derecho

        Si l < n y input[l] > input[largest] Entonces
            largest <- l
        Fin Si

        Si r < n y input[r] > input[largest] Entonces
            largest <- r
        Fin Si

        Si largest != i Entonces
            Intercambiar input[i] con input[largest]
            heapify(input, n, largest)  // Recursivamente heapificar el subárbol afectado
        Fin Si
    Fin Funcion

    Funcion estático sortHeap(input)
        n <- tamaño de input

        // Construir el heap (reorganizar el arreglo)
        Para i desde n / 2 - 1 hasta 0 hacer
            heapify(input, n, i)
        Fin Para

        // Extraer un elemento del heap uno por uno
        Para i desde n - 1 hasta 0 hacer
            Intercambiar input[0] con input[i]
            heapify(input, i, 0)  // Llamar a heapify en el heap reducido
        Fin Para
    Fin Funcion

    Función estática main(input)
        sortHeap(input)
        Devolver input
    Fin Función
Fin Clase

Inicio
    tamano <- 0
    ingresar_tamano(tamano)  // Llamar a la función para ingresar el tamaño

    input <- nuevo vector de tamaño tamano
    completar_array(input)  // Completar el array con los datos ingresados por el usuario

    sorted <- Heap::main(input)  // Usar la clase Heap para ordenar el array

    Imprimir "Sorted array is: "
    Para cada i en sorted hacer
        Imprimir i
    Fin Para
    Imprimir nueva línea
Fin
Fin del Programa*/