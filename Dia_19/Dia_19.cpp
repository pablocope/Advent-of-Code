#include "TableEntry.h"
#include "HashTable.h"

#include <iostream>
#include <cstdlib>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

//Usaremos una tabla hash para almacenar todas los patrones de colores que tenemos, de forma que resultará más fácil encontrar si existe uno que se ajuste a lo que queremos o no
//En este caso la propia clave que usamos es el dato que querremos así que podemos prescindir de la variable valor, de todas formas las dejamos por si nos sirviera en un futuro

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

bool check_possible(HashTable& towels_table, string& design, int start, vector<int>& memoria){
    //Si hemos llegado al final del diseño, es posible construirlo
    if(start == design.length()) {
        return true;
    }

    //Vamos a usar una memoria para almacenar si una rama del problema no ha sido calculada (-1), si una rama es posible (1) o si una rama es imposible (0)
    if(memoria[start] != -1){
        return memoria[start] == 1;
    }

    //Intentamos todos los fragmentos posibles desde el índice actual
    for(int i = start+1; i <= design.length(); i++){
        string fragmento = design.substr(start, i - start);

        //Si el fragmento está disponible en la tabla, intentamos avanzar
        if(towels_table.search(fragmento) && check_possible(towels_table, design, i, memoria)){
            //cout << "Fragmento encontrado: " << fragmento << endl;
            memoria[start] = 1;
            return true;
            
        }
    }

    //Si no se encuentra combinación, no se puede construir el diseño
    memoria[start] = 0;
    return false;
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
        cout << "----- Combinación: " << designs[i] << " -----" << endl;
        vector<int> memoria(designs[i].length(), -1); 
        if(check_possible(towels_table, designs[i], 0, memoria)){
            cout << "Es posible" << endl;
            patrones_posibles++;
        }else{
            cout << "No es posible" << endl;
        }
    }

    cout << patrones_posibles << endl;

    return 0;
}



