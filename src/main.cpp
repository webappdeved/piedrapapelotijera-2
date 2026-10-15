/* 
   ====================================================================
   Materia: Laboratorio de Programación (LPR) — 5° Año
   Institución: E.E.S.T. N° 1 "Eduardo Ader" — Vicente López
   Archivo: src/main.cpp
   Actividad 7: Mini Juego Piedra, Papel o Tijera + Persistencia en Disco
   ====================================================================
*/

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

// 1. Estructura de datos para representar una partida
struct Partida {
    int idPartida;
    string jugador;
    string eleccionJugador;
    string eleccionIA;
    string resultado;
};

// Prototipos de funciones modulares
void jugarPartida(int& contadorID);
void guardarEnDisco(const Partida& p);
void leerHistorialDisco();

int main() {
    // Inicializar la semilla para los números aleatorios de la IA
    srand(time(0));
    
    int contadorID = 1;
    int opcion = 0;

    cout << "=====================================================" << endl;
    cout << "  LPR 2026 - ACTIVIDAD 7: PIEDRA, PAPEL O TIJERA      " << endl;
    cout << "  Estudiante / Grupo: Sofia Mojica                   " << endl;
    cout << "=====================================================" << endl;

    do {
        cout << "\n--- MENU PRINCIPAL DE JUEGO Y PERSISTENCIA ---" << endl;
        cout << "1. Jugar Partida (Piedra, Papel o Tijera)" << endl;
        cout << "2. Ver Historial de Partidas Guardadas en Disco (.txt)" << endl;
        cout << "3. Salir del Sistema" << endl;
        cout << "Ingrese una opcion (1-3): ";
        cin >> opcion;

        if (opcion == 1) {
            jugarPartida(contadorID);
        } 
        else if (opcion == 2) {
            leerHistorialDisco();
        } 
        else if (opcion == 3) {
            cout << "\n[SISTEMA] Saliendo del programa... Datos resguardados en disco." << endl;
        } 
        else {
            cout << "\n[ERROR] Opcion invalida. Reintente." << endl;
        }

    } while (opcion != 3);

    return 0;
}

// Función para procesar la jugada contra la IA
void jugarPartida(int& contadorID) {
    Partida p;
    p.idPartida = contadorID++;

    cout << "\n--- NUEVA PARTIDA #" << p.idPartida << " ---" << endl;
    cout << "Ingrese su Nombre / Nickname: ";
    cin.ignore(); // Limpieza de búfer
    getline(cin, p.jugador);

    int opcJugador = 0;
    cout << "\nElija su jugada:" << endl;
    cout << "1. Piedra" << endl;
    cout << "2. Papel" << endl;
    cout << "3. Tijera" << endl;
    cout << "Opcion (1-3): ";
    cin >> opcJugador;

    // Asignar selección del usuario
    if (opcJugador == 1) p.eleccionJugador = "Piedra";
    else if (opcJugador == 2) p.eleccionJugador = "Papel";
    else p.eleccionJugador = "Tijera";

    // Elección aleatoria de la IA (1 a 3)
    int opcIA = (rand() % 3) + 1;
    if (opcIA == 1) p.eleccionIA = "Piedra";
    else if (opcIA == 2) p.eleccionIA = "Papel";
    else p.eleccionIA = "Tijera";

    // Evaluar reglas del juego
    cout << "\n[JUGADA] " << p.jugador << " eligio: " << p.eleccionJugador << endl;
    cout << "[JUGADA] La IA eligio: " << p.eleccionIA << endl;

    if (p.eleccionJugador == p.eleccionIA) {
        p.resultado = "Empate";
    } 
    else if ((p.eleccionJugador == "Piedra" && p.eleccionIA == "Tijera") ||
             (p.eleccionJugador == "Papel" && p.eleccionIA == "Piedra") ||
             (p.eleccionJugador == "Tijera" && p.eleccionIA == "Papel")) {
        p.resultado = "Ganaste";
    } 
    else {
        p.resultado = "Perdiste";
    }

    cout << "[RESULTADO] Partida finalizada con: " << p.resultado << endl;

    // Guardar la partida de forma persistente en el disco duro
    guardarEnDisco(p);
}

// Función para persistir los datos en el disco con ofstream en modo Append
void guardarEnDisco(const Partida& p) {
    ofstream archivo("src/historial_partidas.txt", ios::app);
    
    if (archivo.is_open()) {
        archivo << p.idPartida << " | " << p.jugador << " | " << p.eleccionJugador 
                << " vs " << p.eleccionIA << " | " << p.resultado << endl;
        archivo.close();
        cout << "[PERSISTENCIA] Partida resguardada en 'src/historial_partidas.txt' correctamente." << endl;
    } else {
        cout << "[ERROR] No se pudo abrir el archivo para guardar datos." << endl;
    }
}

// Función para leer y recuperar el historial con ifstream
void leerHistorialDisco() {
    ifstream archivo("src/historial_partidas.txt");
    string linea;

    cout << "\n=== HISTORIAL RECUPERADO DE ALMACENAMIENTO SECUNDARIO ===" << endl;
    if (archivo.is_open()) {
        bool tieneDatos = false;
        while (getline(archivo, linea)) {
            cout << linea << endl;
            tieneDatos = true;
        }
        if (!tieneDatos) {
            cout << "[SISTEMA] El historial de partidas se encuentra vacio." << endl;
        }
        archivo.close();
    } else {
        cout << "[SISTEMA] No hay historial registrado en el disco aun." << endl;
    }
    cout << "=========================================================" << endl;
}
