/*1. Hacer una estructura llamada corredor, en la cual se tendrán los siguientes
campos: Nombre, edad, sexo, club, pedir datos al usuario para un corredor, y asignarle
una categoría de competición:
- Juvenil <= 18 años
- Señor <= 40 años
- Veterano > 40 años
Posteriormente imprimir todos los datos del corredor, incluida su categoría de
competición.*/

#include<iostream>
#include<conio.h>
#include<string.h>
using namespace std;

typedef struct Corredor {
	char nombre[20];
	int edad;
	char sexo[10];
	char club[20];
}c1;

int main() {
	int i = 0;
	c1 *Vdatos;
	Vdatos = new c1[3]; // asignarle memoria
	fflush(stdin);
	char categoria[20];//tomar en cuenta para el uso de caracteres 
	/*
	cout << "Nombre: "; cin.getline(c1[i].nombre, 20, '\n');
	cout << "Edad: "; cin >> c1.edad;
	cout << "Sexo: "; cin.getline(c1.sexo, 10, '\n');
	cout << "Club: "; cin.getline(c1.club, 20, '\n');
	*/
	
	//ingreso de datos 
	for (i = 0; i < 3; i++) {
		cout << "\nIngrese Nombre: " << i + 1 << ":"; cin >> Vdatos[i].nombre;
		cout << "\nIngrese Edad: " << i + 1 << ":"; cin >> Vdatos[i].edad;
		cout << "\nIngrese Sexo: " << i + 1 << ":"; cin >> Vdatos[i].sexo;
		cout << "\nIngrese Club: " << i + 1 << ":"; cin >> Vdatos[i].club;
	}
	//muestra de datos 
	for (int i = 0; i < 3; i++) {
		cout << Vdatos[i].nombre<<endl;
		cout << Vdatos[i].edad<<endl;
		cout << Vdatos[i].sexo<<endl;
		cout << Vdatos[i].club<<endl;
	}

	//otros compiladores usan strcpy
	if (Vdatos[i].edad <= 18) {
		strcpy(categoria, "Juvenil");
	}
	else if (Vdatos[i].edad <= 40) {
		strcpy(categoria, "Senior");
	}
	else {
		strcpy(categoria, "Veterano");
	}

	cout << "\n\nMostrando Datos" << endl;
	cout << "Nombre: " << Vdatos[i].nombre << endl;
	cout << "Edad: " << Vdatos[i].edad << endl;
	cout << "Sexo: " << Vdatos[i].sexo << endl;
	cout << "Club: " << Vdatos[i].club << endl;
	cout << "Categoria: " << categoria << endl;

	getch();
	//system("pause");
	return 0;
}