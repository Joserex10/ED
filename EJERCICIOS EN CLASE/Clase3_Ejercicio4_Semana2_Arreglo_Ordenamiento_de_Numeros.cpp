#include <cstdlib>
#include <iostream>
using namespace std;

int main()
{
    int tmp,i,j,LI,LS;
    int k =0;
    int n[100];
    
    string verificador;
    
    do{
        cout<<"Ingrese Un numero: "; cin >> n[k];
        k++;
        cout<<"Desea continuar? :";
        cin>>verificador;
   
    }while(verificador != "v");
    
    LI =0;
    LS = k -1;
    for(i =LI; i<=LS-1; i++){
        for(j=LI; j<=LS-1;j++){
            if(n[j]>n[j+1]){
                tmp=n[j];
                n[j]=n[j+1];
                n[j+1] = tmp;
            }
        }
    }
    
    cout<<"Numeros ordenados: ";
    for(int i=0; i<k; i++){
        cout<< n[i] << " ";
    }
    cout<< endl;

    return 0;
}