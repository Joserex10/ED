#include <iostream>
#include <stdio.h>
#include <limits>
using namespace std;
void pedirDatos();

unsigned short nElementos; //declaracion de los elementos
int *nVector = new int[10]; // asignacion de un arreglo de enteros

int main() {

    pedirDatos();

	//leer los elementos del arreglo

	for (int i = 0; i < nElementos; i++) {
		cout << "Ingrese la edad:" << i + 1 << ": ";
		cin >> nVector[i];
	}

	//imprimir los elementos del arreglo 
	cout << " \nLos elementos del arreglo son: \n";
	for (int i = 0; i < nElementos; i++) {
		cout << "\nEdad:" << i + 1 << "= " << nVector[i] << '\n';
	}

	//int* nVector = new int[10]; liberar memoria 
	delete[]nVector;
	nVector= NULL;
	system("pause");
	return 0;

}
void pedirDatos(){

    //lectura y validacion
    do
    {
        cout << "\nIngrese la cantidad de elementos: \n";
        cin >> nElementos;

        while (cin.fail() || nElementos != static_cast<int>(nElementos)) {  // Verificar si los valores ingresados son números enteros
            cin.clear(); // Limpiar el estado de error del flujo de entrada
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Descartar la entrada inválida hasta la nueva línea
            cout << "\nDebe ingresar solo numeros enteros. Intentelo de nuevo: \n";
            pedirDatos(); // Volver a pedir los datos
        }
    } while (nElementos <= 0 || nElementos > 10);



}