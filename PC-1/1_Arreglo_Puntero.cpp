#include <iostream>
#include <limits>


using namespace std;

void pedirDatos();
void ingresarDatos();
void imprimirDatos();
void imprimirDatosPares();
void ordenar();
void menu();


int numeros, *Pnumeros;

int main(){

    menu();

    delete[] Pnumeros;

    return 0;
}

void menu(){
    unsigned short opcion;

    do{

        cout << "\t\tMenu\t\t";
        cout << "\n1. ingresar datos\n";
        cout << "2. Ingresar datos pares al arreglo\n";
        cout << "3. SALIR";
        cout << '\n';
        cout << "\nIngrese la opcion: \n";
        cin >> opcion;

        switch (opcion) {
            case 1:
                pedirDatos();
                ingresarDatos();
                ordenar();
                imprimirDatos();
                break;
            case 2:
                pedirDatos();
                ingresarDatos();
                ordenar();
                imprimirDatosPares();
                break;

        }
    }while(opcion !=3);
}
void pedirDatos(){

    do{
        cout << "Ingrese la cantidad de elementos a ingresar: \n";
        cin >> numeros;                                                 //Ingresar cantidad de numeros

        Pnumeros = new int[numeros];                                    // dicemos que Pnumeros(el puntero de numeros) sea igual a new int[numeros](numeros seria la cantidad de elementos que ingresaremos al arreglo)

        while (cin.fail() || numeros != static_cast<int>(numeros)) {  // Verificar si los valores ingresados son números enteros
            cin.clear(); // Limpiar el estado de error del flujo de entrada
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Descartar la entrada inválida hasta la nueva línea
            cout << "\nDebe ingresar solo numeros enteros. Intentelo de nuevo: \n";
            pedirDatos(); // Volver a pedir los datos
        }

    }while(numeros < 0);                                                // mientras que numeros sea menor a cero repetiremos el bucle

}
void ingresarDatos(){

    for(int i; i< numeros; i++){                                        // para cada elemento de i que sea menor a numeros(cantidad de elementos en el arreglo) ingresara al for y a i se le sumara 1
        cout << "Ingrese los numeros: ";
        cin >> Pnumeros[i];                                             // ingresamos los numeros mediante(Pnumeros[i] que nos permite ingresar la cantidad de numeros que dijimos antes)
    }

    cout << "\nDatos ingresados correctamente!!!\n";
    system("pause");
}

void imprimirDatos(){
    for(int i =0;i<numeros;i++){                                        // para cada elemento de i que sea menor a numeros ingrsara al for y a i se le suma 1
        cout << i+1 << ")  " <<  Pnumeros[i] << endl;                   // imprimir los numeros ingresados
    }
}
void imprimirDatosPares(){
    for(int i = 0; i< numeros; i++){
        if(Pnumeros[i]%2 == 0 && Pnumeros[i] !=0) {
            cout << i + 1 << ") " << Pnumeros[i] <<" es par" << endl;
        }

    }

}
void ordenar(){
    int aux;
    for(int i=0; i<numeros; i++){
        for(int j=0;j<numeros-1;j++){
            if(*(Pnumeros+j) > *(Pnumeros+j+1)){
                aux = *(Pnumeros+j);
                *(Pnumeros+j) = *(Pnumeros+j+1);
                *(Pnumeros+j+1) = aux;
            }
        }
    }
}
