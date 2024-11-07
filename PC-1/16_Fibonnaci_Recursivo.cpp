#include <iostream>

using namespace std;

void pedirDatos();
int fibonacci(int n);

unsigned short numero1;

int main() {
    pedirDatos();
    cout << fibonacci(numero1);
}
void pedirDatos(){
    cout << "Ingrese un numero: " << endl;
    cin >> numero1;
}
int fibonacci(int n1) {
    if (n1 <= 1) {
        return n1;
    } else {
        return fibonacci(n1 - 1) + fibonacci(n1 - 2);
    }
}