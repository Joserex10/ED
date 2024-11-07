#include<iostream>
#include<vector>

using namespace std;

void revertirVector(vector<int>& listaNumeros,int inicio,int final);

int main(){
	vector<int> listaNumeros = {1,2,3,4,5};
	//vector<tipoDato> nombreVector = {valores de inicialización};
	revertirVector(listaNumeros,0,listaNumeros.size()-1);
	
	cout<<"Lista invertida: "<<endl;
	for(int numero:listaNumeros){
		cout<<numero<<" ";
	}
}

void revertirVector(vector<int>& listaNumeros,int inicio,int final){
	if(inicio>=final){
		return;
	}	
	swap(listaNumeros[inicio],listaNumeros[final]);
	revertirVector(listaNumeros,inicio+1,final-1);	
}








