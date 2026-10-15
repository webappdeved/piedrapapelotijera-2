# Registro de Cambios (Changelog) - Grupo N.º 3
## Proyecto Integrador Anual - LPR 2026

Todos los cambios notables en este proyecto serán documentados en este archivo siguiendo los estándares de control de versiones académicos.

---

## 2026-10-13
###  Añadido
- Implementación de la estructura base del mini juego interactivo de Piedra, Papel o Tijera en `src/main.cpp`.
- Modelado de datos complejos mediante el uso del `struct Partida` para empaquetar variables heterogéneas.
- Integración de persistencia no volátil en almacenamiento secundario utilizando la librería `<fstream>` (`ofstream` en modo `ios::app`).
- Desarrollo de la función modular `leerHistorialDisco` empleando `ifstream` para recuperar registros del disco.
- Configuración de los archivos de entorno y control de versiones `.gitignore` y `.gitattributes`.
- Creación de evidencias gráficas locales en la carpeta `capturas/` (`jugada_consola.png` y `archivo_disco.png`).

###  Corregido
- Corrección de marcas de agua antiplagio insertando los datos institucionales reales de la E.E.S.T. N.° 1 "Eduardo Ader" y el nombre de la estudiante Sofia Mojica.
- Limpieza de saltos de línea remanentes en el búfer de entrada de la terminal mediante la función `cin.ignore()` antes de las capturas de cadenas.
