#include <iostream>
#include "Apermutacion.h"
#include <string> 
template <class T>
ostream & operator<<(ostream &os, const vector<T> & d){
   for (int i=0;i<d.size();i++)
      os<<d[i]<<" ";
   os<<endl;
   return os;
}

void MuestraSecuencia(const Apermutacion & P){
  Apermutacion::const_iterator it;
  
  for (it=P.begin();it!=P.end();++it)
      cout<<*it<<" ";
  cout<<endl;    
}


int main(){
  int n;
  cout<<"Dime el tamaño de las secuencias :";
  cin>>n;
  
  Apermutacion P(n);
  
  cout<<"El numero total de secuencias: "<<P.NumeroSecuenciasPosibles()<<endl;
  
  do{
  MuestraSecuencia(P);
   
  }while (P.GeneraSiguiente());
  


  
}  
  
  
   
  
