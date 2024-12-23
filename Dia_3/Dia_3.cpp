#include <iostream>
#include <cstdlib>
#include <cmath>
#include <sstream>
#include <string>
#include <vector>
#include <regex>

using namespace std;

string leer_lista(){
    
    stringstream input;

    cout << "Introduce la memoria corrupta:" << endl;

    string frase;

    while (getline(cin, frase) && !frase.empty()) {
        input << frase;
    }

    return input.str();

}


int main() {
    
    string corrupted_memory;

    corrupted_memory = leer_lista();

    //cout << corrupted_memory<< endl;  //para comprobar que ha leido correctamente el código

    /*
    Patrón para comparar: 
    - R"" indica que la cadena de texto es tal cual (no se interpretan caracteres como \n)
    - cada vez que hay una "\(" significa que busca el paréntesis escrito
    - "(\d{1,3})" el paréntesis marca que es un subgrupo, la \d representa cualquier dígito del 0-9 y {1,3} son las cifras del número
    */
    regex patron(R"(mul\((\d{1,3}),(\d{1,3})\))"); //El patron para comparar queda de esta forma
    
    smatch matches;

    int suma = 0;

    string::const_iterator search_start = corrupted_memory.cbegin();

    while (regex_search(search_start, corrupted_memory.cend(), matches, patron)) {
        // Extraemos los dos numeros de la multiplicacion
        //matches[0] almacena la coincidencia completa, matches[1] almacena el primer subgrupo delimitado por parentesis del patron, y así sucesivamente
        int x = stoi(matches[1]);
        int y = stoi(matches[2]);

        suma += x * y;

        //cambiamos la posición por la que empieza a buscar
        search_start = matches.suffix().first;
    }

    cout << suma << endl;

    return 0;
}
