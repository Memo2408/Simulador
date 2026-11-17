#pragma once
#include <cstddef>
#include <vector>
#include "proceso.h"
// Lo programa Germán en generador.cpp
class Generador {
public:
    Generador(int maxTamano, int maxCuanto);           // procesos al azar
    Generador(std::vector<Proceso> fijos);             // lista fija, para pruebas
    Proceso* siguiente();             // lo crea con new; con lista fija, nullptr al acabarse
private:
    int maxTamano = 0, maxCuanto = 0, siguienteId = 1;
    std::vector<Proceso> fijos;
    std::size_t pos = 0;
};
