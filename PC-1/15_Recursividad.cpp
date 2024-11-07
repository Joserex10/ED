#include <iostream>

using namespace std;

void pedirDatos();
int Recursividad(int n1, int n2);

unsigned short numero1,numero2;

int main(){

    pedirDatos();
    cout << Recursividad(numero1,numero2);

    return 0;
}

void pedirDatos(){
    cout << "Ingrese el numero 1 a sumar: "<<endl;
    cin >> numero1;
    cout << "Ingrese el numero 2 a sumar: " << endl;
    cin >> numero2;

}
int Recursividad(int n1,int n2){
    unsigned short suma;
    if(n1 == 0 && n2 == 0){
       suma =0;
    }
    else if(n1 == 0){
        suma = n2;
    }
    else if(n2 == 0){
        suma = n1;
    }
    else if(n1 > n2){
        suma = n1 +n2;
    }
    else if(n2>n1){
        suma = n2 + n1;
    }
    else{
        suma = n1 + Recursividad(n1,n2-n1);
    }
    return suma;
}