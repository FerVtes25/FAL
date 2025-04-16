// Fernando Vieites Moreira
// FAL-A68


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

// función que resuelve el problema
pair <int, int> resolver(const vector <int> v1, const vector <int> v2, int ini, int fin) {

    if (ini == fin) {
        return make_pair(v1[ini], v2[ini]);
    }

    int mitad = (ini + fin) / 2;

    if (v1[mitad] == v2[mitad]) {
        return make_pair(v1[mitad], v2[mitad]);
    }
    if (mitad != 0) {
        if (v1[mitad - 1] < v2[mitad - 1] && v1[mitad] > v2[mitad]) {
            return make_pair(v1[mitad - 1], v1[mitad]);
        }
    }

    pair <int, int> izq = resolver(v1, v2, ini, mitad);
    if (ini == mitad && izq.first == izq.second){
        return izq;
    }
    else if (ini != fin) {
        return izq;
    }

    pair <int, int> der = resolver(v1, v2, mitad, fin);
    if (ini == mitad && der.first == der.second) {
        return der;
    }
    else if (ini != fin) {
        return der;
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int n;

    cin >> n;

    if (n == 0)
        return false;

    vector <int> v1(n);
    vector <int> v2(n);

    for (int i = 0; i < n; i++) {
        cin >> v1[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> v2[i];
    }

    pair <int, int> sol = resolver(v1, v2, 0, v1.size());

    if (sol.first == sol.second) {
        cout << "HABLAN " << sol.first << "\n";
    }
    else {
        cout << "SE CRUZAN " << sol.first << " " << sol.second << "\n";
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
