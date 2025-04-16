// Fernando Vieites Moreira
// FAL-A68


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

// función que resuelve el problema
bool esValida(vector <int> & torre) {
    for (int i = 1; i < torre.size(); i++) {
        if (torre[i] == 2 && torre[i - 1] == 2) {
            return false;
        }
    }
    return true;
}

void resolver(int k, int altura, vector <int>& torre) {
    if (k == altura) {
        if (esValida(torre)) {
            for (int i = 0; i < altura; i++) {
                if (torre[i] == 0) {
                    cout << "azul" << " ";
                }
                else if (torre[i] == 1) {
                    cout << "rojo" << " ";
                }
                else {
                    cout << "verde" << " ";
                }
            }
        }  
        cout << "\n";
    }
    else {
        for (int i = 0; i < 3; i++) {
            torre.push_back(i);

            resolver(k + 1, altura, torre);
            torre.resize(torre.size() - 1);
        }
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int n;

    cin >> n;

    if (n == 0)
        return false;

    vector <int> torre;
    if (n > 0) {
        torre.push_back(1);
    }

    resolver(1, n, torre);

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
