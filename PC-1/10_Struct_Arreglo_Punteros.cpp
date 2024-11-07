#include <iostream>

using namespace std;
struct Jurados{
    unsigned short puntuacion1,puntuacion2,puntuacion3;

}jurados[3], *Pjurados = jurados;

void menu();
void pedirDatos();
void imprimirDatos();
void puntuacionFinal();

int main(){

    menu();

}

void menu(){
    unsigned short opcion;

    do{
        cout << "\t\tMENU\t\t";
        cout << "\n1. Ingresar Datos" << endl;
        cout << "2. Imprimir datos" << endl;
        cout << "3. Puntuacion final del participante" << endl;
        cout << "4. SALIR" << endl;
        cout << "\nIngrese la opcion: "; cin >> opcion;

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
                puntuacionFinal();
                system("pause");
                cout << '\n';
                break;
        }
    }while(opcion != 4);


}
void pedirDatos(){
    for(int i =0; i < 3; i++){
        fflush(stdin);
        cout << "Ingrese la puntuacion de la ronda " << i+1 << endl;
        cin  >> jurados[i].puntuacion1 ;
        cout << '\n';
        cin  >> jurados[i].puntuacion2 ;
        cout << '\n';
        cin  >> jurados[i].puntuacion3 ;
        cout << '\n';
    }
    cout << "DATOS INGRESADOS CORRECTAMENTE" << endl;
}
void imprimirDatos(){
    cout << "Las calificaciones de cada ronda son: " << endl;
    for(int i = 0; i < 3; i++){
        cout << "Ronda: " << i+1 << endl;
        cout << jurados[i].puntuacion1;
        cout << '\n';
        cout << jurados[i].puntuacion2;
        cout << '\n';
        cout << jurados[i].puntuacion3;
        cout << '\n';
    }
}
void puntuacionFinal(){
    float promedio;
    cout << "La puntuacion final del participante es: "<< endl;
    for(int i = 0; i < 3; i++){
        unsigned short max = 0, min = 10; // Se reinician max y min para cada ronda
        cout << "Ronda: " << i+1 <<endl;

        // Comparamos las puntuaciones con max y min
        if(jurados[i].puntuacion1 > max ){
            max = jurados[i].puntuacion1;
        }
        if(jurados[i].puntuacion2 > max ){
            max = jurados[i].puntuacion2;
        }
        if(jurados[i].puntuacion3 > max ){
            max = jurados[i].puntuacion3;
        }
        if(jurados[i].puntuacion1 < min){
            min = jurados[i].puntuacion1;
        }
        if(jurados[i].puntuacion2 < min){
            min = jurados[i].puntuacion2;
        }
        if(jurados[i].puntuacion3 < min){
            min = jurados[i].puntuacion3;
        }

        // Sumamos la puntuación máxima y mínima para calcular el promedio
        promedio = max + min;
        cout << "La calificacion mas alta es: " << max << " y la mas baja es: " << min << endl;
        cout << "El promedio de las 3 rondas es: " << promedio/2 << endl;
    }
}
