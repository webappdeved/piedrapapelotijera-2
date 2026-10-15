# GUÍA DE USUARIO Y OPERACIÓN DEL SISTEMA
## Proyecto: Mini Juego "Piedra, Papel o Tijera" con Persistencia de Datos (fstream)
## Institución: E.E.S.T. N° 1 "Eduardo Ader" Vicente López
## Asignatura: Laboratorio de Programación (LPR) - 5° Año 3° División
## Autor: Grupo N.º 3 (Zacarias G., Mojica S., De Armas L., Roberts M.)
## Versión: v1.0.0 | Fecha: 15 de octubre de 2026

---

## CONTROL DE VERSIONES

| Versión | Fecha | Descripción |
| :--- | :--- | :--- |
| v1.0.0 | 15/10/2026 | Emisión de la guía inicial del usuario para la versión ejecutable del juego en consola con soporte de archivos no volátiles. |

---

## 1. REQUISITOS MÍNIMOS DEL SISTEMA
* Sistema Operativo: Windows 10 o Windows 11 (64-bit).
* Consola de Comandos: Windows PowerShell 5.1+ o Símbolo del sistema (CMD).
* Memoria RAM: 512MB libres de espacio volátil.
* Almacenamiento: 10MB de espacio disponible en disco duro o unidad de estado sólido para el archivo histórico.

---

## 2. GUÍA PASO A PASO DE EJECUCIÓN

### Paso 1: Apertura de la Terminal
Abra la carpeta del proyecto piedrapapelotijera en el explorador de Windows, presione la tecla Shift y haga clic derecho en un área vacía. Seleccione la opción "Abrir la ventana de PowerShell aquí". Alternativamente, puede inicializar el entorno desde la terminal integrada de Visual Studio Code utilizando el atajo Ctrl + Ñ.

### Paso 2: Invocación del Ejecutable
En la línea de comandos activa de la terminal, ingrese la ruta del binario compilado y presione Enter para inicializar el hilo de ejecución:
```powershell
.\src\piedrapapelotijera.exe
```

### Paso 3: Operación del Menú e Interpretación de Resultados
Una vez en ejecución, la interfaz de consola desplegará el encabezado institucional y el menú principal del sistema:

```text
=====================================================
  LPR 2026 - ACTIVIDAD 7: PIEDRA, PAPEL O TIJERA      
  Estudiante / Grupo: Sofia Mojica (Grupo 3)
=====================================================

--- MENU PRINCIPAL DE JUEGO Y PERSISTENCIA ---
1. Jugar Partida (Piedra, Papel o Tijera)
2. Ver Historial de Partidas Guardadas en Disco (.txt)
3. Salir del Sistema
Ingrese una opcion (1-3): 
```

* Selección Opción 1: El sistema solicitará el ingreso de un Nickname por teclado. A continuación, proveerá un submenú numérico para capturar la jugada del operador (1 para Piedra, 2 para Papel, 3 para Tijera). La aplicación generará de forma pseudoaleatoria la jugada de la inteligencia artificial, comparará los estados lógicos bajo las reglas del juego, imprimirá el veredicto en pantalla (Ganaste, Perdiste o Empate) y persistirá la línea de texto en el disco duro.
* Selección Opción 2: El subprograma suspenderá temporalmente la lógica del juego para abrir el flujo de lectura hacia el almacenamiento secundario, volcando en la pantalla todas las filas de texto correspondientes al histórico de enfrentamientos resguardados.

---

## 3. RESOLUCIÓN DE PROBLEMAS FRECUENTES (FAQ)

### 1. Problema: La ventana de la consola se abre y se cierra instantáneamente al ejecutar.
* Causa: El binario fue invocado mediante doble clic en el entorno gráfico, provocando que Windows destruya el proceso de la terminal al retornar la función main.
* Solución: Inicialice explícitamente una instancia de PowerShell o CMD y acceda al directorio mediante comandos de navegación de rutas (cd) antes de ejecutar el binario.

### 2. Problema: El flujo salta automáticamente la captura del nombre de usuario y bloquea la entrada.
* Causa: Presencia de un carácter de escape residual de salto de línea (\n) alojado en el buffer de entrada del teclado provocado por una lectura numérica previa.
* Solución: El programa ya cuenta con la instrucción cin.ignore() integrada de forma nativa para purgar el buffer antes de inicializar la captura estructurada de texto.

---

## 4. REFERENCIAS
* Microsoft Corporation. (2026). Documentación técnica de Windows PowerShell y flujos de E/S. https://microsoft.com
