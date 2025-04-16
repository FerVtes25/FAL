// Fernando Vieites Moreira
// FAL-A68


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

// función que resuelve el problema
bool resolver(vector <int> const& v, int c) {
    int i = 0;
    int j = 0;
    bool tramo = false;
    int suma = 0;

    while (i < v.size() && tramo != true) {
        suma += v[j];

        if (suma == c) {
            tramo = true;
        }
        else if (v[j] > c) {
            j++;
            i = j;
            suma = 0;
        }
        else if ((suma < c && j + 1 == v.size())) {
            i++;
            j = i;
            suma = 0;
        }
        else if (suma < c) {
            j++;
        }
        else {
            i++;
            j = i;
            suma = 0;
        }
    }
    return tramo;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int n;
    int c;
    cin >> n;

    if (n == -1)
        return false;

    vector <int> v(n);

    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    cin >> c;

    if (resolver(v, c) == true) {
        cout << "SI" << "\n";
    }
    else {
        cout << "NO" << "\n";
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
