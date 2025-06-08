#include "pch.h"
#include <Windows.h>
#include <iostream>
#include "offset_handler.h"

extern int GetMoneyOffset(); // Declaraci�n de una funci�n para obtener el valor actual del dinero
extern void SetMoneyOffset(int newValue); // Declaraci�n correcta de SetMoneyOffset

DWORD WINAPI MainThread(LPVOID lpReserved)
{
    // Crear una nueva consola para interactuar con el usuario
    AllocConsole();
    FILE* fStream;
    freopen_s(&fStream, "CONOUT$", "w", stdout); // Redirige la salida est�ndar a la consola
    freopen_s(&fStream, "CONIN$", "r", stdin);   // Redirige la entrada est�ndar a la consola

    InitOffsetHandler();

    // Bucle principal para interacci�n de consola
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
            std::cout << "Entrada inv�lida. Por favor ingrese un n�mero." << std::endl;
            continue;
        }

        SetMoneyOffset(newMoneyValue);
        std::cout << "El valor del dinero ha sido actualizado a: " << newMoneyValue << std::endl;
        Sleep(500); // Peque�a espera para evitar sobrecarga
    }

    return 0;
}
