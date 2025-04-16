// Fernando Vieites Moreira
// FAL-A68


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

struct tParque {
    string nombre_atraccion;
    int tiempo_atraccion;
    int satisfaccion;
    bool moja;
};

// función que resuelve el problema
void resolver(int k, const vector <tParque>& v, vector <int>& solucion, int num_mojan, int num_no_mojan, int tiempo_total, int tiempo_actual, vector <bool> & seleccionados, int satisfaccionActual, int & satisfaccionTotal) {

    for (int i = 0; i < v.size(); i++) {
        if (!seleccionados[i]) {

            //solucion[k] = i;
            seleccionados[i] = true;
            tiempo_actual += v[i].tiempo_atraccion;
            satisfaccionActual += v[i].satisfaccion;
            if (v[i].moja == true) {
                num_mojan++;
            }
            else {
                num_no_mojan++;
            }

            if (num_mojan <= v.size() / 2 && tiempo_actual <= tiempo_total) {
                if (num_mojan <= num_no_mojan) {
                    satisfaccionTotal = max(satisfaccionActual, satisfaccionTotal);
                }
                else if (k + 1 < v.size()) {
                    resolver(k + 1, v, solucion, num_mojan, num_no_mojan, tiempo_total, tiempo_actual, seleccionados, satisfaccionActual, satisfaccionTotal);
                }
            }


            seleccionados[i] = false;
            tiempo_actual -= v[i].tiempo_atraccion;
            satisfaccionActual -= v[i].satisfaccion;
            if (v[i].moja == true) {
                num_mojan--;
            }
            else {
                num_no_mojan--;
            }
        }
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int atracciones, tiempo;

    cin >> atracciones >> tiempo;

    if (atracciones == 0 && tiempo == 0)
        return false;

    vector <tParque> v(atracciones);

    for (int i = 0; i < atracciones; i++) {
        cin >> v[i].nombre_atraccion;
        cin >> v[i].tiempo_atraccion;
        cin >> v[i].satisfaccion;
        cin >> v[i].moja;
    }

    vector <int> solucion;
    int num_mojan = 0;
    int num_no_mojan = 0;
    vector <bool> seleccionados(atracciones, false);
    int satisfaccionTotal = -1;
    int satisfaccionActual = 0;

    resolver(0, v, solucion, num_mojan, num_no_mojan, tiempo, 0, seleccionados, satisfaccionActual, satisfaccionTotal);

    if (satisfaccionTotal != -1) {
        cout << satisfaccionTotal << "\n";
    }
    else {
        cout << "NINGUNA\n";
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
