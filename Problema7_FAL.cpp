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
void resuelveCaso() {
    // leer los datos de la entrada
    int anho1;
    cin >> anho1;
    int anho2;
    cin >> anho2;

    int max;
    int ventas;

    cin >> max;
    for (int i = 0; i < (anho2 - anho1); i++) {
        cin >> ventas;

        if (ventas > max) {
            max = ventas;
            cout << anho1 + i + 1 << " ";
        }
    }
    //TipoSolucion sol = resolver(datos);
    // escribir sol
    cout << endl;
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