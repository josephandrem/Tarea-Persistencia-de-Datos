Algoritmo GestionEstudiantes
    Definir nombre, carrera Como Cadena
    Definir edad, opcion Como Entero
    Definir promedio Como Real
    
    Repetir
        Escribir "--- MENU PRINCIPAL ---"
        Escribir "1. Registrar Estudiante"
        Escribir "2. Salir"
        Leer opcion
        
        Segun opcion Hacer
            1:
                Escribir "Nombre:"
                Leer nombre
                Repetir
                    Escribir "Edad:"
                    Leer edad
                Hasta Que edad > 0
                Escribir "Carrera:"
                Leer carrera
                Repetir
                    Escribir "Promedio (0-10):"
                    Leer promedio
                Hasta Que promedio >= 0 Y promedio <= 10
                Escribir "Datos guardados en Datos.txt"
            2:
                Escribir "Saliendo..."
            De Otro Modo:
                Escribir "Opcion incorrecta"
        FinSegun
    Hasta Que opcion == 2
FinAlgoritmo