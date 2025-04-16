//Fernando Vieites Moreira
//FAL-A68


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

/*
// función que resuelve el problema
TipoSolucion resolver(TipoDatos datos) {


}*/

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int num_anhos;
    string nacion;
    cin >> num_anhos;
    int sol = num_anhos + 1;

    if (num_anhos == 0)
        return false;

    cin >> nacion;
    vector <string> v;

    for (int i = 0; i < num_anhos; i++) {
        string a;
        cin >> a;
        v.push_back(a);
    }

    for (int i = 0; i < num_anhos; i++) {
        if (v[i] == nacion) {
            sol = num_anhos - i;
        }
    }

    //TipoSolucion sol = resolver(datos);

    if (sol > num_anhos) {
        cout << "NUNCA" << endl;
    }
    else {
        cout << sol << endl;
    }

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
