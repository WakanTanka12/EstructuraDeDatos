#include <iostream>
#include <string>
#include <iomanip>

#define MAX 1000
 //sexo sexo ñi Ñi

using namespace std;

int total = 0;

void assign_letter(float WakanGrades[], char WakanLetter[], int n);
void new_student(string WakanNames[], float WakanGrades[], char WakanLetter[], int n);
void sort_by_grade(float WakanGrades[]);
void show_sheet(string WakanNames[], float WakanGrades[], char WakanLetter[]);

int main()
{
    int option, n;
    float WakanGrades[MAX];
    char WakanLetter[MAX];
    string WakanNames[MAX];
    while (true) {
        cout << "\t MENU" << endl
            << "1. Ingresar estudiantes" << endl
            << "2. Ver la nota mas alta" << endl
            << "3. Ver la nota mas baja" << endl
            << "4. Ver el promedio del grupo" << endl
            << "5. Ver la cantidad de aprobados" << endl
            << "6. Ver la cantidad de reprobados" << endl
            << "7. Ver la informacion completa" << endl
            << "0. Salir" << endl;
        cout << "Ingrese la opcion que desee: ";
        cin >> option;
        
        switch (option) {
            case 1: {
                cout << "Cuantos estudiantes quiere ingresar?: ";
                cin >> n;
                new_student(WakanNames, WakanGrades, WakanLetter, n);
                sort_by_grade(WakanGrades);
                break;
            }
            case 2: {
                cout << "El estudiante con la nota más alta es: " << endl;
                cout << WakanNames[total - 1] << " " << WakanGrades[total - 1];
                break;
            }
            case 3: {
                cout << "El estudiante con la nota más baja es: " << endl;
                cout << WakanNames[0] << " " << WakanGrades[0];
                break;
            }
            case 4: {
                float promedio, suma = 0;
                for (int i = 0 ; i < total ; i++) {
                    suma += WakanGrades[i];
                }
                promedio = suma / total;
                cout << "El promedio de todas las notas es: " << promedio;
                break;
            }
            case 5: {
                int aprobados = 0;
                for (int i = 0 ; i < total ; i++) {
                    if (WakanGrades[i] >= 60) 
                        aprobados++;
                }
                cout << "La cantidad de aprobados es: " << aprobados;
                break;
            }
            case 6: {
                int reprobados = 0;
                for (int i = 0 ; i < total ; i++) {
                    if (WakanGrades[i] < 60)
                        reprobados++;
                }
                break;
            }
            case 7: {
                show_sheet(WakanNames, WakanGrades, WakanLetter);
                break;
            }
            default: {
                return 0;
                break;
            }
        }
    }
}

void assign_letter(float WakanGrades[], char WakanLetter[], int n, int total) {
    for (int i = total - 1; i < total + n ; i++) {
        if (WakanGrades[i] >= 90)
            WakanLetter[i] = 'A';
        else if (WakanGrades[i] < 90 && WakanGrades[i] >= 80)
            WakanLetter[i] = 'B';
        else if (WakanGrades[i] < 80 && WakanGrades[i] >= 70)
            WakanLetter[i] = 'C';
        else if (WakanGrades[i] < 70 && WakanGrades[i] >= 60)
            WakanLetter[i] = 'D';
        else 
            WakanLetter[i] = 'F';
    }
}
void new_student(string WakanNames[], float WakanGrades[], char WakanLetter[], int n) {
    for (int i = total; i < total + n; i++) {
        cout << "Ingrese el nombre del estudiante: ";
        cin.ignore();
        getline(cin, WakanNames[i]);
        cout << "Ingrese la nota del estudiante: ";
        cin >> WakanGrades[i];
        while (WakanGrades[i] < 0 || WakanGrades[i] > 100) {
            cout << "Valor invalido, por favor ingrese una nota entre 0 y 100: ";
            cin >> WakanGrades[i];
        }
    }

    total += n;
    assign_letter(WakanGrades, WakanLetter, n, total);
}

void sort_by_grade(float WakanGrades[]) {
    int index_length = total - 1;
    bool sorted = false;
    while (!sorted) {
        sorted = true;
        for (int i = 0 ; i <= index_length ; i++)
            if (WakanGrades[i] > WakanGrades[i + 1]) {
                swap (WakanGrades[i], WakanGrades[i + 1]);
                sorted = false;
            }
    }
}
void show_sheet(string WakanNames[], float WakanGrades[], char WakanLetter[]) {
    for (int i = 0; i < total; i++) {
        cout << setw(30) << WakanNames[i] << setw(5) << WakanGrades[i] << setw(10) << WakanLetter[i] << endl;
    }
}
