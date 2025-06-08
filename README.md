# 💉 [DRG] Cheat Interno de Dinero por Inyección de DLL

> 🔴 **ADVERTENCIA EXTREMA: FINES EDUCATIVOS ÚNICAMENTE**
> Este proyecto es una prueba de concepto sobre la modificación de memoria a través de la inyección de DLLs. Su propósito es puramente educativo para entender cómo funcionan los procesos a bajo nivel. El uso de esta herramienta podría resultar en la corrupción de tu partida guardada o una eventual prohibición. **Úsalo bajo tu propio y absoluto riesgo.**

## 🎯 Descripción del Proyecto

Este repositorio contiene el código fuente en **C++** de un "cheat" interno para el videojuego **Deep Rock Galactic**. A diferencia de una herramienta externa, este proyecto se compila como un archivo de librería de enlace dinámico (`.dll`) que debe ser **inyectado** directamente en el espacio de memoria del proceso del juego.

Una vez inyectado, permite al usuario modificar la cantidad de créditos

## ⚙️ Flujo de Ejecución

1.  **Inyección de DLL**: El usuario utiliza un programa "inyector" para cargar el `.dll` en el proceso del juego.
2.  **Punto de Entrada `DllMain`**: Al inyectar, se llama a la función `DllMain` del DLL.
3.  **Creación de un Hilo (`CreateThread`)**: `DllMain` crea un hilo secundario para no bloquear el juego.
4.  **Bucle Principal y Hotkeys**: El hilo escucha si el usuario presiona una tecla de acceso rápido (hotkey).
5.  **Acceso Directo a Memoria**: Al presionar la hotkey, calcula la dirección de memoria del dinero usando punteros y offsets.
6.  **Modificación de Valor**: Escribe un nuevo valor directamente en esa dirección de memoria.

## 🛠️ Stack Tecnológico

* **C++**: Lenguaje utilizado para el desarrollo de bajo nivel.
* **Windows API (WinAPI)**: Funciones como `CreateThread` y `GetAsyncKeyState`.

## 🚀 Uso y Ejecución

Tienes dos opciones para utilizar esta herramienta.

### Opción 1: (Recomendado) Descargar la Release Pre-compilada

Este es el método más fácil y no requiere conocimientos de programación.

1.  **Ir a la Página de Releases**:
    * **[Haz clic aquí para ir a la página de Releases del proyecto](https://github.com/Russtels/DeepRockGalactic-Money-Internal-Cheat/releases)**

2.  **Descargar el Archivo**:
    * Busca la última versión y descarga el archivo `.dll` que se encuentra en la sección de "Dll3 v1".

3.  **Proceder a la Inyección**:
    * Sigue los pasos descritos en la sección **"Proceso de Inyección"** más abajo.

> **Importante**: La release pre-compilada solo funcionará para la versión específica de Deep Rock Galactic para la que fue creada. Si el juego se ha actualizado recientemente, es probable que esta opción no funcione y debas usar la Opción 2.

### Opción 2: (Avanzado) Compilar desde el Código Fuente

Este método es para desarrolladores o si la release pre-compilada está desactualizada.

1.  **Clonar y Compilar**:
    * Clona el repositorio.
    * Abre la solución (`.sln`) en Visual Studio.
    * Asegúrate de que los **offsets** en el código son correctos para tu versión del juego (esto es crucial).
    * Compila el proyecto en modo **Release** y la arquitectura **x64**. Esto generará tu propio archivo `.dll`.

2.  **Proceder a la Inyección**:
    * Sigue los pasos descritos a continuación.

---

### Proceso de Inyección (Para ambas opciones)

Para que el cheat funcione, necesitas un **inyector de DLLs**.

1.  **Iniciar el Juego**: Abre Deep Rock Galactic y carga tu partida (llega hasta la estación espacial).
2.  **Abrir el Inyector**: Ejecuta tu programa inyector de DLLs (ej. Process Hacker, Xenos Injector, etc.).
3.  **Seleccionar Proceso**: En el inyector, busca y selecciona el proceso del juego. Usualmente se llama `FSD-Win64-Shipping.exe`.
4.  **Seleccionar DLL**: Busca y selecciona el archivo `.dll` que descargaste o compilaste.
5.  **Inyectar**: Ejecuta la inyección. Si no hay errores, el DLL ya estará corriendo dentro del juego.
6.  **Activar en el Juego**: Vuelve al juego y presiona la hotkey definida en el código para activar la funcionalidad.
