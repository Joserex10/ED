
/*
INICIO

Inicio del programa:
    Funcion DiHola(cantidad):
        Si cantidad > 0 Entonces
            Escribir "Hola "
            DiMundo(cantidad - 1)
        Fin Si
    Fin Funcion

    Funcion DiMundo(cantidad):
        Si cantidad > 0 Entonces
            Escribir "Mundo!"
            DiHola(cantidad - 1)
        Fin Si
    Fin Funcion

    Inicio:
        DiHola(4)
    Fin
Fin del programa

FIN
*/

#include <iostream>
using namespace std;

// Prototipos de funciones
void DiHola(int cantidad);
void DiMundo(int cantidad);

int main() {
    DiHola(4);
    return 0;
}
void DiHola(int cantidad) {
    if (cantidad > 0) {
        cout << "Hola ";
        DiMundo(cantidad - 1);
    }
}

void DiMundo(int cantidad) {
    if (cantidad > 0) {
        cout << "Mundo!" << endl;
        DiHola(cantidad - 1);
    }
}