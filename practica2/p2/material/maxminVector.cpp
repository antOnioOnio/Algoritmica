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

void ZapatosPies(int* zapatos, int* pies, int inicio, int n)
    {
        pair<int,int> partidor;

        if (inicio < n) {
            partidor = pivote(pies,zapatos[inicio],inicio,n);
            partidor = pivote(zapatos, pies[partidor.second], inicio,n);

            ZapatosPies(zapatos,pies,inicio,partidor.first-1);
            ZapatosPies(zapatos,pies,partidor.second+1, n);
        }

    }

//===============================================================

void printarr(int a[], int n)
{
    for (int i = 0; i < n; ++i)
       cout << a[i] << "  " ;
    cout << endl;
}

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
// pair<int,int> modaVector(int *v, int inicio, int n){
//     pair<int,int> moda;
//     pair<int,int> pivotes;
//     int *heterogeneo = new int [n];
//     int *homogeneo = new int [n];  

//     int tam_hom = 0;
//     int tam_het = 0; //cont_homo = 0;

//     int pivote_peq= 0;
//     int pivote_gran = 0;

//     moda.first = 0;
//     moda.second = 0;


//     pivotes = pivote(v, v[inicio], inicio, n-1);

//     pivote_peq = pivotes.first;
//     pivote_gran = pivotes.second;


//     for (int i = pivote_peq;i <= pivote_gran; ++i){
//         homogeneo[tam_hom] = v[i];
//         tam_hom++;
//        // cout << homogeneo[i] << " ";
//     }

//     for(int i = 0;i < pivote_peq; ++i){
//         heterogeneo[tam_het] = v[i];
//         tam_het++;
//         //cout << heterogeneo[i] << " ";
//     }
//    // cout <<endl;

//     for (int i = pivote_gran+1;i < n; ++i){
//         heterogeneo[tam_het] = i;
//         tam_het++;
//         //cout << heterogeneo[i] << " ";
//     }//cout <<endl;

//     if (tam_hom <= tam_het){
//         pair<int,int>siguiente = modaVector(heterogeneo, 0, tam_het);
//         if (siguiente.second > moda.second){
//             moda.first = siguiente.first;
//             moda.second = siguiente.second;
//         }
//     }else{
//         moda.first = homogeneo[0];
//         moda.second = tam_hom;
//     }

//     return moda;
// };

int main(int argc, char* argv[])
{


      //  if (argc!=3) // Lectura de parámetros
    //    sintaxis();
//    int tam=atoi(argv[1]); // Tamaño del vector
  //  int vmax=atoi(argv[2]); // Valor máximo

    //if (tam<=0 || vmax<=0)
      //  sintaxis();

    int *vec = new int [8];
    srand(time(0));
    vec[0] = 5;
    vec[1] = 3;
    vec[2] = 2;
    vec[3] = 7;
    vec[4] = 3;
    vec[5] = 4;
    vec[6] = 3;
    vec[7] = 9;

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

    pair<int,int> p = modaVector(vec, 0, 8);
    end = high_resolution_clock::now();
    cout << p.first << " " << p.second << endl;



    tiempo_transcurrido = duration_cast<duration< double> >(end - start);

    //cout << tam << "\t" << tiempo_transcurrido.count() << endl;

    return 0;
}
//     // Lectura de parámetros
//     if (argc != 3)
//         sintaxis();
//     int tam = atoi(argv[1]); // Tamaño del vector
//     int vmax = atoi(argv[2]); // Valor máximo
//     if (tam <= 0 || vmax <= 0)
//         sintaxis();


//     pair<int,int> ab;

//     int *a = new int[tam];
//     int *b = new int[tam];
    

//     int val;

//     srand(time(0));

//     for (int i = 0; i<tam ; i++){
//         val = (rand() % vmax);
//         a[i] = val;
//         b[i] = val;
//     }
//     random_shuffle(&a[0],&a[tam]);
//     random_shuffle(&b[0],&b[tam]);   

//     // printarr(a, tam);
//     // printarr(b, tam);
    
//     high_resolution_clock::time_point start,end;
//     duration<double> tiempo_transcurrido;
    
//     start = high_resolution_clock::now();

//     ZapatosPies(a, b, 0, tam - 1);

//     end = high_resolution_clock::now();

//     tiempo_transcurrido  = duration_cast<duration<double> >(end - start);

//     cout << tam << "\t" <<tiempo_transcurrido.count() << endl;
//     // printarr(a, tam);
//     // printarr(b, tam);

//     return 0;
// }


// /*int main()
// {
//     srand(time(0));
//     // int vector[10];
//     // pair<int,int> res;
//     // for (int i = 0; i < 10; ++i){
//     //     vector[i] = rand()%100;
//     //     cout << vector[i] << endl;
//     // }

//     // res = Maxmin(vector, 10);
//     // cout << res.first << " " << res.second<< endl;

//     // return 0;

// // int filas = 8;
// // int columnas = 8;
// // pair<int,int>maximosminimos;
// // int **matriz = new int *[filas];

// // for ( int i = 0 ; i< filas ; i++){
// //     matriz[i] = new int [filas];
// // }
// // for (int i = 0; i < filas; i++)
// // {

// //     for (int j = 0; j < columnas; j++)
// //     {
    
// //        matriz[i][j] = rand()%100;
        
// //     }
// // }

// //   for (int i = 0; i < filas; i++)
// // {
// //     for (int j = 0; j < columnas; j++)
// //     {
    
// //       cout <<  matriz[i][j] << "\t" ;
        
// //     }
// //     cout <<endl;
// // }

// int *vector = new int[10];

// vector[0] = 3;
// vector[1] = 2;
// vector[2] = 7;
// vector[3] = 9;
// vector[4] = 1;
// vector[5] = 3;
// vector[6] = 5;
// vector[7] = 8;
// vector[8] = 6;
// vector[9] = 3;


// pair <int,int> hola = quicksort(vector, 0, 10);


// cout << "first: " << hola.first << " second: " << hola.second << endl;			
// // maximosminimos = Max_Min(matriz,0,0,filas);

// //cout << "maximo " << maximosminimos.first <<endl;
// //cout << "minimo " << maximosminimos.second <<endl;

// return 0;
// }
// */
