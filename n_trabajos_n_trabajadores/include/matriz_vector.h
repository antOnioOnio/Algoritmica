#ifndef _MATRIZ_H
#define _MATRIZ_H
#include <iostream>
#include <vector>
#include <cassert>
#include <algorithm>
using namespace std;
template <class T>
class Matriz{
	  private:
		    vector<vector<T> > m;
		    int nr, nc;
		    void Copiar(const Matriz<T> &M){
			   this->nr= M.nr;
			  this->nc = M.nc;
			  
			  m = vector< vector<T> >(nr);
			  typename vector<vector<T> >::iterator it_r;
			  typename vector<vector<T> >::const_iterator it_r_m;
			  for (it_r_m=M.m.begin(),it_r=m.begin();it_r_m!=M.m.end(); ++it_r_m,++it_r){
				    typename vector<T>::const_iterator it_c_m;
				    *it_r=vector<T>(nc);
				    typename vector<T>::iterator it_c;
				    //El for de abajo se puede sustituir por (*it_r).assign((*it_r_m).begin(),(*it_r_m).end()
				    for (it_c_m =(*it_r_m).begin(),it_c=(*it_r).begin(); it_c_m!=(*it_r_m).end(); ++it_c_m,++it_c){
				         *it_c=*it_c_m;  
				    }
			  }
			  //La asignacion típica es
			  //for (int i=0;i<nr;i++){
			  //    m[i]= vector<T>(nc);
			  //	for (int j=j<nc;j++)
			  //		m[i][j]= M.m[i][j];
			  //	}
			      
		    }
		    void Borrar(){
			 //Todo el codigo de abajo se podría implementar con la sentencia m.clear()     
			typename vector<vector<T> >::iterator it_r;
			//el for se podría haber eliminado y solamente dejar m.erase(m.begin(),m.end());
			for (it_r = m.begin(); it_r!=m.end();++it_r)
				 (*it_r).erase((*it_r).begin(),(*it_r).end());
			m.erase(m.begin(),m.end());
			
		    }		
	  public:
		Matriz():nr(0),nc(0){}
		Matriz(int nr,int nc, const T&value = T()){
			   this->nr=nr;
			   this->nc=nc;
			   m= vector< vector<T> >(nr);
			   typename vector <vector<T> >::iterator it;
			   for (it=m.begin(); it!=m.end();++it){ // for (it=m.rbegin();it!=m.rend();++it){
			      *it=vector<T>(nc,value);
			   }
		}
		~Matriz(){}
		Matriz(const Matriz<T>&M){
			  Copiar(M);
		}	  
		Matriz<T> & operator=(const Matriz<T> & M){	  
			  if (this!=&M){
				    Borrar();
				    Copiar(M);
			  }
			  return *this;
	        }	
	        int filas()const{ return nr;}
	        int cols()const {return nc;}
	        //Añade una columna en la posicion pos-esima
	       Matriz<T>& addCol(int pos,const  vector<T> &v){
			 assert(v.size()==nr);
			 //tenemos que hacer un resize de cada fila 
			 
			 typename vector <vector<T> >::iterator it;
			 typename vector<T>::const_iterator itv=v.begin();
			 for (it=m.begin();it!=m.end(); ++it,++itv){
				   (*it).resize(nc+1);
				   for (int i=nc;i>pos;i--)
					    (*it)[i]=(*it)[i-1]; //*it.at(i)=*it.at(i-1)
				   
				  (*it)[pos]=*itv;
			 }
			 nc++;
			 return *this;
	       }
	       
	       //Añade una fila en la posicion pos-esima
	       Matriz<T>& addRow(int pos,const  vector<T> &v){
			 assert(v.size()==nc);
			 //tenemos que hacer un resize de cada  columna
			 m.resize(nr+1);
			 for (int i=nr;i>pos;--i)
				   m[i].assign(m[i-1].begin(),m[i-1].end());
			 m[pos].assign(v.begin(),v.end());
			 nr++;
			 return *this;
	       }	   
	       //Elimina una columna en la posicion pos-esima
	       Matriz<T>& delCol(int pos){
			typename vector <vector<T> >::iterator it; 
			for (it=m.begin();it!=m.end();++it){ 
			  for (int i=pos;i<nc-1;i++)
				   (*it).at(i)=(*it).at(i+1);
			  (*it).pop_back();
			}
			  nc--;
			  return *this;
	       }
	       //Elimina una fila en la posicion pos-esima
	       Matriz<T>& delRow(int pos){
			
			for (int i=pos;i<nr-1;i++)
			   m[i]=m[i+1];
			m.pop_back();
			nr--;
			return *this;
			
	       }
	       void set(int r,int c, const T &v){
			 assert(r>=0 && r<nr && c>=0 && c<nc);
			 m[r][c]=v; //m.at(r).at(c)=v;
			 
	       }
	       const T& get(int r,int c)const{
			  assert(r>=0 && r<nr && c>=0 && c<nc);
			  return m[r][c];
	       }
	       T& get(int r,int c){
			  assert(r>=0 && r<nr && c>=0 && c<nc);
			  return m[r][c];
	       }
	      vector<T> & operator[](int r){
			    assert(r>=0 && r<nr);
			    return m[r];
	       }	    
	        const vector<T> & operator[](int r)const {
			    assert(r>=0 && r<nr);
			    return m[r];
	       }
	      //Intercambio de dos matrices
	      void swap(Matriz<T> & M){
			m.swap(M.m);
			std::swap(nr,M.nr);
			std::swap(nc,M.nc);
	      }
	      friend ostream & operator<<(ostream & os, const Matriz<T> &M){
			for (int i=0;i<M.nr;i++){
				  os<<"\n";
			          for (int j=0;j<M.nc;j++)
					    os<<M.m[i][j]<<" ";
			}
			return os;
	      }
	      friend istream & operator>>(istream & is,  Matriz<T> &M){
			
			int nr,nc;
			is>>nr>>nc;
			Matriz<T>Maux(nr,nc);
			for (int i=0;i<nr;i++){
				  
			          for (int j=0;j<nc;j++)
					    is>>Maux.m[i][j];
			}
			M=Maux;
			return is;
	      }
};
#endif