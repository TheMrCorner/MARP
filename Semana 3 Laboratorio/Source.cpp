
/*@ <answer>
 *
 * Nombre y Apellidos:
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <queue>
#include <math.h>
using namespace std;


/*@ <answer>

 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.

 @ </answer> */


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>

class Orchestra {
private:
    struct pair {
        float part, inst;
    };

    class comparator {
    public:
        bool operator() (pair a, pair b) {
            return(ceil(a.inst / a.part) < ceil(b.inst / b.part));
        } // operator
    };

    int m_n, m_p; // Partituras y numeros
    priority_queue<pair, vector<pair>, comparator>* m_queue;

    void reparte() {
        while (m_p > 0) {
            pair t = m_queue->top();
            m_queue->pop();

            t.part++;

            m_queue->push(t);

            m_p--;
        } // while
    } // reparte

public: 

    Orchestra(int n, int p) : m_n(n), m_p(p)  {
        m_queue = new priority_queue<pair, vector<pair>, comparator>();

        for (int i = 0; i < n; i++) {

            int inst;

            std::cin >> inst;

            pair t{ 1, inst };

            m_queue->push(t);
        } // for

        // Repartir partituras
        int temp = m_p - m_n; // Minimo 1 para cada instrumento

        if (temp != 0) {
            m_p = temp;
            reparte();
        } // if
    } // Orchestra

    int get_bigger() {
        return ceil(m_queue->top().inst / m_queue->top().part);
    } // get_bigger
};

bool resuelveCaso() {
    int p, n;

    p = n = 0;

    // leer los datos de la entrada
    std::cin >> p;
    std::cin >> n;

    if (p == NULL) {
        return false;
    }

    // resolver el caso posiblemente llamando a otras funciones
    Orchestra* o = new Orchestra(n, p);

    // escribir la solución
    std::cout << o->get_bigger() << "\n";

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
