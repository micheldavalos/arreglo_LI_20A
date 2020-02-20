#ifndef ARREGLO_H
#define ARREGLO_H

#include <iostream>
#include <stdexcept>
using namespace std;

template<class T>
class Arreglo
{
    T *arreglo;
    size_t cont;
    size_t tam;
    const static size_t MAX = 5;

public:
    Arreglo();
    void insertar_final(const T &dato);
    void insertar_inicio(const T &dato);
    void insertar(const T &dato, size_t p);

    void eliminar_ultimo();
    void eliminar_inicio();

    size_t size();
    T& operator[](size_t p);
    void operator+(const T& dato);
    void operator<<(const T& dato);

private:
    void expandir();
};

template<class T>
Arreglo<T>::Arreglo()
{
    arreglo = new T[MAX];
    cont = 0;
    tam = MAX;
}

template<class T>
void Arreglo<T>::insertar_final(const T &dato)
{
    if (cont == tam) {
        expandir();
    }
    arreglo[cont] = dato;
    cont++;
}

template<class T>
void Arreglo<T>::insertar_inicio(const T &dato)
{
    if (cont == tam) {
        expandir();
    }
    for (size_t i = cont; i > 0; i--) {
        arreglo[i] = arreglo[i-1];
    }
    arreglo[0] = dato;
    cont++;
}

template<class T>
void Arreglo<T>::insertar(const T &dato, size_t p)
{
    if (p >= cont) {
        throw out_of_range("posición no válida");
    }
    if (cont == tam) {
        expandir();
    }
    for (size_t i = cont; i > p; i--) {
        arreglo[i] = arreglo[i-1];
    }
    arreglo[p] = dato;
    cont++;
}

template<class T>
void Arreglo<T>::eliminar_ultimo()
{
    if (cont == 0) {
        throw out_of_range("arreglo vacío");
    }
    cont--;
}

template<class T>
void Arreglo<T>::eliminar_inicio()
{
    if (cont == 0) {
        throw out_of_range("arreglo vacío");
    }
    for (size_t i = 0; i < cont-1; ++i) {
        arreglo[i] = arreglo[i+1];
    }
    cont--;
}

template<class T>
size_t Arreglo<T>::size()
{
    return cont;
}

template<class T>
T &Arreglo<T>::operator[](size_t p)
{
    if (p >= cont) {
        throw out_of_range("posicion no válida");
    }
    return arreglo[p];
}

template<class T>
void Arreglo<T>::operator+(const T &dato)
{
    insertar_final(dato);
}

template<class T>
void Arreglo<T>::operator<<(const T &dato)
{
    insertar_inicio(dato);
}

template<class T>
void Arreglo<T>::expandir()
{
    T *nuevo = new T[tam+MAX];
    for (size_t i = 0; i < cont; ++i) {
        nuevo[i] = arreglo[i];
    }
    delete []arreglo;
    arreglo = nuevo;
    tam = tam + MAX;
}

#endif // ARREGLO_H

