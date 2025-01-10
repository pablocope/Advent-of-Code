#include <iostream>
#include <cstdlib>
#include <cmath>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

class Grafo{
private:
    vector<vector<int>> mapa; //Mapa de los caminos y las alturas
    vector<vector<Nodo>> adjList; //Lista de adyacencia
public:

    void leer_mapa(vector<vector<int>> map){
        string input;
        cout << "Introduce el mapa:" << endl;

        while (getline(cin, input) && !input.empty()) {
            vector<int> fila;
                
            int longitud = input.length();
            for (int i = 0; i < longitud; i++) {
                
                fila.push_back(input[i]);
            }

            if(!fila.empty()){ //Mete la fila leida en otro vector
                map.push_back(fila);
            }   
        }
    }
};

class Nodo{
private:
    int nodo_num; //Número identificador del nodo
    int altura; //valor de altura del nodo
    int pos[2]; //posición en el mapa

public:

};

