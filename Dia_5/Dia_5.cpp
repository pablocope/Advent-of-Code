#include <iostream>
#include <cstdlib>
#include <cmath>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

void leer_lista(vector<vector<int>>& rules, vector<vector<int>>& updates){
    string input;
    cout << "Introduce la lista de reglas de ordenación y después de un salto de lines las updates (copiar tal cual el input del AoC):" << endl;
    vector<int> cero = {0,0};
    rules.push_back(cero);
    //Leer reglas
    while (getline(cin, input) && !input.empty()) {
        vector<int> rule;
        istringstream line_stream(input);
        string fila;

        while(getline(line_stream, fila, '|')){
            rule.push_back(stoi(fila));
        }

        if(!rule.empty()){ //Mete la fila leida en otro vector
            rules.push_back(rule);
        }   
    }

    //Leer updates
    while (getline(cin, input) && !input.empty()) {
        vector<int> update;
        istringstream line_stream(input);
        string fila;

        while(getline(line_stream, fila, ',')){
            update.push_back(stoi(fila));
        }

        if(!update.empty()){ //Mete la fila leida en otro vector
            updates.push_back(update);
        }   
    }
}

void imprimir_datos(vector<vector<int>>& rules, vector<vector<int>>& updates){ //para comprobar obtención correcta de los datos
    for(int i = 0; i < rules.size(); i++){
        for(int j = 0; j < rules[i].size(); j++){
            cout << rules[i][j] << " ";
        }
        cout << endl;
    }

    cout << endl;

    for(int i = 0; i < updates.size(); i++){
        for(int j = 0; j < updates[i].size(); j++){
            cout << updates[i][j] << " ";
        }
        cout << endl;
    }
}

//Para ordenar el vector con las rules
int Partition(vector<vector<int>>& v, int ini, int fin){
    int x = v[fin][0];
    int i = ini;

    for(int j = ini; j <= fin-1; j++){
        if(v[j][0] <= x){
            vector<int> aux = v[i];
			v[i] = v[j];
			v[j] = aux;
            i++;
        }
    }
	
	vector<int> aux = v[i];
	v[i] = v[fin];
	v[fin] = aux;
    
    return i;
}

void QuickSort(vector<vector<int>>& v, int ini, int fin){
    if(ini < fin){
        int pivot = Partition(v, ini, fin);

        QuickSort(v, ini, pivot-1);
        QuickSort(v, pivot+1, fin);
    }
}

//Función para búsqueda binaria modificada para que encuentre la primera posición que contenga el valor buscado
int BusquedaBinaria(int x, vector<vector<int>> v, int ini, int fin){

	if(ini > fin){
		return -1; //No se encuentra en el array
	}

	int medio = (ini + fin)/2;

	if(v[medio][0] == x){
		while((medio >= 0) && (v[medio][0] == x)){
            medio--;
        }
        return medio;
	}else if(v[medio][0] > x){
		return BusquedaBinaria(x, v, ini, medio-1);
	}else{
		return BusquedaBinaria(x, v, medio+1, fin);
	}
}

int check_order(vector<vector<int>> rules, vector<int> update){ //devuelve 0 si está en orden incorrecto y devuelve el número del medio si está en orden correcto
        
    for(int i = update.size()-1; i >= 0; i--){
        int pos_rule = BusquedaBinaria(update[i], rules, 0, rules.size()-1);
        if (pos_rule == -1) {
            //cout << "No se encontró ninguna regla para " << update[i] << endl;
            continue; // Pasa al siguiente elemento del update
        }
        while(pos_rule < rules.size() && pos_rule >= 0){
            
            for(int j = i; j >= 0; j--){
                //cout << "Verificando regla " << rules[pos_rule][0] << "|" << rules[pos_rule][1] << " con update " << update[i] << endl;
                if(rules[pos_rule][1] == update[j] && rules[pos_rule][0] == update[i]){
                    return 0;
                }
            }
            pos_rule++;
        }
    }

    return update[update.size()/2];
    
}

/*int check_order(vector<vector<int>> rules, vector<int> update) { 
    for (int i = 0; i < update.size(); i++) {
        int pos_rule = BusquedaBinaria(update[i], rules, 0, rules.size());
        if (pos_rule == -1) {
            cout << "No se encontró ninguna regla para " << update[i] << endl;
            continue; // Pasa al siguiente elemento del update
        }
        while (pos_rule < rules.size() && rules[pos_rule][0] == update[i]) {
            // Verifica si la regla viola el orden en la actualización
            cout << "Verificando regla " << rules[pos_rule][0] << "|" << rules[pos_rule][1] << " con update " << update[i] << endl;
            int required_position = -1;
            for (int j = 0; j < update.size(); j++) {
                if (update[j] == rules[pos_rule][1]) {
                    required_position = j;
                    break;
                }
            }
            // Si la página requerida está en una posición anterior, el orden es incorrecto
            if (required_position != -1 && required_position < i) {
                return 0; 
            }
            pos_rule++;
        }
    }
    // Si pasa todas las reglas, devuelve el valor del medio
    return update[update.size() / 2];
}*/

int check_list(vector<vector<int>> rules, vector<vector<int>> updates){

    int suma = 0;

    for(int n = 0; n < updates.size(); n++){
        suma += check_order(rules, updates[n]);
    }

    return suma;

}

int main(){

    vector<vector<int>> rules;
    vector<vector<int>> updates;

    leer_lista(rules, updates);

    QuickSort(rules, 0, rules.size()-1);

    imprimir_datos(rules, updates);

    int total = check_list(rules, updates);

    cout << "El resultado es: " << total << endl;

    return 0;
}