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
bool resuelveCaso() {
    // leer los datos de la entrada
    int N;
    cin >> N;
    
    if (N == -1)
        return false;

    vector <bool> a(N);
    int x;
    int K;
    int j = 0;
    int z = 0;

    cin >> K;
    
    for (int i = 0; i < N; i++) {
        cin >> x;
        if (x == 0) {
            a[i] = false;
        }
        else {
            a[i] = true;
            j++;
        }
    }
    vector <int> v(j - K + 1);

    for (int i = 0; i < j - K + 1; i++) {
        v[i] = - i;
    }

    for (int i = 0; i < N; i++) {
        if (a[i] == true) {
            
        }
    }
    

    cin >> K;

    for (int i = 0; i < N; i++) {

    }

    //TipoSolucion sol = resolver(datos);

    // escribir sol


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