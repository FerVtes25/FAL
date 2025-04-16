// Fernando Vieites Moreira
// FAL-A68


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

// función que resuelve el problema
bool todosIguales(vector <int> const& v, int p, int q) {
    for (int i = 0; i < q - p; i++) {
        if (v[p + i] != v[p + i + 1]) {
            return false;
        }
    }
    return true;
}

int resolver(vector <int> const &v, int l) {
    int p = -1;
    int q = -1;
    bool iguales = false;
    int k = 0;

    for (int i = 1; i < v.size(); i++) {
        if (v[i] == v[i - 1] && iguales == false) {
            p = i;
        }
        else if (v[i] != v[i - 1] && iguales == true) {
            q = i;
            
        }
    }

    return k;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int l, n;

    cin >> l >> n;

    vector <int> v(n);

    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    int sol = resolver(v, l);
    
    cout << sol << "\n";
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