// Fernando Vieites Moreira
// FAL-A68

/*
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

// función que resuelve el problema
void resolver(int k, const vector <vector<int>> & matriz, vector <int> & vigilantes_necesarios_monte, int distancia_maxima_desplazamiento, int desplazamientoActual, int & desplazamientoTotal, int montes_cubiertos) {

    for (int i = 0; i < matriz[0].size(); i++) {

        if (matriz[k][i] <= distancia_maxima_desplazamiento && !(matriz[k][i] < distancia_maxima_desplazamiento && i == matriz.size()-1)) {

            vigilantes_necesarios_monte[i]--;
            if (vigilantes_necesarios_monte[i] == 0) {
                montes_cubiertos++;
            }
            desplazamientoActual += matriz[k][i];
            
            if (desplazamientoActual < desplazamientoTotal || desplazamientoTotal == -1) {
                if (k + 1 == matriz.size()) {
                    if (montes_cubiertos == matriz[0].size()) {
                       desplazamientoTotal = desplazamientoActual;
                        
                    }
                }
                else {
                    resolver(k + 1, matriz, vigilantes_necesarios_monte, distancia_maxima_desplazamiento, desplazamientoActual, desplazamientoTotal, montes_cubiertos);
                }
            }

            vigilantes_necesarios_monte[i]++;
            if (vigilantes_necesarios_monte[i] == 1) {
                montes_cubiertos--;
            }
            desplazamientoActual -= matriz[k][i];
        }

    }

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada

    int montes, vigilantes;

    cin >> montes >> vigilantes;

    if (montes == 0 && vigilantes == 0)
        return false;

    vector <int> vigilantes_necesarios_monte(montes);

    for (int i = 0; i < montes; i++) {
        cin >> vigilantes_necesarios_monte[i];
    }

    int distancia_maxima_desplazamiento;

    cin >> distancia_maxima_desplazamiento;

    vector <vector<int>> desplazamientos_vigilantes(vigilantes, vector <int>(montes));

    for (int i = 0; i < vigilantes; i++) {
        for (int j = 0; j < montes; j++) {
            cin >> desplazamientos_vigilantes[i][j];
        }
    }

    int desplazamientoActual = 0;
    int desplazamientoTotal = -1;
    int montes_cubiertos = 0;



    resolver(0, desplazamientos_vigilantes, vigilantes_necesarios_monte, distancia_maxima_desplazamiento, desplazamientoActual, desplazamientoTotal, montes_cubiertos);

    if (desplazamientoTotal == -1) {
        cout << "IMPOSIBLE\n";
    }
    else {
        cout << desplazamientoTotal << "\n";
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
}*/

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

void vueltaAtras(const vector<vector<int>>& matriz, int distanciaMaxima, int k, int brigadas, int vigilantes, vector<int>& brigadasMinima,
    vector<int>& sol, int& distanciaAct, int& mejorDistancia, bool& haySol, vector<int>& acumulados, int& cubiertos) {
    for (int brigada = 0; brigada < brigadas; brigada++) {
        if (matriz[k][brigada] <= distanciaMaxima) {
            brigadasMinima[brigada]--;
            distanciaAct += matriz[k][brigada];
            if (brigadasMinima[brigada] == 0) cubiertos++;
            if (k == vigilantes - 1) {
                if (cubiertos == brigadas) {
                    mejorDistancia = min(distanciaAct, mejorDistancia);
                    haySol = true;
                }

            }
            else if (distanciaAct + acumulados[k + 1] < mejorDistancia) {
                vueltaAtras(matriz, distanciaMaxima, k + 1, brigadas, vigilantes, brigadasMinima, sol, distanciaAct, mejorDistancia, haySol, acumulados, cubiertos);
            }
            if (brigadasMinima[brigada] == 0) cubiertos--;
            brigadasMinima[brigada]++;
            distanciaAct -= matriz[k][brigada];

        }
    }

}

bool resuelveCaso() {
    int brigadas, vigilantes;
    cin >> brigadas >> vigilantes;
    if (brigadas == 0 && vigilantes == 0) return false;
    vector<int> brigadaMinima(brigadas);
    for (int i = 0; i < brigadas; i++)
    {
        cin >> brigadaMinima[i];
    }
    int distanciaMaxima;
    cin >> distanciaMaxima;
    vector <int> minimos(vigilantes, INT_MAX);
    vector<vector<int>> matriz(vigilantes, vector<int>(brigadas));
    for (int i = 0; i < vigilantes; i++)
    {
        for (int j = 0; j < brigadas; j++)
        {
            cin >> matriz[i][j];
            minimos[i] = min(minimos[i], matriz[i][j]);
        }

    }
    vector<int>acumulados(vigilantes);
    acumulados[vigilantes - 1] = minimos[vigilantes - 1];
    for (int i = vigilantes - 2; i >= 0; --i)
    {
        acumulados[i] = acumulados[i + 1] + minimos[i];
    }

    int distanciaAct = 0, mejorDistancia = INT_MAX;
    vector<int> sol(vigilantes);
    bool haySol = false;
    int c = 0;
    vueltaAtras(matriz, distanciaMaxima, 0, brigadas, vigilantes, brigadaMinima, sol, distanciaAct, mejorDistancia, haySol, acumulados, c);
    if (haySol) cout << mejorDistancia << '\n';
    else cout << "IMPOSIBLE\n";
    return true;
}

int main() {
#ifndef DOMJUDGE
    std::ifstream in("sample.in");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

    while (resuelveCaso()) {}

#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
#endif

    return 0;
}