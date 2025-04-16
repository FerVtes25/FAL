// Fernando Vieites Moreira
// FAL-A68


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

// función que resuelve el problema
/*
TipoSolucion resolver(TipoDatos datos) {


}*/

struct tPersona {
    string nombre;
    int altura;
    //bool alto;
};

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int n;
    cin >> n;

    if (!std::cin)
        return false;

    int x;
    cin >> x;

    vector <tPersona> v(n);
    vector <string> bajos;
    vector <string> altos;

    for (int i = 0; i < n; i++) {
        tPersona persona;
        cin >> persona.nombre;
        cin >> persona.altura;
        v[i] = persona;
    }

    for (int i = 0; i < v.size(); i++) {
        if (v[i].altura <= x) {
            bajos.push_back(v[i].nombre);
        }
    }
    sort(bajos.begin(), bajos.end());
    for (int i = 0; i < v.size(); i++) {
        if (v[i].altura > x) {
            altos.push_back(v[i].nombre);
        }
    }
    sort(altos.begin(), altos.end());

    cout << "Bajos: ";
    for (int i = 0; i < bajos.size(); i++) {
        cout << bajos[i] << " ";
    }

    cout << "\nAltos: ";
    for (int i = 0; i < altos.size(); i++) {
        cout << altos[i] << " ";
    }

    cout << "\n";

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