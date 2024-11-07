/*1. Hacer una estructura llamada corredor, en la cual se tendrán los siguientes
campos: Nombre, edad, sexo, club, pedir datos al usuario para un corredor, y asignarle
una categoría de competición:
- Juvenil <= 18 años
- Señor <= 40 años
- Veterano > 40 años
Posteriormente imprimir todos los datos del corredor, incluida su categoría de
competición.*/


#include <iostream>
#include <limits>
using namespace std;

struct Corredor{
    string nombre;
    unsigned short edad;
    string sexo;
    char club[20];

}corredor[3], *Pcorredor = corredor;

void menu();
void pedirDatos();
void ImprimirDatos();

int main(){
    menu();
    return 0;
}
void menu(){
    unsigned short opcion;
    do{
        cout << "\t\tMenu\t\t";
        cout <<"\n1. Ingresar datos de competidores\n";
        cout << "2.SALIR \n";
        cout << "\nOpcion: \n";
        cin >> opcion;

        switch (opcion) {
            case 1:
                pedirDatos();
                ImprimirDatos();
                break;
        }

    }while(opcion !=2);

}
void pedirDatos(){
    for(int i = 0; i < 3; i++){
        cin.ignore();
        fflush(stdin);
        cout << "Ingrese los datos del competidor: \n";
        cout << "\nNombre: \n "; getline(cin,corredor[i].nombre);
        cout << "Edad: \n"; cin>> corredor[i].edad;
        cout << "Sexo: \n"; cin>> corredor[i].sexo;
        cout << "Club: \n"; cin>>corredor[i].club;
    }
}
void ImprimirDatos(){
    for(int i=0;i<3;i++){
        cout << i+1 << ") " << endl;
        cout << "Nombre: "<<corredor[i].nombre << endl;
        cout << "Edad: "<<corredor[i].edad << endl;
        cout << "Sexo: "<<corredor[i].sexo << endl;
        cout << "Club: "<<corredor[i].club << endl;
        if(corredor[i].edad <= 18){
            cout << "Juveline";
        }
        else if(corredor[i].edad >18 &&  corredor[i].edad <= 40){
            cout << "Senor\n";
        }else{
            cout << "Veterano\n";
        }
        cout << "\n";
    }
}