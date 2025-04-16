// Fernando Vieites Moreira
// FAL-A68


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

// función que resuelve el problema

void vueltaAtras (int k, const vector <vector <int>>& matriz, vector <int> & actual, int & satisfaccion, int & solucion, vector <bool>& marcador, int niños, int juguetes) {

    for (int i = 0; i < juguetes; i++) {

        if (!marcador[i]) {
            marcador[i] = true;
            satisfaccion += matriz[k][i];
            actual[k] = i;

            if (k == niños - 1) {
                solucion = max(satisfaccion, solucion);
            }
            else {
                vueltaAtras(k + 1, matriz, actual, satisfaccion, solucion, marcador, niños, juguetes);
            }

            marcador[i] = false;
            satisfaccion -= matriz[k][i];
        }
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int juguetes;

    cin >> juguetes;

    if (!std::cin)
        return false;

    int niños;
    cin >> niños;

    vector <vector <int>> matriz(niños, vector<int>(juguetes));
    vector <int> actual(niños);
    int satisfaccion = 0;
    int solucion = -1;
    vector <bool> marcador(juguetes, false);

    for (int i = 0; i < niños; i++) {
        int max_fila = -1;
        for (int j = 0; j < juguetes; j++) {
            cin >> matriz[i][j];
        }
    }

    vueltaAtras(0, matriz, actual, satisfaccion, solucion, marcador, niños, juguetes);

    cout << solucion << "\n";

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