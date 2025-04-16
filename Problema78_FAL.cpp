// Fernando Vieites Moreira
// FAL-A68


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

// función que resuelve el problema
void resolver(const vector <int> v1, const vector <int> v2, int ini, int fin, int & sol) {
    if (ini + 1 == fin) {
        sol = v2[ini];
        return;
    }


    int mitad = (ini + fin) / 2;

    if (v1[mitad - 1] == v2[mitad - 1]) {
        resolver(v1, v2, mitad, fin, sol);
    }
    else {
        resolver(v1, v2, ini, mitad, sol);
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada

    int n;

    cin >> n;

    if (n == -1)
        return false;

    vector <int> v1(n);
    vector <int> v2(n + 1);
    bool encontrado = false;

    for (int i = 0; i < n; i++) {
        cin >> v1[i];
    }
    for (int i = 0; i < n + 1; i++) {
        cin >> v2[i];
    }

    int sol = -1;

    resolver(v1, v2, 0, v2.size(), sol);

    cout << sol << "\n";

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
