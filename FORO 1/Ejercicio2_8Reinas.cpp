
/*
INICIO

Inicio del programa:
    Definir las constantes N, n, True y False
    Declarar los arreglos Reinas, DiagPrin, DiagSec y Col
    Declarar las funciones Inicializa, Anota, BorraAnotacion, Aceptable, EnsayaReina y EscribeSolucion
    Declarar la variable TieneSolucion e inicializarla como False
    Llamar a la función Inicializa
    Llamar a la función EnsayaReina con los parámetros 1 (posición de la reina) y la dirección de memoria de TieneSolucion

Función Inicializa:
    Para i desde 1 hasta n-1 hacer:
        Asignar True a Col[i]
        Asignar 0 a Reinas[i]
    Para i desde 1 hasta 2*N-1 hacer:
        Asignar True a DiagSec[i] y DiagPrin[i]

Función EnsayaReina con parámetros i y solucion:
    Declarar la variable j e inicializarla en 0
    Repetir mientras solucion sea False y j sea menor que N:
        Incrementar j en 1
        Si Aceptable(i, j) es verdadero entonces:
            Llamar a Anota con los parámetros i y j
            Si i es menor que N entonces:
                Llamar recursivamente a EnsayaReina con los parámetros i + 1 y solucion
            Sino:
                Asignar True a la variable apuntada por solucion
            Si solucion es falso entonces:
                Llamar a BorraAnotacion con los parámetros i y j

Función Aceptable con parámetros i y j:
    Retornar (Col[j] AND DiagPrin[i - j + N] AND DiagSec[i + j - 1])

Función Anota con parámetros i y j:
    Asignar False a Col[j]
    Asignar False a DiagPrin[i - j + N]
    Asignar False a DiagSec[i + j - 1]
    Asignar j a Reinas[i]

Función BorraAnotacion con parámetros i y j:
    Asignar True a Col[j]
    Asignar True a DiagPrin[i - j + N]
    Asignar True a DiagSec[i + j - 1]
    Asignar 0 a Reinas[i]

Función EscribeSolucion:
    Imprimir "Número de columna en la que se coloca cada reina"
    Para i desde 1 hasta N hacer:
        Imprimir "Reina " seguido de i y "en columna " seguido de Reinas[i]

Fin del programa.

FIN
*/

#include <iostream>
using namespace std;

#define N 8
#define n (N+1)
#define True 1
#define False 0

int Reinas[n];
int DiagPrin[2 * N], DiagSec[2 * N], Col[n];

void Inicializa();
void Anota(int i, int j);
void BorraAnotacion(int i, int j);
int Aceptable(int i, int j);
void EnsayaReina(int i, int* solucion);
void EscribeSolucion();

int main() {
    int TieneSolucion = False;
    Inicializa();
    EnsayaReina(1, &TieneSolucion);
    if (TieneSolucion){
        EscribeSolucion();
    }   
    return 0;
}
void Inicializa() {
    for(int i = 1; i < n; i++) {
        Col[i] = True;
        Reinas[i] = 0;
    }
    for(int i = 1; i < 2 * N; i++) {
        DiagSec[i] = True;
        DiagPrin[i] = True;
    }
}
void Anota(int i, int j) {
    Col[j] = False;
    DiagPrin[i - j + N] = False;
    DiagSec[i + j - 1] = False;
    Reinas[i] = j;
}
void BorraAnotacion(int i, int j) {
    Col[j] = True;
    Reinas[i] = 0;
    DiagPrin[i - j + N] = True;
    DiagSec[i + j - 1] = True;
}
int Aceptable(int i, int j) {
    return (Col[j] && DiagPrin[i - j + N] && DiagSec[i + j - 1]);
}
void EnsayaReina(int i, int* solucion) {
    int j = 0;
    do {
        j++;
        if (Aceptable(i, j)) {
            Anota(i, j);
            if (i < N){
                EnsayaReina(i + 1, solucion);
            }   
            else{
                *solucion = True;
            }
            if (!(*solucion)){
                BorraAnotacion(i, j);
            }     
        }
    } while (!(*solucion) && (j < N));
}
void EscribeSolucion() {
    cout << "\nNúmero de columna se colocan cada reina\n";
    for (int i = 1; i <= N; i++){
        cout << "\t Reina " << i << " en columna " << Reinas[i] << endl;
    }
        
}