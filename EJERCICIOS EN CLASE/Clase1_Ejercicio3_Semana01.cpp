/*ejercicio 02*/
#include <iostream>
#include <conio.h>
#include <locale.h>
using namespace std;


//prototipo de funcion 

void PedirDatos();
void Cuadrado(float n);
//presentacion de funciones 

//variable global 
float numero;

int main(){
    setlocale(LC_ALL, "sp");
    PedirDatos();
    Cuadrado(numero);
    
    return 0;
}

//desarrollo de funciones 

void PedirDatos(){
    cout <<"\nDigite el Número: ";
    cin>>numero;
}

void Cuadrado(float n){
    float cuadrado =0;
    cuadrado = numero*numero;
    cout<<"\nEl cuadrado del Número es:  "<<cuadrado<<endl;
    
}