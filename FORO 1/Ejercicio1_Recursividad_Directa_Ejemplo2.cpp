/*
Inicio
    Función caminar(pasos)
        Si pasos > 0 entonces
            Imprimir "Diste un paso! \t Numero de paso: ", contador
            Incrementar contador en 1
            Llamar a caminar(pasos - 1)
        Fin Si
    Fin Función

    contador = 1
    Inicio del programa
        Llamar a caminar(100)
        Devolver 0
    Fin del programa
Fin 
*/

#include <iostream>
using namespace std;

void caminar(int pasos);
int contador = 1;
int main(){

    caminar(100);
    return 0;
}
void caminar(int pasos){
    if(pasos > 0){
        cout << "Diste un paso!\t" << "Numero de paso: "<< contador << endl;;
        contador++;
        caminar(pasos - 1);
        
    }

}