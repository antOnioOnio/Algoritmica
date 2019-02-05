#include <iostream>
#include <cstdlib>
#include <chrono>

using namespace std;
using namespace std::chrono;

pair<int,int> mayorYMenor(pair<int,int> p1, pair<int,int> p2){
    pair<int,int> resultado = p2;

    if (p1.first > resultado.first)
        resultado.first = p1.first;
    if (p1.second < resultado.second)
        resultado.second = p1.second;

    return resultado;
}

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

pair<int,int> maxMinMatriz(int **m, int inicioI, int inicioJ, int n){
    pair<int,int> c1;

    if (n == 1){

        c1.first = m[inicioI][inicioJ];
        c1.second = m[inicioI][inicioJ];

        return c1;
    }else{
        int mitad = n/2;

        c1 = maxMinMatriz(m,inicioI, inicioJ, mitad);
        pair<int,int> c2 = maxMinMatriz(m, inicioI, inicioJ + mitad, mitad);
        pair<int,int> c3 = maxMinMatriz(m, inicioI + mitad, inicioJ, mitad);
        pair<int,int> c4 = maxMinMatriz(m, inicioI + mitad, inicioJ + mitad, mitad);

        pair<int,int> resultado1 = mayorYMenor(c1, c2);
        pair<int,int> resultado2 = mayorYMenor(c3, c4);

        resultado1 = mayorYMenor(resultado1, resultado2);

        return resultado1;

    }


}

void sintaxis() {
    cerr << "Sintaxis:" << endl;
    cerr << " TAM: Tamaño del vector (>0)" << endl;
    cerr << " VMAX: Valor máximo (>0)" << endl;
    cerr << "Genera un vector de TAM números aleatorios en [0,VMAX[" << endl;
    exit(EXIT_FAILURE);
}



int main(int argc, char *argv[]){

    if (argc!=3) // Lectura de parámetros
        sintaxis();
    int tam=atoi(argv[1]); // Tamaño del vector
    int vmax=atoi(argv[2]); // Valor máximo

    if (tam<=0 || vmax<=0)
        sintaxis();

    int *vec = new int [tam];
    srand(time(0));

    for (int i = 0; i < tam; ++i){
        vec[i] = rand()%vmax;
    }
 /*   
    for (int i = 0; i < tam; ++i){
            matriz[i] = new int[tam];
    }

    for (int i = 0; i < tam; ++i){
        for (int j  = 0; j < tam; ++j){
            matriz[i][j] = rand()%vmax;
            //cout << matriz[i][j] << endl;
        }
    }
*/
    high_resolution_clock::time_point start, end;
    duration<double> tiempo_transcurrido;
    start = high_resolution_clock::now();

    pair<int,int> final = Maxmin(vec, tam);

    end = high_resolution_clock::now();
    //cout << final.first << " " << final.second << endl;

    tiempo_transcurrido = duration_cast<duration< double> >(end - start);

    cout << tam << "\t" << tiempo_transcurrido.count() << endl;

    return 0;


}
