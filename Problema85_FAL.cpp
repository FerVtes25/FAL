// Fernando Vieites Moreira
// FAL-A68


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

// función que resuelve el problema
void resolver(int k, int num_equipos, int num_proyectos, const vector <vector<int>> & matriz, const vector <int> & equipos, vector <bool> & equipo_seleccionado, 
    vector <bool> & proyecto_acabado, vector <int> & proyecto_equipo, int & sueldoTotal, int sueldoActual) {

    for (int equipo = 0; equipo < num_proyectos; equipo++) {
        if (!equipo_seleccionado[equipo]) {

            equipo_seleccionado[equipo] = true;
            proyecto_equipo[k] = equipo;
            sueldoActual += matriz[k][i];





        }

    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int num_equipos, num_proyectos;

    cin >> num_equipos >> num_proyectos;

    vector <int> equipos(num_equipos);

    for (int i = 0; i < num_equipos; i++) {
        cin >> equipos[i];
    }

    vector <vector<int>> matriz(num_proyectos, vector<int>(3));

    for (int i = 0; i < num_proyectos; i++) {
        cin >> matriz[i][0];//minimo personas
        cin >> matriz[i][1];//max personas
        cin >> matriz[i][2];//sueldo
    }

    int sueldoActual = 0;
    int sueldoTotal = -1;

    vector <bool> equipo_seleccionado(num_equipos, false);
    vector <bool> proyecto_acabado(num_proyectos, false);
    vector <int> proyecto_equipo(num_equipos);

    resolver(0, num_equipos, num_proyectos, matriz, equipos, equipo_seleccionado, proyecto_acabado, proyecto_equipo, sueldoTotal, sueldoActual);

    if (sueldoTotal == -1) {
        cout << "NO\n";
    }
    else {
        cout << sueldoTotal << "\n";
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