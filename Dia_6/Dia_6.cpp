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

class Mapa {
private:
    vector<vector<Casilla>> map;
    //El inicio de las coordenadas es el punto de arriba a la izquierda del mapa
    int pos_x;
    int pos_y;

    int prev_pos_x;
    int prev_pos_y;

    int total_visitadas;
    
    void set_pos_inicial(){
        for(int i = 0; i < map.size(); i++){
            for(int j = 0; j < map[i].size(); j++){
                if(map[i][j].get_caracter() == '^'){
                    pos_x = j;
                    pos_y = i;
                    return;
                }
            }
        }
    }

public:
    Mapa(){
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
                map.push_back(fila);
            }   
        }

        total_visitadas = 0;
        set_pos_inicial();
    }

    void imprimir_mapa(){
        for(int i = 0; i < map.size(); i++){
            for(int j = 0; j < map[i].size(); j++){
                cout << map[i][j].get_caracter();
            }
            cout << endl;
        }
    }
    
    //Las funciones de movimiento devuelven 0 si está todo correcto, en caso de no poder moverse porque hay colisión devuelven un -1
    int move_up(){
        prev_pos_y = pos_y;
        pos_y--;

        if(check_collision()){
            pos_y = prev_pos_y;
            map[pos_y][pos_x].set_visited();
            return -1;
        }else{
            map[pos_y][pos_x].set_visited();
            return 0;
        }
    }

    int move_right(){
        prev_pos_x = pos_x;
        pos_x++;

        if(check_collision()){
            pos_x = prev_pos_x;
            map[pos_y][pos_x].set_visited();
            return -1;
        }else{
            map[pos_y][pos_x].set_visited();
            return 0;
        }
    }

    int move_down(){
        prev_pos_y = pos_y;
        pos_y++;

        if(check_collision()){
            pos_y = prev_pos_y;
            map[pos_y][pos_x].set_visited();
            return -1;
        }else{
            map[pos_y][pos_x].set_visited();
            return 0;
        }
    }

    int move_left(){
        prev_pos_x = pos_x;
        pos_x--;

        if(check_collision()){
            pos_x = prev_pos_x;
            map[pos_y][pos_x].set_visited();
            return -1;
        }else{
            map[pos_y][pos_x].set_visited();
            return 0;
        }
    }

    bool check_collision(){
        if(map[pos_y][pos_x].get_caracter() == '#'){
            return true;
        }else{
            return false;
        }
    }

    int recuento(){
        for(int i = 0; i < map.size(); i++){
            for(int j = 0; j < map[i].size(); j++){
                if(map[i][j].get_visited()){
                    total_visitadas++;
                }
            }
        }

        return total_visitadas;
    }
    
};

/*
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
*/

int main(){

    Mapa mapa;

    mapa.imprimir_mapa();

    return 0;
}