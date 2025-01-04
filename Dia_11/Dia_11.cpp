#include <iostream>
#include <cstdlib>
#include <cmath>
#include <sstream>
#include <string>
#include <list>

using namespace std;

void leer_lista(list<long long>& lista){
    string input;
    cout << "Introduce la lista de piedras:" << endl;

    getline(cin, input);
    istringstream line_stream(input);
    int numero;
        
    while(line_stream >> numero){
        lista.push_back(numero);
    }
    
}

void print(list<long long> lista){
    list<long long>::iterator it = lista.begin(); //creamos un iterador para que apunte a un elemento de la lista
    
    for (it = lista.begin(); it != lista.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;
}

int contarCifras(long long numero) {
    if(numero == 0){
        return 1;
    }

    int cifras = 0;
    while(numero > 0){
        numero /= 10;
        cifras++;
    }
    return cifras;
}

int blink(list<long long>& stones, int n){
    if(n <= 0){
        return stones.size();
    }

    list<long long>::iterator it = stones.begin();
    for(it; it != stones.end(); advance(it, 1)){
        if(*it == 0){
            *it = 1;
        }else if(contarCifras(*it) % 2 == 0){
            int mitad_sup = (*it / pow(10, contarCifras(*it)/2));
            int mitad_inf = *it - (mitad_sup * pow(10, contarCifras(*it)/2));
            *it = mitad_inf;
            stones.insert(it, mitad_sup);
        }else{
            *it *= 2024;
        }
    }
    print(stones);
    return blink(stones, n - 1);
}

int main(){

    list<long long> stones;

    leer_lista(stones);
    //print(stones);

    cout << blink(stones, 25) << endl;

    return 0;
}