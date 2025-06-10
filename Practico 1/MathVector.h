#pragma once

#include "Vector.h"

class MathVector : public Vector<int> {
    public:
    MathVector(int _capacity = 10) : Vector (_capacity) {
    }

    double promedio () {
        int suma = 0;
        double promedio;
        for (int i = 0 ; i < size ; i++) {
            suma += items[i];
        }
        promedio = float(suma) / size;
        return promedio;
    }

    double mediana () {
        int *_items = new int[size];
        double mediana;
        for (int i = 0; i < size ; i++) {
            _items[i] = items[i];
        }

        for (int i = 0; i < size - 1; ++i) {
            for (int j = 0; j < size - i - 1; ++j) {
                if (_items[j] > _items[j + 1]) {
                    int temp = _items[j];
                    _items[j] = _items[j + 1];
                    _items[j + 1] = temp;
                }
            }
        }

        if(size%2 == 0) 
            mediana = (_items[size/2 - 1] + _items[size/2]) / 2.0;
        else
            mediana = (_items[(size) / 2]);

        delete[] _items;
        return mediana;
    }

    int moda() {
        int *_items = new int[size];

        for (int i = 0; i < size ; i++) {
            _items[i] = items[i];
        }

        for (int i = 0; i < size - 1; ++i) {
            for (int j = 0; j < size - i - 1; ++j) {
                if (_items[j] > _items[j + 1]) {
                    int temp = _items[j];
                    _items[j] = _items[j + 1];
                    _items[j + 1] = temp;
                }
            }
        }

        int moda = _items[0];
        int frecuenciaModa = 1;

        int actual = _items[0];
        int frecuenciaActual = 1;

        for(int i = 1 ; i < size ; i++) {
            if(_items[i] == actual) {
                frecuenciaActual++;
            } else {
                if (frecuenciaActual > frecuenciaModa) {
                    moda = actual;
                    frecuenciaModa = frecuenciaActual;
                }
                actual = _items[i];
                frecuenciaActual = 1;
            }
        }

        if (frecuenciaActual > frecuenciaModa) {
            moda = actual;
            frecuenciaModa = frecuenciaModa;
        }
        delete[] _items;
        return moda;
    }

    int maximo() {
        int maximo = items[0];
        for (int i = 1 ; i < size ; i++) {
            if (items[i] > maximo) {
                maximo = items[i];
            }
        }
        return maximo;
    }

    int minimo() {
        int minimo = items[0];
        for (int i = 1 ; i < size ; i++) {
            if (items[i] < minimo) {
                minimo = items[i];
            }
        }
        return minimo;
    }
};
