#include <iostream>
#include <queue>
#include <string>
#include <limits>

using namespace std;

void imprecion();

int main() {

    imprecion(); // llamamos a la funcion con todo el procedimiento
    return 0;
}

void imprecion(){
        queue<string> imprimir; // Cola para almacenar trabajos de impresión
        short opcion;

        do {
            // menu de opciones
            cout << "1. Agregar trabajo de impresion\n";
            cout << "2. Procesar trabajo de impresion\n";
            cout << "3. Salir\n";
            cout << "Seleccione una opcion: ";
            cin >> opcion;

            while (cin.fail() || opcion != static_cast<short>(opcion)){  // Verificar si los valores ingresados son números enteros
                cin.clear(); // Limpiar el estado de error del flujo de entrada
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Descartar la entrada inválida hasta la nueva línea
                cout << "Debe ingresar solo numeros enteros. Intentelo de nuevo: ";
                cout << '\n';
                system("pause");
                imprecion(); // Volver a pedir los datos
            }

            switch(opcion) {
                case 1: {
                    fflush(stdin);
                    string trabajo;
                    cout << "Ingrese el nombre del trabajo: ";
                    getline(cin,trabajo);
                    imprimir.push(trabajo); //Ingresamos el trabajo
                    cout << "Trabajo agregado a la cola de impresion.\n";
                    system("pause");
                    cout << "\n";
                    break;
                }
                case 2: {
                    if (!imprimir.empty()) {
                        cout << "Procesando trabajo: " << imprimir.front() << endl;
                        imprimir.pop();
                    } else {
                        cout << "No hay trabajos en la cola de impresion.\n";
                    }
                    system("pause");
                    cout << "\n";
                    break;
                }
                case 3:
                    cout << "Saliendo del programa.\n";
                    exit(0);



            }

        } while(opcion != 3);


};


//SEUDOCODIGO

/*Inicio del programa
    Función imprecion()
        Crear una cola para almacenar trabajos de impresión
        Definir la variable opcion como entero corto

        Hacer
            Mostrar el menú de opciones
            Leer la opción ingresada por el usuario en la variable opcion

            Mientras la entrada no sea un número entero o no sea válido
                Limpiar el estado de error del flujo de entrada
                Descartar la entrada inválida hasta la nueva línea
                Mostrar un mensaje indicando al usuario que ingrese solo números enteros
                Volver a pedir la entrada

            Según la opción ingresada
                Caso 1:
                    Pedir al usuario que ingrese el nombre del trabajo
                    Leer el nombre del trabajo ingresado por el usuario y almacenarlo en una variable
                    Agregar el trabajo a la cola de impresión
                    Mostrar un mensaje indicando que el trabajo fue agregado a la cola de impresión
                Caso 2:
                    Si la cola de impresión no está vacía
                        Mostrar el trabajo que se está procesando (el primero en la cola)
                        Quitar el trabajo de la cola
                    Sino
                        Mostrar un mensaje indicando que no hay trabajos en la cola de impresión
                Caso 3:
                    Mostrar un mensaje indicando que el programa está saliendo
                    Finalizar el programa

        Mientras la opción ingresada no sea 3

    Fin de la función imprecion

    Llamar a la función imprecion() desde el programa principal

Fin del programa
*/
