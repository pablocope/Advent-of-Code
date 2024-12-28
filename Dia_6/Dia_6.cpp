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
                
                if(map[i][j].get_visited()){
                    cout << "X";
                }else{
                    cout << map[i][j].get_caracter();
                }
            }
            cout << endl;
        }
    }
    
    //Las funciones de movimiento devuelven 0 si está todo correcto, en caso de no poder moverse porque hay colisión devuelven un -1
    int move_up(){
        cout << "Intentando moverse hacia arriba..." << pos_x << " " << pos_y <<endl;
        prev_pos_y = pos_y;
        pos_y--;

        if(!check_exit() && check_collision()){
            pos_y = prev_pos_y;
            map[pos_y][pos_x].set_visited();
            return -1;
        }else if(!check_exit()){
            map[pos_y][pos_x].set_visited();
            return 0;
        }
        return 0;
    }

    int move_right(){
        cout << "Intentando moverse hacia derecha..." << pos_x << " " << pos_y << endl;
        prev_pos_x = pos_x;
        pos_x++;

        if(!check_exit() && check_collision()){
            pos_x = prev_pos_x;
            map[pos_y][pos_x].set_visited();
            return -1;
        }else if(!check_exit()){
            map[pos_y][pos_x].set_visited();
            return 0;
        }
        return 0;
    }

    int move_down(){
        cout << "Intentando moverse hacia abajo..." << pos_x << " " << pos_y << endl;
        prev_pos_y = pos_y;
        pos_y++;
        
        if(!check_exit() && check_collision()){
            pos_y = prev_pos_y;
            map[pos_y][pos_x].set_visited();
            return -1;
        }else if(!check_exit()){
            map[pos_y][pos_x].set_visited();
            return 0;
        }
        return 0;
    }

    int move_left(){

        cout << "Intentando moverse hacia izquierda..." << pos_x << " " <<pos_y << endl;
        prev_pos_x = pos_x;
        pos_x--;

        if(!check_exit() && check_collision()){
            pos_x = prev_pos_x;
            map[pos_y][pos_x].set_visited();
            return -1;
        }else if(!check_exit()){
            map[pos_y][pos_x].set_visited();
            return 0;
        }
        return 0;
    }

    //Comprueba si en la posión en la que se encuentra hay un obstáculo
    bool check_collision(){
        if(map[pos_y][pos_x].get_caracter() == '#'){
            return true;
        }else{
            return false;
        }
    }

    //Comprueba si en la posición en la que está se ha salido fuera del mapa
    bool check_exit(){
        cout << "comprobando que no ha salido" << endl;
        if(pos_y >= map.size() || pos_y < 0 || pos_x >= map[pos_y].size() || pos_x < 0){
            cout << "El guardia ha salido" << endl;
            return true;
        }else{
            return false;
        }
    }

    int recuento(){
        total_visitadas = 0;

        for(int i = 0; i < map.size(); i++){
            for(int j = 0; j < map[i].size(); j++){
                if(map[i][j].get_visited() || map[i][j].get_caracter() == '^'){
                    total_visitadas++;
                }
            }
        }

        return total_visitadas;
    }
    
};

int main(){

    Mapa mapa;

    while(true){
        while(mapa.move_up() == 0){
            if(mapa.check_exit()){
                
                cout << "El total de casillas pisadas es " << mapa.recuento() << endl;
                return 0;
            }
        }
        while(mapa.move_right() == 0){
            if(mapa.check_exit()){
                
                cout << "El total de casillas pisadas es " << mapa.recuento() << endl;
                
                return 0;
            }
        }
        while(mapa.move_down() == 0){
            if(mapa.check_exit()){
                
                cout << "El total de casillas pisadas es " << mapa.recuento() << endl;
                
                return 0;
            }
        }
        while(mapa.move_left() == 0){
            if(mapa.check_exit()){
                
                cout << "El total de casillas pisadas es " << mapa.recuento() << endl;
                return 0;
            }
        }
    }

    return 0;
}