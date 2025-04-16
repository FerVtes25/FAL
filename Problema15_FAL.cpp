// Fernando Vieites Moreira
// FAL-68


#include <iostream>
#include <iomanip>
#include <fstream>
#include <algorithm>
#include <vector>

using namespace std;


// función que resuelve el problema
void resolver(vector <int> &datos) {
    int x = 1;
    for (int i = 1; i < datos.size(); i++) {
        if (datos[i] != datos[i - 1]) {
            datos[x] = datos[i];
            x++;
        }
    }
    datos.resize(x);
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada

    int numElems;
    cin >> numElems;

    if (!cin) {
        return false;
    }
        

    vector <int> v;

    for (int i = 0; i < numElems; i++) {
        int x;
        cin >> x;
        v.push_back(x);
    }
    sort(v.begin(), v.end());

    resolver(v);

    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;


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