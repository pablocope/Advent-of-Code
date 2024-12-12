#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>

#define TAMANYO 5

using namespace std;

//FUNCIONES

//funciones para ordenar un array mediante QuickSort
int Partition(int v[], int ini, int fin){

	int x = v[fin];
	int i = ini;

	for(int j = ini; j <= fin-1; j++){
		if(v[j] <= x){
			int aux = v[i];
			v[i] = v[j];
			v[j] = aux;

			i++;
		}
	}
	
	int aux = v[i];
        v[i] = v[fin];
        v[fin] = aux;

	return i;
}


void QuickSort(int v[], int ini, int fin){
        if(ini < fin){
                int pivot = Partition(v, ini, fin);

                QuickSort(v, ini, pivot-1);
                QuickSort(v, pivot+1, fin);
        }
}

//Función para mostrar por pantalla un array
void imprimir_lista(int v[], int tamanyo){

	cout << "{";

	for(int i = 0; i<tamanyo; i++){
                cout << v[i];
                if(i < tamanyo-1){
                        cout << ", ";
                }else{
                        cout << "}" << endl;
                }
        }
}

//Funciones para calcular la distancia entre dos listas
int distancia_puntos(int a, int b){
    int distancia = 0;
    distancia = abs(a - b);
    return distancia;
}

int distancia_listas(int l1[], int l2[], int tamanyo){
    int suma = 0;
    for(int i = 0; i < tamanyo; i++){
        suma = suma + distancia_puntos(l1[i], l2[i]);
    }
    return suma;
}


//PROGRAMA PRINCIPAL
int main(){

    srand(time(NULL));

    int lista_1[TAMANYO];
    int lista_2[TAMANYO];

    //Rellenamos los vectores con números aleatorios
    for(int i = 0; i < TAMANYO; i++){
        lista_1[i] = rand() % 10;
        lista_2[i] = rand() % 10;
    }

    //imprimimos las listas para ver cómo son
    cout << "Las listas sonlas siguientes:" << endl;
    imprimir_lista(lista_1, TAMANYO);
    imprimir_lista(lista_2, TAMANYO);
    cout << endl;

    //Ordenamos lista_1
    QuickSort(lista_1, 0, TAMANYO);
    //Ordenamos lista_2
    QuickSort(lista_2, 0, TAMANYO);

    //Imprimimos listas para ver como han quedado
    cout << "Ordenando listas..." << endl;
    imprimir_lista(lista_1, TAMANYO);
    imprimir_lista(lista_2, TAMANYO);

    cout << "La distancia entre las listas es " << distancia_listas(lista_1, lista_2, TAMANYO) << endl;

    return 0;
}