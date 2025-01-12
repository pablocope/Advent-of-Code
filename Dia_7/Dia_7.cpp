#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <fstream>

using namespace std;

//Clase para un nodo del árbol binario
class Nodo {
public:
    long long valor;
    Nodo* izquierdo;
    Nodo* derecho;

    Nodo(long long v) : valor(v), izquierdo(nullptr), derecho(nullptr) {}
    long long getValor() { return valor; }
};

//Clase Árbol Binario
class ArbolBinario {
private:
    Nodo* raiz;

    // Función para liberar memoria (destructor)
    void liberarMemoria(Nodo* nodo) {
        if (nodo != nullptr) {
            liberarMemoria(nodo->izquierdo);
            liberarMemoria(nodo->derecho);
            delete nodo;
        }
    }

    // Función auxiliar para imprimir el árbol
    void imprimirArbolAux(Nodo* nodo, int nivel) {
        if (nodo == nullptr) {
            return;
        }

        for (int i = 0; i < nivel; i++) {
            cout << "  ";
        }
        cout << nodo->valor << endl;

        imprimirArbolAux(nodo->izquierdo, nivel + 1);
        imprimirArbolAux(nodo->derecho, nivel + 1);
    }

    // Función auxiliar para insertar la lista al árbol
    void insertarListaAux(Nodo*& nodo, vector<long long> valores, int n) {
        if (n >= valores.size()) {
            return;
        }

        if (n == 1) {
            nodo = new Nodo(valores[n]);
        }
                
        if (n < valores.size()) {
            n++;
            nodo->izquierdo = new Nodo(nodo->getValor() + valores[n]);
            insertarListaAux(nodo->izquierdo, valores, n);
            nodo->derecho = new Nodo(nodo->getValor() * valores[n]);
            insertarListaAux(nodo->derecho, valores, n);
        }
    }

    bool buscarNumeroAux(Nodo* nodo, long long valor) {
        if (nodo == nullptr) {
            return false;
        }
        if (nodo->valor == valor) {
            return true;
        }
        return buscarNumeroAux(nodo->izquierdo, valor) || buscarNumeroAux(nodo->derecho, valor);
    }

public:
    // Constructor
    ArbolBinario() : raiz(nullptr) {}

    // Destructor
    ~ArbolBinario() {
        liberarMemoria(raiz);
    }

    bool buscarNumero(long long valor) {
        return buscarNumeroAux(raiz, valor);
    }

    // Crea el arbol a partir de la lista haciendo los cálculos para que el nodo de la izquierda sume el siguiente número y para que el de la derecha multiplique el siguiente número
    void insertarLista(vector<long long> valores) {
        int n = 1;
        insertarListaAux(raiz, valores, n);
    }

    // Función pública para imprimir el árbol
    void imprimirArbol() {
        cout << "Imprimiendo árbol: " << endl;
        imprimirArbolAux(raiz, 0);
    }
};

void leerLista(vector<vector<long long>>& lista) {
    ifstream archivo("datos.txt");
    
    if (!archivo.is_open()) {
        cout << "Error al abrir el archivo" << endl;
        return;
    }

    string input;
    while (getline(archivo, input)) {
        vector<long long> valores;
        istringstream line_stream(input);
        string fila;

        // Leer hasta el primer ':'
        getline(line_stream, fila, ':');
        if (!fila.empty()) {
            valores.push_back(stoll(fila));
        }

        long long valor;
        
        while (line_stream >> valor) {
            valores.push_back(valor);
        }

        if (!valores.empty()) {
            lista.push_back(valores);
        }
    }

    archivo.close();
}

void imprimirLista(vector<vector<long long>> lista) {
    for (int i = 0; i < lista.size(); i++) {
        for (int j = 0; j < lista[i].size(); j++) {
            if (j == 0) {
                cout << lista[i][j] << ": ";
            } else {
                cout << lista[i][j] << " ";
            }
        }
        cout << endl;
    }
}

int main() {
    vector<vector<long long>> lista;

    leerLista(lista);
    vector<ArbolBinario> arbol(lista.size());

    long long total = 0;
    
    for (int i = 0; i < lista.size(); i++) {
        
        arbol[i].insertarLista(lista[i]);
        if(arbol[i].buscarNumero(lista[i][0])) {
            total += lista[i][0];
        }
        arbol[i].imprimirArbol();
    }

    cout << "Resultado: " << total << endl;

    return 0;
}
