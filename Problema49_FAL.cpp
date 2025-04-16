// Fernando Vieites Moreira
// FAL-A68


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

// función que resuelve el problema
bool resolver(vector <int> v, int ini, int fin, int & maximo, int & minimo) {

    if (ini + 1 == fin) {
        maximo = minimo = v[ini];
        return true;
    }

    int mitad = (ini + fin) / 2;
    int maxIzq, maxDer, minIzq, minDer;

    bool izq = resolver(v, ini, mitad, maxIzq, minIzq);

    if (izq == false) return false;

    bool der = resolver(v, mitad, fin, maxDer, minDer);

    maximo = max(maxIzq, maxDer);
    minimo = min(minIzq, minDer);

    if (maxIzq > maxDer || minIzq > minDer || der == false) return false;

    return true;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    
    int n;

    cin >> n;

    if (n == 0)
        return false;

    vector <int> v;

    while (n != 0) {
        v.push_back(n);
        cin >> n;
    }

    int min = -1;
    int max = -1;

    bool sol = resolver(v, 0, v.size(), max, min);

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
