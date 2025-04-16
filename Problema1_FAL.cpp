// Fernando Vieites Moreira
// FAL-A68

#include <iostream>
#include <iomanip>
#include <fstream>


// Funcion que lee de la entrada, resuelve el problema y escribe la salida
void resuelveCaso() {

    int n;
    std::cin >> n;
    // Declaración de variables
    // Codigo del alumno
    int max = n;
    int num_max = 0;

    while (n != 0) {
        // Aqui codigo del alumno

        if (n > max) {
            max = n;
            num_max = 1;
        }
        else if (n == max) {
            num_max++;
        }

        std::cin >> n;
    }

    // Escribir el resultado
    // Codigo del alumno
    std::cout << max << " " << num_max << std::endl;

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
    for (int i = 0; i < numCasos; ++i) resuelveCaso();

    
    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}