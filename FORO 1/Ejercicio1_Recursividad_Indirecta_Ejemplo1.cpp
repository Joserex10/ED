
/*
Inicio

    Funcion DiHola(cantidad):
        Si cantidad > 0 Entonces
            Escribir "Nicole saludo a Jose !!! "
            holaNicole(cantidad - 1)
        Fin Si
    Fin Funcion

    Funcion holaNicole(cantidad):
        Si cantidad > 0 Entonces
            Escribir "Jose saluda a Nicole !!!"
            holaJose(cantidad - 1)
        Fin Si
    Fin Funcion

Inicio del programa
    holaJose(100)
Fin del programa

Fin

*/

#include <iostream>
using namespace std;

void holaJose(int cantidad);
void holaNicole(int cantidad);

int main() {
    holaJose(100);
    return 0;
}
void holaJose(int cantidad) {
    if (cantidad > 0) {
        cout << "\nNicole saludo a Jose !!!\n";
        holaNicole(cantidad - 1);
    }
}

void holaNicole(int cantidad) {
    if (cantidad > 0) {
        cout << "Jose saluda a Nicole !!!\n" << endl;
        holaJose(cantidad - 1);
    }

    
}