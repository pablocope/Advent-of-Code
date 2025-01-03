#include <iostream>
#include <cstdlib>
#include <cmath>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

void leer_lista(vector<int>& v){
    string input;
    cout << "Introduce la lista de piedras:" << endl;

    getline(cin, input);
    istringstream line_stream(input);
    int numero;
        
    while(line_stream >> numero){
        v.push_back(numero);
    }
    
}

void print(vector<int> v){
    for(int i = 0; i < v.size(); i++){
        cout << v[i] << endl;
    }
    cout << endl;
}

int main(){

    vector<int> stones;

    leer_lista(stones);
    print(stones);

    return 0;
}