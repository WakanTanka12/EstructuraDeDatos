#pragma once

#include "Vector.h"

class VectorCalculator : public Vector<int> {
    public:
    VectorCalculator(int _capacity = 10) : Vector(_capacity) {}

    void suma(Vector v1, Vector v2) {
        VectorCalculator suma;
        int maxSize = v1.getSize();
        if(v2.getSize() > maxSize) {
            maxSize = v2.getSize();
        }

        // Rellenar los espacios faltantes con 0
        if(v1.getSize() < maxSize) {
            for (int i = v1.getSize() ; i < v2.getSize() ; i++)
                v1.pushBack(0);
        }
        else {
            for (int i = v2.getSize() ; i < v1.getSize() ; i++)
                v2.pushBack(0);
        }

        for (int i = 0 ; i < maxSize ; i++) {
            suma.pushBack(v1.at(i) + v2.at(i));
        }

        size = suma.getSize();
        for (int i = 0 ; i < size ; i++) {
            items[i] = suma.at(i);
        }
    }

    void resta(Vector v1, Vector v2) {
        VectorCalculator resta;
        int maxSize = v1.getSize();
        if(v2.getSize() > maxSize) {
            maxSize = v2.getSize();
        }

        // Rellenar los espacios faltantes con 0
        if(v1.getSize() < maxSize) {
            for (int i = v1.getSize() ; i < v2.getSize() ; i++)
                v1.pushBack(0);
        }
        else {
            for (int i = v2.getSize() ; i < v1.getSize() ; i++)
                v2.pushBack(0);
        }

        for (int i = 0 ; i < maxSize ; i++) {
            resta.pushBack(v1.at(i) - v2.at(i));
        }

        size = resta.getSize();
        for (int i = 0 ; i < size ; i++) {
            items[i] = resta.at(i);
        }
    }

    int productoPunto(Vector v1, Vector v2) {
        int sumatoria = 0;
        int maxSize = v1.getSize();
        if(v2.getSize() > maxSize) {
            maxSize = v2.getSize();
        }

        // Rellenar los espacios faltantes con 0
        if(v1.getSize() < maxSize) {
            for (int i = v1.getSize() ; i < v2.getSize() ; i++)
                v1.pushBack(0);
        }
        else {
            for (int i = v2.getSize() ; i < v1.getSize() ; i++)
                v2.pushBack(0);
        }

        for (int i = 0 ; i < maxSize ; i++) {
            sumatoria += (v1.at(i)*v2.at(i));
        }

        return sumatoria;
    }
};
