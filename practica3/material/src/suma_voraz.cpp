#include <iostream>
#include <cstdlib>  // Para generación de números pseudoaleatorios
#include <vector>
#include <fstream>
#include <algorithm>

using namespace std;


void secuencia(int suma, vector<int> &vec, vector<int> &sec) {
    int sumaActual = 0;
    
    int indiceSec = 0;
    int cont = 0;
    sort(vec.begin(),vec.end());
    int indiceMax = vec.size()-1;

    while ((sumaActual < suma) && indiceMax >-1) {
        if (sumaActual + vec[indiceMax] <= suma) {
            sumaActual += vec[indiceMax];
            sec.push_back(vec[indiceMax]);
            
        } 
        indiceMax--;
    }

}


int main(int argc, char *argv[]) {

    if (argc != 3) {
        cout << "Dime el nombre del fichero con los datos" << endl;
        return 0;
    }
    int suma = atoi(argv[2]);

    ifstream f(argv[1]);
    int numero;
    vector<int> secuen;
    vector<int> vec;

    if (!f) {
        cout << " No puedo abrir el fichero " << argv[1] << endl;
        return 0;
    } else {
        while (!f.eof()) {
            f >> numero;
            vec.push_back(numero);
        }
    }


    secuencia(suma, vec, secuen);
    cout << "{ ";
    for (int i = 0; i < secuen.size(); i++) {
        cout << secuen[i] << " ";
    }
    cout << "}" << endl;

}
