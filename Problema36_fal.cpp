// Fernando Vieites Moreira
// FAL-A68

#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

// función que resuelve el problema
string resolver(int n) {
    if (n / 2 > 0) {
        int x = (n % 2);
        if (x == 0) {
            return resolver(n / 2) + "0";
        }
        else {
            return resolver(n / 2) + "1";
        }
        
    }
    else {
        if (n == 0) {
            return "0";
        }
        else {
            return "1";
        }
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int n;

    cin >> n;
    
    cout << resolver(n) << "\n";
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