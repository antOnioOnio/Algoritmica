#include <iostream>
#include <cstdlib>  // Para generación de números pseudoaleatorios
#include <chrono>// Recursos para medir tiempos
using namespace std;
using namespace std::chrono;


int insercion(int *a, int n)
{
  for (int i = 0 ; i<n ; i++){
      int x = a[i] ;
      int j = i-1;
      while(j>=0 && x<a[j]){
          a[j+1] = a[j];
          j = j-1;
      }
      a[j+1]=x;
  }
}

int seleccion(int *a, int n){
  for (int i = 0 ; i<n-1 ; i++){
    int pmin = i;
    for (int j=i+1 ; j<n ; j++){
      if ( a[pmin]>a[j]){
        pmin = j;
      }
    }
    swap(a[i],a[pmin]);
  }
}

int burbuja(int *a, int n)
{
    int c, d, t;

    for (c = 0; c < (n - 1); c++) {
        for (d = 0; d < n - c - 1; d++) {
            if (a[d] > a[d + 1]) {
                t = a[d];
                a[d] = a[d + 1];
                a[d + 1] = t;
            }
        }
    }
}

}
void sintaxis()
{
  cerr << "Sintaxis:" << endl;
  cerr << "  TAM: Tamaño del vector (>0)" << endl;
  cerr << "  VMAX: Valor máximo (>0)" << endl;
  cerr << "Se genera un vector de tamaño TAM con elementos aleatorios en [0,VMAX[" << endl;
  exit(EXIT_FAILURE);
}

int main(int argc, char * argv[])
{
  // Lectura de parámetros
  if (argc!=2)
    sintaxis();
  int tam=atoi(argv[1]);     // Tamaño del vector
  //int vmax=atoi(argv[2]);    // Valor máximo
  if (tam<=0 )
    sintaxis();
  
  // Generación del vector aleatorio
  // int *v=new int[tam];       // Reserva de memoria
  // srand(time(0));            // Inicialización del generador de números pseudoaleatorios
  // for (int i=0; i<tam; i++)  // Recorrer vector
  //   v[i] = rand() // % vmax ;    // Generar aleatorio [0,vmax[
  
  // generacion del vector ordenado
  int *ordenado = new int[tam];
  for ( int i = 0 ; i < tam ; i++){
      ordenado[i]=i;
  }

  // generacion del vector orden inverso
  int *orden_inverso = new int[tam];
  int cont = tam;
  for ( int i = 0 ; i<tam ; i++){
    orden_inverso[i] = cont;
    cont--;
  }


 high_resolution_clock::time_point start,//punto de inicio
                                  end; //punto de fin
 duration<double> tiempo_transcurrido;  //objeto para medir la duracion de end 						   // y start
  
 start = high_resolution_clock::now(); //iniciamos el punto de inicio
 
  //int x = vmax+1;  // Buscamos un valor que no está en el vector
  seleccion(orden_inverso,tam); // de esta forma forzamos el peor caso
  
 end = high_resolution_clock::now(); //anotamos el punto de de fin 
 //el tiempo transcurrido es
 tiempo_transcurrido  = duration_cast<duration<double> >(end - start);

  // Mostramos resultados
  cout << tam << "\t" <<tiempo_transcurrido.count() << endl;
  
  delete [] ordenado;     // Liberamos memoria dinámica
}
