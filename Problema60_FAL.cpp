// Fernando Vieites Moreira
// FAL-A68


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

// función que resuelve el problema
bool esValida(const int k, const vector <string>& tipos, const vector <int> sol, const int i) {

    if (k % 2 != 0) {
        if (tipos[i] == tipos[sol[k - 1]]) {
            return false;
        }
        if (i < sol[k - 1]) {
            return false;
        }
    }
    return true;
}

void vueltaAtras(int k, const vector <string>& tipos, vector <int> & sol, bool & solucion) {
    for (int i = 0; i < tipos.size(); i++) {

        sol[k] = i;

        if (esValida(k, tipos, sol, i)) {
            if (k == sol.size() - 1) {
                for (int i = 0; i < sol.size(); i++) {
                    cout << sol[i] << " ";
                }
                cout << "\n";
                solucion = true;
            }
            else {
                if (k + 1 < sol.size()) {
                    vueltaAtras(k + 1, tipos, sol, solucion);
                }
            }
        }
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada

    int m;
    cin >> m;

    if (!std::cin)
        return false;

    int n;
    cin >> n;

    vector <string> tipos(m);
    vector <int> sol(2*n);

    for (int i = 0; i < m; i++) {
        cin >> tipos[i];

    }
    bool solucion = false;

    vueltaAtras(0, tipos, sol, solucion);

    if (solucion == false) {
        cout << "SIN SOLUCION" << "\n";
    }

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