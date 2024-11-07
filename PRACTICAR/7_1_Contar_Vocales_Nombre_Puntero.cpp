#include <iostream>
#include <string.h>
using namespace std;

char nombreUsuario[30];

void pedirDatos();
int Vocales(char *);

int contadorA = 0, contadorE = 0, contadorI = 0, contadorO = 0, contadorU = 0;

int main(){
    pedirDatos();
    cout << "Las vocales son las siguientes: \n"<<Vocales(nombreUsuario) << endl;;
    return 0;
}

void pedirDatos(){
    cout << "Ingrese su nombre: "; cin.getline(nombreUsuario,30,'\n');
    strupr(nombreUsuario);
}

int Vocales(char *nombre){
    
    while(*nombre){
        switch(*nombre){
            case 'A': 
                contadorA++;
                break;
            case 'E': 
                contadorE++;
                break;
            case 'I': 
                contadorI++;
                break;
            case 'O': 
                contadorO++;
                break;
            case 'U': 
                contadorU++;
                break;
        }
        nombre++;
    }
    cout << "A: " << contadorA << endl;
    cout << "E: " << contadorE << endl;
    cout << "I: " << contadorI << endl;
    cout << "O: " << contadorO << endl;
    cout << "U: " << contadorU << endl;
    return 0;
}