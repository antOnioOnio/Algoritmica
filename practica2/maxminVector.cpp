#include <iostream>
#include <cstdlib>
#include <list>
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

/*void quickSort(int *v, int i, int j){
    if(i< j){
        int p = pivote (v, i, j);
        quickSort(v, i , p-1);
        quickSort(v, p+1, j);
    }
}*/
// pair<int,int> pivote(int *v, int i, int j){
    
//     pair<int,int> pivote_real;
//     int k, l ;
//     int cont_second = 0;
//     k = i;
//     int piv = v[i];
//     l = j+1;
//     int indices_iguales[100];
//     int tam = j ;

//     do {
//         k = k+1;
//         if (v[k] == piv){
//         	indices_iguales[cont_second]=k;
//         	cont_second++;
//         }
//     }while (v[k]<= piv && k<j);

//     do {
//         l = l-1;
//         if (v[l] == piv){
//         	indices_iguales[cont_second] = k;
//         	cont_second++;
//         }
//     }while (v[l]> piv);

//     while ( k<l){
//         swap(v[k], v[l]);

//         do {
//             k = k+1;
//         }while ( v[k] <= piv);
        
//         do {
//             l = l-1;
//         }while ( v[l]>piv);
//     }
//     swap(v[i], v[l]);
//     int metidos_detras = 0;
//     int metidos_adelante = 0;
//     bool existe_derecha = false;

//     while (cont_second != 0){
//     	if (indices_iguales[cont_second] < l){
//     		swap(v[l-1 -metidos_detras], v[cont_second]);
//     		pivote_real.first = l-1-metidos_detras;
//     		metidos_detras++;
//     	}else {
//     		existe_derecha = true;
//     		swap(v[l+1+metidos_adelante], v[cont_second]);
//     		pivote_real.second = l+1+metidos_adelante;
//     		metidos_adelante++;
//     	}
//     	cont_second--;
//     }

//     if (!existe_derecha){
//     	pivote_real.second = l;
//     }
//     cout <<" entro " << endl;
//     for ( int o = 0 ; o< tam ; o++ ){
//     	cout << "vector --> "<< v[o] << endl;
//     }
//     return pivote_real;
// }
pair<int,int> pivote(int* v,int i, int j)
{
    cout << "entro en piviote"<<  endl;
    int piv, k, l;
    k = i;
    piv = v[i];
    l = j + 1;
    list<int> pos;

    do {
        k = k + 1;
        if(v[k]==piv)
            pos.push_back(k);
    } while (v[k] <= piv && k < j);

    do {
        l = l - 1;
        if(v[l] == piv)
            pos.push_back(l);
    } while (v[l] > piv);

    while (k < l) {
        swap(v[k], v[l]);

        do {
            k = k + 1;
        } while (v[k] <= piv);

        do {
            l = l - 1;
        } while (v[l] > piv);
    }

    swap(v[i], v[l]);

    //Sabemos los que son iguales al pivote
    int contador1=0;
    int contador2=0;
    int ultimo;
    pair<int,int> resultado;
    bool hay=false;

    while(!pos.empty()){
        int elemento = pos.back();
        pos.pop_back();
        if(elemento < l){
            swap(v[l-1 - contador1],v[elemento]);
            resultado.first = l-1-contador1;
            contador1++;
        }
        else{
            hay= true;
            swap(v[l+1 + contador2], v[elemento]);
            resultado.second = (l+1+contador2);
            contador2++;
        }
    }
    if(!hay){
        resultado.second = l;
    }
      for ( int o = 0 ; o< j ; o++ ){
    	cout << "vector --> "<< v[o] << endl;
    }
    return resultado;
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

            // int filas = 8;
            // int columnas = 8;
            // pair<int,int>maximosminimos;
            // int **matriz = new int *[filas];

            // for ( int i = 0 ; i< filas ; i++){
            //     matriz[i] = new int [filas];
            // }
            // for (int i = 0; i < filas; i++)
            // {

            //     for (int j = 0; j < columnas; j++)
            //     {
                
            //        matriz[i][j] = rand()%100;
                    
            //     }
            // }

//   for (int i = 0; i < filas; i++)
// {
//     for (int j = 0; j < columnas; j++)
//     {
    
//       cout <<  matriz[i][j] << "\t" ;
        
//     }
//     cout <<endl;
// }

int *vector = new int[10];

vector[0] = 3;
vector[1] = 3;
vector[2] = 3;
vector[3] = 9;
vector[4] = 1;
vector[5] = 8;
vector[6] = 5;
vector[7] = 5;
vector[8] = 6;
vector[9] = 7;


pair <int,int> hola = pivote(vector, 0, 10);


cout << "first: " << hola.first << " second: " << hola.second << endl;			
// maximosminimos = Max_Min(matriz,0,0,filas);

//cout << "maximo " << maximosminimos.first <<endl;
//cout << "minimo " << maximosminimos.second <<endl;

return 0;
}
