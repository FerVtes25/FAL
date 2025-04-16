// Fernando Vieites Moreira
// FAL-A68


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

// función que resuelve el problema
bool todosConsecutivos(vector <int> const& v, int p, int q) {
    bool ok = true;

    for (int i = p + 1; i < q; i++) {
        if (!(v[i] == v[i - 1] - 1 || v[i] == v[i - 1] + 1)) {
            return false;
        }
    }
    return true;
}

int resolver(vector <int> const &v) {
    int k = 0;
    int p = 0;
    int i = 2;
    int tamanho = v.size() - 1;

    while (p < tamanho) {
        if (todosConsecutivos(v, p, p + i)) {
            k++;
            i++;

            if (i + p >= v.size() + 1 || p >= tamanho - 1) {
                p++;
                i = 2;
            }
        }
        else {
            p ++;
            i = 2;
        }
    }
    return k;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int n;

    cin >> n;
    
    vector <int> v(n);

    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    if (n == 0) {
        cout << "0" << "\n";
    }
    else {
        cout << resolver(v) << "\n";
    }
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