#include <iostream>

using namespace std;
int numero;

void pedirDatos();
int hallarFactorial(int n);

int main(){
    pedirDatos();
    cout << hallarFactorial(numero);

    return 0;
}
void pedirDatos(){
    cout << "Ingrese el factorial a calcular: " << endl;
    cin >> numero;
}
int hallarFactorial(int n){
    if(n == 0){
        n = 1;
    }else{
        n  = n * hallarFactorial(n-1);
    }
    return n;
}