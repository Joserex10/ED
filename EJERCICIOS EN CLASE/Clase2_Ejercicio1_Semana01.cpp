
#include <iostream>
using namespace std;
template<typename T>
T suma(T a, T b){
    return a + b;
}
double x , y;
void perdirDatos();

int main()
{
    
    perdirDatos();
    cout<<"Entero: \n"<< suma<int>(x,y)<<"\n";
    cout<<"float: \n"<< suma<float>(x,y)<<"\n";
    cout<<"double: \n"<< suma<double>(x,y)<<"\n";
    return 0;
    

    
}

void perdirDatos(){
    cout<<"Ingresa numero 1: ";
    cin>>x;
    cout<<"Ingrese numero 2: ";
    cin>>y;
}