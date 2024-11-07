/*
#include <iostream>
using namespace std;

void IngresaDatos(int num[]) {
    for(int i=0;i<10;i++){
        cout << "Ingrese un numero el numero " <<i<< ": "; cin >> num[i];
    }
}
void parImpar(){ 
    int num[10], *Pnum;
    IngresaDatos(num);
    Pnum = num;
    for(int i=0;i<10;i++){
        if(*Pnum % 2 ==0){
            cout << "El numero " <<*Pnum<< " es par\n";
        }
        else{
            cout << *Pnum << " es impar\n";
        }
        *Pnum++;
    }
}

int main() {
    parImpar();
    return 0;
}


*/


#include <iostream>
using namespace std;

void pedirDatos(int num[]){
    
    for(int i=0;i<10;i++){
        cout << "Ingrese numero " <<i+1<< ": "; cin >> num[i];
    }
}
void verificarMenor(){
    int num[10], *Pnum;
    Pnum = num;
    pedirDatos(num);
    for(int i=0;i<10;i++){
        if(num[i] < *Pnum){
             *Pnum = num[i];
        }
        
    }
    cout << "El numero "<< *Pnum << " es el menor y su posicion en memoria es: "<<Pnum;
    
}

int main(){
    verificarMenor();

    return 0;
}

