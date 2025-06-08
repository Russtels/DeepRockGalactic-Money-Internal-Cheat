#include "pch.h"
#include <Windows.h>
#include "offset_handler.h"
#include "offsets.h"
#include <cstdint> // Para uintptr_t y tipos enteros de tama�o fijo

uintptr_t baseAddress; // Variable global para almacenar la direcci�n base del m�dulo

void InitOffsetHandler()
{
    // Obtener la direcci�n base del m�dulo del juego
    baseAddress = (uintptr_t)GetModuleHandle(L"FSD-Win64-Shipping.exe");
}

void SetMoneyOffset(int newValue)
{
    // Paso 1: Obtener la direcci�n intermedia
    uintptr_t intermediateAddress = *(uintptr_t*)(baseAddress + 0x6006AF0);

    // Paso 2: Calcular la direcci�n final sumando el offset
    uintptr_t moneyAddress = intermediateAddress + 0x588;

    // Modificar el valor en esa direcci�n
    *(int*)moneyAddress = newValue;
}

int GetMoneyOffset()
{
    // Paso 1: Obtener la direcci�n intermedia
    uintptr_t intermediateAddress = *(uintptr_t*)(baseAddress + 0x6006AF0);

    // Paso 2: Calcular la direcci�n final sumando el offset
    uintptr_t moneyAddress = intermediateAddress + 0x588;

    // Retornar el valor actual del dinero
    return *(int*)moneyAddress;
}
