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

void imprimir_sopa(vector<vector<char>> sopa_letras){
    for(int i = 0; i < sopa_letras.size(); i++){
        for(int j = 0; j < sopa_letras[i].size(); j++){
            cout << sopa_letras[i][j];
        }
        cout << endl;
    }
}

bool verificar_rango_xmas(vector<vector<char>>& sopa, int i, int j) {
    return i >= 0 && i < sopa.size() && j >= 0 && j < sopa[i].size();
}

int contar_xmas(vector<vector<char>>& sopa_letras){
    int total = 0;

    for(int i = 0; i < sopa_letras.size(); i++){
        for(int j = 0; j < sopa_letras[i].size(); j++){
            if(sopa_letras[i][j] == 'X'){
                // Comprobamos hacia la derecha
                if (verificar_rango_xmas(sopa_letras, i, j + 3) &&
                    sopa_letras[i][j + 1] == 'M' &&
                    sopa_letras[i][j + 2] == 'A' &&
                    sopa_letras[i][j + 3] == 'S') {
                    total++;
                }
                // Comprobamos hacia la izquierda
                if (verificar_rango_xmas(sopa_letras, i, j - 3) &&
                    sopa_letras[i][j - 1] == 'M' &&
                    sopa_letras[i][j - 2] == 'A' &&
                    sopa_letras[i][j - 3] == 'S') {
                    total++;
                }
                // Comprobamos hacia abajo
                if (verificar_rango_xmas(sopa_letras, i + 3, j) &&
                    sopa_letras[i + 1][j] == 'M' &&
                    sopa_letras[i + 2][j] == 'A' &&
                    sopa_letras[i + 3][j] == 'S') {
                    total++;
                }
                // Comprobamos hacia arriba
                if (verificar_rango_xmas(sopa_letras, i - 3, j) &&
                    sopa_letras[i - 1][j] == 'M' &&
                    sopa_letras[i - 2][j] == 'A' &&
                    sopa_letras[i - 3][j] == 'S') {
                    total++;
                }
                // Comprobamos diagonal arriba derecha
                if (verificar_rango_xmas(sopa_letras, i - 3, j + 3) &&
                    sopa_letras[i - 1][j + 1] == 'M' &&
                    sopa_letras[i - 2][j + 2] == 'A' &&
                    sopa_letras[i - 3][j + 3] == 'S') {
                    total++;
                }
                // Comprobamos diagonal abajo derecha
                if (verificar_rango_xmas(sopa_letras, i + 3, j + 3) &&
                    sopa_letras[i + 1][j + 1] == 'M' &&
                    sopa_letras[i + 2][j + 2] == 'A' &&
                    sopa_letras[i + 3][j + 3] == 'S') {
                    total++;
                }
                // Comprobamos diagonal abajo izquierda
                if (verificar_rango_xmas(sopa_letras, i + 3, j - 3) &&
                    sopa_letras[i + 1][j - 1] == 'M' &&
                    sopa_letras[i + 2][j - 2] == 'A' &&
                    sopa_letras[i + 3][j - 3] == 'S') {
                    total++;
                }
                // Comprobamos diagonal arriba izquierda
                if (verificar_rango_xmas(sopa_letras, i - 3, j - 3) &&
                    sopa_letras[i - 1][j - 1] == 'M' &&
                    sopa_letras[i - 2][j - 2] == 'A' &&
                    sopa_letras[i - 3][j - 3] == 'S') {
                    total++;
                }
            }
        }
    }

    return total;
}

bool verificar_rango_masmas(vector<vector<char>>& sopa, int i, int j){
    return i -1 >= 0 && i + 1 < sopa.size() && j - 1 >= 0 && j + 1 < sopa[i].size();
}

int contar_masmas(vector<vector<char>>& sopa_letras){
    int total = 0;

    for(int i = 0; i < sopa_letras.size(); i++){
        for(int j = 0; j < sopa_letras[i].size(); j++){
            if(sopa_letras[i][j] == 'A'){
                // Comprobamos arriba dos M y abajo dos S
                if (verificar_rango_masmas(sopa_letras, i, j) &&
                    sopa_letras[i - 1][j - 1] == 'M' &&
                    sopa_letras[i - 1][j + 1] == 'M' &&
                    sopa_letras[i + 1][j + 1] == 'S' &&
                    sopa_letras[i + 1][j - 1] == 'S' ) {
                    
                    total++;
                }
                // Comprobamos derecha dos M e izquierda dos S
                if (verificar_rango_masmas(sopa_letras, i, j) &&
                    sopa_letras[i - 1][j - 1] == 'S' &&
                    sopa_letras[i - 1][j + 1] == 'M' &&
                    sopa_letras[i + 1][j + 1] == 'M' &&
                    sopa_letras[i + 1][j - 1] == 'S' ) {
                    
                    total++;
                }
                // Comprobamos abajo dos M y arriba dos S
                if (verificar_rango_masmas(sopa_letras, i, j) &&
                    sopa_letras[i - 1][j - 1] == 'S' &&
                    sopa_letras[i - 1][j + 1] == 'S' &&
                    sopa_letras[i + 1][j + 1] == 'M' &&
                    sopa_letras[i + 1][j - 1] == 'M' ) {
                    
                    total++;
                }
                // Comprobamos abajo dos M y arriba dos S
                if (verificar_rango_masmas(sopa_letras, i, j) &&
                    sopa_letras[i - 1][j - 1] == 'M' &&
                    sopa_letras[i - 1][j + 1] == 'S' &&
                    sopa_letras[i + 1][j + 1] == 'S' &&
                    sopa_letras[i + 1][j - 1] == 'M' ) {
                    
                    total++;
                }
                
            }
        }
    }

    return total;
}

int main(){

    vector<vector<char>> sopa_letras;

    leer_lista(sopa_letras);

    //imprimir_sopa(sopa_letras);

    int contador = 0;
    
    //contador =  contar_xmas(sopa_letras);
    
    contador = contar_masmas(sopa_letras);

    cout << contador;

    return 0;
}