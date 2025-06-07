# LAB7 - Detección y Análisis de Errores en C++

## Descripción

Este laboratorio está enfocado en la identificación, análisis y corrección de errores comunes en programas escritos en C++. Se abordan errores de diferentes tipos, incluyendo:

- **Errores de sintaxis**
- **Errores de tiempo de ejecución** (por ejemplo, división por cero)
- **Errores de acceso a memoria** (acceso fuera de los límites de un arreglo, uso de memoria después de liberarla, pérdida de memoria, uso de memoria no inicializada)
- **Condiciones de carrera** en programas concurrentes con hilos

El laboratorio incluye ejemplos de código que presentan estos errores intencionalmente, para que el estudiante los detecte y analice utilizando herramientas como **Sanitizers** y **Valgrind**.

## Archivos principales

- `main.cpp`: Ejemplo con errores de sintaxis, división por cero y acceso fuera de los límites de un arreglo.
- `programa.cpp`: Ejemplo de división por cero.
- `memoria.cpp`: Ejemplo de errores de memoria (fuga de memoria, acceso fuera de límites, uso de memoria no inicializada).
- `sanitizers.cpp` y `sanitizers2.cpp`: Ejemplos para detectar errores de memoria y condiciones de carrera usando sanitizers.
- `hilos.cpp`: Ejemplo de uso correcto de mutex para evitar condiciones de carrera en programas concurrentes.

## Instrucciones

1. **Compila los programas** usando las banderas adecuadas para activar los sanitizers, por ejemplo:
   ```
   g++ -fsanitize=address -g programa.cpp -o programa
   ```
   o para detectar condiciones de carrera:
   ```
   g++ -fsanitize=thread -g sanitizers2.cpp -o sanitizers2 -lpthread
   ```

2. **Ejecuta los programas** y observa los mensajes de error generados por los sanitizers o valgrind.

3. **Analiza y corrige** los errores detectados.

## Objetivo

Familiarizarse con los errores más comunes en C++ y aprender a utilizar herramientas de análisis dinámico para detectarlos y corregirlos, mejorando así la calidad y robustez del software. 