#ifndef HASHTABLE_H
#define HASHTABLE_H

#include "TableEntry.h"

#include <iostream>
#include <cstdlib>
#include <sstream>
#include <string>
#include <vector>

using namespace std;


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

#endif