#include <iostream>
#include <cstdlib>  // Para generación de números pseudoaleatorios
#include <vector>
#include <fstream>

using namespace std;

// Devolveremos true si hay una subsecuencia de numeros que sume sum

vector<int> SubSum(vector<int> vec,  int sum)
{
    // El valor de matriz[i][j] sera true si hay una subsecuencia
    // del vector que sume i
  
    bool matriz[vec.size()+1][sum+1];
    vector<int>vecDevolver;

    // inicializamos valores
    for (int i = 0; i <= vec.size(); i++)
        matriz[i][0] = true;

    for (int i = 1; i <= sum; i++)
        matriz[0][i] = false;


    // rellenamos matriz con los valores correspondientes
    for (int i = 1; i <= vec.size(); i++)
    {
        for (int j = 1; j <= sum; j++)
        {
            if (j - vec[i-1]>= 0){
                matriz[i][j] = matriz[i - 1][j] || matriz[i - 1][j - vec[i - 1]];
            }else {
                matriz[i][j]=matriz[i-1][j];
            }
        }
    }


    // Imprimimos matriz
    for (int i = 0; i <= vec.size(); i++)
    {
        for (int j = 0; j <= sum; j++)
            cout<<  matriz[i][j] <<" ";
        cout << endl;
    }
  
    int i = vec.size();
    int j = sum;

    while ( !matriz[i][j]){
        j--;

    }
    while (j != 0 ){
        if ( matriz[i][j] && !matriz[i-1][j]){
            vecDevolver.push_back(vec[i-1]);
            i--;
            j = j-vec[i];
        } else {
            i--;
        }

    }

    return vecDevolver;
}

int main(int argc, char *argv[])
{
    if (argc != 3) {
        cout << "Dime el nombre del fichero con los datos" << endl;
        return 0;
    }
    int sum = atoi(argv[2]);

    ifstream f(argv[1]);
    int numero;
    vector<int>vec;
    vector<int> sec ;

    if (!f) {
        cout << " No puedo abrir el fichero " << argv[1] << endl;
        return 0;
    } else {
         f >> numero;

        while (!f.eof()) {
            vec.push_back(numero);
            f >> numero;
        }
    }
    cout << "Disponemos de los numeros { " ;
      for ( int i = 0 ; i < vec.size() ; i++){
        cout << vec[i]<< " " ;
    }
    cout << "} para logar la suma : " << sum<<  endl;

    sec = SubSum(vec, sum);

    cout << "Suma mas aproximada se obtiene con { ";
    for (int i = 0; i < sec.size(); i++) {
        cout << sec[i] << " ";
    }
    cout << "}" << endl;

    return 0;
}