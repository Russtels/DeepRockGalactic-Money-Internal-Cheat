#include "pch.h"
#include <Windows.h>
#include <iostream>
#include "offset_handler.h"

extern int GetMoneyOffset(); // Declaración de una función para obtener el valor actual del dinero
extern void SetMoneyOffset(int newValue); // Declaración correcta de SetMoneyOffset

DWORD WINAPI MainThread(LPVOID lpReserved)
{
    // Crear una nueva consola para interactuar con el usuario
    AllocConsole();
    FILE* fStream;
    freopen_s(&fStream, "CONOUT$", "w", stdout); // Redirige la salida estándar a la consola
    freopen_s(&fStream, "CONIN$", "r", stdin);   // Redirige la entrada estándar a la consola

    InitOffsetHandler();

    // Bucle principal para interacción de consola
    while (true)
    {
        int currentMoneyValue = GetMoneyOffset();
        std::cout << "Cantidad actual de dinero: " << currentMoneyValue << std::endl;

        int newMoneyValue;
        std::cout << "Ingrese el nuevo valor de dinero (puede ser decimal o hexadecimal con prefijo 0x): ";
        std::cin >> std::hex >> newMoneyValue;

        if (std::cin.fail())
        {
            std::cin.clear(); // Limpia la bandera de error
            std::cin.ignore(INT_MAX, '\n'); // Ignora el resto de la entrada
            std::cout << "Entrada inválida. Por favor ingrese un número." << std::endl;
            continue;
        }

        SetMoneyOffset(newMoneyValue);
        std::cout << "El valor del dinero ha sido actualizado a: " << newMoneyValue << std::endl;
        Sleep(500); // Pequeña espera para evitar sobrecarga
    }

    return 0;
}
