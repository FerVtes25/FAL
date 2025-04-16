// Fernando Vieites Moreira
// FAL-A68


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

// función que resuelve el problema
bool resolver(vector <int> v, int ini, int fin) {
    if (ini + 1 == fin) {
        return true;
    }

    int mitad = (ini + fin) / 2;
    int paresIzq = 0;
    int paresDer = 0;

    for (int i = 0; i < mitad - i; i++) {
        if (v[i] % 2 == 0) paresIzq++;
        if (v[mitad + i] % 2 == 0) paresDer++;
    }

    if (abs(paresIzq - paresDer) > 2) return false;

    return (resolver(v, ini, mitad) && resolver(v, mitad, fin));
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int n;

    cin >> n;

    if (n == 0)
        return false;

    vector <int> v(n);

    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    bool sol = resolver(v, 0, v.size());

    if (sol == true) {
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
