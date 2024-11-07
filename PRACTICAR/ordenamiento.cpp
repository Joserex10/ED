#include <iostream>
#include <limits>   //Biblioteca limits para poder usar validacion

using namespace std;
//Prototipos
void pedirElementos();
void pedirDatos();
void ordenInsercion();

int i, posicionActual, valorPosicion , numero;
int numeros[] = {};
int main(){
    pedirElementos();   //Funcion que pide a cantidad de elementos del arreglo
    pedirDatos();       //Funcion que pide al usuario digitar cada elemento del arreglo segun la cantidad ingresada
    ordenInsercion();   //Funcion de ordenamiento mediante insercion

    return 0;
}
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
void pedirDatos(){
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
    system("pause");
}
