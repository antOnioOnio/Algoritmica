#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
using namespace std;

vector<pair<char, int>> Operaciones(vector<int> vec, int objetivo)
{

    int tope = 99999999;
    int maximo = *max_element(vec.begin(), vec.end());
    pair<char, int> mismo, sumar, restar, multiplicar, dividir, minimo;
    vector<vector<pair<char, int>>> matriz(vec.size() + 1);
    vector<pair<char, int>> sol;

    mismo.first = '.';
    sumar.first = '+';
    restar.first = '-';
    multiplicar.first = '*';
    dividir.first = '/';

    for (int i = 0; i < matriz.size(); i++)
    {
        matriz[i].resize(maximo * objetivo + 1); // tamaño maximo sera el mayor elemento de los candidatos * nuestro objetivo
    }

    // inicializamos valores
    for (int i = 0; i < matriz[0].size(); i++)
    {
        matriz[0][i].second = i;
        matriz[0][i].first = ' ';
    }

    for (int i = 0; i < matriz.size(); i++)
    {
        matriz[i][0].first = ' ';
        matriz[i][0].second = 0;
    }

    for (int i = 1; i < matriz.size(); i++)
    {
        for (int j = 1; j < matriz[i].size(); j++)
        {
            // actualizmos minimo
            minimo.second = tope;

            // calculamos division
            if (j * vec[i - 1] >= matriz[0].size() - 1)
            {
                dividir.second = tope;
               
            }
            else
            {
                dividir.second = matriz[i - 1][j * vec[i - 1]].second;
            
            }
            if (minimo.second >= dividir.second)
            {
                minimo = dividir;
            }

            // calculamos multiplicacion
            if (j % vec[i - 1] != 0)
            {
                multiplicar.second = tope;
               
            }
            else
            {
                multiplicar.second = matriz[i - 1][j / vec[i - 1]].second;
             
            }
            if (minimo.second >= multiplicar.second)
            {
                minimo = multiplicar;
            }

            // calculamos resta

            if (j + vec[i - 1] > matriz[0].size())
            {
                restar.second = tope;
                
            }
            else
            {
                restar.second = matriz[i - 1][j + vec[i - 1]].second;
              
            }
            if (minimo.second >= restar.second)
            {
                minimo = restar;
            }

            // calculamos suma
            if (j - vec[i - 1] < 0)
            {
                sumar.second = tope;
              
            }
            else
            {
                sumar.second = matriz[i - 1][j - vec[i - 1]].second;
               
            }
            if (minimo.second >= sumar.second)
            {
                minimo = sumar;
            }

            // calculamos mismo
            mismo.second = matriz[i - 1][j].second;
           
            if (minimo.second >= mismo.second)
            {
                minimo = mismo;
            }

            matriz[i][j] = minimo;
        }
    }


        // IMPRIMIR MATRIZ
        for ( int i = 0 ; i < matriz.size() ; i++){
   
            for ( int j = 0 ; j < matriz[i].size(); j++) {

                cout << matriz[i][j].first << matriz[i][j].second << '\t';
            }
            cout << endl;
        }

    int fila = matriz.size() - 1;
    pair<char, int> aux;

    // RECONSTRUCCION DE LA SOLUCION 
    while (fila > 0)
    {
        if (matriz[fila][objetivo].second != matriz[fila - 1][objetivo].second)
        {
            aux.first = matriz[fila][objetivo].first;
            aux.second = vec[fila - 1];
            sol.push_back(aux);
            switch (matriz[fila][objetivo].first)
            {
            case '+':
                objetivo = objetivo - aux.second;
                break;
            case '-':
                objetivo = objetivo + aux.second;
                break;
            case '*':
                objetivo = objetivo / aux.second;
                break;
            case '/':
                objetivo = objetivo * aux.second;
                break;
            }
            fila--;
        }
        else
        {
            fila--;
        }
    }
    return sol;
}
int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        cout << "Dime el nombre del fichero con los datos" << endl;
        return 0;
    }
    int objteivo = atoi(argv[2]);

    ifstream f(argv[1]);
    int numero;
    vector<int> vec;
    vector<pair<char, int>> sec;

    if (!f)
    {
        cout << " No puedo abrir el fichero " << argv[1] << endl;
        return 0;
    }
    else
    {
        f >> numero;

        while (!f.eof())
        {
            vec.push_back(numero);
            f >> numero;
        }
    }
    cout << "Disponemos de los numeros { ";
    for (int i = 0; i < vec.size(); i++)
    {
        cout << vec[i] << " ";
    }
    cout << "} para logar el objetivo : " << objteivo << endl;

    sec = Operaciones(vec, objteivo);

    cout << "La solucion mas aproximada se obtiene con { ";
    for (int i = 0; i < sec.size(); i++)
    {
        cout << sec[i].second << sec[i].first << " ";
    }
    cout << "}" << endl;

    return 0;
}