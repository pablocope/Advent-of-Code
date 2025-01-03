#include <iostream>
#include <cstdlib>
#include <cmath>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

//DIA 2 del ADVENT OF CODE

//modificamos parte de la función de leer lista del día 1

//Función para leer la lista y almacenar los valores en un vector que a su vez está almacenado en otro vector que es el que almacena filas
void leer_lista(vector<vector<int>>& result){
    string input;
    cout << "Introduce la lista:" << endl;

    while (getline(cin, input) && !input.empty()) {
        vector<int> fila;
        stringstream ss(input);
        int n;

        while (ss >> n){ //Pone cada número en un vector
            fila.push_back(n);
        }

        if(!fila.empty()){ //Mete la fila leida en otro vector
            result.push_back(fila);
        }
        
    }
}

int check_safe(vector<vector<int>> v){
    bool report_safe = true;
    int safe = 0;
    int n = 0; //Para saber cuantos de los primeros numeros del report son iguales

    for(int i = 0; i < v.size(); i++){

        n = 0;
        int errores = 0;
        
        while((v[i][n] == v[i][n+1]) && (n < v.size()-1)){
            n++;
        }

        if(v[i][n] > v[i][n+1]){ //Comprobamos que sea orden decreciente
            for(int j = 0; j < v[i].size()-1; j++){
                if(v[i][j] <= v[i][j+1]){
                    errores++;
                }else if(abs(v[i][j] - v[i][j+1]) > 3){ //Comprobamos que disfiera del siguiente en más de 3
                    errores++;
                }else{
                    report_safe = true;
                }
            }
            if(errores > 1){
                report_safe = false;
            }

        }else if(v[i][n] < v[i][n+1]){ //Comprobamos que sea orden creciente
            for(int j = 0; j < v[i].size()-1; j++){
                if(v[i][j] >= v[i][j+1]){
                    errores++;
                }else if(abs(v[i][j] - v[i][j+1]) > 3){ //Comprobamos que disfiera del siguiente en más de 3
                    errores++;
                }else{
                    report_safe = true;
                }
            }
            if(errores > 1){
                report_safe = false;
            }
        }

        if(report_safe == true){
            safe++;
        }
    }

    return safe;
}

int main(){

    vector<vector<int>> datos;

    leer_lista(datos);

    cout << datos.size() << endl;

    cout << check_safe(datos) << " reportes son seguros." << endl;

    return 0;
}