#include <iostream>
using namespace std;

struct  Vueltas
{
    float horas, minutos, segundos;
    
}vueltas[3], *Pvueltas = vueltas;


void pedirDatos();
void SumarVueltas(Vueltas *);

int main(){

    pedirDatos();
    SumarVueltas(Pvueltas);

    return 0;
}

void pedirDatos(){
    for(int i=0;i<3;i++){
        fflush(stdin);
        cout << "Ingrese el tiempo de la "<<i+1<< " vuelta:\n ";
        cout << "Horas: ";
        cin >> (Pvueltas+i)->horas;
        cout << "Minutos: ";
        cin >> (Pvueltas+i)->minutos;
        cout << "Segundos: ";
        cin >> (Pvueltas+i)->segundos;
    }

}
void SumarVueltas(Vueltas *Pvueltas){
    float sumaH = 0;
    float sumaM = 0;
    float sumaS = 0;
    for(int i = 0; i < 3; i++){
        sumaH += (Pvueltas+i)->horas;
        sumaM += (Pvueltas+i)->minutos;
        sumaS += (Pvueltas+i)->segundos;
    }
    cout << "El total de horas fue: " << sumaH << endl;
    cout << "El total de minutos fue: " << sumaM << endl;
    cout << "El total de segundos fue: " << sumaS << endl;
}