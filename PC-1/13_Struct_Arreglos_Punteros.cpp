#include <iostream>

using namespace std;
struct Vueltas{
    string nombre;
    unsigned short tiempo;

}vueltas[3], *Pvueltas = vueltas;

void pedirDatos();
void imprimirDatos();
void imprimirGanador();
void promedio();
void menu();

int main(){

    menu();
    return 0;
}

void menu(){
    unsigned short opcion;
    do{
        cout << "\t\tMENU\t\t";
        cout << "\n1. Ingresar Datos" << endl;
        cout << "2. Imprimir Datos" << endl;
        cout << "3. Imprimir ganador" << endl;
        cout << "4. Promedio de tiempo" << endl;
        cout << "5. SALIR" << endl;
        cout << "\nIngrese la opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                pedirDatos();
                system("pause");
                cout << '\n';
                break;
            case 2:
                imprimirDatos();
                system("pause");
                cout << '\n';
                break;
            case 3:
                imprimirGanador();
                system("pause");
                cout << '\n';
                break;
            case 4:
                promedio();
                system("pause");
                cout << '\n';
                break;
        }
    }while(opcion != 5);

}

void pedirDatos(){
    for(int i =0; i< 3; i++){
        cin.ignore();
        fflush(stdin);
        cout << "Vuelta Ganador: " << i+1 << endl;
        cout << "Ingrese el nombre del corredor: " << endl;
        getline(cin, vueltas[i].nombre);
        cout << "Ingrese el tiempo de la vuelta: " << endl;
        cin >> vueltas[i].tiempo;
    }
    cout << "\nTODOS LOS DATOS INGRESADOS" << endl;
}
void imprimirDatos(){
    for(int i =0; i< 3; i++){
        cout << "Vuelta Ganador: " << i+1 << endl;
        cout << vueltas[i].nombre << endl;
        cout << vueltas[i].tiempo;
        cout <<'\n';
    }
    cout << "\nTODOS LOS DATOS MOSTRADOS" << endl;
}
void imprimirGanador(){
    unsigned short max = 9999;
    string nombre;
    for(int i =0; i< 3; i++){
        if(vueltas[i].tiempo < max){
            max = vueltas[i].tiempo;
            nombre = vueltas[i].nombre;
        }
    }
    cout << "El ganador es: "  << nombre << " con un tiempo de: "<< max << endl;


}
void promedio(){
    float promedio =0;
    unsigned short cantidad =0;
    for(int i =0; i< 3; i++){
        promedio += vueltas[i].tiempo;
        cantidad ++;
    }
    cout << "El promedio de tiempo de las 3 vueltas es de " << promedio/cantidad << endl;
}