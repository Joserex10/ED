#include <iostream>

using namespace std;

void menu();
void pedirDatos();
void imprimirDatos();
void imprimirDatosPares();
void ordenarMenorMayor();
void ordenarMayorMenor();

int nElementos, *PnElementos;


int main(){

    menu();

    return 0;
}
void menu(){
    unsigned short opcion;
    do {
        cout << "\t\tMENU\t\t";
        cout << "\n1. Ingresar Datos Arreglo" << endl;
        cout << "2. Imprimir Datos pares" << endl;
        cout << "3. Imprimir Datos Ordenados Menor a Mayor" << endl;
        cout << "4. Imprimir Datos Ordenados Mayor a Menor" << endl;
        cout << "5. SALIR" << endl;
        cout << "\nIngrese su opcion: "; cin >> opcion;

        switch (opcion) {
            case 1:
                pedirDatos();
                system("pause");
                cout <<'\n';
                break;
            case 2:
                imprimirDatosPares();
                system("pause");
                cout <<'\n';
                break;
            case 3:
                ordenarMenorMayor();
                imprimirDatos();
                system("pause");
                cout <<'\n';
                break;
            case 4:
                ordenarMayorMenor();
                imprimirDatos();
                system("pause");
                cout <<'\n';
                break;
        }
    }while(opcion !=5);


}
void pedirDatos(){

    cout << "Ingrese la cantidad de elemntos a elegir: ";
    cin >> nElementos;

    PnElementos = new int[nElementos];

    for(int i = 0; i< nElementos; i++){
        cout << "Ingrese el numero: " << endl;
        cin >> PnElementos[i];
    }

}
void imprimirDatos(){
    for(int i = 0; i < nElementos; i++){
        cout << "Numero: " << i+1 << endl;
        cout << PnElementos[i] <<endl;
    }
    cout << "\nTodos los datos fueron mostrados";

}
void imprimirDatosPares(){
    for(int i = 0; i < nElementos; i++){
        if(PnElementos[i]%2 == 0){
            cout << "Es par: " << PnElementos[i] <<endl;
        }

    }
    cout << "\nTodos los datos fueron mostrados";
}
void ordenarMenorMayor(){
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
void ordenarMayorMenor(){
    unsigned short aux;
    for(int i = 0;i < nElementos; i++){
        for(int j = 0; j < nElementos - 1; j++){
            if(*(PnElementos + j) < (*(PnElementos + j +1))){
                aux = *(PnElementos + j);
                *(PnElementos + j) = *(PnElementos + j +1);
                *(PnElementos + j + 1) = aux;
            }
        }
    }
}
