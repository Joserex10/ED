//programa recursivo
//que permite convertir un número de base 10 a binario

#include<iostream>
#include<cstdlib> //Para rand() y srand()
#include<ctime> //Para time() que inicializa la semilla

using namespace std;

void convertirBinario(int numero);

int main(){
	int numero;
	cout<<"Ingrese un número entero: ";
	cin>>numero;
	convertirBinario(numero);
}

void convertirBinario(int numero){
	if(numero==0){//caso base
		return;
	}
	convertirBinario(numero/2); //el número ha llegado a cociente 0
	cout<<numero%2; //si se divide num1%num2 y num1<num2, num1%num2 = num1
}










