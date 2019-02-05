#include <chrono> // Recursos para medir tiempos
#include <cstdlib> // Para generación de números pseudoaleatorios
#include <iostream>
#include <utility>
#include <algorithm>
#include <list>

using namespace std;
//using namespace std::chrono;



void sintaxis()
{
    cerr << "Sintaxis:" << endl;
    cerr << "  TAM: Tamaño del vector (>0)" << endl;
    cerr << "  VMAX: Valor máximo (>0)" << endl;
    cerr << "Se genera un vector de tamaño TAM con elementos aleatorios en [0,VMAX[" << endl;
    exit(EXIT_FAILURE);
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

    // Generación del vector aleatorio
    int *Z = new int[tam]; // Reserva de memoria
    int *P = new int[tam]; // Reserva de memoria

    int val;
    int val2;

    srand(time(0)); // Inicialización del generador de números pseudoaleatorios
    for (int i = 0; i < tam; i++){ // Recorrer vector
        val = (rand() % vmax) + 10 ; // Generar aleatorio [0,vmax[
        val2 = (rand() + 50) % vmax;
        Z[i] = val; 
        P[i] = val;
        cout << Z[i] << " " << P[i] << endl;
    }
    cout << endl;
    val = Z[rand() % tam];

    //random_shuffle(&Z[0],&Z[tam]);
    //random_shuffle(&P[0],&P[tam]);

    //int piv = Pivote(Z, 0, tam);
    for(int i = 0; i < tam; ++i){
        cout << Z[i]<< " " << P[i] << endl;;
    }
    cout << endl << endl;

   // ZapatosPies(Z, P, 0, tam);

   pair<int,int> re = pivote(Z,3,0,tam);

        
    /*for(int i = 0; i < tam; ++i){
        cout << Z[i] << " " << P[i] << endl;
    }*/

    cout << re.first << " " << re.second << endl;
    
    delete[] Z; // Liberamos memoria dinámica
    delete[] P; // Liberamos memoria dinámica
}
