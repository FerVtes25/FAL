// Fernando Vieites Moreira
// FAL-A68


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

// función que resuelve el problema
bool ascenso(vector <int> const& v, int p, int q) {

    for (int i = p + 1; i < q; i++) {
        if (v[i] < v[i - 1]) {
            return false;
        }
    }

    return true;
}

bool tramo(vector <int> const& v, int p, int q) {

    for (int i = p + 1; i < q; i++) {
        if (v[i] <= v[i - 1]) {
            return false;
        }
    }
    return true;
}

vector <int> resolver(vector<int> v) {
    vector <int> sol(4);

    int j = 2;
    bool ascendente = false;
    int longitud = 1;
    int max_longitud = 0;
    int comienzo_tramo_actual = 0;
    int comienzo_tramo_final = 0;
    int final_tramo = 0;
    int num_tramos = 0;
    bool estoy_en_ascenso = false;
    bool estoy_en_tramo = false;
    int long_tramo_actual = 1;
    int long_tramo_final = -1;

    while (j != v.size() + 1) {

        if (ascenso(v, j - 2, j)) {
            j++;

            if (estoy_en_ascenso == false) {
                comienzo_tramo_actual = j - 3;
                estoy_en_ascenso = true;
            }
            else {
                if (tramo(v, j - 2, j)) {
                    long_tramo_actual++;
                    long_tramo_final = max(long_tramo_actual, long_tramo_final);

                    if (estoy_en_tramo == false) {
                        num_tramos++;
                        estoy_en_tramo = true;
                    }
                }
                else {
                    long_tramo_actual = 1;
                    estoy_en_tramo = false;

                }
            }

            longitud++;

            if (longitud > max_longitud) {
                max_longitud = longitud;
                comienzo_tramo_final = comienzo_tramo_actual;
                final_tramo = j - 1;
            }

        }
        else {
            if (estoy_en_ascenso == true) {
                longitud = 1;
                num_tramos++;
                estoy_en_ascenso = false;
                estoy_en_tramo = false;
                j++;
            }
        }
    }

    sol[0] = max_longitud;
    sol[1] = comienzo_tramo_final;
    sol[2] = final_tramo - 1;
    sol[3] = num_tramos;

    return sol;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int n;

    cin >> n;

    vector <int> v(n);
    
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    vector <int> sol = resolver(v);
    
    for (int i = 0; i < 4; i++) {
        cout << sol[i] << " ";
    }
    cout << "\n";
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