// Fernando Vieites Moreira
// FAL-A68


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

// función que resuelve el problema
bool comp(vector<int>& a, vector <int>& b) {
    return (double)a[1] / a[0] > (double)b[1] / b[0];
}

void ordenarMatriz(vector<vector<int>>& matriz) {
    sort(matriz.begin(), matriz.end(), comp);
}

bool esValida(vector <int> solucion, const int k, const int i, const int duracion1, const int duracion2, const int t1, const int t2) {
    for (int j = 0; j < k; j++) {
        if (solucion[j] == i) {
            return false;
        }
    }
    
    return true;
}

bool esSolucion(const int satisfaccionActual, const int satisfaccionFinal, const int duracion1, const int duracion2, const int t1, const int t2) {
    if (duracion1 > 0 && duracion2 > 0) {
        if (satisfaccionActual > satisfaccionFinal || satisfaccionFinal == -1) {
            if (duracion1 == t1 && duracion2 == t2) {
                return true;
            }
        }
    }
    return false;
}

void vueltaAtras(int k, vector <vector<int>> canciones, vector <int> solucion, vector <bool>& cancionesAsignadas, int& satisfaccionActual, int& satisfaccionFinal, int& duracion1, int& duracion2, const int t1, const int t2) {
    for (int i = 0; i < canciones.size(); i++) {

        int trayectoSumado = 0;
        //solucion[k] = 1;

        if (!cancionesAsignadas[k]) {
            satisfaccionActual += canciones[i][1];
            cancionesAsignadas[k] = true;

            if (duracion1 + canciones[i][0] <= t1) {
                duracion1 += canciones[i][0];
                trayectoSumado = 1;
            }
            else {
                duracion2 += canciones[i][0];
                trayectoSumado = 2;
            }

            if (duracion1 <= t1 || duracion2 <= t2) {
                if (esSolucion(satisfaccionActual, satisfaccionFinal, duracion1, duracion2, t1, t2)) {
                    satisfaccionFinal = satisfaccionActual;
                }
                else if (esValida(solucion, k, i, duracion1, duracion2, t1, t2)) {
                    vueltaAtras(k + 1, canciones, solucion, cancionesAsignadas, satisfaccionActual, satisfaccionFinal, duracion1, duracion2, t1, t2);
                }
            }

            

            solucion[k] = -1;
            satisfaccionActual -= canciones[i][1];
            if (trayectoSumado == 1) {
                duracion1 -= canciones[i][0];
            }
            else if (trayectoSumado == 2) {
                duracion2 -= canciones[i][0];
            }
        }
        

        

        


        

        
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int n, t1, t2;

    cin >> n >> t1 >> t2;

    if (n == 0)
        return false;

    vector <vector<int>> canciones(n, vector<int>(2));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 2; j++) {
            cin >> canciones[i][j];
        }
    }

    ordenarMatriz(canciones);

    vector <bool> cancionesAsignadas(n, false);

    vector <int> solucion(n);
    int satisfaccionActual = 0;
    int satisfaccionFinal = -1;
    int duracion1 = 0;
    int duracion2 = 0;

    vueltaAtras(0, canciones, solucion, cancionesAsignadas, satisfaccionActual, satisfaccionFinal, duracion1, duracion2, t1, t2);

    if (satisfaccionFinal == -1) {
        cout << "Imposible" << "\n";
    }
    else {
        cout << satisfaccionFinal << "\n";
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
