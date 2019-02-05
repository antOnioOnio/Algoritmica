#include "abb.h"
#include <string>
#include <sstream>
#include <vector>
#include <cstdlib>  // Para generación de números pseudoaleatorios
#include <chrono>// Recursos para medir tiempos
using namespace std::chrono;
using namespace std;

// tenemos que mirar la eficiencia en el metodo insertar

// en promedio n*log2N
// en el peor n^2
// en el apo tenemos que coger, borrarlo y ponerlas para medir el tiempo
// en gnuplot el factorial es gamma de n+1

void ListarAbb(ABB<int> &ab_bus)
{
	ABB<int>::nodo n;
	// cout << endl
	// 	 << "Elementos ordenados: ";

	for (n = ab_bus.begin(); n != ab_bus.end(); ++n)
	{
		*n;//	cout << *n << " ";
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
	if (argc!=2)
	{
   	 sintaxis();
	}
	int tam=atoi(argv[1]);
	high_resolution_clock::time_point start,//punto de inicio
                                  end; //punto de fin
 	duration<double> tiempo_transcurrido;  //objeto para medir la duracion de end 						   // y start
  
	start = high_resolution_clock::now(); //iniciamos el punto de inicio
	vector<int>ordenado;
	vector<int>orden_inverso;
	vector<int>aleatorio;

	int tam_maximo = 1000;
	int a = tam;
	int al;
	srand(time(0));
	
	ABB<int> ab_bus;
	ABB<int> ab_bus2;
	ABB<int> ab_bus3;

	for (int i = 0 ; i<tam ; i++){
		//ordenado.push_back(i); // nos va a dar el peor
		 orden_inverso.push_back(a); // nos va a dar el mejor
		 a--;
		//aleatorio.push_back(rand()%tam_maximo); // promedio
	}

	for (int i = 0; i < ordenado.size(); i++)
	{
	//	ab_bus.Insertar(ordenado[i]);
		ab_bus2.Insertar(orden_inverso[i]);
	//	ab_bus3.Insertar(aleatorio[i]);
	}

	// for (int i = 0; i < orden_inverso.size(); i++)
	// {
	// 	ab_bus.Insertar(orden_inverso[i]);
	// }

	// for (int i = 0; i < aleatorio.size(); i++)
	// {
	// 	ab_bus.Insertar(aleatorio[i]);
	// }

	ListarAbb(ab_bus2);
		// cout<<endl;
		// ListarAbb(ab_bus2);
		// cout<<endl;
		// ListarAbb(ab_bus3);

	// int x;

	// cout << endl
	// 	 << "Dime un elemento a borrar: ";
	// while (cin >> x)
	// {
	// 	if (ab_bus.Buscar(x))
	// 	{
	// 		cout << endl
	// 			 << x << " esta" << endl;
	// 		ab_bus.Borrar(x);
	// 	}
	// 	else
	// 	{
	// 		cout << "El elemento " << x << " no esta" << endl;
	// 	}
	// 	ListarAbb(ab_bus);
	// }


	end = high_resolution_clock::now(); //anotamos el punto de de fin 
 	//el tiempo transcurrido es
 	tiempo_transcurrido  = duration_cast<duration<double> >(end - start);

  	// Mostramos resultados
 	cout << tam << "\t" <<tiempo_transcurrido.count() << endl;

}