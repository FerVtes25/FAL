// Fernando Vieites Moreira
// FAL-A68


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <tuple>

using namespace std;

// función que resuelve el problema
tuple <int, int, int> resolver(vector <int> v) {
    int suma = 0;
    int max = 0;
    int inicio = 0;
    int inicio_final = 0;
    int num_dias = 0;
    int num_dias_final = 0;

    for (int i = 0; i < v.size(); i++) {
        if (v[i] > 0) {
            suma += v[i];
            num_dias++;

            if (num_dias == 1) {
                inicio = i;
            }
            if (suma > max || suma == max && num_dias < num_dias_final) {
                max = suma;
                inicio_final = inicio;
                num_dias_final = num_dias;
            }
        }
        else {
            suma += v[i];
            num_dias++;

            if (suma <= 0) {
                num_dias = 0;
                suma = 0;
            }
        }
    }

    return make_tuple(max, inicio_final, num_dias_final);
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int n;
    cin >> n;

    if (!std::cin)
        return false;

    vector <int> v(n);

    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    
    auto result = resolver(v);
    int max = get<0>(result);
    int inicio_final = get<1>(result);
    int num_dias_final = get<2>(result);

    cout << max << " " << inicio_final << " " << num_dias_final;
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