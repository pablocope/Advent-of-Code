#include <iostream>
#include <cstdlib>
#include <cmath>
#include <sstream>
#include <string>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

class Nodo {
private:
    int id; // Número identificador del nodo: x + y*mapa[x].size()
    int altura; // Valor de altura del nodo
    int pos[2]; // Posición en el mapa

    bool visitado;

public:
    Nodo(){
    }
    Nodo(int id, int altura, int pos_x, int pos_y) {
        this->id = id;
        this->altura = altura;
        pos[0] = pos_x;
        pos[1] = pos_y;
        visitado = false;
    }

    int getId() { return id; }
    int getAltura() { return altura; }
    int getPosX() { return pos[0]; }
    int getPosY() { return pos[1]; }
    bool getVisitado(){ return visitado;}
    void setVisitado(bool tf){visitado = tf;}
};

class Grafo {
private:
    vector<vector<int>> mapa;                // Mapa de los caminos y las alturas sobre el que se basará el grafo
    vector<vector<int>> adjList;             // Lista de adyacencia con los ID de cada nodo
    vector<Nodo> nodos;                      // Lista de nodos que componen el grafo

    void rellenarAdjList(int x, int y) {
        vector<int> contiguos_posibles;

        if (x + 1 < mapa.size() && mapa[x + 1][y] == mapa[x][y] + 1) {
            int id = (x + 1) + y * mapa[x].size();
            contiguos_posibles.push_back(id);
        }

        if (x - 1 >= 0 && mapa[x - 1][y] == mapa[x][y] + 1) {
            int id = (x - 1) + y * mapa[x].size();
            contiguos_posibles.push_back(id);
        }

        if (y + 1 < mapa[x].size() && mapa[x][y + 1] == mapa[x][y] + 1) {
            int id = x + (y + 1) * mapa[x].size();
            contiguos_posibles.push_back(id);
        }

        if (y - 1 >= 0 && mapa[x][y - 1] == mapa[x][y] + 1) {
            int id = x + (y - 1) * mapa[x].size();
            contiguos_posibles.push_back(id);
        }

        adjList[x + y * mapa[x].size()] = contiguos_posibles;
    }

    void setNodosFalse(){
        for (int i = 0; i < nodos.size(); i++) {
            nodos[i].setVisitado(false);
        }
    }

    /*void rellenarNodos(){
        for (int i = 0; i < mapa.size(); i++) {
            for (int j = 0; j < mapa[i].size(); j++) {
                Nodo nodo(i + j * mapa[i].size(), mapa[i][j], i, j);
                nodos[i + j * mapa[i].size()] = nodo;
            }
        }
    }*/

public:
    Grafo() {
        leerMapa();
        adjList.resize(mapa.size() * mapa[0].size());
        nodos.resize(mapa.size() * mapa[0].size());
        crearAdjList();
    }

    void leerMapa() {
        string input;
        cout << "Introduce el mapa:" << endl;

        while (getline(cin, input) && !input.empty()) {
            vector<int> fila;

            int longitud = input.length();
            for (int i = 0; i < longitud; i++) {
                fila.push_back(input[i] - '0');
            }

            if (!fila.empty()) { // Mete la fila leída en otro vector
                mapa.push_back(fila);
            }
        }
    }

    void crearAdjList() {
        //rellenarNodos();
        // Recorremos el mapa para crear nodos y listas de adyacencia
        for (int i = 0; i < mapa.size(); i++) {
            for (int j = 0; j < mapa[i].size(); j++) {
                int id = i + j * mapa[i].size();
                Nodo nodo(id, mapa[i][j], i, j);
                nodos[id] = nodo;

                rellenarAdjList(i, j);
            }
        }
    }

    void imprimirAdjList(){
        cout << "Lista de adyacencia:" << endl;
        for (int i = 0; i < adjList.size(); i++) {
            cout << "Nodo " << i << ": ";
            for (int j = 0; j < adjList[i].size(); j++) {
                cout << adjList[i][j] << " ";
            }
            cout << endl;
        }
    }

    void imprimirNodos(){
        cout << "Lista de nodos:" << endl;
        for (int i = 0; i < nodos.size(); i++) {
            cout << "Nodo " << i << ": " << nodos[i].getAltura();
            cout << endl;
        }
    }

    void imprimirMapa() const {
        cout << "Mapa cargado:" << endl;
        for (int i = 0; i < mapa.size(); i++) {
            for (int j = 0; j < mapa[i].size(); j++) {
                cout << mapa[i][j] << " ";
            }
            cout << endl;
        }
    }

    vector<int> encontrarNodosConAltura(int altura) {
        vector<int> ids;
        for (int i = 0; i < nodos.size(); i++) {
            if (nodos[i].getAltura() == altura) {
                ids.push_back(nodos[i].getId());
            }
        }
        return ids;
    }
    
    int contarNodosAlcanzables(){
        vector<int> ids_nodo_base = encontrarNodosConAltura(0);
        int total_nodos_alcanzables = 0;
        for(int i = 0; i < ids_nodo_base.size(); i++){
            
            buscarAltura(ids_nodo_base[i], &total_nodos_alcanzables);
            setNodosFalse();
            
        }
        return total_nodos_alcanzables;
    }

    void buscarAltura(int id_nodo, int *total){
        //cout << "Buscando en nodo " << id_nodo << endl;
        if(nodos[id_nodo].getAltura() == 9){
            if(nodos[id_nodo].getVisitado() == false){
                (*total)++;
                nodos[id_nodo].setVisitado(true);
                //cout << "Nodo encontrado de altura 9: " << id_nodo << endl;
            }
        }else{
            for(int n = 0; n < adjList[id_nodo].size(); n++){
                buscarAltura(adjList[id_nodo][n], total);
            }
        }
        
    }
/*
    int contarNodosAlcanzables(int startId, int objetivoAltura) {
        unordered_map<int, bool> visitado;
        queue<int> q;
        q.push(startId);
        visitado[startId] = true;

        int count = 0;
        while (!q.empty()) {
            int currentId = q.front();
            q.pop();

            if (nodos[currentId].getAltura() == objetivoAltura) {
                count++;
            }

            for (int vecino : adjList[currentId]) {
                if (!visitado[vecino] && nodos[vecino].getAltura() >= nodos[currentId].getAltura()) {
                    visitado[vecino] = true;
                    q.push(vecino);
                }
            }
        }
        return count;
    }*/

    
};

int main() {
    Grafo grafo;

    grafo.imprimirMapa();

    grafo.imprimirAdjList();

    grafo.imprimirNodos();

    vector<int> nodosAlturaCero = grafo.encontrarNodosConAltura(0);
    cout << "Nodos con altura 0 encontrados: " << nodosAlturaCero.size() << endl;

    //int total_rutas = 0;

    /*for (int i = 0; i < nodosAlturaCero.size(); ++i) {
        int id = nodosAlturaCero[i];
        int alcanzables = grafo.contarNodosAlcanzables(id);
        cout << "Desde el nodo con ID " << id << " se pueden alcanzar " << alcanzables << " nodos con altura 9." << endl;
        total_rutas += alcanzables;
    }*/

    cout << "Total de rutas extraídas: " << grafo.contarNodosAlcanzables() << endl;

    return 0;
}
