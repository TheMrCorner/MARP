
/*@ <answer>
 *
 * Nombre y Apellidos:
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
using namespace std;

#include "Grafo.h"  // propios o los de las estructuras de datos de clase

/*@ <answer>

 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.

 @ </answer> */


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>

class ArbolLibre {
private:
    bool correcto;
    Grafo* arbol;

    vector<bool>* visitado;
    vector<int>* ant;

    void dfs(int v) {

        visitado->at(v) = true;

        for (int i : arbol->ady(v))
        {
            if (!visitado->at(i)) {
                ant->at(i) = v;
                dfs(i);
            }
            else {
                if (i != ant->at(v)) {
                    // Detecta ciclo
                    correcto = false;
                } // if
            } // else
        } // for
    } // dfs

public: 

    ArbolLibre(int V, int A) {
        correcto = true; // Suponemos correcto de primeras
        arbol = new Grafo(V);
        visitado = new vector<bool>(V, false);
        ant = new vector<int>(V);

        for (int i = 0; i < A; i++)
        {
            int v, w;

            std::cin >> v >> w;

            arbol->ponArista(v, w);
        } // for

        dfs(0); 

        if (correcto) {
            for (int i = 0; i < visitado->size(); i++)
            {
                if (!visitado->at(i)) {
                    correcto = false;
                } // if
            } // for
        } // if
    } // ArbolLibre

    bool es_libre() {
        return correcto;
    } // es_libre
};

bool resuelveCaso() {
    int v, a;

    v = a = 0;

    // leer los datos de la entrada
    std::cin >> v >> a;

    if (v == NULL)  // fin de la entrada
        return false;

    // resolver el caso posiblemente llamando a otras funciones
    ArbolLibre* free = new ArbolLibre(v, a);

    // escribir la solución
    if (free->es_libre())
        std::cout << "SI" << "\n";
    else
        std::cout << "NO" << "\n";

    return true;
}

//@ </answer>
//  Lo que se escriba dejado de esta línea ya no forma parte de la solución.

int main() {
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("casos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

    while (resuelveCaso());

    // para dejar todo como estaba al principio
#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif
    return 0;
}
