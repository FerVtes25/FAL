// Fernando Vieites Moreira
// FAL-A68


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

// función que resuelve el problema
void resolver(int k, int altura, vector <vector<int>> &soluciones, int indiceSol, vector <int> & torre) {
    for (int i = 0; i < 3; i++) {
        torre.push_back(i);

        if (k == altura - 1) {
            for (int i = 0; i < altura; i++) {
                if (torre[i] == 0) {
                    cout << "azul" << " ";
                }
                else if (torre[i] == 1) {
                    cout << "rojo" << " ";
                }
                else{
                    cout << "verde" << " ";
                }
            }
            cout << "\n";
            
        }
        else {
            resolver(k + 1, altura, soluciones, indiceSol, torre);
        }
        torre.resize(torre.size() - 1);
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

    vector <int> colores(3);

    for (int i = 0; i < 3; i++) {
        colores[i] = i;
    }

    vector <int> torre;
    vector <vector<int>> soluciones(3 ^ n, torre);

    resolver(0, n, soluciones, 0, torre);

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
