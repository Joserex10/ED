#include <iostream>
using namespace std;

float num1,num2;

void pedirDatos();
void Intercambio(float *,float *);

int main(){
    pedirDatos();

    cout << "\nAntes del Cambio" << endl;

    cout << num1 << endl;
    cout << num2 << endl;
    Intercambio(&num1, &num2);

    cout <<"\nDespues del intercambio los nuevos valores son: "<< endl;

    cout <<num1 << endl;
    cout<<num2 << endl;

    return 0;
}

void pedirDatos(){
    
    cout << "Ingrese numero 1: "; cin >> num1;
    cout << "Ingrese numero 2: "; cin >> num2;

}
void Intercambio(float *Pnum1, float *Pnum2){
    float aux;

    aux = *Pnum1;
    *Pnum1 = *Pnum2;
    *Pnum2 = aux;

}