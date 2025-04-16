// Fernando Vieites Moreira
// FAL-A68


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

struct tCinta {
    string color;
    int longitud;
};

// función que resuelve el problema
pair<int, int> resolver(vector <tCinta> &v) {
    int j = 0;
    tCinta aux;
    for (int i = 0; i < v.size(); i++) {
        if (v[i].color == "a") {
            aux = v[i];
            v[i] = v[j];
            v[j] = aux;
            j++;
        }
    }
    int k = j;
    for (int i = j; i < v.size(); i++) {
        if (v[i].color == "v") {
            aux = v[i];
            v[i] = v[k];
            v[k] = aux;
            k++;
        } 
    }
    
    sort(v.begin(), v.begin() + j, [](const tCinta& a, const tCinta& b) {
        return a.longitud < b.longitud;
        });
    sort(v.begin() + j + 1, v.begin() + k, [](const tCinta& a, const tCinta& b) {
        return a.longitud < b.longitud;
    });
    sort(v.begin() + k + 1, v.end(), [](const tCinta& a, const tCinta& b) {
        return a.longitud < b.longitud;
    });


    return make_pair(j, k);
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int n;
    cin >> n;

    if (!std::cin)
        return false;

    vector <tCinta> v(n);

    for (int i = 0; i < n; i++) {
        cin >> v[i].color;
        cin >> v[i].longitud;
    }

    pair <int, int> indices = resolver(v);

    // escribir sol
    cout << "Azules: ";
    for (int i = 0; i < indices.first; i++) {
        cout << v[i].longitud << " ";
    }
    cout << "\nVerdes: ";
    for (int i = indices.first; i < indices.second; i++) {
        cout << v[i].longitud << " ";
    }
    cout << "\nRojos: ";
    for (int i = indices.second; i < n; i++) {
        cout << v[i].longitud << " ";
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