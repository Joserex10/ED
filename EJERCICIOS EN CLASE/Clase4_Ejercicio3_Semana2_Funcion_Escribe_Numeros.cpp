/*Ejercicio02: Escriba una función escribeNumeros(int ini, int fin) que devuelva 
en la salida estándar los números del ini al fin. Escriba una versión que escriba los 
números en orden ascendente.

		escribeNumeros(ini,fin) = ini                             , si ini=fin
								  escribeNumeros(ini,fin-1)       , si fin>ini
*/

#include <iostream>
using namespace std;

void pedirDatos();
void escribeNumeros(int, int);

int ini, fin;
int main(){
	pedirDatos();	
	escribeNumeros(ini, fin);
	return 0;
}
void escribeNumeros(int ini, int fin){
	if(ini == fin){
		cout << " " << fin << " " <<endl;
	}
	if(ini < fin){
		cout << " "<< ini << " "<<endl;
		escribeNumeros(ini + 1,fin);
	}
}
void pedirDatos(){
	do{
	cout << "Escribe el numero inicial: ";
	cin >> ini;
	cout << "Escribe el numero final: ";
	cin >> fin;
	
	if(ini <0){
			cout<< "Ingrese numero incial psotivo \n";
		}
}while(ini<0);
}



/*
void walk(int steps);
int main(){

    walk(100);

    return 0;
}
void walk(int steps){
    if(steps > 0){
        cout << "You take a step!\n";
        walk(steps - 1);

*/
