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
    int a;
    int numElems;
    int veces_minimo = 1;
    int minimo;
    long long int suma = 0;

    cin >> numElems;
    
    //vector <int> numeros;

    cin >> a;
    minimo = a;
    //numeros.push_back(a); 

    for (int i = 0; i < numElems - 1; i++) {

        cin >> a;

        if (a == minimo) {
            veces_minimo++;
        }
        else if (a < minimo) {
            suma += (minimo * veces_minimo);
            veces_minimo = 1;
            minimo = a;
        }
        else {
            suma += a;
        }
    }

   

    //TipoSolucion sol = resolver(datos);
    // escribir sol

    cout << suma << " " << numElems - veces_minimo << endl;
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