#include <iostream>
#include <stdlib.h>
#include <limits>
using namespace std;
int num, *Pnum;

void pedirDatos();
void numerosPares(int *Pnum, int num);

int main(){

    pedirDatos();
    numerosPares(Pnum,num);

    delete[] Pnum;
    return 0;
}
void pedirDatos(){

    cout << "Ingrese la cantidad de numeros: "; cin >> num;
    while(cin.fail()){
		cin.clear();
		cin.ignore(numeric_limits<streamsize>:: max(),'\n');
		cout << "Entrada invalida, porfavor ingrese numeros positivos: ";
		cin >> num;
	}

    Pnum = new int[num];
    for(int i=0;i<num;i++){
        cout << "Ingrese el numero "<<i+1<< " :"; cin >> Pnum[i];
        
    }

}
void numerosPares(int *Pnum, int num){
    for(int i=0;i<num;i++){
        if(*(Pnum+i)%2==0){
            cout <<"\n\nNumero par encontrado en el arreglo\n" <<*(Pnum+i);
        }
    }
}