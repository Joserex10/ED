#include <iostream>
using namespace std;

int elemento, *Pelemento;



void pedirDatos();
void Mostrar();
int Buscar();

int main(){
    pedirDatos();
    Mostrar();
    Buscar();
    delete [] Pelemento;
    return 0;
}

void pedirDatos(){
    cout << "Ingrese la cantidad de elementos: "; cin >> elemento;

    Pelemento = new int [elemento];

    for(int i =0; i<elemento;i++){
        cout << "Ingrese el " <<i+1<< " numero: "; cin >> *(Pelemento+i);
    }

}
void Mostrar(){
    cout << "\nArreglo: ";
    for(int i=0; i<elemento;i++){
        cout <<'\n' <<*(Pelemento+i);
    }
}
int Buscar(){
    int index;
    cout <<"\nIngrese el numero a buscar: "; cin >> index;
    for(int i=0;i<elemento;i++){
        if(*(Pelemento+i) == index){
            cout <<"Si se encuentra en el arreglo";
        }

    }
    return 0;
    
}