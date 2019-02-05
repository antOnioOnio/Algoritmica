#include "Apermutacion.h"
#include "matriz_vector.h"
#include <fstream>
#include <iostream>
#include <ctime>
/**
 * @brief Obtiene el mejor beneficio de asignar a n trabajadores n trabajos usando voraces
 * @param n: el numero de trabajos o trabajadores
 * @param B: matriz de beneficios 
 * @return el mejor beneficio total
 * */
int Asi_Trabajadores_Voraz(int n,const Matriz<unsigned int> &B){
   
  Matriz<bool>usados(n,n,false);
   
   vector<bool>candidatos(n,true);
   
   unsigned int best_bene=0;
   for (int i=0;i<n;i++){
      if (candidatos[i]){ // es un candidatos
	//buscamos entre os trabajos que quedan libres el mas beneficioso
	int mejor=0; int work=0;
	for (int j=0;j<n;j++){
	    if (usados[i][j]==false)
	      if ((int)B.get(i,j)>mejor){
		 work=j; mejor = B.get(i,j);
	      }
	
	}
	cout<<"Trabajador "<<i+1<< " asignamos el trabajo  "<<work+1<<endl;
	best_bene +=mejor;
	for (int t=0;t<n;t++){
	  usados.set(t,work,true);
	  usados.set(i,t,true);
	}
	candidatos[i]=false;
      }
   }
   return best_bene;

}   
/**
 * @brief Establece una cota superior del beneficio para los trabajadores aun no asignados a ningun trabajo.
 * @param asignados: vector con los trabajadores asignados ya a trabajos
 * @param B: matriz de beneficios 
 * @return el beneficio estimado de asignar a los trabajadores aun no asignados trabajos aun libres.Puede que se  repita dicha asignacion
 * */  
int CotaSuperior(vector<int>asignados,const Matriz<unsigned int> &B){
   Matriz<bool>usados(asignados.size(),asignados.size(),false);
   int n=asignados.size();
   vector<bool>candidatos(n,true);
   
   for (unsigned  int i=0;i<asignados.size();i++){
      if(asignados[i]>=0){
       candidatos[i]=false;
       for ( int j=0;j<n;j++)
         usados[j][asignados[i]]=true;
      } 
   }
   unsigned int best_bene=0;
   for (int i=0;i<n;i++){
      if (candidatos[i]){ // es un candidatos
	//buscamos entre os trabajos que quedan libres el mas beneficioso
	int mejor=0;
	//int work=0;
	for (int j=0;j<n;j++){
	    if (usados[i][j]==false)
	      if ((int)B.get(i,j)>mejor){
		 //work=j; 
		 mejor = B.get(i,j);
	      }
	
	}
	//cout<<"Trabajador "<<i+1<< "asignamos "<<work+1<<endl;
	best_bene +=mejor;
	
	
      }
   }
   return best_bene;
}     
  
/**
 * @brief Obtiene un vector de dimension n asociada a la Permutacion
 * @param P: un objeto de tipo arbol de soluciones basados en permutaciones
 * @param n: el numero de trabajos o trabajadores
 * @return el vector asociado a la permutacion
 * */  
vector<int> ObtainAsignaciones(const Apermutacion &P,int n){
    vector<int> out(n,-1);
    Apermutacion::const_iterator it;
    int i=0;
    for (it=P.begin();it!=P.end();++it,++i){
        int c=*it;
        c--;
        out[i]=c;
    }
    return out;
}    
/**
 * @brief Obtiene la suma del beneficio acumulado de las asignaciones realizadas
 * @param P: un objeto de tipo arbol de soluciones basados en permutaciones
 * @param B: matriz de beneficios 
 * @return el beneficio acumulado
 * */  

unsigned int Suma_Beneficio(Apermutacion &P, const Matriz<unsigned int> &B){
  Apermutacion:: iterator it;
  unsigned int s=0;
  int i;
  for (i=0, it=P.begin();it!=P.end();++it,++i){
     int col =*it; col--;
     s+=B.get(i,col);
  }   
  return s;
  
}

/**
 * @brief Muestra en la salida estandar la asignacion realizada.
 * @param P: un objeto de tipo arbol de soluciones basados en permutaciones
 * */  
void MuestraAsignacion(const Apermutacion & P){
  Apermutacion::const_iterator it;
  int i=0;
  for (it=P.begin();it!=P.end();++it,++i)
      cout<<"Trabajador "<<i +1<<" le asigna el trabajo "<<*it<<endl;
  cout<<endl;    
} 

/**
 * @brief Obtiene el mejor beneficio de asignar a n trabajadores n trabajos usando backtracking
 * @param n: el numero de trabajos o trabajadores
 * @param ab: Arbol de permutaciones para obtener la mejor solucion
 * @param B: matriz de beneficios 
 * @return el mejor beneficio total
 * */

int Asig_Trabajadores(int n, Apermutacion &ab,const Matriz<unsigned int> &B){
    Apermutacion P(n); 
    bool seguir =true;
    int bact=0; int best_beneficio=0;
    unsigned int nodos_recorridos =0;
    while (seguir){
        nodos_recorridos++;
        bact=Suma_Beneficio(P,B);
	if (P.GetLevel()==n-1){
	  if (bact>best_beneficio){
	      /*cout<<"Actualizando solucion : "<<bact<<endl;
	      MuestraAsignacion(P);*/
	      best_beneficio=bact;
	      ab=P;
	      seguir =P.Backtracking(); //da igual hacer P.GeneraSiguiente() ya que estamos en una hoja
	  }
	  else seguir=P.GeneraSiguiente();
	}
	else seguir=P.GeneraSiguiente();
	
    }
    int total=P.NumeroSecuenciasPosibles();
    cout<<"Numero de nodos recorridos "<<nodos_recorridos<< " total nodos "<<total<<" Porcentaje "<<(nodos_recorridos/(double)total)*100.0<<endl;
    return best_beneficio;
}    
    
    

/**
 * @brief Obtiene el mejor beneficio de asignar a n trabajadores n trabajos usando backtracking y una poda basada en un cota superior
 * @param n: el numero de trabajos o trabajadores
 * @param ab: Arbol de permutaciones para obtener la mejor solucion
 * @param B: matriz de beneficios 
 * @return el mejor beneficio total
 * */    
int Asig_Trabajadores_Poda(int n, Apermutacion &ab,const Matriz<unsigned int> &B){
    Apermutacion P(n); 
    bool seguir =true;
    int bact=0; int best_beneficio=0;
    unsigned int nodos_recorridos =0;
    while (seguir){
        nodos_recorridos++;
        bact=Suma_Beneficio(P,B);
	if (P.GetLevel()==n-1){
	  if (bact>best_beneficio){
	      /*cout<<"Actualizando solucion : "<<bact<<endl;
	      MuestraAsignacion(P);*/
	      best_beneficio=bact;
	      ab=P;
	      seguir =P.Backtracking();
	  }
	  else 
	      
	        seguir=P.GeneraSiguiente();
	    
	 }
	else{
	   vector<int> C=ObtainAsignaciones(P,n);
	   int bestimado = bact+CotaSuperior(C,B);
	   if (bestimado >=best_beneficio)
	      seguir=P.GeneraSiguiente();
	   else
	      seguir =P.Backtracking();
	   
	}
    }
    int total=P.NumeroSecuenciasPosibles();
    cout<<"Numero de nodos recorridos "<<nodos_recorridos<< " total nodos "<<total<<" Porcentaje "<<(nodos_recorridos/(double)total)*100.0<<endl;
    return best_beneficio;
}    
 

 
 
int main(int argc, char *argv[]){
  if (argc!=2){
      cout<<"Dime el fichero con la matriz de beneficios"<<endl;
      return 0;
  }
   
   ifstream f (argv[1]);
   if (!f){
      cerr<<"No puedo abrir el fichero "<<argv[1];
      return 0;
   }
   Matriz<unsigned int> M;
   f>>M;
   
   cout<<"Beneficios (filas=trabajadores, columnas=trabajos):"<<endl;
   cout<<M<<endl;
   
   if (M.filas()!=M.cols()){
     cout<<"La matriz de beneficios debe ser cuadrada"<<endl;
     return 0;
   }  
   int n = M.filas();
  
   cout<<endl;
   clock_t tantes,tdespues;
   cout<<"__________________________________"<<endl;
   cout<<"Algoritmo voraz..."<<endl;
   tantes=clock();
   cout<<"Con voraces beneficio total: "<<Asi_Trabajadores_Voraz(n,M)<<endl ;
   tdespues=clock();
   cout<<"Tiempo "<<(tdespues-tantes)/(double)CLOCKS_PER_SEC;
   cout<<endl<<"__________________________________"<<endl;
   Apermutacion Pbest(n);
   cout<<"Algoritmo Backtracking...."<<endl;
   tantes=clock();
   cout<<"Best_Beneficio con Backtracking: "<<Asig_Trabajadores(n,Pbest ,M)<<endl;
   
   tdespues=clock();
   MuestraAsignacion(Pbest);
   cout<<"Tiempo "<<(tdespues-tantes)/(double)CLOCKS_PER_SEC;
   cout<<endl<<"__________________________________"<<endl;
   
   Apermutacion Pbest_Poda(n);
   cout<<"Algoritmo Backtracking con Poda...."<<endl;
   tantes=clock();
   cout<<"Best_Beneficio con Backtracking y Poda: "<<Asig_Trabajadores_Poda(n,Pbest_Poda ,M)<<endl;
  
   tdespues=clock();
   MuestraAsignacion(Pbest_Poda);
   cout<<"Tiempo "<<(tdespues-tantes)/(double)CLOCKS_PER_SEC;
   cout<<endl<<"__________________________________"<<endl;
 
}   
   
   
   
   


