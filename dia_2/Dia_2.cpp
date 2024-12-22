/*
7 6 4 2 1
1 2 7 8 9
9 7 6 2 1
1 3 2 4 5
8 6 4 4 1
1 3 6 7 9
*/
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

        if(fila.empty()){ //Mete la fila leida en otro vector
            result.push_back(fila);
        }
        
    }
}

bool check_if_safe(vector<vector<int>>& v){
    
    for(int i = 0; i < v.size(); i++){
        if(v[i][0] >= v[i][1]){ //Comprobamos que sea orden decreciente
            for(int j = 0; j < v[i].size()-1; j++){
                if(v[i][j] < v[i][j+1]){
                    return false;
                }
                if(abs(v[i][j] - v[i][j+1]) > 3){ //Comprobamos que disfiera del siguiente en más de 3
                    return false;
                }
            }
        }else if(v[i][0] <= v[i][1]){ //Comprobamos que sea orden creciente
            for(int j = 0; j < v[i].size()-1; j++){
                if(v[i][j] > v[i][j+1]){
                    return false;
                }
                if(abs(v[i][j] - v[i][j+1]) > 3){ //Comprobamos que disfiera del siguiente en más de 3
                    return false;
                }
            }
        }
    }

    return true;
}

int main(){

    vector<vector<int>> datos;

    leer_lista(&datos);
    
    

    return 0;
}