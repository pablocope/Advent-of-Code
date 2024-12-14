#include <iostream>
#include <cstdlib>
#include <cmath>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

//-----------------------------------------------------------------------------------
//FUNCIONES
//-----------------------------------------------------------------------------------

//Función para extraer los números de las listas
void leer_lista(vector<int>& l1, vector<int>& l2){
    string input;
    cout << "Introduce las listas:" << endl;

    while (getline(cin, input) && !input.empty()) {
        stringstream ss(input);

        int num1, num2;
        if (ss >> num1 >> num2) {
            l1.push_back(num1);
            l2.push_back(num2);
        }
    }
}

//Funciones para ordenar un vector mediante QuickSort
int Partition(vector<int>& v, int ini, int fin){
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
	v[i] = v[j];
	v[j] = aux;
    
    return i;
}

void QuickSort(vector<int>& v, int ini, int fin){
    if(ini < fin){
        int pivot = Partition(v, ini, fin);

        QuickSort(v, ini, pivot-1);
        QuickSort(v, pivot+1, fin);
    }
}

//Función para mostrar por pantalla un vector
void imprimir_lista(const vector<int>& v){
    cout << "{";

    for(size_t i = 0; i < v.size(); i++){
        cout << v[i];
        if(i < v.size()-1){
            cout << ", ";
        }else{
            cout << "}" << endl;
        }
    }
}

//Funciones para calcular la distancia entre dos listas
int distancia_puntos(int a, int b){
    return abs(a - b);
}

int distancia_listas(const vector<int>& l1, const vector<int>& l2){
    int suma = 0;
    for(size_t i = 0; i < l1.size(); i++){
        suma += distancia_puntos(l1[i], l2[i]);
    }
    return suma;
}

//-----------------------------------------------------------------------------------
//                              PROGRAMA PRINCIPAL
//-----------------------------------------------------------------------------------
int main(){
    vector<int> lista_1;
    vector<int> lista_2;

    leer_lista(lista_1, lista_2);

    //Imprimimos las listas para ver cómo son
    cout << "Las listas son las siguientes:" << endl;
    imprimir_lista(lista_1);
    imprimir_lista(lista_2);
    cout << endl;

    //Ordenamos lista_1
    QuickSort(lista_1, 0, lista_1.size() - 1);
    //Ordenamos lista_2
    QuickSort(lista_2, 0, lista_2.size() - 1);

    //Imprimimos listas para ver cómo han quedado
    cout << "Ordenando listas..." << endl;
    imprimir_lista(lista_1);
    imprimir_lista(lista_2);

    cout << "La distancia entre las listas es " << distancia_listas(lista_1, lista_2) << endl;

    return 0;
}

/*#include <iostream>
#include <cstdlib>
#include <cmath>
#include <sstream>
#include <string>

#define TAMANYO 1000

using namespace std;

//-----------------------------------------------------------------------------------
//FUNCIONES
//-----------------------------------------------------------------------------------

//Función para extraer los números del array
void leer_lista(int l1[], int l2[]){
    int count = 0;
	string input;
    cout << "Introduce las listas:" << endl;

    while (getline(cin, input) && !input.empty()) {
        if (count >= TAMANYO) {
            cerr << "Se ha alcanzado el tamaño máximo del array" << endl;
            break;
        }

        stringstream ss(input);

        int num1, num2;
        if (ss >> num1 >> num2) {    // Extrae dos números de la línea
            l1[count] = num1;
            l2[count] = num2;
            ++count;
        }
    }

}

//Funciones para ordenar un array mediante QuickSort
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

//-----------------------------------------------------------------------------------
//                              PROGRAMA PRINCIPAL
//-----------------------------------------------------------------------------------
int main(){

    int lista_1[TAMANYO];
    int lista_2[TAMANYO];

    leer_lista(lista_1, lista_2);

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
}*/