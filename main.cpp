#include <iostream>
#include "arreglo.h"
#include "personaje.h"
using namespace std;

#define T Personaje

int main()
{
    Arreglo<T> a;
    string op;

    while (true) {
        cout << "1) Agregar final" << endl;
        cout << "2) Agregar inicio" << endl;
        cout << "3) Mostrar" << endl;
        cout << "4) Insertar posición" << endl;
        cout << "5) Eliminar último" << endl;
        cout << "6) Eliminar inicio" << endl;
        cout << "7) Eliminar" << endl;
        cout << "8) Buscar" << endl;
        cout << "9) Buscar todos" << endl;
        cout << "10) Sort" << endl;
        cout << "0) Salir" << endl;
        getline(cin, op);

        if (op == "1") {
            T t;
            cin >> t;
            a + t; //a.insertar_final(t);
        }
        else if (op == "2") {
            T t;
            cin >> t;
            a << t; //a.insertar_inicio(t);
        }
        else if (op == "3") {
            for (size_t i = 0; i < a.size(); ++i) {
                cout << a[i] << endl;
            }
        }
        else if (op == "4") {
            T t;
            size_t p;

            cin >> t;
            cout << "posicion: ";
            cin >> p; cin.ignore();

            a.insertar(t, p);
        }
        else if (op == "5") {
            a.eliminar_ultimo();
        }
        else if (op == "6") {
            a.eliminar_inicio();
        }
        else if (op == "7") {
            size_t p;

            cout << "posicion: ";
            cin >> p; cin.ignore();

            a.eliminar(p);
        }
        else if (op == "8") {
            T t;
            cin >> t;

            T *ptr = a.buscar(t);
            if (ptr == nullptr) {
                cout << "no existe" << endl;
            }
            else {
                cout << "Encontrado" << endl;
                cout << *ptr;
            }

        }
        else if (op == "9") {
            T t;
            cin >> t;

            Arreglo<T*> ptrs = a.buscar_todos(t);
            if (ptrs.size() == 0) {
                cout << "No encontrado" << endl;
            }
            else {
                cout << "Encontrados" << endl;
                for (size_t i = 0; i < ptrs.size(); i++) {
                    cout << *(ptrs[i]) << endl;
                }
            }

        }
        else if (op == "10") {
            a.sort();
        }
        else if (op == "0") {
            break;
        }
    }

    return 0;
}
