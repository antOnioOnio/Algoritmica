#include <iostream>
#include <cstdlib>
#include <chrono>

using namespace std;

pair<int,int> Maxmin(int *v, int n){

    pair<int,int> resultado;


    if (n == 1){
        resultado.first =v[0];
        resultado.second =v[0];


        return resultado;

    }else{

        pair<int,int> ri = Maxmin(v, n-n/2);
        resultado = Maxmin(v+n/2, n-n/2);
        if (ri.first<resultado.first)
            resultado.first=ri.first;

        if (ri.second>resultado.second)
            resultado.second=ri.second;

        return resultado;
    }
}


int main(){

    int vector[10];
    pair<int,int> res;

    for (int i = 0; i < 10; ++i){
        vector[i] = rand()%100;
        cout << vector[i] << endl;
    }

    res = Maxmin(vector, 10);
    cout << res.first << " " << res.second;

    return 0;
}
