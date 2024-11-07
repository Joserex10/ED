#include<iostream>
#include<math.h>
using namespace std;
//prototipos de las funciones utilizadas
void pedirDatos();
void operador();
int sumar(int n1, int n2);
int restar(int n1, int n2);
int multiplicar(int n1, int n2);
float dividir(int n1, int n2);
int potencia(int n1, int n2);
int residuo(int n1, int n2);

int operacion;
char op;
int n1, n2;

int main(){
	 pedirDatos();
	 operador();

return 0;
	
}
int sumar(int n1, int n2) {
    int operacionS;
    if (n2 == 0) {
        operacionS = n1;
    }
    else if (n1 == 0) {
        operacionS = n2;
    }
	else if(n2 < 0){
		operacionS = sumar(n1 - 1, n2 + 1);
	}
    else {
        operacionS = sumar(n1 + 1, n2 - 1);
    }
    return operacionS;
}

int restar(int n1, int n2){
	int operacionR;
    if (n2 == 0) {
        operacionR = n1;
    }
    else if (n1 == 0) {
        operacionR = n2;
    }
	else if(n1 < 0 && n2 < 0){
		operacionR = restar(n1 + 1 , n2 + 1);
	}
    else {
        operacionR = restar(n1-1 , n2 - 1);
    }
    return operacionR;
}

int multiplicar(int n1, int n2){
	int operacionR;
	if(n1 == 0){
		operacion = n1;
	}
	else if(n2 == 0){
		operacion = n2;
	}
    else if (n2 == 1) {
        operacionR = n1;
    }
    else if (n1 == 1) {
        operacionR = n2;
    }
	else if(n1 < 0){
		operacionR =  -multiplicar(-n1, n2);
	}
	else if(n2 < 0){
		operacionR =  -multiplicar(n1, -n2);
	}
	else if(n1 < 0 && n2 < 0){
		operacionR =  multiplicar(-n1, -n2);
	}
    else {
        operacionR = n1 + multiplicar(n1 , n2 - 1);
    }
    return operacionR;
}

float dividir(int n1, int n2){
	int operacionD;
	if (n1 < n2) {
        operacionD = 0; // División completa
    }
	else if(n1 == 0 || n2 == 0 ){
		operacionD = 0;
	}
	else if(n1 == n2 ){
		operacionD =  1 + dividir(n1 - n2, n2);
	}
    else{
		operacionD =  1 + dividir(n1 - n2, n2);
	}
	return operacionD;
    
}

int potencia(int n1, int n2){
	if(n2==0){
		return 1;
	}
	if(n2==1){
		return n1;
	}else{
		return n1*potencia(n1,n2-1);
	}
}

int residuo(int n1, int n2) {
	int operacion;
    if (n2 == 0) {
        operacion = 0; 
    }
	else if(n1 == 0){
		operacion = 0;
	}
    else if (n1 < n2) {
        operacion = n1;
    }
	else if(n2 > n1){
		operacion = n1;
	}
	else{
		operacion = residuo(n1 - n2, n2);
	}
	return operacion;
    
}
void pedirDatos(){
	cout<<"Ingrese el operador: ";
	cin>>op;
	cout << "Ingrese los numeros para la operacion: ";
	cin>>n1;
	cin>>n2;
	while (cin.fail() || n1 != static_cast<int>(n1) || n2 != static_cast<int>(n2)) {  // Verificar si los valores ingresados son números enteros
        cin.clear(); // Limpiar el estado de error del flujo de entrada
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Descartar la entrada inválida hasta la nueva línea
        cout << "Debe ingresar solo números enteros. Inténtelo de nuevo: ";
        pedirDatos(); // Volver a pedir los datos
    }

}

void operador(){
	switch(op){
			case '+':
				cout<<"La suma de "<<n1<<" y "<<n2<<" es "<<sumar(n1,n2)<<endl;
				break;
			case '-':
				cout<<"La resta de "<<n1<<" y "<<n2<<" es "<<restar(n1,n2)<<endl;
				break;
			case '*':
				cout<<"La multiplicacion "<<n1<<" y "<<n2<<" es "<<multiplicar(n1,n2)<<endl;
				break;
			case 'P':
				cout<<n1<<" elevado a "<<n2<<" es "<<potencia(n1,n2)<<endl;
				break;
			case 'D':
				cout<<"El cociente de "<<n1<<" y "<<n2<<" es "<<dividir(n1,n2)<<endl;
				break;
			case '/':
				cout<<"El resto de dividir "<<n1<<" entre "<<n2<<" es "<<residuo(n1,n2)<<endl;
				break;
			default:
			cout<<"No es un operador valido  ";
			break;
				
		}
}










