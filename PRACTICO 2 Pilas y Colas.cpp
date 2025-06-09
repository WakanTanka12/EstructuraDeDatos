#include "Queue.h"
#include <string>

//1.
class Paquete {
    private:
    int id;
    string tipo;
    public:
    Paquete (int _id = 0, string _tipo = "Desconocido") : id(_id), tipo(_tipo){}

    friend ostream& operator<<(ostream& os, const Paquete& p) {
        os << "ID: " << p.id << " Tipo: " << p.tipo;
        return os;
    }
};

class Almacen {
    private:
    Queue<Paquete> Inventario;
    public:
    void AgregarPaquete(const Paquete &p) {
        Inventario.push(p);
    }

    bool QuitarPaquete() {
        Paquete value;
        return Inventario.pop(value);
    }
    void MostrarPaquetes() {
        Inventario.print();
    }
};

int main() {    
    Almacen A;
    int opcion;
    while(true) {
        cout << "1. Agregar Paquete" << endl;
        cout << "2. Sacar paquete" << endl;
        cout << "3. Mostrar" << endl;
        cout << "0. Salir" << endl;
        cin >> opcion;

        switch(opcion) {
            case 1: {
                int id;
                string tipo;
                cin >> id;
                cin.ignore();
                getline(cin, tipo);
                Paquete p(id, tipo);
                A.AgregarPaquete(p);
                break;
            }
            case 2: {
                if(A.QuitarPaquete()) {
                } else {
                    cout << "Ya no hay ningun paquete";
                }
                break;
            }
            case 3: {
                A.MostrarPaquetes();
            }
            case 0: {
                return 0;
            }
        }
    }
    return 0;
}

#include "Stack.h"

//2.
class Libro {
    private:
    string Titulo;
    string Autor;
    string Editorial;

    friend ostream& operator<<(ostream& os, const Libro& l) {
        os << "Titulo: " << l.Titulo << " Autor: " << l.Autor << " Editorial: " << l.Editorial;
        return os;
    }

    public:
    Libro(string T, string A, string E) : Titulo(T), Autor(A), Editorial(E) {}
};

class Libreria {
    private:
    Stack<Libro> Libros;
    public:
    void AgregarLibro(string T, string A, string E) {
        Libro L(T, A, E);
        Libros.push(L);
    }
    void mostrar() {
        Libros.print();
    }
};

int main () {
    Libreria L1;
    L1.AgregarLibro("48 Leyes del poder", "Robert Greene", "Viking Press");
    L1.mostrar();
}

#include <iostream>
#include "Queue.h"

//3.
class Paciente {
    private:
    string nombre;
    int edad;
    string motivo;
    public:
    Paciente(string n, int e, string m) : nombre(n), edad(e), motivo(m){}

    friend ostream& operator<<(ostream& os, const Paciente& p) {
        os << "Nombre: " << p.nombre << " Edad: " << p.edad << " Motivo: " << p.motivo;
        return os;
    }
};

class SalaDeEspera {
    private:
    Queue<Paciente> Sala;
    public:
    void NuevoPaciente(string n, int e, string m) {
        Paciente P(n, e, m);
        Sala.push(P);
    }
    void Mostrar() {
        Sala.print();
    }
};

int main() {
    SalaDeEspera Sala;
    Sala.NuevoPaciente("Axel Gutierrez", 18, "Difuncion erectil");
    Sala.Mostrar();
    return 0;
}

#include <iostream>
#include "Queue.h"

//4.
class Documento {
    private:
    string nombre;
    int nPaginas;
    public:
    Documento(string n = "Desconocido", int np = 0) : nombre(n), nPaginas(np) {}

    friend ostream& operator<<(ostream& os, const Documento& D) {
        os << "|Nombre: " << D.nombre << " |Número de Páginas: " << D.nPaginas;
        return os;
    }

};

class Impresora {
    private:
    Queue<Documento> Cola;
    public:
    void AgregarDocumento(string n, int np) {
        Documento D(n, np);
        Cola.push(D);
    }

    void VerProximoDoc() {
        Documento value;
        if(Cola.peek(value)) {
            cout << value;
        } else {
            cout << "Ya no hay ningún documento en la cola" << endl;
        }
    }
};

int main() {
    Impresora a;
    a.AgregarDocumento("Como hacer handstreams", 20);
    a.VerProximoDoc();
}

#include <iostream>
#include "Stack.h"

//5
class Plato {
    private:
    string ID;
    string tipo;
    public:
    Plato(string _ID = "Desconocido", string _tipo = "Desconocido") : ID(_ID), tipo(_tipo) {}

    friend ostream& operator<<(ostream& os, const Plato& P) {
        os << "|ID: " << P.ID << " |Tipo: " << P.tipo;
        return os;
    }

};

class Lavaplato {
    private:
    Stack<Plato> L;
    public:
    void nuevoPlato(string _ID, string tipo) {
        Plato P(_ID, tipo);
        L.push(P);
    }

    void LavarPlatos(int n) {
        Plato value;
        for(int i = 0 ; i < n ; i++) {
            if(L.pop(value)) {
            } else {
                cout << "Ya no hay ningun plato" << endl;
                return;
            }
        }
    }

    void MostrarPila() {
        L.print();
    }
};

int main () {
    Lavaplato a;
    a.nuevoPlato("01001", "Hondo");
    a.nuevoPlato("02344", "Hondo");
    a.nuevoPlato("04566", "Hondo");
    a.nuevoPlato("05278", "Plano");
    a.MostrarPila();
    a.LavarPlatos(3);
    a.MostrarPila();
}

#include <iostream>
#include <string>
#include "Queue.h"

//6.
class Cliente {
    private:
    string nombre;
    string motivo;
    public:
    Cliente(string _nombre = "Desconocido", string _motivo = "Desconocido") : nombre(_nombre), motivo(_motivo) {}

    friend ostream& operator<<(ostream& os, const Cliente& C) {
        os << "|Nombre: " << C.nombre << " |Motivo: " << C.motivo;
        return os;
    }
};

int main() {
    int opcion;
    Queue<Cliente> Fila;
    while(true) {
        cout << "1. Nuevo Cliente" << endl;
        cout << "2. Atender Cliente" << endl;
        cout << "3. Mostrar Fila" << endl;
        cout << "0. Salir" << endl;
        cin >> opcion;
        switch(opcion) {
            case 1: {
                string nombre, motivo;
                cout << "Ingrese el nombre: ";
                cin.ignore();
                getline(cin, nombre);
                cout << "Ingrese el motivo: ";
                getline(cin, motivo);
                Cliente C(nombre, motivo);
                Fila.push(C);
                break;
            }
            case 2: {
                Cliente value;
                if(Fila.pop(value)) {
                } else {
                    cout << "Ya no hay mas clientes";
                }
                break;
            }
            case 3: {
                Fila.print();
                break;
            }
            case 0: {
                return 0;
                break;
            }
        }
    }
}

#include <iostream>
#include "Queue.h"

//7.
class Caja {
    private:
    int fecha;
    int unidades;
    public:
    Caja(int _fecha = 0, int _unidades = 0) : fecha(_fecha), unidades(_unidades) {}
};

class Almacen {
    private:
    Queue<Caja> a;
    public:
    void AgregarCaja(int fecha, int unidades) {
        Caja Caja1(fecha, unidades);
        a.push(Caja1);
    }

    void QuitarCaja() {
        Caja value;
        a.pop(value);
    }
};

int main () {
    Almacen WakanAlmacen;
    WakanAlmacen.AgregarCaja(1745891022, 20);
    WakanAlmacen.AgregarCaja(1740149262, 10);
    return 0;
}

#include <iostream>
#include "Stack.h"

//8.
class action {
    private:
    string actions;
    string contenido;
    public:
    action(string _actions = "", string _contenido = "") : actions(_actions), contenido(_contenido) {}
};

class registro {
    private:
    Stack<action> registro;
    public:
    void nuevaAccion(string accion, string contenido) {
        action WakanAction(accion, contenido);
        registro.push(WakanAction);
    }

    void deshacer() {
        action value;
        registro.pop(value);
    }
};

int main() {
    registro A;
    A.nuevaAccion("Escribir", "HOlaxd");
    A.nuevaAccion("Copiar", "HOlaxd");
    A.deshacer();
}

#include <iostream>
#include "Queue.h"

//9.
class Pasajero {
    private:
    string nombre;
    string destino;
    public:
    Pasajero() {
        nombre = "Desconocido";
        destino = "Desconocido";
    }
    Pasajero(string _nombre, string _destino) {
        nombre = _nombre;
        destino = _destino;
    }
};

class Fila {
    private:
    Queue<Pasajero> Tren;
    public:
    void AgregarPasajero(string _nombre, string _destino) {
        Pasajero Temp(_nombre, _destino);
        Tren.push(Temp);
    }

    void AtenderPasajero() {
        Pasajero Temp;
        Tren.pop(Temp);
    }

    void MostrarFila() {
        Tren.print();
    }
};

int main () {
    Fila PrimeraFila;
    PrimeraFila.AgregarPasajero("Julio Cesar", "Copacabana");
    PrimeraFila.AtenderPasajero();
}

#include <iostream>
#include "Queue.h"

//10.
class Consulta {
    private:
    string nombre;
    string descripcion;
    public:
    Consulta (string _nombre = "Desconocido", string _descripcion = "") : nombre(_nombre), descripcion (_descripcion) {}

    void imprimir(ostream& os) const {
    os << "Nombre: " << nombre << "  Motivo: " << descripcion;
    }
};

class GestionDeConsultas {
    private:
    Queue<Consulta> Fila;
    public:
    void mostrarConsulta () {
        Consulta value;
        if (Fila.peek(value)) 
            value.imprimir(cout);
        else
            cout << "Ya no hay consultas";
    }

    void agregarConsulta (string _nombre, string _descripcion) {
        Consulta temp(_nombre, _descripcion);
        Fila.push(temp);
    }
};

int main() {
    GestionDeConsultas PrimeraFila;
    PrimeraFila.agregarConsulta("Angelo", "Se me metió un virus");
    PrimeraFila.mostrarConsulta();
    return 0;
}

#include <iostream>
#include "Stack.h"

//11.
class GestionDeExamenes {
    private:
    Stack<int> Notas;
    public:
    float PromedioDeNotas() {
        int value, suma = 0, size = Notas.getSize();
        float promedio;
        for(int i = 0 ; i < size ; i++) {
            if(Notas.pop(value)) {
                suma += value;
            }
        }
        promedio = float(suma) / size;
        return promedio;
    }

    void AgregarNota(int nota) {
        Notas.push(nota);
    }
};

int main() {
    GestionDeExamenes Examenes;
    Examenes.AgregarNota(58);
    Examenes.AgregarNota(100);
    Examenes.AgregarNota(23);
    Examenes.AgregarNota(45);
    cout << Examenes.PromedioDeNotas();
}
