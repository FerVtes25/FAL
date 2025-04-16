// Fernando Vieites Moreira
// FAL-A68


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

// función que resuelve el problema
bool esSolucion(const int altura, const int k, const vector <int> num_piezas_actual) {
    if (altura - 1 == k) {
        //no se si hay q comprobar n >= 2
        if (num_piezas_actual[1] <= num_piezas_actual[0] + num_piezas_actual[2]) {
            return false;
        }
        return true;
    }
    return false;
}

bool esValida(const vector <int>& torre, const int k, const vector <int> num_piezas_actual, const vector <int> & num_piezas_total) {
    if (k > 0) {
        if (torre[k] == 2 && torre[k - 1] == 2) {
            return false;
        }
    }
    for (int i = 0; i < 3; i++) {
        if (num_piezas_actual[i] > num_piezas_total[i]) {
            return false;
        }
    }
    if (num_piezas_actual[2] > num_piezas_actual[0]) {
        return false;
    }
    return true;
}

void vueltaAtras(int k, int altura, vector <int> & torre, vector <int> & num_piezas_actual, const vector <int> & num_piezas_total, int & num_soluciones) {

    for (int i = 0; i < 3; i++) {
        torre[k] = i;
        num_piezas_actual[i]++;

        if (esValida(torre, k, num_piezas_actual, num_piezas_total)) {
            if (k == altura - 1) {
                if (esSolucion(altura, k, num_piezas_actual)) {
                    num_soluciones++;

                    for (int j = 0; j < altura; j++) {
                        if (torre[j] == 0) {
                            cout << "azul ";
                        }
                        else if (torre[j] == 1) {
                            cout << "rojo ";
                        }
                        else {
                            cout << "verde ";
                        }
                    }
                    cout << "\n";
                }
            }
            else {
                vueltaAtras(k + 1, altura, torre, num_piezas_actual, num_piezas_total, num_soluciones);
            }
        }
        num_piezas_actual[i]--;
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada

    int altura, piezas_azules, piezas_rojas, piezas_verdes;

    cin >> altura;

    if (altura == 0)
        return false;

    cin >> piezas_azules >> piezas_rojas >> piezas_verdes;

    vector <int> torre(altura);
    torre[0] = 1;

    int num_soluciones = 0;

    vector <int> num_piezas_actual(3);
    vector <int> num_piezas_total(3);

    num_piezas_total[0] = piezas_azules;
    num_piezas_total[1] = piezas_rojas;
    num_piezas_total[2] = piezas_verdes;
    num_piezas_actual[0] = 0;
    num_piezas_actual[1] = 1;
    num_piezas_actual[2] = 0;

    vueltaAtras(1, altura, torre, num_piezas_actual, num_piezas_total, num_soluciones);

    if (num_soluciones == 0) {
        cout << "SIN SOLUCION" << "\n";
    }

    cout << "\n";

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
