#include <iostream>
#include <cstdlib>
#include <cmath>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

void leer_lista(vector<vector<int>>& rules, vector<vector<int>>& updates){
    string input;
    cout << "Introduce la lista de reglas de ordenación y después de un salto de lines las updates (copiar tal cual el input del AoC):" << endl;

    //Leer reglas
    while (getline(cin, input) && !input.empty()) {
        vector<int> rule;
        istringstream line_stream(input);
        string fila;

        while(getline(line_stream, fila, '|')){
            rule.push_back(stoi(fila));
        }

        if(!rule.empty()){ //Mete la fila leida en otro vector
            rules.push_back(rule);
        }   
    }

    //Leer updates
    while (getline(cin, input) && !input.empty()) {
        vector<int> update;
        istringstream line_stream(input);
        string fila;

        while(getline(line_stream, fila, ',')){
            update.push_back(stoi(fila));
        }

        if(!update.empty()){ //Mete la fila leida en otro vector
            updates.push_back(update);
        }   
    }

}

int main(){

    vector<vector<int>> rules;
    vector<vector<int>> updates;

    leer_lista(rules, updates);

    for(int i = 0; i < rules.size(); i++){
        for(int j = 0; j < rules[i].size(); j++){
            cout << rules[i][j] << " ";
        }
        cout << endl;
    }

    cout << endl;

    for(int i = 0; i < updates.size(); i++){
        for(int j = 0; j < updates[i].size(); j++){
            cout << updates[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}