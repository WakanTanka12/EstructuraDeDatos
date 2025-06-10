#include "Vector.h"
#include "matrix.h"
#include "MathVector.h"
#include "VectorCalculator.h"
#include "Inventario.h"

using namespace std;

bool simetria(const Vector<int>& v);
int sumarPares(const Vector<int>& v);


int main() {
    // Declarar Vector
    Vector<int> WakanVector;
    WakanVector.pushBack(1);
    WakanVector.pushBack(2);
    WakanVector.pushBack(3);
    WakanVector.pushBack(2);
    WakanVector.pushBack(1);

    // 1. Simetria

    if (simetria(WakanVector))
        cout << "El vector es simetrico" << endl;
    else
        cout << "El vector no es simetrico" << endl;

    // 2. Sumar Pares

    cout << "La suma de los pares es: " << sumarPares(WakanVector) << endl;

    //3.1 Promedio

    MathVector WakanVector2;
    WakanVector2.pushBack(5);
    WakanVector2.pushBack(7);
    WakanVector2.pushBack(4);
    WakanVector2.pushBack(10);
    WakanVector2.pushBack(12);
    WakanVector2.pushBack(10);

    cout << "El promedio es: " << WakanVector2.promedio() << endl;
    //3.2 Mediana
    cout << "La mediana es: " << WakanVector2.mediana() << endl;
    //3.3 Moda
    cout << "La moda es: " << WakanVector2.moda() << endl;
    //4.1 Maximo
    cout << "El maximo es: " << WakanVector2.maximo() << endl;
    //4.2 Minimo
    cout << "El minimo es: " << WakanVector2.minimo() << endl;
    //5.1 Suma
    Vector<int> WakanVector3;
    WakanVector3.pushBack(5);
    WakanVector3.pushBack(7);
    VectorCalculator Sumas;
    Sumas.suma(WakanVector, WakanVector3);
    Sumas.print();
    //5.2 Resta
    VectorCalculator Restas;
    Restas.resta(WakanVector3, WakanVector);
    Restas.print();
    //5.3 Producto punto
    VectorCalculator productoPunto;
    cout << "Producto punto: " << productoPunto.productoPunto(WakanVector, WakanVector3) << endl;
    
    //6.1 Inventario
    Inventario Inv;
    Inv.AgregarProducto(1, "Libro", 50, 5);
    Inv.AgregarProducto(2, "Mantequilla", 100, 20);
    Inv.EliminarProducto(2);
    Inv.BuscarProducto("Libro");    
    return 0;
}

bool simetria(const Vector<int>& v) {
    bool esSimetrica = true;
    int size = v.getSize();
    for (int i = 0 ; i < size/2 ; i++) {
        if (v.at(i) != v.at(size - 1 - i)) {
            esSimetrica = false;
            break;
        }
    }
    return esSimetrica;
}

int sumarPares(const Vector<int>& v) {
    int suma = 0;
    for (int i = 0 ; i < v.getSize() ; i++) {
        if (v.at(i)%2 == 0)
            suma += v.at(i);
    }
    return suma;
}
