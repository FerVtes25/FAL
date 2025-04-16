// Fernando Vieites Moreira
// FAL-A68


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

// función que resuelve el problema

bool resolver(vector <int> datos, int p) {
    bool ok = true;
    int mayor = datos[0];
    
    for (int i = 1; i <= p; i++) {
        if (datos[i] > mayor) {
            mayor = datos[i];
        }
    }

    for (int i = p + 1; i < datos.size(); i++) {
        if (datos[i] <= mayor) {
            ok = false;
        }
    }

    return ok;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int numElems;
    int p;
    int mayor = 0;
    
    int a;

    cin >> numElems;
    cin >> p;
    vector<int> vector;

    for (int i = 0; i < numElems ; i++) {
        cin >> a;
        vector.push_back(a);
    }

    bool sol = resolver(vector, p);
    
    if (sol == true || p == numElems - 1) {
        cout << "SI" << endl;
    }
    else {
        cout << "NO" << endl;
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