#include "imagen.h"
#include <fstream>
#include <iostream>
using namespace std;


int CalcularNformas(const Imagen &I, const Imagen &){
    Imagen subcuadrante

    

}

int main(int argc, char * argv[]){
  if (argc!=3){
      cout<<"Los parametros son: ";
     cout<<"1.-Dime el nombre de una imagen"<<endl;
     cout<<"2.-Dime el nombre de una forma"<<endl;
     return 0;
  }   
  
  Imagen I,forma;
  I.LeerImagen(argv[1]);
  forma.LeerImagen(argv[2]);


  cout << I.num_filas()<<endl;
    cout << I.num_cols()<<endl;

    cout << forma.num_filas()<<endl;
    cout << forma.num_cols()<<endl;
  
  
}