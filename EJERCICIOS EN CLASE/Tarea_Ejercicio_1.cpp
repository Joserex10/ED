#include <iostream>
#include <cstdlib>      //Generacion de numeros aleatorios
#include <ctime>        //Agarra el tiempo y fecha de la computadora
using namespace std;

void generarMatriz(int matriz[][10]);           //Funcion para generar Matriz
void imprimirMatriz(int matriz[][10]);          //Funcion para Imprimir Matriz

int main() {
    int matriz[10][10];     //Declaracion del tamaño de la matriz
    srand(time(0));        //Asegura que sean numeros aleatorios en cada ejecucion
    generarMatriz(matriz);      
    imprimirMatriz(matriz);     
    return 0;
}

void generarMatriz(int matriz[][10]) {
    bool numerosUsados[100] = {false};      //Arreglo boleano de tamaño 100 inicializando todos los elementos en falso para asegurar que no se repitan
    int contador = 0;
    
    for(int i = 0; i < 10; ++i) {           //Filas
        for(int j = 0; j < 10; ++j) {       //Columnas
            int numeroAleatorio;        //Almacena los numeros aleatorios
            do {
                numeroAleatorio = rand() % 100;             //Genera un numero aleatorio del 0 al 99
            } while(numerosUsados[numeroAleatorio]);        //Verifica si los numeros generados ya fueron utilizados

            matriz[i][j] = numeroAleatorio;
            numerosUsados[numeroAleatorio] = true; 
            contador++;
        }
    }
}

void imprimirMatriz(int matriz[][10]) {
    for(int i = 0; i < 10; ++i) {           //Filas
        for(int j = 0; j < 10; ++j) {       //Columnas
            cout << matriz[i][j] << "\t";   //Imprime Matriz
        }
        cout << endl;
    }
}
