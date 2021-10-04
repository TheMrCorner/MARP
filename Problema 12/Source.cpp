
// Nombre y Apellidos

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

#include <iostream>
#include <fstream>
#include <vector>

#include "Grafo.h"

using namespace std;

// función que resuelve el problema
// comentario sobre el coste, O(f(N)), donde N es ...
class Ciudad {
private:

    Grafo* amigos;
    vector<bool>* visitado;
    vector<int>* ant;

    int m_maxGroup;

    void dfs(int v, int &totalGroup) {
        visitado->at(v) = true;
        totalGroup++;

        for (int i : amigos->ady(v))
        {
            if (!visitado->at(i)) {
                ant->at(i) = v;
                dfs(i, totalGroup);
            }
        } // for
    } // dfs

public:
    Ciudad(int n, int m) {
        amigos = new Grafo(n);
        visitado = new vector<bool>(n, false);
        ant = new vector<int>(n);
        m_maxGroup = 0;
        int a, b, t;

        for (int i = 0; i < m; i++)
        {
            cin >> a >> b;

            amigos->ponArista(a - 1, b - 1);
        } // for

        for (int i = 0; i < n; i++)
        {
            t = 0;
            
            if (!visitado->at(i)) {
                dfs(i, t);
            } // if

            if (t > m_maxGroup) {
                m_maxGroup = t;
            } // if
        } // for
    } // Ciudad

    int maxGroup() {
        return m_maxGroup;
    } // maxGroup
};

// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    int N, M;

    N = M = 0;

    // leer los datos de la entrada
    cin >> N >> M;

    Ciudad c = Ciudad(N, M);

    // escribir solución
    cout << c.maxGroup() << "\n";
}

int main() {
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("casos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

    int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();

    // para dejar todo como estaba al principio
#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif
    return 0;
}
