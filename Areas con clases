Encabezado de WakanArea.h

#pragma once
class WakanArea
{
private:
	float base;
	float altura;
	float radio;
public: 
	WakanArea();
	void set_altura(float h);
	void set_base(float b);
	void set_radio(float r);
	float get_altura();
	float get_base();
	float area_rectangulo();
	float area_triangulo();
	float area_circulo();
};

Cpp de WakanArea.h

#include "WakanArea.h"

using namespace std;

WakanArea::WakanArea() {

}
void WakanArea::set_altura(float h) {
	altura = h;
}

void WakanArea::set_base(float b) {
	base = b;
}

void WakanArea::set_radio(float r) {
	radio = r;
}

float WakanArea::get_altura() {
	return altura;
}

float WakanArea::get_base() {
	return base;
}

float WakanArea::area_rectangulo() {
	return (base * altura);
}

float WakanArea::area_triangulo() {
	return (base * altura) / 2;
}

float WakanArea::area_circulo() {
	return (3.1416 * radio * radio);
}

Programa Principal

#include <iostream>
#include "WakanArea.h"
using namespace std;

int main()
{
	int opcion;
	float WakanAltura, WakanBase, WakanRadio;
	
	while (true) {
		cout << "\tMenu de calculo de areas\n"
			 << "1.Rectangulo\n"
			 << "2.Triangulo\n"
			 << "3.Circulo\n"
			 << "0.Salir\n";
		cout << "Ingrese la opcion que desee: ";
		cin >> opcion;
			
		switch (opcion) {
			case 1: {
				cout << "Ingrese la base del rectangulo: ";
				cin >> WakanBase;
				while (WakanBase <= 0) {
					cout << "\nPor favor ingrese un valor mayor a 0: ";
					cin >> WakanBase;
				}

				cout << "Ingrese la altura del rectangulo: ";
				cin >> WakanAltura;
				while (WakanAltura <= 0) {
					cout << "\nPor favor ingrese un valor mayor a 0: ";
					cin >> WakanAltura;
				}

				WakanArea Rectangulo;
				Rectangulo.set_base(WakanBase);
				Rectangulo.set_altura(WakanAltura);
				cout << "El area es: " << Rectangulo.area_rectangulo();

				break;
			}
			case 2: {
				cout << "Ingrese la base del triangulo: ";
				cin >> WakanBase;
				while (WakanBase <= 0) {
					cout << "\nPor favor ingrese un valor mayor a 0: ";
					cin >> WakanBase;
				}

				cout << "Ingrese la altura del triagulo: ";
				cin >> WakanAltura;
				while (WakanAltura <= 0) {
					cout << "\nPor favor ingrese un valor mayor a 0: ";
					cin >> WakanAltura;
				}
				break;
				WakanArea Triangulo;
				Triangulo.set_base(WakanBase);
				Triangulo.set_altura(WakanAltura);
				cout << "El area es: " << Triangulo.area_triangulo();
				break;
			}

			case 3: {
				cout << "Ingrese el area del circulo: ";
				cin >> WakanRadio;
				while (WakanBase <= 0) {
					cout << "\nPor favor ingrese un valor mayor a 0: ";
					cin >> WakanBase;
				}

				WakanArea Circulo;
				Circulo.set_radio(WakanRadio);
				cout << "El area es: " << Circulo.area_circulo();
				break;
			}

			case 0: {
				return 0;
			}

			default: {
				cout << "Valor invalido\n";
			}
		}
	}
	return 0;
}
