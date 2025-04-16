// Fernando Vieites Moreira
// FAL-A68


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

// función que resuelve el problema
void vueltaAtras(const vector <vector <int>>& m, vector <int> & ruta, int & precioFinal, int & precioActual, int k, vector <bool> & marcador) {
    for (int i = 1; i < m.size(); i++) {
        if (!marcador[i]) {
            marcador[i] = true;
            ruta[k] = i;
            precioActual += m[k][i];

            if (k == m.size() - 1) {
                if (precioActual < precioFinal || precioFinal == -1) {
                    precioFinal = precioActual;
                }
            }
            else {
                vueltaAtras(m, ruta, precioFinal, precioActual, k + 1, marcador);
            }
            marcador[i] = false;
            precioActual -= m[k][i];
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

    vector <vector <int>> m(n, vector<int>(n));
    vector <int> ruta(n, -1);
    vector <bool> marcador(n, false);
    int precioFinal = -1;
    int precioTotal = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> m[i][j];
        }
    }

    vueltaAtras(m, ruta, precioFinal, precioTotal, 0, marcador);

    cout << precioFinal << "\n";

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
