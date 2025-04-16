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

    bool sol = true;
    int max_rep;
    int num_elems;
    cin >> max_rep;
    cin >> num_elems;
    int reps = 1;
 

    vector <int> v(num_elems);

    for (int i = 0; i < num_elems; i++) {
        cin >> v[i];
    }

    int i = 1;
    while (i < num_elems && sol) {
        if (v[i] == v[i - 1]) {
            reps++;
            if (reps > max_rep) {
                sol = false;
            }
        }
        else if (v[i] - v[i - 1] == 1) {
            reps = 1;
        }
        else {
            sol = false;
        }
        
        i++;
    }
    /*
    while (j != num_elems) {
        if (v[i] == v[j]) {
            j++;
            reps++;
            if (reps > max_rep) {
                sol = false;
            }
        }
        else {
            i++;
            reps = 0;
        }
        
    }*/
    
    //TipoSolucion sol = resolver(datos);
    // escribir sol
    if (sol == false) {
        cout << "No" << endl;
    }
    else {
        cout << "Si" << endl;
    }

}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("casos.txt");
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