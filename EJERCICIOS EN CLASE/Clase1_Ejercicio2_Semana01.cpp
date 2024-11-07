#include <iostream>
#include <cmath>
using namespace std;
void dibujaCuadrado(int a, int b);
int main() {
int a,b;
cout<<"Ingrese 1: ";
cin >> a;
cout<<"Ingrese 2: ";
cin>>b;
dibujaCuadrado(a,b);
}
void dibujaCuadrado(int a, int b){
for (int i = 0; i < b; ++i) {
for (int i = 0; i < a; ++i) {
cout << "*";
}
cout << endl;
}
}

