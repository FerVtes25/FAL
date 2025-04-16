// Fernando Vieites Moreira
// FAL-A68


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;


// función que resuelve el problema
vector <int> resolver(vector <int> v) {
    vector <int> repes(v.size(), 0);
    vector <int> sol;
    int max = 0;
    int num_iguales = 0;

    int maxRepes = 1;

    for (int i = 1; i < v.size(); i++) {
        if (v[i] == v[i - 1]) {
            num_iguales++;
            repes[i - num_iguales]++;
            if (num_iguales > max) {
                max = num_iguales;
            }
        }
        else {
            num_iguales = 0;
        }
    }

    for (int i = 0; i < v.size(); i++) {
        if (repes[i] == max) {
            sol.push_back(i);
        }
    }
    return sol;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int n;
    int max;


    cin >> n;
    cin >> max;

    if (n == -1)
        return false;

    vector <int> v(n);

    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    sort(v.begin(), v.end());

    vector <int> sol = resolver(v);

    // escribir sol
    for (int i = sol.size() - 1; i >= 0; i--) {
        cout << v[sol[i]] << " ";
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
