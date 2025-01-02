#include <iostream>
#include <cstdlib>
#include <cmath>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

//Usaremos una tabla hash para almacenar todas los patrones de colores que tenemos, de forma que resultará más fácil encontrar si existe uno que se ajuste a lo que queremos o no
//En este caso la propia clave que usamos es el dato que querremos así que podemos prescindir de la variable valor, de todas formas las dejamos por si nos sirviera en un futuro

class TableEntry{
public:
	string key;
	string value;

	TableEntry(string key, string value){
		this->key = key;
		this->value = value;
	}

	TableEntry(string key){
		this->key = key;
	}

	TableEntry(){
		this->key = "";
	}
};

class HashTable {
private:
    int n; // Elementos almacenados
    int max; // Tamaño de la tabla
    vector<vector<TableEntry>> table;

    int funcion_hash(string key){ //Calculamos valor hash en función de las letras y su correspondiente posición en la palabra
        int sum = 0;
        for (int i = 0; i < key.size(); i++) {
            char c = key[i];
            sum += static_cast<int>(c)+(10*i);
        }
        return sum % max;
    }

public:
    HashTable(int size){
        n = 0;
        max = size; 
        table = vector<vector<TableEntry>>(max);
    }

    void insert(string key){
        int index = funcion_hash(key);
        
        table[index].push_back(TableEntry(key));
        n++;
    }

    bool search(string key){ //Hemos adaptado la función de búsqueda para que en vez de devolver el valor de una posición simplemente compruebe si existe una entrada de la tabla con dicha llave
        int index = funcion_hash(key);
        for (int i = 0; i < table[index].size(); i++) {
            if (table[index][i].key == key) {
                return true; //Existe la llave que buscamos en la tabla
            }
        }
        return false; //No existe la llave que buscamos
    }

    void fill_table(vector<string> towels){
        for(int i = 0; i < towels.size(); i++){
            insert(towels[i]);
        }
    }

    void print(){
        for(int i = 0; i < max; i++){
            for(int j = 0; j < table[i].size(); j++){
                cout << table[i][j].key << ", ";
            }
            if(table[i].size() < 1){
                cout << "NULL";
            }
            cout << endl;
        }
    }
};

//Reaprovechamos parte de la función de lectura del input del día 5
void leer_lista(vector<string>& towels, vector<string>& designs){
    string input;
    cout << "Introduce la lista de toallas y la lista de diseños (input del AoC):" << endl;
    
    //Leer toallas y ponerlas en un vector
    while (getline(cin, input) && !input.empty()) {
        
        istringstream line_stream(input);
        string fila;

        while(getline(line_stream, fila, ',')){
            fila.erase(0, fila.find_first_not_of(" \t")); //Esto sirve para eliminar el espacio que se genera delante de cada palabra
            towels.push_back(fila);
        }
    }

    //Leer diseños
    while (getline(cin, input) && !input.empty()) {
        istringstream line_stream(input);
        designs.push_back(input);  
    }
}

void print(vector<string> v){
    for(int i = 0; i < v.size(); i++){
        cout << v[i] << endl;
    }
    cout << endl;
}

bool check_possible(HashTable towels_table, string design) {
    int i = 0;

    while(i < design.length()) {
        bool encontrado = false;

        for(int j = design.length() - i; j > 0; j--) {
            string fragmento = design.substr(i, j);
            //cout << "Comprobamos fragmento: " << fragmento << endl;

            if(towels_table.search(fragmento)) {
                //cout << "Fragmento encontrado: " << fragmento << endl;
                i += j;
                encontrado = true;
                break; 
            }
        }

        if(!encontrado) {
            //cout << "No se encontró un fragmento válido a partir de: " << design.substr(i) << endl;
            
            return false;
        }
    }

    return true;
}

int main(){

    HashTable towels_table(128);
    vector<string> designs;
    vector<string> towels;

    int patrones_posibles = 0;

    leer_lista(towels, designs);
    towels_table.fill_table(towels);
    print(towels);
    towels_table.print();
    print(designs);

    for(int i = 0; i < designs.size(); i++){
        //cout << "----- Combinación: " << designs[i] << " -----" << endl; 
        if(check_possible(towels_table, designs[i])){
            //cout << "Es posible" << endl;
            patrones_posibles++;
        }
    }

    cout << patrones_posibles;

    return 0;
}



