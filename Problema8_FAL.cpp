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
void resuelveCaso() {
    // leer los datos de la entrada
    bool sol = false;
    int x = -1;
    int elems;
    int suma = 0;
    cin >> elems;
    vector<int> vector(elems);


    
    for (int i = 0; i < elems; i++) {
        cin >> vector[i];
    }
    if (elems > 0) {
        suma = vector[elems - 1];
        if (vector[elems - 1] == 0) {
            sol = true;
            x = elems - 1;
        }
        for (int i = elems - 1; i > 0; i--) {
            if (vector[i - 1] == suma && sol == false) {
                sol = true;
                x = i - 1;
            }
            suma += vector[i - 1];
        }
    }
    

    if (sol == true) {
        cout << "Si " << x << endl;
    }
    else {
        cout << "No " << endl;
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