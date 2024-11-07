#include <iostream>
using namespace std;

int nElementos ,*PnElementos;
void pedirDatos();
void imprimirDatosPares();
void imprimirDatos();
void ordenar();
void menu();

int main(){
    menu();
    return 0;
}
void menu(){
    unsigned short opcion;
    do{
        cout << "\t\tMENU\t\t";
        cout << "\n1. Ingresar Datos" << endl;
        cout << "2. Imprimir Datos Pares" << endl;
        cout << "3. Imprimir Datos Ordenados" << endl;
        cout << "4. SALIR" << endl;
        cout << "\nIngrese la opcion: "; cin >> opcion;

        switch (opcion) {
            case 1:
                pedirDatos();
                system("pause");
                cout <<'\n';
                break;
            case 2:
                ordenar();
                imprimirDatosPares();
                system("pause");
                cout <<'\n';
                break;
            case 3:
                ordenar();
                imprimirDatos();
                system("pause");
                cout <<'\n';
                break;
        }
    }while(opcion != 4);
}
void pedirDatos(){
    cout << "Ingrese la cantidad de numero de elementos: ";
    cin >> nElementos;
    PnElementos = new int[nElementos];

    for(int i = 0; i <nElementos; i++){
        cout << "Ingrese el numero " << i+1 << endl;
        cin >> PnElementos[i];
    }
}
void imprimirDatosPares(){
    cout << "Los numeros de arreglo son: " << endl;
    for(int i = 0; i < nElementos; i++){
        if(PnElementos[i] % 2 == 0){
            cout << "Es par: "<<  PnElementos[i] << endl;
        }
        else{
            cout << "No es par: " << PnElementos[i] << endl;
        }
    }
}
void ordenar(){
    unsigned short aux;
    for(int i =0; i< nElementos; i++){
        for(int j=0; j < nElementos -1; j++){
            if(*(PnElementos + j) > (*(PnElementos +j +1))){
                aux  = *(PnElementos+j);
                *(PnElementos + j) = *(PnElementos + j +1);
                *(PnElementos +j+1) = aux;
            }
        }
    }
}
void imprimirDatos(){
    cout << "Los numeros de arreglo son: " << endl;
    for(int i = 0; i < nElementos; i++){
        cout <<  PnElementos[i] << endl;
    }
}