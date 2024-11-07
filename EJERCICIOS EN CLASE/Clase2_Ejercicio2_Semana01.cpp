#include <iostream>
using namespace std;

template<typename T>
T maximo(T a, T b, T c){
    T mayor = a;
    if(b>mayor) mayor=b;
    if(c>mayor) mayor=c;
    return mayor;
}

int main()
{
    char caracter1, caracter2, caracter3;
    cout<<"Ingrese tres caracteres: ";
    cin>> caracter1>> caracter2>> caracter3;
    
    char mayor = maximo(caracter1, caracter2, caracter3);
    cout<<"El mayor caracter es: " << mayor;

    return 0;
}
