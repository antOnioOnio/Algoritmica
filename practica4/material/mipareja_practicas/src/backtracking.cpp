#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <utility>
#include <chrono>
#include "Apermutacion.h"
#include <queue>
using namespace std;
using namespace std::chrono;

struct Nodo{
    int dactual;
    int ci;
    int de;
    int cs;
    Apermutacion per;

    Nodo(int dactual1, int CI1, int DE1, int CS1, const Apermutacion p1){
        dactual = dactual1;
        ci = CI1;
        de = DE1;
        cs = CS1;
        per = p1;
    }

    
};

   bool operator<(const Nodo& c,const Nodo& c2){
        return c.de < c2.de;
    }

vector<int> ObtenerAsignaciones(const Apermutacion &p,int n){
    vector<int> resultado(n,-1);
    Apermutacion::const_iterator it;
    int i = 0;
    for (it=p.begin();it!=p.end();++it,++i){
        int col=*it;
        col--;
        resultado[i]=col;
    }
    return resultado;
}

bool yaEsta(int n, vector<int> &v){

    for ( int i = 0 ; i < v.size() ; i++){
        if (n == v[i]) return true;
    }

    return false;
}

int CotaSuperior(vector<vector<int> > &M, int fila, vector<int> asig)
{
    vector<pair<int, int> > companieros;
    pair<int,int> aux,aux2;
    int sig, sig_col;
    vector<int> usados;
    for (int i = 0; i < fila; ++i){
        if (asig[i]!=-1){
            aux.first = i;
            aux.second = asig[i];
            companieros.push_back(aux);
            usados.push_back(i);
            usados.push_back(asig[i]);
        }
    }
    for (int i = 0; i < fila; i++)
    {
        int minimo = 10000;
  
         if (!yaEsta(i,usados)){
            for(int j = 0; j< fila; ++j){

                if (!yaEsta(j,usados)){
                 
                    if (M[i][j] < minimo && M[i][j] != 999){                     
                        minimo = M[i][j];
                        aux2.first = i;
                        aux2.second = j;
                        
                    }
                }
           }
           companieros.push_back(aux2);
           usados.push_back(aux2.first);
           usados.push_back(aux2.second);
           
        }  
         
    }

    vector<pair <int, int> >::iterator it = companieros.begin();
    int menor_discrepancia = 0;
    for ( it; it != companieros.end(); ++it){
        //cout << "interior iterador " << (*it).first<< " " << (*it).second <<  endl;
        menor_discrepancia += M[(*it).first][(*it).second];
        //cout << "discrepancias " << menor_discrepancia << endl;
    }

   //cout << "discrepancias " << menor_discrepancia << endl;
    return menor_discrepancia*2; //Esto es el doble de la cota superior para asi contemplar 1-5 y 5-1
}

int CotaInferior(vector<vector<int> > &M, int fila, vector<int> asig){
    vector<pair<int, int> > companieros;
    pair<int,int> aux;

    for (int i = 0; i < fila; i++)
    {   
            aux.first = i;
            aux.second = asig[i];
            companieros.push_back(aux);   
    }
    vector<pair <int, int> >::iterator it = companieros.begin();
    int menor_discrepancia = 0;
    for ( it; it != companieros.end(); ++it){
        menor_discrepancia += M[(*it).first][(*it).second];
    }

    return menor_discrepancia;
}
//Como tenemos un arbol k-nario entonces iniciamos el vector de datos a 0 y el lvl a 0 tambien
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

int sumaDiscrepancia(Apermutacion &p, vector<vector<int> > m){
    Apermutacion::iterator it;
    int suma = 0;
    it = p.begin();
    for (int i = 0; it!=p.end();++it,++i){
        int col = *it;
        col--;
        suma += m[i][col];
    }
    return suma;
}

void MuestraAsignacion(const Apermutacion & P){
  Apermutacion::const_iterator it;
  int i=0;
  for (it=P.begin();it!=P.end();++it,++i)
      cout<<"Trabajador "<<i +1<<" le asigna el trabajo "<<*it<<endl;
  cout<<endl; 
}

int backtracking (vector<pair<int,int> > &res, int &menor_discrepancia, int n, Apermutacion &ab,vector<vector<int> > &matrizDiscrepancias){
    Apermutacion p(n);
    bool seguir = true;
    int v = 0;
    Apermutacion::iterator it;
    
    int nodos_recorridos = 0;

    while (seguir){
        nodos_recorridos++;
        v = sumaDiscrepancia(p,matrizDiscrepancias);
        //cout << v << endl;
        if (p.GetLevel() == n-1){
            if (v < menor_discrepancia){
      //          cout<<"Actualizando solucion : "<<v<<endl;
	    //  MuestraAsignacion(p);
                menor_discrepancia = v;
                ab = p;
                seguir = p.Backtracking();
            }else{
                seguir = p.GeneraSiguienteProfundidad();
            }
        }else{
            seguir = p.GeneraSiguienteProfundidad();
        }
    }

    it = ab.begin();

    for (int i = 0; it!=ab.end();++it, ++i){
        pair<int,int> pa;
        pa.first = i;
        pa.second = *it-1;
        res.push_back(pa);
    }
    return nodos_recorridos;
}

int backtrackingPoda (vector<pair<int,int> > &res, int &menor_discrepancia, int n, Apermutacion &ab,vector<vector<int> > &matrizDiscrepancias){
    Apermutacion p(n);
    bool seguir = true;
    int v = 0;
    Apermutacion::iterator it;
    
    int nodos_recorridos = 0;

    while (seguir){
        nodos_recorridos++;
        v = sumaDiscrepancia(p,matrizDiscrepancias);
 
        //cout << v << endl;
        if (p.GetLevel() == n-1){
            if (v < menor_discrepancia){
                menor_discrepancia = v;
                ab = p;
                  vector<int> ss = p.GetSecuencia();
             /* for (int i = 0; i<ss.size();++i){
                cout << "Asignaciones " << ss[i] << " con " << i<<  endl;
            }*/
                seguir = p.Backtracking();
             
                
            }else{
                seguir = p.GeneraSiguienteProfundidad();
            }
        }else{
            vector<int> asig = ObtenerAsignaciones(p,n);
           /* for (int i = 0; i<asig.size();++i){
                cout << "Asignaciones " << asig[i] << " con " << i<<  endl;
            }*/
            int mejor = CotaSuperior(matrizDiscrepancias,n,asig)-v;
            if (mejor < menor_discrepancia)
                seguir = p.GeneraSiguienteProfundidad();
            else
                seguir = p.Backtracking();
        }
    }

    it = ab.begin();

    for (int i = 0; it!=ab.end();++it, ++i){
        
        pair<int,int> pa;
        pa.first = i;
        pa.second = *it-1;
        res.push_back(pa);
    }
    return nodos_recorridos;
}

int branchAndBound (vector<pair<int,int> > &res, int &menor_discrepancia, int n, Apermutacion &ab,vector<vector<int> > &matrizDiscrepancias){
    Apermutacion p(n);
    vector<int> asig = ObtenerAsignaciones(p,n);
    int cs = CotaSuperior(matrizDiscrepancias,n,asig);
    cout << "Cota superior inicial " << cs << endl;
    int ci = CotaInferior(matrizDiscrepancias,n,asig);
    cout << "Cota inferior inicial " << ci << endl;
    int de = (ci+cs)/2;
    int C = cs;
    int dActual = 0;
    Apermutacion mejorP(n);
    int n_nodos = 0;
    Nodo node(dActual, ci, de, cs, p);
    priority_queue <Nodo> cola;
    cola.push(node);
    while (!cola.empty()){
        n_nodos++;
        Nodo nodito = cola.top();
        if (nodito.ci < C){
            vector<vector<int> > hijos = nodito.per.GeneraHijos();
                for (int i = 0; i < hijos.size(); ++i){
                    Apermutacion hijo(hijos[i], hijos[i].size());
                    vector<int> asig = ObtenerAsignaciones(hijo,n);
                    dActual = sumaDiscrepancia(hijo,matrizDiscrepancias);
                    cs = CotaSuperior(matrizDiscrepancias, hijos.size(), asig);
                    ci = CotaInferior(matrizDiscrepancias, hijos.size(), asig);
                    de = (cs+ci)/2;
                    if (hijo.GetLevel() == n-1 && dActual<menor_discrepancia){
                        menor_discrepancia = dActual;
                        if (C>dActual){
                            C=dActual;
                            mejorP = hijo;
                        }
                    }else if(ci<=C){
                        Nodo nuevo(dActual,ci,de,cs,hijo);
                        cola.push(nuevo);
                       // ordenarCola(cola);
                        if (C>cs)
                            C=cs;
                    }
                }
            }
            
        }
    return n_nodos;
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
        for (int j = 0; j < matrizInicial[i].size(); j++)
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

    vector< pair<int,int > > companieros;
    int menor_discrepancia = 10000;
    Apermutacion ab(personas);

    

    int t_nodos = backtracking(companieros, menor_discrepancia,personas, ab, matrizDiscrepancias);
    vector<pair <int, int> >::iterator it = companieros.begin();
    for ( it; it != companieros.end(); ++it){
        cout <<"Persona " << (*it).first +1 << " asignada con " << (*it).second+1 << endl;
        //discrepancia += matrizDiscrepancias[(*it).first][(*it).second];
    }
    cout <<  "Discrepancia backtracking " << menor_discrepancia <<endl;
    cout << "Nodos recorridos " << t_nodos << endl;

    Apermutacion ab_poda(personas);
    vector< pair<int,int > > companieros_poda;
    int menor_discrepancia_poda = 10000;
    int t_nodo_poda = backtrackingPoda(companieros_poda, menor_discrepancia_poda, personas, ab_poda, matrizDiscrepancias);

    vector<pair <int, int> >::iterator it_poda;
  
    /*
            HASTA AQUI BACKTRACKING FUNCIONANDO BIEN,    
            
            
            
            
            BRANCH AND BOUND NO HEMOS PODIDO TERMINARLO POR FALTA DE TIEMPO



     */
  //   return 0;
    for ( it_poda = companieros_poda.begin(); it_poda != companieros_poda.end(); ++it_poda){
        cout <<"Persona " << (*it_poda).first +1 << " asignada con " << (*it_poda).second+1 << endl;
        //discrepancia += matrizDiscrepancias[(*it).first][(*it).second];
    }
    tiempo_transcurrido = duration_cast<duration< double> >(end - start);
    cout <<  "Tiempo \t" << tiempo_transcurrido.count() << endl;
    
    cout <<  "Discrepancia backtracking con poda" << menor_discrepancia_poda <<endl;
    cout << "Nodos recorridos con poda" << t_nodo_poda << endl;

    Apermutacion ab_ByB(personas);
    vector< pair<int,int > > companieros_ByB;
    int menor_discrepancia_byb = 10000;
    int t_nodo_byb = branchAndBound(companieros_ByB, menor_discrepancia_poda, personas, ab_ByB, matrizDiscrepancias);

    vector<pair <int, int> >::iterator it_ByB;
  

    
    int discrepancia = 0;
    
    for ( it_ByB = companieros_ByB.begin(); it_ByB != companieros_ByB.end(); ++it_ByB){
        cout <<"Persona " << (*it_ByB).first +1 << " asignada con " << (*it_ByB).second+1 << endl;
        discrepancia += matrizDiscrepancias[(*it).first][(*it).second];
    }
     end = high_resolution_clock::now();
    tiempo_transcurrido = duration_cast<duration< double> >(end - start);
    cout <<  "Tiempo \t" << tiempo_transcurrido.count() << endl;
    cout <<  "Discrepancia byb" << menor_discrepancia_byb <<endl;
    cout << "Nodos recorridos con poda" << t_nodo_byb << endl;



return 0;
} 
