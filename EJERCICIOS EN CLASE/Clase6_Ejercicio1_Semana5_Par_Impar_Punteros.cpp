/*

Desarrolle una funcion aplicando punteros que determine si un numero entero es par o impar

*/
#include<iostream>
#include<conio.h>
#include<stdio.h>
#include<locale.h>
#include <limits>

using namespace std;


void PedirDatos(int* n1) {
	do {
		cout << "Ingrese un n�mero positivo: "; cin >> *n1;
	
	while(cin.fail()){
		cin.clear();
		cin.ignore(numeric_limits<streamsize>:: max(),'\n');
		cout << "Entrada invalida, porfavor ingrese numeros positivos: ";
		cin >> *n1;
	}
	} while (*n1 < 0);
}

string HallaTipo(int* n1) {
	if (*n1 % 2 == 0 && *n1 != 0){
		return "\nEs par";
	} 
	else if (*n1 == 0){
		return "\nEs neutro";
	} 
	else return "\nEs impar";
}

int main() {
	setlocale(LC_ALL, "spanish");
	int num, *pNum = new int;
	PedirDatos(&num);
	*pNum = num;
	cout << HallaTipo(pNum);
	delete pNum;
	pNum = NULL;
	getch();
	return 0;
}
