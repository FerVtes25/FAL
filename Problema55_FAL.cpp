// Fernando Vieites Moreira
// FAL-A68


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;


// función que resuelve el problema
void resolver(int n, int nivel, const string& letras, string palabra, vector <bool>& usado) {

    if (nivel == n) {
        cout << palabra << "\n";
        return;
    }

    for (int i = 0; i < letras.size(); i++) {
        if (!usado[i]) {
            usado[i] = true;
            resolver(n, nivel + 1, letras, palabra + letras[i], usado);
            usado[i] = false;
        }
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

    vector <bool> usado(m, false);

    resolver(n, 0, letras, "", usado);

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