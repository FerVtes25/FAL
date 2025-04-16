// Fernando Vieites Moreira
// FAL-A68


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

// función que resuelve el problema
bool hiperminimalista(const vector <int> v, int ini, int fin) {
    if (ini == fin) {
        return true;
    }

    int minimo = v[ini];
    int num_minimos = 1;
    int indice_minimo = ini;

    for (int i = ini + 1; i <= fin; i++) {
        if (v[i] < minimo) {
            minimo = v[i];
            num_minimos = 1;
            indice_minimo = i;
        }
        else if (v[i] == minimo) {
            num_minimos++;
        }
    }
    if (num_minimos > 1) {
        return false;
    }
    
    if (indice_minimo > ini) {
        hiperminimalista(v, ini, indice_minimo - 1);
    }
    if (indice_minimo < fin) {
        hiperminimalista(v, indice_minimo + 1, fin);
    }

    return true;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int n;

    cin >> n;

    if (n == -1)
        return false;

    vector <int> v(n);

    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    bool sol = hiperminimalista(v, 0, v.size() - 1);

    if (sol == true) {
        cout << "SI\n";
    }
    else {
        cout << "NO\n";
    }

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
