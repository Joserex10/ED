#include <iostream>

using namespace std;

void sort(int array[], int size);                           // 1 + log n
int main(){

    int array[] = {10,8,3,4,5,2,7,1,6,9,};                  //1
    int size = sizeof(array)/sizeof(array[0]);              //3

    sort(array,size);                                       //1 + log n

    for(int element : array){                               // 1 +(1+ (2)+2)
        cout << element << " ";                             //2
    }
    return 0;
}

void sort(int array[], int size){                           //1 + log n      
    int temp;                                               //1
    for(int i = 0; i< size -1; i++){                        //1 + n(1+n(1+(3+3)+2)+2)
        for(int j = 0; j < size-i; j++){                    //1 + n(1 +(3+3)+2)
            if(array[j] > array[j + 1]){                    //3+(3)
                temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}