/*Rea;oce una funcion recursiva que suma los primeros n enteros positivos
 * Nota: para plantear la funcion recursiva tenga en cuneta que la suma puede expresarse
 * mediante la siguiente recurrecia:
 *
 * suma(n) = 1          , si n=1
 *          n+suma(n-1)  , si n > 1*/

#include <iostream>
using namespace std;

void pedirDatos();
int sumar(int n);

unsigned short nElementos;

int main(){
    pedirDatos();
    cout << sumar(nElementos);

    return 0;
}
void pedirDatos() {
    do {
        cout << "Ingrese la cantidad de elementos: " << endl;
        cin >> nElementos;
    } while(nElementos <= 0);
}
int sumar(int n){
    int suma = 0;
    if(n == 1){ //caso base
        suma = 1;
    }
    else{       //caso general
        suma = n + sumar(n-1);
    }
    return suma;
}