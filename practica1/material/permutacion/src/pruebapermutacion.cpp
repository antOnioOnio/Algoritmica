#include <iostream>
#include "permutacion.h"
#include <string> 

#include <cstdlib>  // Para generación de números pseudoaleatorios
#include <chrono>// Recursos para medir tiempos
using namespace std;
using namespace std::chrono;

template <class T>
ostream & operator<<(ostream &os, const vector<T> & d){
   for (int i=0;i<d.size();i++)
      os<<d[i]<<" ";
   os<<endl;
   return os;
}

void MuestraPermutaciones(const Permutacion & P){
  Permutacion::const_iterator it;
  int cnt=1;
  for (it=P.begin();it!=P.end();++it,++cnt)
      cout<<cnt<<"->"<<*it<<endl;
      
}

bool EsOrdenado(const int *v, const int n){
  bool es = true;
  for (int i =0;i<n-1;i++){
    if(v[i]>v[i+1]){
      es = false;
      break;
    }
  }
  return es;
}

void ModificaVector(int *v, int *v_final, const int *v_base, const Permutacion &P){
  const vector<unsigned int> s= (*(P.begin()));
  
  //for(unsigned int i=0; i<s.size(); i++)
   // cout<<v[s[i]-1];

  // cout<< "-";
  
  for(unsigned int i=0; i<s.size(); i++){
    v_final[i] = v_base[v[s[i]-1]];
   // cout << v_final[i];
  }
 // cout << endl;
}


void ImprimeCadena(const string &c,const Permutacion &P){
  const vector<unsigned int> s= (*(P.begin()));
  
  for (unsigned int i=0;i<s.size();i++)
     cout<<c[s[i]-1];
  cout<<endl;
}

void sintaxis()
{
  cerr << "Sintaxis:" << endl;
  cerr << "  TAM: Tamaño del vector (>0)" << endl;
  cerr << "  VMAX: Valor máximo (>0)" << endl;
  cerr << "Se genera un vector de tamaño TAM con elementos aleatorios en [0,VMAX[" << endl;
  exit(EXIT_FAILURE);
}

int main(int argc, char * argv[]){
  if ( argc != 2)
  sintaxis();  

  int tam=atoi(argv[1]);
  int vmax=10;

	high_resolution_clock::time_point start,//punto de inicio
                                  end; //punto de fin
 	duration<double> tiempo_transcurrido;  //objeto para medir la duracion de end 						   // y start
  
	start = high_resolution_clock::now(); //iniciamos el punto de inicio

  if ( tam<=0){
    sintaxis();
  }
  int *v= new int[tam];
  int *v_base = new int[tam];
  int *v_final = new int[tam];

  //cout << " Vector permutaciones: " ;
  for ( int i = 0 ; i<tam ; i++){
    v[i]=i;
  //    cout << v[i];
  }
  srand(time(0));

 // cout << endl << " Vector valores: ";
 // int con = tam;
    for ( int i = 0 ; i<tam ; i++){
      v_base[i] = rand()%vmax;    // para aleatorio
    //  v_base[i] = i;            // para ordenado
    //  v_base[i] = con;          // para el peor
    //  con--;

  //    cout << v_base[i];
    }
//  cout << endl;

  Permutacion permu(tam, -1);
  do{
    ModificaVector(v, v_final, v_base, Otra);
  //  cout << endl;
  }while(!EsOrdenado(v_final,tam) && permu.GeneraSiguiente()  );
  


    delete[] v;
    delete[] v_base;
    delete[] v_final;



  end = high_resolution_clock::now(); //anotamos el punto de de fin 
 	//el tiempo transcurrido es
 	tiempo_transcurrido  = duration_cast<duration<double> >(end - start);

  	// Mostramos resultados
  cout << tam << "\t" <<tiempo_transcurrido.count() << endl;





  // cout<<"Dime el tamaño de las permutaciones:";
  // cin>>n;
  
  // Permutacion P(n);
  // cout<<"El numero total de permutaciones: "<<P.NumeroPermutacionesPosibles()<<endl;
  // MuestraPermutaciones(P);
   
  //Para no tener almacenadas todas las permutaciones solo la acutal
  
  
  //Leemos una cadena y generamos todas sus permutaciones
//   string cad;
//   cout<<"Dime una palabra:";
//   cin>>cad;
//   Permutacion Otra(cad.size(),1);
//   int cnt=1;
//   do{
//     cout<<cnt<<"-->";
//     ImprimeCadena(cad,Otra);
//     cnt++;
//   }while(Otra.GeneraSiguiente());
// 
}  
  
  
   
  
