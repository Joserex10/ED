/*
Inicio

Función factorial(num):
    Si num < 1 Entonces
        Devolver 1
    Sino
        Devolver num * factorial(num - 1)
    Fin Si
Fin Función

Procedimiento pedirDatos():
    Escribir "Ingrese factorial a calcular: "
    Leer num
Fin Procedimiento

Inicio del programa:
    Definir num Como Entero
    pedirDatos()
    Escribir "El factorial de ", num, " es: ", factorial(num)
Fin del programa

Fin
*/

#include <iostream>
using namespace std;

void pedirDatos();

int num;

int factorial(int num);
int main(){

    pedirDatos();
    cout << "El factorial de " << num <<" es: " << factorial(num);
    return 0;
}
int factorial(int num){
    if(num < 1){
       return 1; 
    }
    else{
        return num * factorial(num - 1);
    }
}
void pedirDatos(){
    cout << "Ingrese factorial a calcular: " << endl;
    cin >> num;
}