// Fernando Vieites Moreira
// FAL-A68


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

// función que resuelve el problema
bool esSolucion(const vector <vector <int>>& matriz, const int precioFinal, const int precioActual, const int k) {
    if (k < matriz[0].size() - 1) {
        return false;
    }
    return true;
}

bool esValido(const vector <int>& productos_super, const int precioFinal, const int precioActual, const int i) {
    if (precioActual >= precioFinal && precioFinal != -1) {
        return false;
    }
    if (productos_super[i] > 3) {
        return false;
    }
    return true;
}

void vueltaAtras(int k, const vector<vector<int>>& matriz, vector <int> & productos_super, int & precioFinal, int & precioActual) {

    for (int i = 0; i < matriz.size(); i++) {

        precioActual += matriz[i][k];
        productos_super[i]++;

        if (esValido(productos_super, precioFinal, precioActual, i)) {
            if (esSolucion(matriz, precioFinal, precioActual, k)) {
                precioFinal = precioActual;
            }
            else {
                if (k + 1 < matriz[i].size()) {
                    vueltaAtras(k + 1, matriz, productos_super, precioFinal, precioActual);
                }
            }
        }
        precioActual -= matriz[i][k];
        productos_super[i]--;
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int supermercados, productos;

    cin >> supermercados >> productos;

    vector <int> productos_super(supermercados, 0);
    vector <vector<int>> matriz(supermercados, vector<int>(productos));

    for (int i = 0; i < supermercados; i++) {
        for (int j = 0; j < productos; j++) {
            cin >> matriz[i][j];
        } 
    }

    int precioFinal = -1;
    int precioActual = 0;
    
    vueltaAtras(0, matriz, productos_super, precioFinal, precioActual);

    cout << precioFinal << "\n";
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