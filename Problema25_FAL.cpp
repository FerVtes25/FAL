// Fernando Vieites Moreira
// FAL-A68


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

// función que resuelve el problema
/*
TipoSolucion resolver(TipoDatos datos) {


}*/

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int long long n;
    int long long k;
    int izq = 0;
    int der = 0;
    int sol = 0;
    

    cin >> n;

    if (n == 0)
        return false;

    cin >> k;

    vector <int> v(n);
    vector <int> pos(n);

    for (int i = 0; i < n; i++) {
        cin >> v[i];
        if (i == 0) {
            if (v[i] >= 0) {
                pos[i] = 1;
            }
            else {
                pos[i] = 0;
            }
        }
        else {
            if (v[i] > 0) {
                pos[i] = pos[i - 1] + 1;
            }
            else {
                pos[i] = pos[i - 1];
            }
        }
    }

    for (int i = k - 1; i < n; i++) {
        
        if (i - k >= 0) {
            if ((pos[i] - pos[i - (k / 2)]) <= (pos[i - (k / 2)] - pos[i - k])) {
                sol++;
            }
        }
        else {
            if ((pos[i] - pos[i - (k/2)]) <= pos[i - (k / 2)]) {
                sol++;
            }
        }
    }

    cout << sol << "\n";

    //TipoSolucion sol = resolver(datos);

    // escribir sol

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
