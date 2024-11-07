#include <iostream>
using namespace std;

struct Alumno{
    char nombre[30];
    int edad;
    float promedio;
}alumno[3], *Palumno = alumno;

void pedirDatos();
void MejorPromedio(Alumno *);

int main(){

    pedirDatos();
    MejorPromedio(Palumno);

    return 0;
}
void pedirDatos(){
    for(int i=0;i<3;i++){
        fflush(stdin);
        cout << "Digite su nombre: " ;
        cin.getline((Palumno+i)->nombre,30,'\n');   //Guardando nombres para cada alumno
        cout << "Digite su edad: ";
        cin >> (Palumno+i)->edad;
        cout << "Digite el promedio: ";
        cin >> (Palumno+i)->promedio;
    }
}
void MejorPromedio(Alumno *Palumno){
    float mayor = 0.0;
    int pos=0;
    for(int i=0;i<3;i++){
        if((Palumno+i)->promedio > mayor){
            mayor = (Palumno+i )->promedio;    //Comprobar el mayor promedio
            pos = i;    //Guardar la posicion del mayor promedio
        }
    }
    //Imprimir los datos del alumno con el mayor promedio
    cout << "\nEl alumno con mejor promedio es: \n"<< endl;
    cout << "\nNombre: " << (Palumno+pos)->nombre <<endl;
    cout << "\nEdad: " << (Palumno+pos)->edad<< endl;
    cout << "\nPromedio: " << (Palumno+pos)->promedio <<endl;
}