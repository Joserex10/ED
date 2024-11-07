

for(int i = 0; i < n - 1; i++){     // 1 + n(1 + (1 + 3) + 2) + 2)
    for(int k = i; k < n; k++){     // 1 + (1 + (1 + 3) + 2)
        if(vec[i] > vec[k]){        //1 + (3)
            int aux = vec[i];       //2
            vec[i] = vec[j];        //3
            vec[k] = aux;           //2
        }
    }
}
                                    // 1 + n(1 +(1 +3)+ 2) + 2)
                                    //1 + n(10)