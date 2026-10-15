# MANUAL TÉCNICO DEL PROGRAMADOR Y ARQUITECTURA DE CÓDIGO
## Proyecto: Mini Juego "Piedra, Papel o Tijera" con Persistencia de Datos (fstream)
## Institución: E.E.S.T. N° 1 "Eduardo Ader" Vicente López
## Asignatura: Laboratorio de Programación (LPR) - 5° Año 3° División
## Docente: Mansilla Muñoz York Elías
## Autor / Grupo: Gabriel Zacarías, Sofía Mojica, Leonel De Armas, Mateo Roberts (Grupo N.º 3)
## Fecha: 15 de octubre de 2026 | Versión: v1.0.0

---

## CONTROL DE VERSIONES Y CHANGELOG

| Versión | Fecha | Autor | Descripción de Cambios |
| :--- | :--- | :--- | :--- |
| v1.0.0 | 15/10/2026 | Grupo 3 | Emisión inicial de la suite del juego interactivo en C++ con persistencia de estructuras en disco no volátil. |

---

## 1. ARQUITECTURA DEL SISTEMA Y ENTORNO DE DESARROLLO

* **Requisitos:** Compilador `g++` (MinGW-w64 GCC v16.2.0+) con C++11 habilitado, Visual Studio Code y PowerShell.
* **Estructura:** Incluye archivos de configuración de Git, la licencia MIT, documentación en `docs/`, código fuente en `src/main.cpp`, archivo de persistencia `historial_partidas.txt` y capturas de evidencia.

---

## 2. DOCUMENTACIÓN DE MÓDULOS Y FUNCIONES (`src/main.cpp`)

* **Estructura Global (`struct Partida`):** Almacena `idPartida`, `jugador`, `eleccionJugador`, `eleccionIA` y `resultado`.
* **Módulos Principales:**
  * `jugarPartida`: Controla la lógica de juego y gestiona el buffer con `cin.ignore()`.
  * `guardarEnDisco`: Guarda los datos usando `ofstream` con la bandera `ios::app` para evitar sobreescrituras.
  * `leerHistorialDisco`: Lee los registros del archivo de texto secuencialmente mediante `ifstream`.

---

## 3. INSTRUCCIONES DE COMPILACIÓN Y DIAGNÓSTICO

* **Compilación:** Ejecutar `g++ src/main.cpp -o src/piedrapapelotijera.exe` y luego `.\src\piedrapapelotijera.exe` en PowerShell.
* **Diagnóstico:** Verificar la existencia de la carpeta `src/` si fallan los streams y asegurar el uso de `srand(time(0))` para la aleatoriedad de la IA.

---

## 4. REFERENCIAS
* Kernighan, B. W., & Ritchie, D. M. (1988). *El lenguaje de programación C* (2.ª ed.). Prentice Hall.
* Stroustrup, B. (2013). *The C++ programming language* (4th ed.). Addison-Wesley.
