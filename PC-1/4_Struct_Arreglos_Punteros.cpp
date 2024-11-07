#include <iostream>

using namespace std;
struct Peliculas{
    string nombre, director, genero;
    char fechaLanzamiento[10], duracion[10];


}peliculas[10], *Ppeliculas = peliculas;

void pedirDatos();
void imprimirDatos();
void buscarDirector();
void buscarGenero();
void menu();

int main(){
    menu();
    pedirDatos();
    imprimirDatos();
    buscarDirector();
    buscarGenero();

    return 0;
}

void menu(){
    unsigned short opcion;

    do{
    cout << "\t\tMENU\t\t";
    cout <<"\n1.Ingresar Datos de peliculas: " << endl;
    cout << "2. Mostrar Peliculas Disponibles: " << endl;
    cout << "3. Buscar peliculas por director: " << endl;
    cout << "4.Buscar peliculas por genero: " << endl;
    cout << "5. SALIR" << endl;
    cout << "\nIngrese su opcion: \n";
    cin >> opcion;


        switch (opcion) {
            case 1:
                pedirDatos();
                system("pause");
                break;
            case 2:
                imprimirDatos();
                system("pause");
                break;
            case 3:
                buscarDirector();
                system("pause");
                break;
            case 4 :
                buscarGenero();
                system("pause");
                break;
        }
    }while(opcion !=5);
}

void pedirDatos(){
    for(int i = 0; i < 2; i++){
        fflush(stdin);
        cout << "Pelicula numero: "<< i+1 <<endl;
        cout << "Ingrese el nombre de la pelicula: " << endl;
        getline(cin, peliculas[i].nombre);
        cout << "Ingrese el nombre del director: "<< endl;
        getline(cin, peliculas[i].director);
        cout << "Ingrese el genero: "<< endl;
        getline(cin, peliculas[i].genero);
        cout << "Ingrese la duracion de la pelicula en minutos: "<< endl;
        cin >> peliculas[i].duracion;
        cout << "Ingrese la fecha de lanzamiento: "<< endl;
        cin >> peliculas[i].fechaLanzamiento;
    }

}
void imprimirDatos(){
    for(int i = 0;i < 2; i++){
        cout << "Pelicula numero: "<< i+1 <<'\n' <<endl;
        cout << "Nombre: " << peliculas[i].nombre <<'\n'<< endl;
        cout << "Director: " << peliculas[i].director <<'\n'<< endl;
        cout << "Genero: " << peliculas[i].genero <<'\n'<< endl;
        cout << "Duracion: " << peliculas[i].duracion <<'\n' << endl;
        cout << "Fecha de lamzamiento: " << peliculas[i].fechaLanzamiento <<'\n'<< endl;
    }
}
void buscarDirector(){
    cin.ignore();
    string director;
    cout << "Ingrese el nombre del director a buscar: ";
    getline(cin,director);
    for(int i =0;i<2;i++){
        if(peliculas[i].director == director){
            cout << "Peliculas disponibles del director: " << director << '\n' <<endl;
            cout << peliculas[i].nombre << endl;
            cout << peliculas[i].director << endl;
            cout << peliculas[i].genero << endl;
            cout << peliculas[i].duracion << endl;
            cout << peliculas[i].fechaLanzamiento << endl;
        }
    }

}
void buscarGenero(){
    cin.ignore();
    string genero;
    cout << "Ingrese el genero: " << endl;
    getline(cin,genero);
    for(int i =0; i< 2; i++){
        if(peliculas[i].genero == genero){
            cout << "Peliculas disponibles segun el genero: " << genero << endl;
            cout << peliculas[i].nombre << endl;
            cout << peliculas[i].director << endl;
            cout << peliculas[i].genero << endl;
            cout << peliculas[i].duracion << endl;
            cout << peliculas[i].fechaLanzamiento << endl;
        }
    }


}