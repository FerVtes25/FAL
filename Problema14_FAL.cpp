// Fernando Vieites Moreira
// FAL-A68


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

// función que resuelve el problema
pair <int, int> resolver(vector <int> v, int t) {
    int ini = -1;
    int fin = 0;
    int aux = -1;
    int max = 0;

    for (int i = 0; i < v.size(); i++) {
        if (v[i] > t) {
            if (aux == -1) {
                aux = i;
            }
            if (i == v.size() - 1|| v[i + 1] <= t) {
                int x = i - aux + 1;

                if (x > max) {
                    max = x;
                    ini = aux;
                    fin = i;
                }
                aux = -1;
            }
        }
        else {
            aux = -1;
        }
    }

    return make_pair(ini, fin);
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int n;
    int t;

    cin >> n;
    cin >> t;

    vector <int> v(n);

    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    
    pair <int, int> sol = resolver(v, t);
    // escribir sol

    cout << sol.first << " " << sol.second << "\n";
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