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
	v[i] = v[fin];
	v[fin] = aux;
    
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

//Función de búsqueda binaria para la parte dos
int BusquedaBinaria(int x, vector<int> v, int ini, int fin){

	if(ini > fin){
		return -1; //No se encuentra en el array
	}

	int medio = (ini + fin)/2;

	if(v[medio] == x){
		return medio;
	}else if(v[medio] > x){
		return BusquedaBinaria(x, v, ini, medio-1);
	}else{
		return BusquedaBinaria(x, v, medio+1, fin);
	}
}

//Función para encontrar los números iguales de una lista
int cantidad_similar(int x, vector<int> v){
	int similares = 0;
	int pos_x = BusquedaBinaria(x, v, 0, v.size());

	if(pos_x == -1){
		return 0;
	}

	similares++;

	int pos_x_right = pos_x + 1;
	int pos_x_left = pos_x - 1;

	while(x == v[pos_x_left]){ //miramos las posiciones anteriores a la que hemos encontrado
		pos_x_left--;
		similares++;
	}
	while(x == v[pos_x_right]){ //miramos las posiciones anteriores a la que hemos encontrado
		pos_x_right++;
		similares++;
	}

	return similares;
}

double calculo_similares(vector<int> l1, vector<int> l2){
	double similares = 0;

	
	for(int i = 0; i < l1.size(); i++){
		//cout << l1[i]*cantidad_similar(l1[i], l2) << " + ";
		similares = similares + l1[i]*cantidad_similar(l1[i], l2);
	}


	return similares;
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

	cout << "SEGUNDA PARTE" << endl << "El cálculo del similarity score es:" << fixed << calculo_similares(lista_1, lista_2);

    return 0;
}