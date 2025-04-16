// Fernando Vieites Moreira
// FAL-A68


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;


// función que resuelve el problema
void resolver(int n, int nivel, const string& letras, string palabra) {

    if (nivel == n) {
        cout << palabra << "\n";
        return;
    }

    for (char letra : letras) {
        resolver(n, nivel + 1, letras, palabra + letra);
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int m, n;

    cin >> m >> n;

    if (!std::cin)
        return false;

    string letras = "";

    for (int i = 0; i < m; i++) {
        letras += (char)('a' + i);
    }

    resolver(n, 0, letras, "");

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