#include <chrono>
#include <cstdlib>
#include <iostream>
#include <utility>
#include <algorithm>

using namespace std;


void intercambiar(int &a, int &b){
    int aux = a;
    a=b;
    b = aux;
}

int pivote(int *v, int i, int j){
    int piv, k, l;
    pair<int,int> pares;
    k =i;
     piv = v[i];
    l = j+1;

    do{
        k = k+1;
    }while (v[k] <= piv && k<j);

    do{
        l = l-1;
    }while(v[l] > piv);

    while (k<l){
        intercambiar(v[k], v[l]);
        //posible posicion para el if y comprobar que son iguales
        do{
            k=k+1;
        }while(v[k] <= piv);

        do{
            l = l-1;
        }while (v[l]>piv);
    }
    intercambiar(v[i], v[l]);

    return l;
}


void zapatero(int *zapatos, int *ninios, int inicio_zapatos, int final_zapatos){
    int pivote_zapatos, pivote_ninios;

    if (inicio_zapatos < final_zapatos){

        pivote_zapatos = pivote(zapatos,inicio_zapatos, final_zapatos);
        pivote_ninios = pivote(ninios, inicio_zapatos, final_zapatos);

        zapatero(zapatos, ninios, inicio_zapatos, pivote_zapatos-1);
        zapatero(zapatos, ninios, inicio_zapatos, pivote_ninios-1);

        zapatero(zapatos, ninios, pivote_zapatos+1, final_zapatos);
        zapatero(zapatos, ninios, pivote_ninios+1, final_zapatos);

    }
}

void sintaxis()
{
    cerr << "Sintaxis:" << endl;
    cerr << "  TAM: Tamaño del vector (>0)" << endl;
    cerr << "  VMAX: Valor máximo (>0)" << endl;
    cerr << "Se genera un vector de tamaño TAM con elementos aleatorios en [0,VMAX[" << endl;
    exit(EXIT_FAILURE);
}

int main(){

    int tamanio = 20;
    int *zapatos = new int[tamanio];
    int *ninios = new int[tamanio];


    //generar el vector aleatorio
    srand(time(0));
    int valor;
    for (int i = 0; i < tamanio; i++){
        valor = (rand() % tamanio);
        zapatos[i] = valor;
        ninios[i] = valor;

    }
    // barajamos los vectores para que se desordenen
    random_shuffle(&zapatos[0], &zapatos[tamanio]);
    random_shuffle(&ninios[0], &ninios[tamanio]);


    cout << "Vectores desordenados: " << endl;
    for(int i = 0; i < tamanio; ++i){
        cout << zapatos[i] << " " << ninios[i] << endl;
    }



    zapatero(zapatos, ninios, 0, tamanio);
    cout << endl << "Vectores ordenados: " << endl;

    for(int i = 0; i < tamanio; ++i){
        cout << zapatos[i] << " " << ninios[i] << endl;
    }

    delete[] zapatos;
    delete[] ninios;
}