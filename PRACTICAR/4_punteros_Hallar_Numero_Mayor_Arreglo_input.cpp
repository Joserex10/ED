#include <iostream>
using namespace std;

int num, *Pnum;

void pedirDatos();
int hallarMax(int *, int);


int main(){

    pedirDatos();
    cout << "El mayor numero en el arreglo es: "<< hallarMax(Pnum,num);
    return 0;
}
void pedirDatos(){

    cout <<"Ingrese la cantidad de numeros: "; cin >> num;

    Pnum = new int [num];

    for(int i=0;i<num;i++){
        cout << "Ingrese el " << i+1 << " numero: "; cin >> Pnum[i];
    }
}
int hallarMax(int *Pnum, int num){
    int max = 0;

    for( int i =0; i< num; i++){
        if(*(Pnum+i)>max){
            max = *(Pnum+i);
        }
    }
    return max;
}