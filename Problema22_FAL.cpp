// Fernando Vieites Moreira
// FAL-A68


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;


// función que resuelve el problema

int kemparejados(vector<int> v, int n, int k) {
    int sol = 0;
    int i = 0;
    int j = 1;

    if (k == 0) {
        sol = n;
    }
    else {
        
        while (j < n) {
            int x = abs(v[i] - v[j]);
            if (x == k) {
                sol++;
                i++;
                j++;
            }
            else if (x < k) {
                j++;
            }
            else {
                i++;
                if (i == j) {
                    j++;
                }
            }
        }
    }
    return sol;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int numElems;
    int k;
    cin >> numElems;

    if (numElems == -1)
        return false;

    vector <int> v(numElems);
    cin >> k;

    for (int i = 0; i < numElems; i++) {
        cin >> v[i];
    }

    sort(v.begin(), v.end());

    int sol = kemparejados(v, numElems, k);

    cout << sol << endl;

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
