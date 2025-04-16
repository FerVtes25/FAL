// Fernando Vieites Moreira
// FAL-A68


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

struct tDatos {
    int coste;
    int superficie;
};

// función que resuelve el problema
bool esSolucion(const int superficieActual, const int superficieFinal) {
    if (superficieActual > superficieFinal || superficieFinal == -1) {
        return true;
    }
    return false;
}

bool esValida(vector <int> solucion, int k, const int costeActual, const int presupuesto) {
    for (int j = 0; j < k; j++) {
        if (solucion[j] == k) {
            return false;
        }
    }
    if (costeActual > presupuesto) {
        return false;
    }
    return true;
}

void vueltaAtras(int k, vector<vector<int>>& matriz, const int presupuesto, vector <int> solucion, int costeActual, int superficieActual, int & superficieFinal) {
    for (int i = 0; i < matriz.size(); i++) {
        costeActual += matriz[i][0];
        superficieActual += matriz[i][1];
        solucion[k] = i;

        if (esValida(solucion, k, costeActual, presupuesto)) {
            if (esSolucion(superficieActual, superficieFinal)) {
                superficieFinal = superficieActual;
            }
            else {
                vueltaAtras(k + 1, matriz, presupuesto, solucion, costeActual, superficieActual, superficieFinal);
            }
        }
        costeActual -= matriz[i][0];
        superficieActual -= matriz[i][1];
        solucion[k] = -1;
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int n, presupuesto;
    
    cin >> n;

    if (!std::cin)
        return false;

    cin >> presupuesto;
     
    vector <vector<int>> matriz(n, vector <int>(2));
    vector <int> solucion(n);
    int costeActual = 0;
    int superficieActual = 0;
    int superficieFinal = -1;

   

    for (int i = 0;  i < n; i++) {
        cin >> matriz[i][0];
        cin >> matriz[i][1];
    }

    vueltaAtras(0, matriz, presupuesto, solucion, costeActual, superficieActual, superficieFinal);

    cout << superficieFinal << "\n";

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