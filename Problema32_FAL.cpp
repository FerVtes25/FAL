// Fernando Vieites Moreira
// FAL-A68


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

/*
El coste es O(n) siendo n el número de elementos del vector, ya que los recorre todos y realiza operaciones constantes sobre ellos

La cota es n-i-1

P:{L >= 1 ∧ n >= 0}

Q:{∀ p ∈ sol: (0 <= p <= n - L) ∧ (∀ k ∈ [p, p + L - 2]: |v[k] - v[k - 1]| <= 1)}

I:{(0 < i < v.size()) ∧ (j > 0) ∧ (∀ k ∈ [i - j + 1, i] : |v[k] - v[k - 1]| <= 1)}
*/

// función que resuelve el problema
vector <int> resolver(vector <int> v, int L) {
    int j = 1;
    vector <int> sol;

    for (int i = 1; i < v.size(); i++) {
        if (abs(v[i] - v[i - 1]) <= 1) {
            j++;
        }
        else {
            j = 1;
        }
        if (j == L) {
            sol.push_back(i - j + 1);
        }
    }
    return sol;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    long long int L;
    int n;
    cin >> n;
    cin >> L;

    if (n == 0 && L == 0)
        return false;

    vector <int> v(n);

    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    vector <int> sol = resolver(v, L);

    // escribir sol
    cout << sol.size() << " ";
    for (int i = 0; i < sol.size(); i++) {
        cout << sol[i] << " ";
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
