#include "apo.h"

#include <cstdlib>  // Para generación de números pseudoaleatorios
#include <chrono>// Recursos para medir tiempos
using namespace std;
using namespace std::chrono;


void sintaxis()
{
  cerr << "Sintaxis:" << endl;
  cerr << "  TAM: Tamaño del vector (>0)" << endl;
  cerr << "  VMAX: Valor máximo (>0)" << endl;
  cerr << "Se genera un vector de tamaño TAM con elementos aleatorios en [0,VMAX[" << endl;
  exit(EXIT_FAILURE);
}

int main(int argc, char * argv[]){

 if (argc!=2){
    sintaxis();
}
int tam=atoi(argv[1]);


  // Generación del vector aleatorio
  // int *v=new int[tam];       // Reserva de memoria
  // srand(time(0));            // Inicialización del generador de números pseudoaleatorios
  // for (int i=0; i<tam; i++)  // Recorrer vector
  //   v[i] = rand() // % vmax ;    // Generar aleatorio [0,vmax


APO<int>ap_int;
APO<int>ap_int2;
int a_insertar;
int tam_maximo = 1000;
srand(time(0));

	high_resolution_clock::time_point start,//punto de inicio
                                  end; //punto de fin
 	duration<double> tiempo_transcurrido;  //objeto para medir la duracion de end 						   // y start
  
	start = high_resolution_clock::now(); //iniciamos el punto de inicio
	int contador = tam;
	for ( int i = 0 ; i<tam ; i++ )
	{
		//a_insertar=rand()%tam_maximo; // este para aleatorio, osea promedio
		//a_insertar=i; 				// este para ordenado
		a_insertar = contador;
		contador--;
		ap_int.insertar(a_insertar);
	}
	//cout<<"APO introducido: "<<ap_int <<endl;
	for (int i = 0 ; i<tam ; i++)
	{
		
		ap_int2.insertar(ap_int.minimo());
		ap_int.borrar_minimo();
	}

	//cout<<"APO ordenado: "<<ap_int2 <<endl;
	
	end = high_resolution_clock::now(); //anotamos el punto de de fin 
 	//el tiempo transcurrido es
 	tiempo_transcurrido  = duration_cast<duration<double> >(end - start);

  	// Mostramos resultados
 	 cout << tam << "\t" <<tiempo_transcurrido.count() << endl;

}	  