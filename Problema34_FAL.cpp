// Fernando Vieites Moreira
// FAL-A68


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

// función que resuelve el problema
int sumaDigitos(int n) {
    if (n / 10 > 0) {
        return sumaDigitos(n / 10) + (n % 10);
    }
    else {
        return n;
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int n;
    int num;

    cin >> n;
    cin >> num;
    
    vector <int> v(n);

    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    int x = sumaDigitos(num);

    vector <int> sol;

    for (int i = 0; i < n; i++) {
        int y = sumaDigitos(v[i]);
        if (x == y) {
            sol.push_back(v[i]);
        }
    }
    
    for (int i = 0; i < sol.size(); i++) {
        cout << sol[i] << " ";
    }
    cout << "\n";
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