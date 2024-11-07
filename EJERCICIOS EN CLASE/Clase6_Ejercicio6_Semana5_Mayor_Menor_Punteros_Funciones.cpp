#include<iostream>
#include<cmath>
#include<iomanip>
#include<stdio.h>
#include<locale>
#include<conio.h>

using namespace std;

int mayor(int a, int b) {
	if (a > b) {
		return a;
	}
	else {
		return b;
	}
}

int main() {
	setlocale(LC_ALL, "spanish");
	int* a = new int;
	int* b = new int;

	do {
		cout << "Ingrese el primer número: ";
		cin >> *a;
	} while (!(*a >= 0));

	do {
		cout << "Ingrese el segundo número: ";
		cin >> *b;
	} while (!(*b >= 0));

	cout << "*****************************\n";
	cout << "El mayor es: " << mayor(*a, *b);

	delete a;
	delete b;
	a = NULL;
	b = NULL;
	_getch();
	return 0;
}