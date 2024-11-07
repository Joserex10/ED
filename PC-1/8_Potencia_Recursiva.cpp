#include <iostream>
using namespace std;

unsigned short base, exponente, factorial, numero, numero1, numero2 , numeroD1, numeroD2, numeroR1, numeroR2;

void pedirDatosF();
void pedirDatosS();
void pedirDatosP();
void pedirDatosM();
void pedirDatosD();
void pedirDatosR();
int hallarPotencia(int x,int y);
int hallarSuma(int n);
int hallarFactorial(int n);
int hallarMultiplicacion(int n1, int n2);
int hallarDivision(int n1, int n2);
int hallarResta(int n1, int n2);
void menu();

int main(){

    menu();

    return 0;
}
void menu(){
    unsigned short opcion;


    do{
        cout << "\t\tMENU\t\t";
        cout << "\n1. Hallar Factorial" << endl;
        cout << "2. Hallar Suma" << endl;
        cout << "3. Hallar Potencia" << endl;
        cout << "4. Hallar Multiplicacion" << endl;
        cout << "5. Hallar division" << endl;
        cout << "6. Hallar resta" << endl;
        cout << "7. SALIR"<<endl;
        cout << "\nIngrese su opcion: "; cin >> opcion;

        switch (opcion) {
            case 1:
                pedirDatosF();
                cout << hallarFactorial(factorial) << endl;
                system("pause");
                cout << '\n';
                break;
            case 2:
                pedirDatosS();
                cout << hallarSuma(numero)<< endl;
                system("pause");
                cout << '\n';
                break;
            case 3:
                pedirDatosP();
                cout << hallarPotencia(base, exponente)<< endl;
                system("pause");
                cout << '\n';
                break;
            case 4:
                pedirDatosM();
                cout << hallarMultiplicacion(numero1,numero2) << endl;
                system("pause");
                cout << 'n';
                break;
            case 5:
                pedirDatosD();
                cout << hallarDivision(numeroD1, numeroD2) << endl;
                system("pause");
                cout << '\n';
                break;
            case 6:
                pedirDatosR();
                cout << hallarResta(numeroR1, numeroR2) << endl;
                system("pause");
                cout << '\n';
                break;
        }

    }while(opcion !=7);

}

void pedirDatosF(){
    cout << "Ingrese el factorial: "; cin >> factorial;
}
int hallarFactorial(int n){
    if(n == 0){
        n =1;
    }else{
        n = n* hallarFactorial(n-1);
    }
    return n;
}
void pedirDatosS(){
    cout << "Ingrese el numero: "; cin >> numero;
}
int hallarSuma(int n){
    int suma;
    if(n == 1){
        suma = 1;
    }else{
        suma = n + hallarSuma(n-1);
    }
    return suma;
}
void pedirDatosP(){
    cout << "Ingrese la base: "; cin >> base;
    cout << "Ingrese el exponente: "; cin >> exponente;
}
int hallarPotencia(int x,int y){
    int pot;
    if(y == 1){
        pot = x;
    }else{
        pot = x * hallarPotencia(x,y-1);
    }
    return pot;
}
void pedirDatosM(){
    cout << "Ingrese el numero 1: ";cin >> numero1;
    cout << "Ingrese el numero 2: "; cin >> numero2;
}
int hallarMultiplicacion(int n1, int n2){
    int multi;
    if(n1 == 0 && n2 ==0){
        multi = 0;
    }
    else if(n1 == 0 || n2 == 0){
        multi = 0;
    }
    else if(n1 == 1){
        multi = n2;
    }
    else if(n2 == 1){
        multi = n1;
    }
    else{
        multi = n1 + hallarMultiplicacion(n1,n2-1);
    }
    return multi;
}
void pedirDatosD(){
    cout << "Ingrese numero 1: "; cin >> numeroD1;
    cout << "Ingrese numero 2: "; cin >> numeroD2;
}
int hallarDivision(int n1, int n2){
    float divi;
    if (n1 < n2) {
        divi = 0; // División completa
    }
    else if(n1 == 0 || n2 == 0 ){
        divi = 0;
    }
    else if(n1 == n2 ){
        divi =  1 + hallarDivision(n1 - n2, n2);
    }
    else{
        divi =  1 + hallarDivision(n1 - n2, n2);
    }
    return divi;
}
void pedirDatosR(){
    cout << "Ingrese el numero 1: "; cin >> numeroR1;
    cout << "Ingrese el numero 2: "; cin >>  numeroR2;
}
int hallarResta(int n1, int n2){
    unsigned short resta;
    if(n1 ==0 && n2 == 0){
        resta = 0;
    }
    else if(n1 == 0){
        resta = n2;
    }
    else if(n2 == 0){
        resta = n1;
    }
    else if(n1 < n2){
        resta = n2 - n1;
    }
    else if(n2 < n1){
        resta = n1 - n2;
    }
    else{
        resta = n1 - hallarResta(n1 - n2, n2);
    }
    return resta;
}