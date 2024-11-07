#include <iostream>
using namespace std;

struct Estudiante{
    string nombre;
    char edad;
    string carrera;
    float promedio;

}estudiante[3] , *Pestudiante = estudiante;

void pedirDatos();
void imprimirDatos();
void buscarCarrera();
void buscarEdad();
void calcularPromedio();
void menu();


int main(){

    menu();


}
void menu(){
    unsigned short opcion;

    do{
        cout << "\t\tMENU\t\t";
        cout << "\n1. Ingresar Alumnos" << endl;
        cout << "2. Buscar por carreara" << endl;
        cout << "3. Buscar por edad" << endl;
        cout << "4. Calcular promedio de notas" << endl;
        cout << "5.SALIR" << endl;
        cout << "\nIngrese su opcion: "; cin>> opcion;

        switch (opcion) {
            case 1:
                pedirDatos();
                imprimirDatos();
                system("pause");
                break;
            case 2:
                buscarCarrera();
                system("pause");
                break;
            case 3:
                buscarEdad();
                system("pause");
                break;
            case 4:
                calcularPromedio();
                system("pause");
                break;

        }

    }while(opcion !=5);
}
void pedirDatos(){
    for(int i = 0; i < 3;i++){
        fflush(stdin);
        cout <<"Estudiante " <<  i+1 << endl;
        cout << "Ingrese el nombre del estudiante: " << endl;
        getline(cin,estudiante[i].nombre);
        cout << "Ingrese la carrera: " << endl; getline(cin,estudiante[i].carrera);
        cout << "Ingrese la edad: " << endl; cin >> estudiante[i].edad;
        cin.ignore();
        cout << "Ingrese el promedido de sus notas: " << endl; cin >> estudiante[i].promedio;
    }
}
void imprimirDatos(){
    for(int i=0;i<3;i++){
        fflush(stdin);
        cout << i+1 << ") " << '\n' <<endl;
        cout <<"Nombre: " <<estudiante[i].nombre << endl;
        cout <<"Carrera: " <<estudiante[i].carrera << endl;
        cout <<"Edad: "<<estudiante[i].edad << endl;
        cout <<"Promedio: " <<estudiante[i].promedio << endl;
    }
}
void buscarCarrera(){
    cin.ignore();
    string carrera;
    cout << "Ingrese la carrera a buscar: ";
    getline(cin, carrera);
    for(int i=0;i<3;i++){
        fflush(stdin);
        if(estudiante[i].carrera == carrera){
            cout << i+1 <<  ") " <<'\n' <<endl;
            cout <<"Nombre: " <<estudiante[i].nombre << endl;
            cout <<"Carrera: " <<estudiante[i].carrera << endl;
            cout <<"Edad: "<<estudiante[i].edad << endl;
            cout <<"Promedio: " <<estudiante[i].promedio << endl;
        }

    }
}
void buscarEdad(){
    cin.ignore();
    char edad;
    cout << "Ingrese la edad a buscar: ";
    cin >> edad;
    for(int i =0;i <3 ;i++){
        fflush(stdin);
        if(estudiante[i].edad == edad){
            cout << i+1 <<  ") " <<'\n' <<endl;
            cout <<"Nombre: " <<estudiante[i].nombre << endl;
            cout <<"Carrera: " <<estudiante[i].carrera << endl;
            cout <<"Edad: "<<estudiante[i].edad << endl;
            cout <<"Promedio: " <<estudiante[i].promedio << endl;
        }
    }
}
void calcularPromedio(){
    float promedio, cantidad;
    for(int i =0;i<3; i++){
        promedio += estudiante[i].promedio;
        cantidad++;
    }
    cout << "El promedio de las notas de todos los estudiantes es de: " << promedio / cantidad << endl;
}
