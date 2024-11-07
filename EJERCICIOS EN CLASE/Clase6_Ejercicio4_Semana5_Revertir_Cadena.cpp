//Función recursiva que permite revertir los caracteres de una cadena de texto,
//es decir, si ingresamos "hola", devuelve "aloh"

#include<iostream>
#include<string> //contiene funciones para la gestión de cadenas de texto

using namespace std;

void revertirCadena(string& cadena, int inicio, int final);

int main(){
	string cadena;
	cout<<"Ingrese una cadena de texto: ";
	cin>>cadena;
	
	revertirCadena(cadena,0,cadena.length()-1); //invoca a la función recursiva
	
	cout<<"Cadena invertida: "<<cadena;
}

void revertirCadena(string& cadena, int inicio, int final){
	if(inicio>=final){ //>cuando es una cadena de longitud par, = cuando es impar
		return;		
	}
	swap(cadena[inicio],cadena[final]); //intercambia un caracter ubicado en
							//la posición incio por otro ubicado en la posición final
							//y viceversa
	revertirCadena(cadena,inicio+1,final-1); //llamada al caso recursivo que permite
							//que inicio crezca y que final disminuya hasta cumplir
							//con el caso base
}







