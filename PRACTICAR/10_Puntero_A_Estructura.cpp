#include <iostream>
using namespace std;

struct Persona{
    char nombre[30];
    int edad;
}persona, *Ppersona = &persona;

void pedirDatos();
void mostrarDatos(Persona *);


int main(){
    pedirDatos();
    mostrarDatos(Ppersona);


    return 0;
}
void pedirDatos(){
    cout << "Digitame tu nombre: ";
    cin.getline(Ppersona->nombre,30,'\n');
    cout << "Digitame la edad: ";
    cin >> Ppersona->edad;
}
void mostrarDatos(Persona *Ppersona){
    cout << "\nSu nombre: " <<Ppersona->nombre << endl;
    cout << "\nSu edad: " << Ppersona->edad << endl;
}