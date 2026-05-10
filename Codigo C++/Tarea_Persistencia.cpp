#include <iostream>
#include <fstream>  // Requerido para ofstream
#include <string>
#include <limits>   // Requerido para validaciones robustas

using namespace std;

// Funcion para evitar errores si el usuario ingresa letras en campos numericos
void validarFlujo() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

int main() {
    int opcion;
    string nombre, carrera;
    int edad;
    float promedio;
    string nombreArchivo = "Datos.txt";

    do {
        cout << "\n--- MENU INTERACTIVO ---" << endl;
        cout << "1. Registrar Estudiante" << endl;
        cout << "2. Salir" << endl;
        cout << "Seleccione una opcion: ";
        
        if (!(cin >> opcion)) {
            cout << "Opcion invalida. Intente de nuevo." << endl;
            validarFlujo();
            continue;
        }

        switch (opcion) {
            case 1:
                cin.ignore(); // Limpiar salto de linea previo
                cout << "Nombre Completo: ";
                getline(cin, nombre);

                cout << "Edad: ";
                while (!(cin >> edad) || edad <= 0) {
                    cout << "Error. Ingrese una edad valida: ";
                    validarFlujo();
                }

                cin.ignore();
                cout << "Carrera: ";
                getline(cin, carrera);

                cout << "Promedio (0-10): ";
                while (!(cin >> promedio) || promedio < 0 || promedio > 10) {
                    cout << "Error. Ingrese un promedio entre 0 y 10: ";
                    validarFlujo();
                }

                // USO DE OFSTREAM, IOS::APP Y CLOSE()
                {
                    ofstream archivo;
                    archivo.open(nombreArchivo, ios::app); // Persistencia (modo agregar)
                    
                    if (archivo.is_open()) {
                        archivo << "Estudiante: " << nombre << " | "
                                << "Edad: " << edad << " | "
                                << "Carrera: " << carrera << " | "
                                << "Promedio: " << promedio << endl;
                        
                        archivo.close(); // REQUERIMIENTO: Cierre manual
                        cout << "[!] Informacion guardada permanentemente." << endl;
                    } else {
                        cout << "Error al abrir el archivo." << endl;
                    }
                }
                break;

            case 2:
                cout << "Finalizando programa..." << endl;
                break;

            default:
                cout << "Opcion fuera de rango." << endl;
        }
    } while (opcion != 2);

    return 0;
}