
/*
Inicio

Funcion getRandomNumber(min, max):
    Retorna un numero aleatorio entre min y max

Funcion Hipo(xi, yi, n, m, sobria):
    Para i desde 0 hasta 9:
        dx = getRandomNumber(-1, 1)
        dy = getRandomNumber(-1, 1)
        xi = max(0, min(n - 1, xi + dx))
        yi = max(0, min(m - 1, yi + dy))
        Imprimir "La hormiga camina hacia una direccion aleatoria (", xi, ", ", yi, ")."
        Si sobria es Falso:
            Imprimir "La hormiga esta borracha."

Inicio del programa:
    Inicializar la semilla para la generacion de numeros aleatorios
    Leer n y m (el volumen del campo)
    Declarar un campo de volumen n x m
    Leer los valores del campo con terrones
    Leer la posicion inicial de la hormiga y la direccion
    Inicializar el numero de pasos en 0
    Inicializar la variable sobria como Verdadero

    Mientras pasos sea menor que 50:
        Si la posicion de la hormiga esta fuera del campo:
            Imprimir "La hormiga esta en el borde del campo."
            Ajustar la posicion de la hormiga y la direccion segun las reglas
        Sino:
            Imprimir "La hormiga esta en la posicion (", xi, ", ", yi, ") y se dirige hacia el ", dir, "."
            Obtener el terron en la posicion actual del campo
            Segun el terron:
                Si es azucar:
                    Imprimir "La hormiga encontro azucar y se lo come."
                Si es licor:
                    Imprimir "La hormiga encontro licor, se lo come, se emborracha y sigue avanzando."
                    Establecer sobria como Falso
                    Llamar a la funcion Hipo con la posicion actual de la hormiga
                    Restablecer sobria como Verdadero después de que Hipo haya terminado
                Si es veneno:
                    Si la hormiga esta sobria:
                        Imprimir "La hormiga encontro veneno, esta sobria, se lo come y muere."
                        Terminar el programa
                    Sino:
                        Imprimir "La hormiga encontro veneno, esta borracha, se lo come y muere."
                        Terminar el programa
            Actualizar la posicion de la hormiga segun la direccion
        Incrementar el numero de pasos

    Imprimir "La hormiga llego al límite de pasos permitidos y sobrevive."

Fin del programa

FIN
*/

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int getRandomNumber(int min, int max) {
    return rand() % (max - min + 1) + min;
}

void Hipo(int& xi, int& yi, int n, int m, bool& sobria) {
    for (int i = 0; i < 10; ++i) {
        int dx = getRandomNumber(-1, 1);
        int dy = getRandomNumber(-1, 1);
        xi = max(0, min(n - 1, xi + dx));
        yi = max(0, min(m - 1, yi + dy));
        cout << "La hormiga camina hacia una direccion aleatoria (" << xi << ", " << yi << ")." << endl;
        if (!sobria) {
            cout << "La hormiga esta borracha." << endl;
        }
    }
}
int main() {
    srand(time(0));
    int n, m;
    cout << "Ingrese el volumen del campo (n m): \n";
    cin >> n >> m;

    int campo[n][m];
    cout << "Ingrese el campo con terrones (0: Vacio, 1: Azucar, 2: Licor, 3: Veneno): \n" << endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> campo[i][j];
        }
    }
    int xi, yi, dir;
    cout << "Ingrese la posicion inicial de la hormiga (x , y) y la direccion (1-8): \n ";
    cin >> xi >> yi >> dir;

    int pasos = 0;
    bool sobria = true;
    while (pasos < 50) {
        if (xi < 0 || xi >= n || yi < 0 || yi >= m) {
            cout << "La hormiga esta en el borde del campo. \n" << endl;
            xi = max(0, min(n - 1, xi));
            yi = max(0, min(m - 1, yi));
            dir = (dir + 1) % 8 + 1;
        } else {
            cout << "La hormiga esta en la posicion (" << xi << ", " << yi << ") y se dirige hacia el " << dir << ".\n" << endl;
            int terron = campo[xi][yi];
            switch (terron) {
                case 1:
                    cout << "La hormiga encontro azucar y se lo come.\n" << endl;
                    break;
                case 2:
                    cout << "La hormiga encontro licor, se lo come, se emborracha y sigue caminando.\n" << endl;
                    sobria = false;
                    Hipo(xi, yi, n, m, sobria);
                    sobria = true;
                    break;
                case 3:
                    cout << "La hormiga encontro veneno.\n" << endl;
                    if (sobria) {
                        cout << "La hormiga esta sobria, se lo come y muere.\n" << endl;
                        return 0;
                    } else {
                        cout << "La hormiga esta borracha, se lo come y muere.\n" << endl;
                        return 0;
                    }
                    break;
            }
            xi += (dir == 2 || dir == 3 || dir == 4) - (dir == 6 || dir == 7 || dir == 8);
            yi += (dir == 4 || dir == 5 || dir == 6) - (dir == 1 || dir == 2 || dir == 8);
        }
        ++pasos;
    }
    cout << "La hormiga llego al limite de pasos permitidos y sobrevive.\n" << endl;
    return 0;
}

