#include <iostream>

using namespace std;

void pedirDatos();
void imprimirDatos();

int nElementos, *PnElementos;

int main(){

    pedirDatos();
    imprimirDatos();

    return 0;
}

void pedirDatos(){
    cout << "Ingrese la cantidad de elementos: " <<endl;
    cin >> nElementos;

    PnElementos = new int[nElementos];

    for(int i = 0;i < nElementos; i++){
        cout << "Ingrese le numero " << i+1 << " :" << endl;
        cin >> PnElementos[i];
    }

}
void imprimirDatos(){

    unsigned short aux;
    for(int i = 0;i < nElementos; i++){
        for(int j = 0; j <nElementos -1; j++){
            if(*(PnElementos + j) > ( *(PnElementos + j +1))){
                aux = *(PnElementos + j);
                *(PnElementos + j) = *(PnElementos + j +1);
                *(PnElementos + j +1) = aux;
            }
        }
    }

    cout << "Elementos Ordenados...." << endl;
    system("pause");

    for(int i=0;i < nElementos; i++){
        cout << i+1 << ": " << PnElementos[i] << endl;
    }

}