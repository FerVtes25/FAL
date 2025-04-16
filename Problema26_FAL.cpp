// Fernando Vieites Moreira
// FAL-A68


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

// función que resuelve el problema
vector <int> resolver(vector<int> &v, int l) {
    int num_seguidos = 1;
    int max_secuencia = 1;
    int max_altura = 0;
    vector <int> sol;
    
    for (int i = v.size() - 2; i >= 0; i--) {
        if (v[i] == v[i + 1]) {
            num_seguidos++;
        }
        else {
            num_seguidos = 1;
        }
        if (num_seguidos == l && v[i] >= max_altura) {
            sol.push_back(i + num_seguidos - 1);
        }
        if (num_seguidos > max_secuencia && v[i] >= max_altura) {
            max_secuencia = num_seguidos;
        }
        if (v[i] > max_altura) {
            max_altura = v[i];
        }
    }
    sol.push_back(max_secuencia);

    return sol;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int n;
    int l;

    cin >> n >> l;

    if (!std::cin)
        return false;

    vector <int> v(n);

    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    vector <int> sol = resolver(v, l);

    if (sol.size() - 1 == 0) {
        cout << "0 0";
    }
    else {
        cout << sol[sol.size() - 1] << " " << sol.size() - 1 << " ";
    }
    
    for (int i = 0; i < sol.size() - 1; i++) {
        cout << sol[i] << " ";
    }
    cout << "\n";

    return true;

}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 


    while (resuelveCaso())
        ;


    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}