// Fernando Vieites Moreira
// FAL-A68

/*
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

// función que resuelve el problema

bool esValido(const vector <int>& productos_super, const int precioFinal, const int precioActual, const int i) {
    if (precioActual >= precioFinal && precioFinal != -1) {
        return false;
    }
    if (productos_super[i] > 3) {
        return false;
    }
    return true;
}

void vueltaAtras(int k, const vector<vector<int>>& matriz, vector <int>& productos_super, int& precioFinal, int& precioActual) {

    for (int i = 0; i < matriz.size(); i++) {

        precioActual += matriz[i][k];
        productos_super[i]++;

        if (esValido(productos_super, precioFinal, precioActual, i)) {
            if (k >= matriz[0].size() - 1) {
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
    //std::ifstream in("datos.txt");
    //auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 


    int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();


    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
   // std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

void compraDeLaSemana(const vector<vector<int>>& datos, vector <int>& productosPorSupermercado, vector<int>& sol, int n, int k, int& costeActual, int& mejorCoste, vector <int>& mejorSol) {
    for (int supermercado = 0; supermercado < n; supermercado++)
    {
        if (productosPorSupermercado[supermercado] < 3) {
            sol[k] = datos[supermercado][k];
            productosPorSupermercado[supermercado]++;
            costeActual += datos[supermercado][k];

            if (k == sol.size() - 1) {
                if (costeActual < mejorCoste) {
                    mejorSol = sol;
                    mejorCoste = costeActual;
                }

            }
            else compraDeLaSemana(datos, productosPorSupermercado, sol, n, k + 1, costeActual, mejorCoste, mejorSol);
            productosPorSupermercado[supermercado]--;
            costeActual -= datos[supermercado][k];
        }
    }


}




void resuelveCaso() {
    int supermercados, productos; //n supermercados y m productos
    //no puede comprar mas de 3 productos en cada supermercado
    cin >> supermercados >> productos;
    vector<vector<int>> datos(supermercados, vector<int>(productos));
    vector <int> productosPorSupermercado(supermercados, 0);
    vector<int> sol(productos, 0); //para almacenar el precio de cada producto
    vector<int> mejorSol(productos, 0);
    for (int i = 0; i < supermercados; i++) {
        for (int j = 0; j < productos; j++) {
            cin >> datos[i][j];
        }
    }
    int costeActual = 0, mejorCoste = INT_MAX;

    compraDeLaSemana(datos, productosPorSupermercado, sol, supermercados, 0, costeActual, mejorCoste, mejorSol);
    if (mejorCoste == INT_MAX) cout << "Sin solucion factible\n";
    else cout << mejorCoste << '\n';
}

int main() {
#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif
    int nCasos;
    cin >> nCasos;
    for (int i = 0; i < nCasos; i++)
    {
        resuelveCaso();
    }

#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
#endif

    return 0;
}
