Encabezado de WakanOperaciones

#pragma once

using namespace std;
class WakanOperaciones
{
private:
	//Data
	float num1, num2, suma;
public:
	//constructor - métodos -
	WakanOperaciones();
	void CalcularSuma();
};

Cpp de WakanOperaciones

#include "WakanOperaciones.h"
#include <iostream>

using namespace std;

//constructor - métodos -
WakanOperaciones::WakanOperaciones() {
	num1 = 4;
	num2 = 5.2;
}
void WakanOperaciones::CalcularSuma() {
	suma = num1 + num2;
	cout << "El resultado es: " << suma;
	
}

Programa Main

#include <iostream>
#include "WakanOperaciones.h"
using namespace std;

int main() {
    WakanOperaciones suma;
    suma.CalcularSuma();
    return 0;
}

