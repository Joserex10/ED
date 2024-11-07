#include <iostream>
#include <limits>
using namespace std;

int i, Elementos, opcion;

int numero[] = {};

void menu();
void burbujaAscendente();
void burbujaDescendente();
void ordenInsercion();
void pedirDatos();
void mostrarArreglo();
int main()
{

    menu();

    return 0;
}
void menu()
{
    do
    {
        cout << "\t\tMenu\t\t" << endl;
        cout << "1. Ordenamiento Burbuja(Ascendente)" << endl;
        cout << "2. Ordenamiento Burbuja(Descendente)" << endl;
        cout << "3. Ordenamiento Insercion" << endl;
        cout << "4. Ordenamiento Seleccion" << endl;
        cout << "5. Ordenamiento MergeSort" << endl;
        cout << "6. SALIR" << endl;
        cout << "\nIngrese la opcion: " << endl;
        cin >> opcion;

        switch (opcion)
        {
        case 1:
            pedirDatos();
            burbujaAscendente();
            cout << "Mostrando el arreglo ordenado...\n\n\n";
            mostrarArreglo();
            cout << '\n';
            system("pause");
            break;
        case 2:
            pedirDatos();
            burbujaDescendente();
            cout << "Mostrando el arreglo ordenado...\n\n\n";
            mostrarArreglo();
            cout << '\n';
            system("pause");
            break;
        case 3:
            pedirDatos();
            cout << "Mostrando los elementos ordenados....\n\n\n";
            ordenInsercion();
            break;
        case 4:
            break;
        case 5:
            break;
        }
    } while (opcion != 6);
}
void pedirDatos()
{
    cout << "Ingrese la cantidad de elementos del arreglo: ";
    cin >> Elementos;

    for (int i = 0; i < Elementos; i++)
    {
        fflush(stdin);
        cout << "Ingrese el numero " << i + 1 << ": " << endl;
        cin >> numero[i];
    }
}
void burbujaAscendente()
{
    int temp;
    for (int i = 0; i < Elementos - 1; i++)
    {
        for (int j = 0; j < Elementos - 1 - i; j++)
        {
            if (numero[j] > numero[j + 1])
            {
                temp = numero[j];
                numero[j] = numero[j + 1];
                numero[j + 1] = temp;
            }
        }
    }
}
void burbujaDescendente()
{
    int temp;
    for (int i = 0; i < Elementos - 1; i++)
    {
        for (int j = 0; j < Elementos - 1 - i; j++)
        {
            if (numero[j] < numero[j + 1])
            {
                temp = numero[j];
                numero[j] = numero[j + 1];
                numero[j + 1] = temp;
            }
        }
    }
}
void mostrarArreglo()
{
    cout << "\n\nMostrando arreglo ordenado:";
    for (int i = 0; i < Elementos; i++)
    {
        cout << '\n'
             << numero[i];
    }
}
void ordenInsercion()
{
    int j;
    for (i = 1; i < Elementos; i++)
    {
        int temp = numero[i]; // Guardamos el valor que vamos a insertar
        j = i - 1;

        // Desplazamos los elementos del arreglo que son mayores que temp hacia adelante
        while (j >= 0 && numero[j] > temp)
        {
            numero[j + 1] = numero[j];
            j--;
        }
        numero[j + 1] = temp; // Insertamos temp en su posición correcta
    }

    cout << "Orden Ascendente\n";
    for (i = 0; i < Elementos; i++)
    {
        cout << numero[i] << endl; // Imprimimos cada número ya ordenado del arreglo
    }
    cout << "\n\n\n\n";
    system("pause");
}
