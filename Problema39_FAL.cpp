// Fernando Vieites Moreira
// FAL-A68


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

// función que resuelve el problema
int buscarIzq(vector<int> v, int h) {
    for (int i = 0; i < v.size(); i++) {
        if (v[i] == h) {
            return i;
        }
    }
    return -1;
}

int buscarDer(vector<int> v, int h) {
    for (int i = v.size() - 1; i >= 0; i--) {
        if (v[i] == h) {
            return i;
        }
    }
    return -1;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int n;
    cin >> n;

    if (!std::cin)
        return false;

    int h;
    cin >> h;

    vector <int> v(n);

    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    int x = buscarIzq(v, h);
    int y = buscarDer(v, h);

    if (x == -1) {
        cout << "NO EXISTE" << "\n";
    }
    else if (x == y) {
        cout << x << "\n";
    }
    else {
        cout << x << " " << y << "\n";
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