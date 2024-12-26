#include <iostream>
#include <cstdlib>
#include <cmath>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

class Casilla {
private:
    bool visited;
    char caracter;

public:
    Casilla(char simbolo){
        caracter = simbolo;
        if(simbolo == '^'){
            visited == true;
        }else{
            visited = false;
        }
    }

    bool get_visited(){
        return visited;
    }

    void set_visited(){
        visited = true;
    }

    char get_caracter(){
        return caracter;
    }
};

void leer_mapa(vector<vector<Casilla>>& mapa){
    string input;
    cout << "Introduce el mapa:" << endl;

    while (getline(cin, input) && !input.empty()) {
        vector<Casilla> fila;
        
        int longitud = input.length();
        for (int i = 0; i < longitud; i++) {
            Casilla casilla(input[i]);
            fila.push_back(casilla);
        }

        if(!fila.empty()){ //Mete la fila leida en otro vector
            mapa.push_back(fila);
        }   
    }
}

void imprimir_mapa(vector<vector<Casilla>> mapa){
    for(int i = 0; i < mapa.size(); i++){
        for(int j = 0; j < mapa[i].size(); j++){
            cout << mapa[i][j].get_caracter();
        }
        cout << endl;
    }
}

int main(){

    vector<vector<Casilla>> mapa;

    leer_mapa(mapa);

    imprimir_mapa(mapa);

    return 0;
}