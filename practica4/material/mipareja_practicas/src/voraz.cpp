#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <utility>
#include <chrono>

using namespace std;
using namespace std::chrono;

bool yaEsta(int n, vector<int> &v){

    for ( int i = 0 ; i < v.size() ; i++){
        if ( n == v[i]) return true;
    }

    return false;
}

vector<pair<int, int> > asignaCompaniero(vector<vector<int> > &M, int fila, int columna)
{
    int tope = 999;
    vector<pair<int, int> > companieros;
    pair<int, int >aux;
    vector<int> usados;
    int minimo = 10000;
    bool sta;

    for (int i = 0; i < fila; i++)
    {
        minimo = 1000;
        if ( !yaEsta(i,usados)){

            for ( int j = 0 ; j< columna ; j++)
            {

                if ( !yaEsta(j, usados)){

                    if ( M[i][j]<minimo && M[i][j] != tope){
                        minimo = M[i][j];
                        aux.first = i;
                        aux.second = j;
                    }

                }


            }
            usados.push_back(aux.first);
            usados.push_back(aux.second);
            companieros.push_back(aux);
        }

    }

    return companieros;
}



int calculaDiscrepancia(vector<vector<int> > &M, int n, int m)
{
    int valor=0;

    for (int i = 0; i < M[i].size(); i++)
    {
        valor += abs(M[n][i] - M[m][i]);
    }
    return valor;
}

void rellenaMatrizDiscrepancias(vector<vector<int> > &MatrizPersonas, vector<vector<int> > &MatrizDiscrepancias)
{


    int tope = 999;
    int aux;

    for (int i = 0; i < MatrizPersonas.size(); i++)
    {
        for (int j = 0; j <= i; j++)
        {
            if (i == j)
            {
                MatrizDiscrepancias[i][j]=tope;
                MatrizDiscrepancias[j][i]=tope;
            }
            else
            {
                aux = calculaDiscrepancia(MatrizPersonas, i, j);
                MatrizDiscrepancias[i][j] = aux;
                MatrizDiscrepancias[j][i] = aux;
            }
        }
    }
}


void imprimeMatriz(vector <vector<int> > &M, int fila, int columna)
{
    cout << endl;

    for (int i = 0; i < fila; i++){
        for (int j = 0; j < columna; j++){
            cout << M[i][j] << "\t";
         }
         cout << endl;
    }
    cout<< endl;
}

int main(int argc, char *argv[])
{

    string filename = argv[1];
    string line;
    ifstream f;

    f.open(filename);

    getline(f, line);
    int personas;
    int caracteristicas;

    f >> personas;
    f >> caracteristicas;

    vector<vector<int> > matrizInicial(personas);
    vector<vector<int> > matrizDiscrepancias( personas);
    int numero;

    for (int i = 0; i < matrizInicial.size(); i++)
    {
        matrizInicial[i].resize(caracteristicas);
        matrizDiscrepancias[i].resize(personas);
    }

    for (int i = 0; i < matrizInicial.size(); i++)
    {
        for (int j = 0; j < matrizInicial[j].size(); j++)
        {
            f >> numero;
            matrizInicial[i][j] = numero;
        }
    }
    cout << "Matriz personas "<< endl;
    imprimeMatriz(matrizInicial,personas, caracteristicas);

    // Medimos tiempos 
    high_resolution_clock::time_point start, end;
    duration<double> tiempo_transcurrido;
    start = high_resolution_clock::now();

    rellenaMatrizDiscrepancias(matrizInicial, matrizDiscrepancias);
    cout << "Discrepancias " << endl;
    imprimeMatriz(matrizDiscrepancias,personas, personas);

    vector< pair<int,int > > companieros = asignaCompaniero(matrizDiscrepancias, personas, personas);


    vector<pair <int, int> >::iterator it = companieros.begin();
    int discrepancia =0;
    for ( it; it != companieros.end(); ++it){
        cout <<"Persona " << (*it).first +1 << " asignada con " << (*it).second+1 << endl;
        discrepancia += matrizDiscrepancias[(*it).first][(*it).second];
    }
    
     end = high_resolution_clock::now();

    tiempo_transcurrido = duration_cast<duration< double> >(end - start);
    cout <<  "Tiempo \t" << tiempo_transcurrido.count() << endl;
    cout <<  "Discrepancia con voraces " << discrepancia*2 <<endl;



return 0;

}