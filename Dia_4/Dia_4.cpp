#include <iostream>
#include <cstdlib>
#include <cmath>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

void leer_lista(vector<vector<char>>& matriz){
    string input;
    cout << "Introduce la sopa de letras:" << endl;

    while (getline(cin, input) && !input.empty()) {
        vector<char> fila;
        
        char letra;
        int longitud = input.length();
        for (int i = 0; i < longitud; i++) {
            letra = input[i];
            fila.push_back(letra);
        }

        if(!fila.empty()){ //Mete la fila leida en otro vector
            matriz.push_back(fila);
        }   
    }
}

int main(){

    vector<vector<char>> sopa_letras;

    leer_lista(sopa_letras);

    for(int i = 0; i < sopa_letras.size(); i++){
        for(int j = 0; j < sopa_letras[i].size(); j++){
            cout << sopa_letras[i][j];
        }
        cout << endl;
    }

    return 0;
}