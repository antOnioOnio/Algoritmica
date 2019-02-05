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




        if (ri.first < resultado.first)
            resultado.first=ri.first;

        if (ri.second > resultado.second)
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

pair<int,int> partition(int a[], int l, int r, int i, int j){
    i = l-1, j = r;
    int p = l-1, q = r;
    int v = a[r];

    while (true)
    {
        cout << "R: " << r << "L: " << l << endl;
        // From left, find the first element greater than
        // or equal to v. This loop will definitely terminate
        // as v is last element
        while (a[++i] < v);

        // From right, find the first element smaller than or
        // equal to v
        while (v < a[--j])
            if (j == l)
                break;

        // If i and j cross, then we are done
        if (i >= j) break;

        // Swap, so that smaller goes on left greater goes on right
        swap(a[i], a[j]);

        // Move all same left occurrence of pivot to beginning of
        // array and keep count using p
        if (a[i] == v)
        {
            p++;
            swap(a[p], a[i]);
        }

        // Move all same right occurrence of pivot to end of array
        // and keep count using q
        if (a[j] == v)
        {
            q--;
            swap(a[j], a[q]);
        }
    }

    // Move pivot element to its correct index
    swap(a[i], a[r]);

    // Move all left same occurrences from beginning
    // to adjacent to arr[i]
    j = i-1;
    for (int k = l; k < p; k++, j--)
        swap(a[k], a[j]);

    // Move all right same occurrences from end
    // to adjacent to arr[i]
    i = i+1;
    for (int k = r-1; k > q; k--, i++)
        swap(a[i], a[k]);
    pair<int,int> retorno;
    retorno.first = i;
    retorno.second = j;
}

// 3-way partition based quick sort
/*void quicksort(int a[], int l, int r,int &i ,int &j){
    if (r <= l) return;



    // Note that i and j are passed as reference
    partition(a, l, r, i, j);

    // Recur
    quicksort(a, l, j, i, j);
    quicksort(a, i, r, i ,j);
}*/

pair<int,int> modaVector(int *v, int inicio, int final){
    pair<int,int> moda;
    pair<int,int> pivotes;
    moda.first = 0;
    moda.second = 0;
    int *heterogeneo = new int [final];
    int *homogeneo = new int [final];
    int tam_hom = 0, tam_het = 0, cont_homo = 0;

    bool ordenador = false;
    int pivote_peq= 0;
    int pivote_gran = 0;

    pivotes = partition(v, inicio, final, pivote_peq, pivote_gran);
    pivote_peq = pivotes.first;
    pivote_gran = pivotes.second;


    for(int i = 0;i < pivote_peq; ++i){
        heterogeneo[i] = v[i];
        tam_het++;
        //cout << heterogeneo[i] << " ";
    }
   // cout <<endl;
    for (int i = pivote_peq;i < pivote_gran; ++i){
        homogeneo[i] = v[i];
        tam_hom++;
       // cout << homogeneo[i] << " ";
    }//cout <<endl;
    for (int i = pivote_gran+1;i < final; ++i){
        heterogeneo[tam_het] = i;
        tam_het++;
        //cout << heterogeneo[i] << " ";
    }//cout <<endl;

    if (tam_hom <= tam_het){
        pair<int,int>siguiente = modaVector(heterogeneo, tam_hom, tam_het);
        if (siguiente.second > moda.second){
            moda = siguiente;
        }
    }else{
        moda.first = homogeneo[0];
        moda.second = cont_homo;
    }

    return moda;
};



void sintaxis() {
    cerr << "Sintaxis:" << endl;
    cerr << " TAM: Tamaño del vector (>0)" << endl;
    cerr << " VMAX: Valor máximo (>0)" << endl;
    cerr << "Genera un vector de TAM números aleatorios en [0,VMAX[" << endl;
    exit(EXIT_FAILURE);
}



int main(){

  //  if (argc!=3) // Lectura de parámetros
    //    sintaxis();
//    int tam=atoi(argv[1]); // Tamaño del vector
  //  int vmax=atoi(argv[2]); // Valor máximo

    //if (tam<=0 || vmax<=0)
      //  sintaxis();

    int *vec = new int [6];
    srand(time(0));
    vec[0] = 5;
    vec[1] = 3;
    vec[2] = 2;
    vec[3] = 7;
    vec[4] = 2;
    vec[5] = 4;
//    vec[6] = 2;
//    vec[7] = 9;

//    for (int i = 0; i < tam; ++i){
//        vec[i] = rand()%vmax;
//    }
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

    //pair<int,int> final = Maxmin(vec, tam);

    pair<int,int> p = modaVector(vec, 0, 6);
    end = high_resolution_clock::now();
    cout << p.first << " " << p.second << endl;



    tiempo_transcurrido = duration_cast<duration< double>>(end - start);

    //cout << tam << "\t" << tiempo_transcurrido.count() << endl;

    return 0;


}
