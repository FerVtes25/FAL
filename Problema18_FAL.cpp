// Fernando Vieites Moreira
// FAL-A68


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

// función que resuelve el problema
vector <int> resolver(vector <int> v1, vector <int> v2) {
    vector <int > sol;
    int j = 0;
    int k = 0;

    if (v1.size() > 0 && v2.size() > 0) {
        while (j < v1.size() && k < v2.size()) {
            if (v1[j] < v2[k] && j < v1.size()) {
                sol.push_back(v1[j]);
                j++;
            }
            else if (v1[j] > v2[k] && k < v2.size()) {
                sol.push_back(v2[k]);
                k++;
            }
            else if (v1[j] == v2[k] && j < v1.size()) {
                sol.push_back(v1[j]);
                j++;
                k++;
            }
        }
        while (j < v1.size()) {
            sol.push_back(v1[j]);
            j++;
        }
        while (k < v2.size()) {
            sol.push_back(v2[k]);
            k++;
        }
    }
    else if (v1.size() == 0) {
        sol = v2;
    }
    else {
        sol = v1;
    }
    
    return sol;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int n1;
    int n2;

    cin >> n1;
    cin >> n2;

    vector <int> v1(n1);
    vector <int> v2(n2);

    for (int i = 0; i < n1; i++) {
        cin >> v1[i];
    }
    for (int i = 0; i < n2; i++) {
        cin >> v2[i];
    }

    vector <int> sol = resolver(v1, v2);
    // escribir sol

    for (int i = 0; i < sol.size(); i++) {
        cout << sol[i] << " ";
    }
    cout << "\n";
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 


    int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();


    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}