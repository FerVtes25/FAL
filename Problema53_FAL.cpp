// Fernando Vieites Moreira
// FAL-A68


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;


// función que resuelve el problema
int resolver(const vector <int>& v, int ini, int fin, int n) {

    if (ini + 1 == fin) {
        return v[ini];
    }

    int medio = (ini + fin) / 2;
    
    int izq = resolver(v, ini, medio, n);
    int der = resolver(v, medio, fin, n);

    int resultado = -1;

    if (izq == der) {
        resultado = izq;
    }
    else {
        int contIzq = 0, contDer = 0;
        for (int i = ini; i < fin; ++i) {
            if (v[i] == izq) {
                contIzq++;
            }
            else if (v[i] == der) {
                contDer++;
            }
        }
        if (contIzq > n / 2) {
            resultado = izq;
        }
        else if (contDer > n / 2) {
            resultado = der;
        }
    }
    return resultado;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int n;

    cin >> n;

    vector <int> v;

    while (n != 0) {
        v.push_back(n);
        cin >> n;
    }

    if (v.size() == 0) {
        cout << "NO" << '\n';
        return;
    }
    sort(v.begin(), v.end());
    int sol = -1;

    sol = resolver(v, 0, v.size(), v.size());
    
    if (sol == -1) {
        cout << "NO" << "\n";
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