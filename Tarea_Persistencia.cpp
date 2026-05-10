#include <iostream>
#include <fstream>
#include <string>
#include <limits> // Necesaria para limpiar el buffer de forma segura

using namespace std;

int main() {
    string nombre, carrera, nombreArchivo = "Datos.txt";
    int edad, cantidad;
    float promedio;

    cout << "Ingrese la cantidad de estudiantes a registrar: ";
    while (!(cin >> cantidad) || cantidad <= 0) {
        cout << "Cantidad no valida. Ingrese un numero entero positivo: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    for (int i = 0; i < cantidad; i++) {
        cout << "\n--- Estudiante " << i + 1 << " ---" << endl;
        
        cin.ignore(); // Limpiar el salto de linea anterior
        cout << "Nombre completo: ";
        getline(cin, nombre);

        cout << "Edad: ";
        cin >> edad;
        while (edad <= 0) {
            cerr << "Edad invalida. Debe ser positiva: ";
            cin >> edad;
        }

        cin.ignore();
        cout << "Carrera: ";
        getline(cin, carrera);

        cout << "Promedio: ";
        cin >> promedio;
        while (promedio < 0 || promedio > 10) {
            cerr << "Promedio invalido (0-10): ";
            cin >> promedio;
        }

        // GUARDAR DATOS (Dentro del ciclo para no perder registros)
        ofstream archivo(nombreArchivo, ios::app); 
        if (archivo.is_open()) {
            archivo << "Nombre: " << nombre << "\n"
                    << "Edad: " << edad << "\n"
                    << "Carrera: " << carrera << "\n"
                    << "Promedio: " << promedio << "\n"
                    << "------------------------" << endl;
            archivo.close(); // REQUERIMIENTO: close()
            cout << "Registro guardado en el archivo." << endl;
        } else {
            cerr << "Error: No se pudo abrir el archivo." << endl;
        }
    }

    cout << "\nProceso finalizado correctamente." << endl;
    return 0;
}