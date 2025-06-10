#pragma once

#include "Vector.h"

class Producto {
    private:
    int id;
    string nombre;
    float precio;
    int stock;

    public:
    Producto(int _id = 00000, string _nombre = "Desconocido", float _precio = 0, int _stock = 0 )
    : id(_id), nombre(_nombre), precio(_precio), stock(_stock) {}

    int getID () {
        return id;
    }

    string getNombre() {
        return nombre;
    }
};

class Inventario {
    private:
    Vector<Producto> Inv;
    public:
    
    void AgregarProducto(int id, string nombre, float precio, int stock) {
        Producto temp(id, nombre, precio, stock);
        Inv.pushBack(temp);
    }

    void EliminarProducto(int id) {
        int index;
        for (int i = 0 ; i < Inv.getSize() ; i++) {
            if (id == Inv.at(i).getID()) {
                index = i;
                break;
            }
        }
        Producto temp;
        Inv.eliminar(index);
    }

    void BuscarProducto(string nombre) {
        int index;
        for (int i = 0 ; i < Inv.getSize() ; i++) {
            if (nombre == Inv.at(i).getNombre()) {
                index = i;
                break;
            }
        }

        cout << "Producto encontrado en la posición: " << index << endl;
    }
};
