#include <iostream>
#include <conio.h>

using namespace std;
struct Empleado{
    string nombre, departamento;
    unsigned short edad, salario;
}empleado[3], *Pempleado = empleado;



void pedirDatos();
void imprimirDatos();
void promedioSueldos();
void menu();



int main(){

    menu();

    return 0;
}

void menu(){
    unsigned short opcion;
    cout << "\t\tMENU\t\t";
    cout << "\n1. Ingresar empleados\n";
    cout << "2.SALIR\n";
    cout << "Ingrese una opcion: \n";
    cin >> opcion;
    do{
        switch (opcion) {
            case 1:
                pedirDatos();
                imprimirDatos();
                promedioSueldos();
                system("pause");
                break;
        }

    }while(opcion !=2);

}
void pedirDatos(){
    for(int i = 0;i < 3; i++){

        fflush(stdin);
        cout <<"Empleado numero " <<i+1 << " :" <<  endl;
        cout << "Ingrese el nombre del empleado: \n";
        getline(cin,empleado[i].nombre);
        cout << "Ingrese la edad del empleado: \n";
        cin >> empleado[i].edad;
        cin.ignore();
        cout << "Ingrese el departamento del empleado: \n";
        getline(cin,empleado[i].departamento);
        cout << "Ingrese el salario del empleado: \n";
        cin >> empleado[i].salario;
    }

}
void imprimirDatos(){
    for(int i = 0;i < 3; i++){
        cout << i+1 << ") " << "Nombre: " << empleado[i].nombre << endl;
        cout << "Edad: " << empleado[i].edad<< endl;
        cout <<  "Departamento: " << empleado[i].departamento<< endl;
        cout <<  "Salario: " << empleado[i].salario<< endl;

        if(empleado[i].salario <=1000){
        cout << "Tiene un salario bajo\n"<< endl;
        }else if(empleado[i].salario >1000 && empleado[i].salario <=3000){
        cout << "Tiene un salario medio\n"<< endl;
        }else{
        cout << "Tiene un salario alto\n"<< endl;
        }

    }
}
void promedioSueldos(){
    float promedio;
    for(int i=0;i < 3; i++){
        promedio += empleado[i].salario;
    }
    cout << "El promedio de los salarios de los trabajadores es: " << promedio/3 << endl;
}
