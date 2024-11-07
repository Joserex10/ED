#include <iostream>
using namespace std;
struct Alumnos{
    string nombre;
    unsigned short calificacion;

}alumnos[3], *Palumnos = alumnos;

void pedirDatos();
void imprimirDatos();
void calcularPromedio();

int main(){
     pedirDatos();
     imprimirDatos();
     calcularPromedio();
    return 0;
}

void pedirDatos(){
    for(int i=0;i<3;i++){
        fflush(stdin);
        cout << "Alumno: " << i+1 << endl;
        cout << "Ingrese el nombre: " << endl;
        getline(cin,alumnos[i].nombre);
        cout << "Ingrese la calificacion: "<<endl;
        cin >> alumnos[i].calificacion;
    }

}
void imprimirDatos(){
    for(int i=0;i<3;i++){
        cout << " El alumno :" << alumnos[i].nombre <<" tiene la calificacion de: " << alumnos[i].calificacion << endl;
    }
}
void calcularPromedio(){
    float promedio;
    unsigned short cantidad;
    for(int i=0;i<3;i++){
        promedio += alumnos[i].calificacion;
        cantidad++;
    }
    cout << "El promedio de notas del salon es de: " << promedio/cantidad << endl;
}