// Fernando Vieites Moreira
// FAL-A68


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

/*
// función que resuelve el problema
int resolver(vector<int> datos) {


}*/

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int anho1;
    int anho2;
    int x;
    cin >> anho1;
    cin >> anho2;
    int anho3;
    int anho4;
    long long int sol;

    if (anho1 == 0 && anho2 == 0)
        return false;

    //cin >> anho2;

    vector <long long int> v (anho2 - anho1 + 1); 
    cin >> v[0];

    for (int i = 1; i <= anho2 - anho1; i++) {
        int y;
        cin >> y;
        v[i] = v[i - 1] + y;
    }

    cin >> x;

    for (int i = 0; i < x; i++) {
        cin >> anho3;
        cin >> anho4;

        int z = anho4 - anho1;
        int p = anho3 - anho1;

        if (p > 0) {
            sol = v[z] - v[p - 1];
        }
        else {
            sol = v[z];
        }
        cout << sol << "\n";
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