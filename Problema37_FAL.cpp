// Fernando Vieites Moreira
// FAL-A68


#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

// función que resuelve el problema
int complementario(int n) {
    if (n / 10 > 0) {
        return complementario(n / 10) * 10 + (9 - n % 10);
    }
    else {
        return 9 - n % 10;
    }
}

int inverso(int n, int i) {
    if (n / 10 > 0) {
        return complementario(n / 10) + (9 - n % 10) * 10^i;
    }
    else {
        return 9 - n % 10;
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    long long int n;

    cin >> n;

    int x = complementario(n);
    int i = 0;

    cout << x << " " << inverso(n, i) << "\n";
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