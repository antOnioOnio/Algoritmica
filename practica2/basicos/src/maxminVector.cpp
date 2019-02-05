#include <iostream>
#include <chrono>
#include <utility>
#include <cstdlib>
#include <list>
#include <algorithm>
using namespace std;
using namespace std::chrono;


//===============================================================
pair<int, int> Maxmin(int *v, int n)
{

    pair<int, int> resultado;

    if (n == 1)
    {
        resultado.first = v[0];
        resultado.second = v[0];
        return resultado;
    }
    else
    {

        pair<int, int> ri = Maxmin(v, n - n / 2);
        resultado = Maxmin(v + n / 2, n - n / 2);
        if (ri.first < resultado.first)
            resultado.first = ri.first;

        if (ri.second > resultado.second)
            resultado.second = ri.second;

        return resultado;
    }
}

//===============================================================

pair<int, int> Max_Min(int **M, int inicioi, int inicioj, int n)
{

    pair<int, int> resultado;

    if (n == 1)
    {
        resultado.first = M[inicioi][inicioj];
        resultado.second = M[inicioi][inicioj];
        return resultado;
    }
    else
    {
        int mitad = int(n/2);
        pair<int, int> izs = Max_Min(M, inicioi, inicioj, mitad);
        resultado.first = izs.first;
        resultado.second = izs.second;
        pair<int, int> des = Max_Min(M, inicioi, inicioj + mitad , mitad);

        if (des.first < resultado.first)
            resultado.first = des.first;

        if (des.second > resultado.second)
            resultado.second = des.second;

        pair<int, int> izi = Max_Min(M, inicioi + mitad, inicioj, mitad);

        if (izi.first < resultado.first)
            resultado.first = izi.first;

        if (izi.second > resultado.second)
            resultado.second = izi.second;

        pair<int, int> dei = Max_Min(M, inicioi + mitad, inicioj +mitad, mitad);

        if (dei.first < resultado.first)
            resultado.first = dei.first;

        if (dei.second > resultado.second)
            resultado.second = dei.second;
        
        return resultado;
    }
}

//===============================================================

pair<int,int> pivote(int* zapatos, int zapato_pivote, int inicio, int n){
    pair<int,int> partidor;

    int apoyo_1 = inicio;
    int apoyo_2 = n;

    while (inicio <= apoyo_2){
        if (zapatos[inicio] < zapato_pivote){
            swap(zapatos[apoyo_1],zapatos[inicio]);
            apoyo_1++;
            inicio++;
        }else if (zapatos[inicio] > zapato_pivote){
            swap(zapatos[inicio],zapatos[apoyo_2]);
            apoyo_2--;
        }else{
            inicio++;
        }
    }

    partidor.first = apoyo_1;
    partidor.second = apoyo_2;

    return partidor;
}

//===============================================================

void Zapatos(int* zapatos, int* pies, int inicio, int n)
    {
        pair<int,int> partidor;

        if (inicio < n) {
            partidor = pivote(pies,zapatos[inicio],inicio,n);
            partidor = pivote(zapatos, pies[partidor.second], inicio,n);

            Zapatos(zapatos,pies,inicio,partidor.first-1);
            Zapatos(zapatos,pies,partidor.second+1, n);
        }

    }

//===============================================================

void printarr(int a[], int n)
{
    for (int i = 0; i < n; ++i)
       cout << a[i] << "  " ;
    cout << endl;
}

//===============================================================
void sintaxis()
{
    cerr << "Sintaxis:" << endl;
    cerr << "  TAM: Tamaño del vector (>0)" << endl;
    cerr << "  VMAX: Valor máximo (>0)" << endl;
    cerr << "Se genera un vector de tamaño TAM con elementos aleatorios en [0,VMAX[" << endl;
    exit(EXIT_FAILURE);
}

//=================================================================================


pair<int, int> modaVector(int* v, int i, int n)
{
    pair<int, int> moda;
    int* he = new int[n];
    int* ho = new int[n];
    int nho, nhe;
    nho = nhe = 0;
    int pos = 0;

    moda.first = moda.second = 0;

    pair<int, int> pospiv = pivote(v, v[i], i, n - 1);
 
    for (int i = pospiv.first; i <= pospiv.second; ++i) {
        ho[nho] = v[i];
        nho++;
    }

    for (int i = 0; i < pospiv.first; ++i) {
        he[nhe] = v[i];
        nhe++;
    }

    for (int i = pospiv.second + 1; i < n; ++i) {
        he[nhe] = v[i];
        nhe++;
    }

    if (nho > nhe) {
        moda.first = ho[0];
        moda.second = nho;
    } else {
        pair<int, int> modav2 = modaVector(he, 0, nhe);
        if (modav2.second > moda.second) {
            moda.first = modav2.first;
            moda.second = modav2.second;
        }
    }

    return moda;
}

int main(int argc, char* argv[])
{
    // Lectura de parámetros
    if (argc != 3)
        sintaxis();
    int tam = atoi(argv[1]); // Tamaño del vector
    int vmax = atoi(argv[2]); // Valor máximo
    if (tam <= 0 || vmax <= 0)
        sintaxis();
    srand(time(0));

    int **matriz = new int *[tam];
    int *vector = new int[tam];
    int *zapatos = new int[tam];
    int *tamanios = new int [tam];
    int val;
    pair<int, int >resultado;
    // rellenamos vector
    for (int i = 0; i < tam; ++i){
       vector[i] = rand()%vmax;
    }
    // rellenamos matriz
    for ( int i = 0 ; i< tam ; i++){
        matriz[i] = new int [tam];
    }
    for (int i = 0; i < tam; i++)
    {

        for (int j = 0; j < tam; j++)
        {
        
        matriz[i][j] = rand()%vmax;
            
        }
    }
    // rellenamos vectores de zapatos y tamanios 
        for (int i = 0; i<tam ; i++)
        {
         val = (rand() % vmax);
         zapatos[i] = val;
         tamanios[i] = val;
        }
        // mezclamos vectores
    random_shuffle(&zapatos[0],&zapatos[tam]);
    random_shuffle(&tamanios[0],&tamanios[tam]);   


    high_resolution_clock::time_point start, end;

    duration<double> tiempo_transcurrido;
    start = high_resolution_clock::now();




    end = high_resolution_clock::now();
    
    //resultado = Maxmin(vector, tam);        // para medir el primer ejercicio
    //resultado = Max_Min(matriz,0, 0, tam);  // para medir segundo
    Zapatos(zapatos, tamanios, 0, tam-1);     // para medir tercero


    tiempo_transcurrido = duration_cast<duration< double> >(end - start);

    cout << tam << "\t" << tiempo_transcurrido.count() << endl;

    return 0;
}

