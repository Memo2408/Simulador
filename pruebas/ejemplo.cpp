// Ejemplo de prueba: cada prueba es un .cpp con su propio main().
// Compilar desde la carpeta del proyecto:
//   g++ -std=c++17 -Wall -o ejemplo.exe pruebas\ejemplo.cpp
// Copia la función revisar() a tu prueba y agrega tus casos.
#include <iostream>
#include <string>
#include "../src/proceso.h"

static int fallas = 0;

static void revisar(bool ok, const std::string& que) {
    std::cout << (ok ? "OK    " : "FALLA ") << que << "\n";
    if (!ok) ++fallas;
}

int main() {
    Proceso p{1, 300, 10};
    revisar(p.id == 1 && p.tamano == 300 && p.cuanto == 10, "Proceso [1,300,10]");
    std::cout << (fallas ? "Hay fallas\n" : "Todo bien\n");
    return fallas ? 1 : 0;
}
