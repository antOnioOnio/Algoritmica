#include <iostream>
#include <cstdlib>
using namespace std;

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

int main()
{
    srand(time(0));
    // int vector[10];
    // pair<int,int> res;
    // for (int i = 0; i < 10; ++i){
    //     vector[i] = rand()%100;
    //     cout << vector[i] << endl;
    // }

    // res = Maxmin(vector, 10);
    // cout << res.first << " " << res.second<< endl;

    // return 0;

int filas = 8;
int columnas = 8;
pair<int,int>maximosminimos;
int **matriz = new int *[filas];

for ( int i = 0 ; i< filas ; i++){
    matriz[i] = new int [filas];
}
for (int i = 0; i < filas; i++)
{

    for (int j = 0; j < columnas; j++)
    {
    
       matriz[i][j] = rand()%100;
        
    }
}

  for (int i = 0; i < filas; i++)
{
    for (int j = 0; j < columnas; j++)
    {
    
      cout <<  matriz[i][j] << "\t" ;
        
    }
    cout <<endl;
}


maximosminimos = Max_Min(matriz,0,0,filas);

cout << "maximo " << maximosminimos.first <<endl;
cout << "minimo " << maximosminimos.second <<endl;

return 0;
}
