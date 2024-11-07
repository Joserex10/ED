#include <iostream> // input output
#include <conio.h> //getch()
using namespace std;
//prototipo de la funcion 
void multiplica(float x, float y);
void pedirDatos();

float num01, num02;
int main()
{
    pedirDatos();
    multiplica(num01, num02);
    getch();
    return 0;
}
//desarrollo de las funciones
void pedirDatos(){
    cout<<" Ingrese los dos numeros: ";
    cin>>num01>>num02;
 }
void multiplica(float x, float y){
    
    float multiplicacion = x*y ;
    cout<<" El resultado es: "<<multiplicacion<<endl;
}