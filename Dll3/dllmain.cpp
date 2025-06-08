#include "pch.h"
#include <Windows.h>

// Declaración de la función MainThread desde otro archivo
DWORD WINAPI MainThread(LPVOID lpReserved);

BOOL APIENTRY DllMain(HMODULE hModule, DWORD  ul_reason_for_call, LPVOID lpReserved)
{
    if (ul_reason_for_call == DLL_PROCESS_ATTACH)
    {
        // Crear un hilo para manejar la lógica del DLL
        CreateThread(nullptr, 0, MainThread, hModule, 0, nullptr);
    }
    return TRUE;
}
