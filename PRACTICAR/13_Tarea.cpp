#include <iostream>
using namespace std;

struct Alumno
{
    char nombre[30];
    float calificacion1,calificacion2,calificacion3;
}alumno[3],*Palumno = alumno;

void pedirDatos();
void mostrarPromedio(Alumno *);


int main(){
    pedirDatos();
    mostrarPromedio(Palumno);
    return 0;
}
void pedirDatos(){
    for(int i=0;i<3;i++){
        fflush(stdin);
        cout << "\nIngrese el nombre del alumno " <<i+1 <<" :"<<endl;
        cin.getline((Palumno+i)->nombre,30,'\n');
        cout << "Ingrese la calificacion "<<i+1<<" :"<<endl;
        cin >> (Palumno+i)->calificacion1;
        cout << "Ingrese la calificacion "<<i+1<<" :"<<endl;
        cin >> (Palumno+i)->calificacion2;
        cout << "Ingrese la calificacion "<<i+1<<" :"<<endl;
        cin >> (Palumno+i)->calificacion3;
    }
    
    

}

void mostrarPromedio(Alumno *Palumno){
    float promedio =0;

    for(int i=0;i<3;i++){
        promedio = (Palumno+i)->calificacion1 + (Palumno+i)->calificacion2 + (Palumno+i)->calificacion3;
        cout << "\n\nEl promedio del alumno "<<(Palumno+i)->nombre<<" es: "<<promedio/3;
    }

}