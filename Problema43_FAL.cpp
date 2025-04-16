// Fernando Vieites Moreira
// FAL-A68


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

// función que resuelve el problema
char resolver(vector <char> v, int ini, int fin, char x1) {
    if (ini == fin) {
        return (v[fin] == x1 + fin) ? x1 + fin + 1 : x1 + fin;
    }

    int medio = (ini + fin) / 2;

    if (v[medio] == x1 + medio) {
        return resolver(v, medio + 1, fin, x1);
    }
    else {
        return resolver(v, ini, medio, x1);
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    char x1, x2;

    cin >> x1 >> x2;

    int n = x2 - x1;

    vector <char> v(n);

    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    
    char sol = resolver(v, 0, n - 1, x1);
    
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