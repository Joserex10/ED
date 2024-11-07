#include <iostream>
using namespace std;

int encontrarMayor(int arreglo[], int longitud);                        //1 + log n

int main() {
    int arreglo[] = {12, 45, 7, 23, 56, 89, 100};                       //2
    int longitud = sizeof(arreglo) / sizeof(arreglo[0]);                //3

    int mayor = encontrarMayor(arreglo, longitud);                      //1 + 1 log n
    cout << "El número mayor en el arreglo es: " << mayor << endl;      //3

    return 0;
}                                                                               

int encontrarMayor(int arreglo[], int longitud) {                       // 1+ log n 
    int mayor = arreglo[0];                                             //2
    for (int i = 1; i < longitud; ++i) {                                //1+ (1+ (1+(2)) +2)
        if (arreglo[i] > mayor) {
            mayor = arreglo[i];
        }
    }
    return mayor;
}                                                   

                                                