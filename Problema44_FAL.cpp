// Fernando Vieites Moreira
// FAL-A68


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

int resolver(int a, const vector<int>& valores, int i) {
    if (i >= valores.size()) {
        return -1;
    }
    if ((valores[i] - i) - a == 0) {
        return valores[i];
    }
    return resolver(a, valores, i + 1);
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int n;
    int x;

    cin >> n;
    cin >> x;
    
    vector <int> v(n);

    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    int sol = resolver(x, v, 0);
    
    if (sol == -1) {
        cout << "NO\n";
    }
    else {
        cout << sol << "\n";
    }
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