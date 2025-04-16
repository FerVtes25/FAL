// Fernando Vieites Moreira
//  FAL-A68


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

// función que resuelve el problema
bool noMasDeDos(vector <int> const& v, int p, int q) {
    int k = 1;

    for (int i = p + 1; i < q; i++) {
        if (v[i] > v[i - 1]) {
            k++;
            if (k >= 3) {
                return false;
            }
        }
        else {
            k = 1;
        }
    }

    return true;
}

int resolver(vector <int> const &v, int k) {
    int h = 0;

    for (int i = k - 1; i < v.size(); i++) {
        if (noMasDeDos(v, i - k + 1, i + 1) == true) {
            h++;
        }
    }
    return h;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int n, k;

    cin >> n;
    if (n == 0)
        return false;

    cin >> k;

    vector <int> v(n);

    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    int sol = resolver(v, k);

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
