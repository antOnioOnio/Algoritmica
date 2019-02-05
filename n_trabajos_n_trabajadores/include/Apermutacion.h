#ifndef __APERMUTA__
#define __APERMUTA__
#include <vector>
using namespace std;
/**
   @brief T.D.A. APermutacion
   
   \b Definición:
   Una instancia \e a del tipo de dato abstracto APermutacion sobre un dominio de enteros
   genera secuencias (x1,x2,x3,...,xk) 1<=k<=n donde cada xi toma valores 1,,,.k, y ademas xi<>xj para i<>j.
   
   Para poder usar el tipo de dato APermutacion se debe incluir el fichero
   
   <tt>\#include APermutacion.h</tt>
   
   El espacio requerido para el almacenamiento es O(n), donde n es la longitud maxima de cada secuencia
   
   @author Rosa Mª Rodríguez Sánchez
   @date 12 de Mayo de 2015
*/


class Apermutacion{
  private:
   vector<int>datos;
   int level;
public:
  /**
   * @brief Constructor por parametros. Inicia la permutacion
   * con n valores a 0.
   * 
   * */
  Apermutacion(int n):datos(vector<int>(n,0)),level(-1){
    GeneraSiguiente();
  }
   
  /** 
   *@brief Establece si la permutacion tiene valores repetidos
   * @return true si hay  valores repetidos y false en caso contrario
   **/
  bool Repetidos(); 
  
  /** 
   * @brief Avance al siguiente valor por el nivel por el que va
   * */
  
  void Next(int l){
    datos[l]++;
  }  
     
  /** 
   * @brief Analiza  si es una permutacion valida 
   * @param l: el nivel hasta el que se quiere analizar si es secuencia valida
   * @return devuelve true si es permutacion valida false en caso contrario
   * */
  bool EsSecuencia(int l);
  
  /** 
   * @brief Analiza  si es una secuencia que puede dar lugar a una  permutacion valida (potencia   permutacion valida)
   * @param l: el nivel hasta el que se quiere analizar si es secuencia valida
   * @return devuelve true si es potencial permutacion valida false en caso contrario
   * */
  bool PosibleSecuencia(int l);
  
  /** 
   * @brief Analiza  si existen mas valores posibles para el nivel dado
   * @param l: el nivel 
   * @return devuelve true si existen mas posibles valores false en caso contrario
   * */
  bool MasHermanos (int l);
  
  /** 
   * @brief Obtiene la siguiente permutacion valida
   * @return devuelve true si se ha generado una permutacion, false si no se puede generar porque ya se 
   * han generado todas
   * */
  
  bool GeneraSiguiente();
  
  
  /** 
   * @brief Obtiene la siguiente permutacion valida por la siguiente rama.
   * @return devuelve true si se ha generado una permutacion, false si no se puede generar porque ya se 
   * han generado todas
   * */
  bool Backtracking();
    
  
  /** 
   * @brief Devuelve  el nivel de la secuencia hasta el momento
   */
  
   int GetLevel()const{ 
      return level;
    }
  
   /**
    * @brief devuelve el numero posible de secuencias
    * 
    */
   int NumeroSecuenciasPosibles();
  
  
  /****************************************/
  /*Iteradores*/
    class iterator{
    private:
       vector< int> ::iterator it;
       vector< int> ::iterator final;
       
    public:
        iterator (){ }
        iterator & operator++(){
	     ++it;
	    return *this;
	}
	
	iterator & operator --(){
	   --it;
	  return *this;
	}
	
	bool operator ==(const iterator & i)const{
	   return (i.it==it);
	}
	bool operator !=(const iterator & i)const{
	   return (i.it!=it);
	}  
	
	int & operator*()const {
	   return *it;
	}
	friend class Apermutacion;
    };
    
    
    
    class const_iterator{
    private:
       vector<int>::const_iterator it;
       vector< int> ::const_iterator final;
    public:
        const_iterator (){ }
        
        const_iterator & operator++(){
	   ++it;
	    return *this;
	}
	
	const_iterator & operator --(){
	   --it;
	  return *this;
	}
	
	bool operator ==(const const_iterator & i)const{
	   return (i.it==it);
	}
	bool operator !=(const const_iterator & i)const {
	   return (i.it!=it);
	}  
	
	const  int & operator*()const {
	   return *it;
	}
	friend class Apermutacion;
    };
    
    
    
    
    
    
    
    iterator begin(){
	iterator i;
	i.it=datos.begin();
	if (level>=0)
	 i.final=datos.begin()+level+1;
	else i.final=datos.end();
	return i;
    }
    iterator end(){
        iterator i;
	if (level>=0){
         if (level ==(int)datos.size()-1 && datos[level]>0)
	   i.it=datos.end();
	 else
	   i.it = datos.begin()+level+1;
	}
	else i.it=datos.end();
	i.final = i.it;
	
	return i;
    }
    
    
    const_iterator begin()const{
	const_iterator i;
	i.it=datos.begin();
	if (level>=0)
	 i.final=datos.begin()+level+1;
	else i.final=datos.end();
	return i;
    }
    const_iterator end()const{
        const_iterator i;
	
	if (level>=0){
         if (level ==(int)datos.size()-1 && datos[level]>0)
	   i.it=datos.end();
	 else
	   i.it = datos.begin()+level+1;
	}
	else i.it=datos.end();
	   
	i.final = i.it;
	
	
	return i;
    }
};
#endif