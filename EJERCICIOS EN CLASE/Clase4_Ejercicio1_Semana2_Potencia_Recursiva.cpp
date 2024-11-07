/* Escriba una funci�n recursiva que calcule un n�mero elevado a una 
potencia entera mayor o igual que cero: x^y. 

	potencia(x,y) = x                  , y=1
				    x*potencia(x,y-1)  , y>1
*/

#include<iostream>
#include<conio.h>
using namespace std;

int potencia(int,int);

int main(){
	int base,exponente;
	
	do{
	//Pedimos los datos al usuario

	cout<<"Digite numero base: ";
	cin>>base;
	cout<<"Digite exponente: ";
	cin>>exponente;

	if(base<= 0 || exponente<=0){
			cout<<"Ingrese numeros positivos\n";
		}
		else{
			//Mostramos el resultado
			cout<<"\nResultado: "<<potencia(base,exponente)<<endl;
			break;	
		}
		
		}while(base>=1  || exponente>=1);

		//getch();
		return 0;
	
}

int potencia(int x,int y){			
	int pot;
	if(y==1){//Caso base
		pot = x;
	}
	else{//Caso general
		pot = x*potencia(x,y-1); //SI ingreso de base 3 y exponente 3 lo que hace es poner el 3 de base en pot y el otro 3 en Y y se reduce 
								 // en 1 ya que y no es == 1 y luego y ==2 y luego y==1 cuando se da cuenta que y == 1 pasa al caso base y lo que hace es 
								 // agarrar el 3 de la base y multiplicarlo por 3 por cada comparacion seria en la primera cuando y==3 y en la segunda cuando 
								 // y == 2 pero en la ultima no lo multiplica por que como y == 1 ya paso al caso base y asi funcionaria:
								 // 3 * 3 = 9 (y==3) 
								 // 9 * 3 = 27 (y==2)
								 // resultado 27 
	}
	return pot;
}
