//programa recursivo
//que permita llenar una matriz 10x10 con números enteros aleatorios

#include<iostream>
#include<cstdlib> //Para rand() y srand()
#include<ctime> //Para time() que inicializa la semilla

using namespace std;
const int filas = 10;
const int columnas = 10;
int matriz[filas][columnas];

void llenarMatriz(int i, int j);
void imprimirMatriz(int i, int j);

int main(){
	srand(time(NULL)); //Inicializamos la semilla
	
	llenarMatriz(filas-1,columnas-1);//Llenamos la matriz desde la última fila y columna
	imprimirMatriz(filas-1,columnas-1);//imprimimos la matriz desde la última fila y columna
}

void llenarMatriz(int i, int j){
	if(i<0) return; //Caso base: todas las filas han sido procesadas (llenadas)
	if(j<0){
		//si se completaron todas las columnas de la fila actual i, se pasa
		//a la fila anterior y se retorna a la última columna
		llenarMatriz(i-1,columnas-1);
	}else{ //si no se han completado las columnas, se coloca el valor
		matriz[i][j] = rand()%100 + 1;
		llenarMatriz(i,j-1);
	}
}

void imprimirMatriz(int i,int j){ //i,j inician en 3,3
	if(i<0) return;
	if(j<0){
		cout<<endl; //cambio de línea por el cambio de fila
		imprimirMatriz(i-1,columnas-1);
	}else{
		cout<<matriz[i][j]<<"\t";
		imprimirMatriz(i,j-1);
	}	
}







