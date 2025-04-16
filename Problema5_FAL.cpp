// Fernando Vieites Moreira
// FAL-A68

#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

// función que resuelve el problema
/*
TipoSolucion resolver(TipoDatos datos) {


}*/

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int D;
    cin >> D;

    if (!std::cin)
        return false;

    int N;
    cin >> N;

    int pala1;
    int pala2;
    int desnivel = 0;
    bool apto = true;
    cin >> pala1;

    for (int i = 0; i < N - 1; i++) {
        cin >> pala2;

        if (pala2 > pala1) {
            desnivel += (pala2 - pala1);
            if (desnivel > D) {
                apto = false;
            }
        }
        else {
            desnivel = 0;
        }
        pala1 = pala2;
    }

    if (apto == true) {
        cout << "APTA" << endl;
    }
    else {
        cout << "NO APTA" << endl;
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