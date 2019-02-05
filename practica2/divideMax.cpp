
#include <iostream>
#include <cstdlib>  // Para generación de números pseudoaleatorios
//#include <pair>

using namespace std;

pair<int, int > MaxMin(int *vector , int tam){

	pair<int, int>resultado;
	pair<int, int>iz;
	pair<int, int>der;
	//pair<int, int>segundo_resu;
	int maximo , minimo = 200 ;
	int pos;
	if ( tam == 1){

		if (maximo < vector[tam-1]){
			 maximo = vector[tam-1];
			 
		}
		if (minimo > vector[tam-1]){
			minimo = vector[tam-1];

		}
		resultado.second = maximo;
		resultado.first = minimo;

		cout << "minimo actual -->" <<resultado.first << " maximo actual -->" <<resultado.second <<endl;
		

	}
	else{

		iz=MaxMin(vector,tam/2);
		der=MaxMin(vector + tam/2, tam - tam/2);

		if(iz.first<der.first){
			resultado.first = iz.first;
		}
		else{
			resultado.first = der.first;
		}
		if( der.second >der.second){
			resultado.second = der.first;
		}
		else{
			resultado.second = iz.first;
		}


		return resultado;
	}



return resultado;

}

void intercambiar(int &a, int &b){
    int aux = a;
    a=b;
    b = aux;
}

int pivote(int *v, int i, int j){
    int piv, k, l;
    k =i;
    piv = v[i];
    l = j+1;

    do{
        k = k+1;
    }while (v[k] <= piv && k<j);

    do{
        l = l-1;
    }while(v[l] > piv);

    while (k<l){
        intercambiar(v[k], v[l]);
        do{
            k=k+1;
        }while(v[k] <= piv);

        do{
            l = l-1;
        }while (v[l]>l);
    }
    intercambiar(v[i], v[l]);

    return l;
}


void zapatero(int *zapatos, int *ninios, int i, int n){

    int pivote_zapatos, pivote_ninios;

    if (i < n){

        pivote_zapatos = pivote(zapatos,i, n);
        pivote_ninios = pivote(ninios, i, n);
        
        zapatero(zapatos,ninios,i,pivote_zapatos-1);
        zapatero(zapatos,ninios,pivote_zapatos+1, n);

        zapatero(zapatos,ninios,i,pivote_ninios-1);
        zapatero(zapatos,ninios,pivote_ninios+1,n);
	}
}
int main (){

	// pair<int, int >prueba;
	// int vector_prueba[10];
	// srand(time(0));
	// 	for (int i = 0 ; i< 10 ; i++){

	// 		vector_prueba[i]=rand() % 100;
	// 		cout << vector_prueba[i]<< endl;
			
	// 	}

	// prueba= MaxMin(vector_prueba, 10);



	// cout << "el minimo es " <<prueba.first << endl;
	// cout << "el maximo es " <<prueba.second << endl;
    // Generación del vector aleatorio
    int *Z = new int[20]; // Reserva de memoria
    int *P = new int[20]; // Reserva de memoria

    int val;

    srand(time(0)); // Inicialización del generador de números pseudoaleatorios

    for (int i = 0; i < 20; i++){ // Recorrer vector
        val = (rand() % 10) ; // Generar aleatorio [0,vmax[

        Z[i] = val;
        P[i] = val; 
        cout << Z[i] <<" " << P[i] << endl;
    }

    random_shuffle(&Z[0], &Z[20]);
    random_shuffle(&P[0], &P[20]);

   //int piv = Pivote(Z, 0, tam);
    for(int i = 0; i < 20; ++i){
        cout <<Z[i] << " " << P[i] << endl;
    }
    cout << "y ahora llamo a la funcion \n\n"<< endl;

    zapatero(Z, P, 0, 20);
    
    for(int i = 0; i < 20; ++i){
        cout << Z[i] << " " << P[i] << endl;
    }
    
    delete[] Z; // Liberamos memoria dinámica
    delete[] P; // Liberamos memoria dinámica



}




