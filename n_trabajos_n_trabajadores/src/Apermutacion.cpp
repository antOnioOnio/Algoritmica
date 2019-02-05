#include "Apermutacion.h"

 bool Apermutacion::Repetidos(){
   for (int i=0;i<=level-1;i++)
      if (datos[i]==datos[level]) return true;
    return false;
 }
 /***************************************************/
 bool Apermutacion::EsSecuencia(int l){
   if (Repetidos()) return false;
   return level>=0 && level<=(int)datos.size()-1;
 }   
  
 /***************************************************/  
 bool Apermutacion::PosibleSecuencia(int l){
   if (Repetidos()) return false;
   return level>=0 && level<(int)datos.size()-1;
 }   
  
/***************************************************/  
bool Apermutacion::MasHermanos(int l){
  return level>=0 && datos[level]<(int)datos.size();
}
/***************************************************/  

bool Apermutacion::GeneraSiguiente(){
  
  if (level<(int)datos.size()-1)//Podemos avanzar al siguiente nivel
     level=level+1;
  while (level>=0 && !MasHermanos(level)){
    datos[level]=0;
    level--;
  }  
  do{
    Next(level);
    if (EsSecuencia(level))
        return true;
   
    if (PosibleSecuencia(level)) level++;
    else
      while (level>=0 && !MasHermanos(level)){
        datos[level]=0;
        level--;
      }
  }while (level>=0);
  return false;
}  
     
/***************************************************/  

bool Apermutacion::Backtracking(){
  if (level==0) return false;
  else{
    while (level>=0 && !MasHermanos(level)){
      datos[level]=0;
      level--;
     }
     if (level<0) return false;
  }	
  do{
    Next(level);
    if (EsSecuencia(level))
        return true;
   
    if (PosibleSecuencia(level)) level++;
    else
      while (level>=0 && !MasHermanos(level)){
        datos[level]=0;
        level--;
      }
  }while (level>=0);
  return false;
}  


/***************************************************/  
int  Apermutacion::NumeroSecuenciasPosibles(){
     unsigned int suma=0;
  
    for (unsigned int k=1; k<=datos.size();k++){
     int total =1;
     for (unsigned int i=k;i<=datos.size();i++)
       total*=i;
    suma+=total;
  
    
  
   }
   return suma;
}   