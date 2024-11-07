#include <iostream>

using namespace std;
struct Jurados{
    unsigned short nota;

}jurados[4], *Pjurados = jurados;

void pedirDatos();
void promedio();

int main(){
    pedirDatos();
    promedio();
    return 0;
}

void pedirDatos(){
    for(int i = 0;i < 4;i++){
        cout << "Jurado " <<i+1 << " ingrese la nota: "<<'\n' <<endl;
        cin >> jurados[i].nota;
    }

}
void imprimirDatos(){
    for(int i=0;i<4;i++){
        cout << "Jurado " << i+1 << " : " << '\n' <<endl;
        cout << jurados[i].nota;
    }
}
void promedio(){
    float promedio;
    int cantidad;
    for(int i=0;i < 4; i++){
        if(jurados[i].nota > 16 || jurados[i].nota < 13){
            promedio += jurados[i].nota;
            cantidad++;
        }else{
            cout << "La nota: " << jurados[i].nota << " no cuenta para el promedio. " <<'\n' <<endl;
        }

    }
    cout << "El promedio de las 4 notas es de: " << promedio/cantidad;

}