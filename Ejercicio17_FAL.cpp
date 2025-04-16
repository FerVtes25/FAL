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
    int n;
    int total = 0;
    cin >> n;

    if (n == -1)
        return false;

    vector <int> valores(n);
    vector <int> v(n);
    if (n > 0) {
        cin >> valores[0];
        total += valores[0];
    }
    
    for (int i = 1; i < n; i++) {
        cin >> valores[i];
        total += valores[i];
        valores[i] += valores[i - 1];
    }

    v[0] = total;
    for (int i = 1; i < n; i++) {
        v[i] = total - valores[i - 1];
    }

    int P;
    cin >> P;
    vector <int> dias(P);
    for (int i = 0; i < P; i++) {
        cin >> dias[i];
    }

    for (int i = 0; i < P; i++) {
        if (dias[i] == n + 1) {
            cout << "0" << "\n";
        }
        else {
            cout << v[dias[i] - 1] << "\n";
        }
    }

    cout << "---" << "\n";

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
