#include <iostream>
#include <vector>
#include <sstream>
#include <string>

using namespace std;

// Clase para un nodo del árbol binario
class Nodo {
public:
    int valor;
    Nodo* izquierdo;
    Nodo* derecho;

    Nodo(int v) : valor(v), izquierdo(nullptr), derecho(nullptr) {}
};

// Clase Árbol Binario
class ArbolBinario {
private:
    Nodo* raiz;

    // Función auxiliar para insertar un valor en el árbol de forma arbitraria
    void insertarAux(Nodo*& nodo, int valor) {
        if (nodo == nullptr) {
            nodo = new Nodo(valor);
        } else {
            // Inserción arbitraria (ejemplo: a la izquierda si está libre, luego a la derecha)
            if (nodo->izquierdo == nullptr) {
                insertarAux(nodo->izquierdo, valor);
            } else {
                insertarAux(nodo->derecho, valor);
            }
        }
    }


    // Función para liberar memoria (destructor)
    void liberarMemoria(Nodo* nodo) {
        if (nodo != nullptr) {
            liberarMemoria(nodo->izquierdo);
            liberarMemoria(nodo->derecho);
            delete nodo;
        }
    }

public:
    // Constructor
    ArbolBinario() : raiz(nullptr) {}

    // Destructor
    ~ArbolBinario() {
        liberarMemoria(raiz);
    }

    // Función para insertar un valor en el árbol
    void insertar(int valor) {
        insertarAux(raiz, valor);
    }

    // Inserta la lista haciendo los cálculos para que el nodo de la izquierda sume el siguiente número y para que el de laderecha multiplique el siguiente número
    void insertarLista(vector<int> valores){ 
        multiplicarSumarNodo(raiz, valores, 0);
    }
    void multiplicarSumarNodo(Nodo* nodo, vector<int> valores, int n){
        if(n > valores.size()){
            return;
        }else{
            if(n == 0){
                raiz = new Nodo(valores[1]);
                n = 1;
            }
            nodo->izquierdo = new Nodo(nodo->valor + valores[n++]);
            multiplicarSumarNodo(nodo->izquierdo, valores, n++);

            nodo->derecho = new Nodo(nodo->valor + valores[n++]);
            multiplicarSumarNodo(nodo->derecho, valores, n++);
        }
    }
    
};

void leerLista(vector<vector<int>>& lista){
    string input;
    cout << "Introduce la lista de numeros:" << endl;

    while (getline(cin, input) && !input.empty()) {
        vector<int> valores;
        istringstream line_stream(input);
        string fila;

        getline(line_stream, fila, ':');
        if (!fila.empty()) {
            valores.push_back(stoi(fila));
        }

        int valor;
        while (line_stream >> valor) {
            valores.push_back(valor);
        }

        if (!valores.empty()) {
            lista.push_back(valores);
        }
    }
}

void imprimirLista(vector<vector<int>> lista){
    for(int i = 0; i < lista.size(); i++){
        for(int j = 0; j < lista[i].size(); j++){
            if(j == 0){
                cout << lista[i][j] << ": ";
            }else{
                cout << lista[i][j] << " ";   
            }
        }
        cout << endl;
    }
}

int main() {
    ArbolBinario arbol;

    vector<vector<int>> lista;

    leerLista(lista);
    //imprimir_lista(lista);

    

    return 0;
}
