
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

 Primero se hace una lectura de la entrada, guardando los valores 
 de las partituras y el numero de instrumentos diferentes. Después
 se crea la clase Orchestra, que es la que se va a encargar de repartir
 las partituras entre los instrumentos. 

 En la constructora se crea una cola de prioridad de structs que guardan
 el número de instrumentos que hay y las partituras que le corresponden, 
 iniciando este último valor en 1 puesto que mínimo va a haber una
 partitura para cada instrumento. Tras esto, se hace una resta para 
 comprobar cuantas partituras hay que repartir y en caso de que no 
 queden por repartir, se termina el cálculo y se muestra por pantalla. 

 Si quedaran partituras por repartir se llama a reparte() con el valor
 m_p actualizado con las partituras que quedan por repartir. Aquí se hace
 un reparto usando la cola de prioridad. 

 Para usar la cola de prioridad se ha implementado un comparador específico
 para el struct que calcula cuál es el atril con más personas de un grupo
 en función de las partituras.

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

    // Coste: O(N) siendo N el valor de las partituras restantes tras repartir las primeras
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
