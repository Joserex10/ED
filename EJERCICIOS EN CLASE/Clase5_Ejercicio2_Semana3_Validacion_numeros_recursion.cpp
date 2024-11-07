#include <iostream>
#include <limits>
using namespace std;

void pedirDatos(int& inicio, int& final);
void escribeNumeros(int ini, int fin);
int main() {
    int inicio, final;
    pedirDatos(inicio, final);

    while (cin.fail() || inicio != static_cast<int>(inicio) || final != static_cast<int>(final)) {  // Verificar si los valores ingresados son números enteros
        cin.clear(); // Limpiar el estado de error del flujo de entrada
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Descartar la entrada inválida hasta la nueva línea
        cout << "Debe ingresar solo números enteros. Inténtelo de nuevo: ";
        pedirDatos(inicio, final); // Volver a pedir los datos
    }

    cout << "Números en orden ascendente: ";
    escribeNumeros(inicio, final);
    cout << endl;

    return 0;
}

void pedirDatos(int& inicio, int& final) {
    cout << "Ingrese el inicio y el final (separados por espacio): ";
    cin >> inicio >> final;
}

void escribeNumeros(int ini, int fin) {
    if (ini == fin) {
        cout << ini << " ";
        return;
    }
    escribeNumeros(ini, fin - 1);
    cout << fin << " ";
}