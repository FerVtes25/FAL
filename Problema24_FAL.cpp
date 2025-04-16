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
    long long int numPags;
    long long int x;
    int suma = 0;
    int max = 0;
    int pag;
    int maxPunt = 0;
    int j = 0;

    cin >> numPags;
    cin >> x;

    if (numPags == 0 && x == 0)
        return false;

    vector <int> v(numPags);

    for (int i = 0; i < numPags; i++) {
        cin >> v[i];
        if (v[i] > maxPunt) {
            maxPunt = v[i];
        }
    }

    for (int i = 0; i < x; i++) {
        suma += v[i];
        if (v[i] == maxPunt) {
            j = x;
        } 
        j--;
    }

    if (j > 0) {
        pag = 0;
        max = suma;
    }

    for (int i = x; i < numPags; i++) {
        suma += v[i];
        suma -= v[i - x];

        if (v[i] == maxPunt) {
            j = x;
        }

        if (suma >= max && j > 0) {
            max = suma;
            pag = i - x + 1;
        }
        j--;
    }

    cout << pag << "\n";

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
