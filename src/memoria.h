#pragma once
#include <string>
#include <vector>
#include "proceso.h"
class Memoria {                       // PrimerAjuste y Buddy heredan de aquí
public:
    virtual bool colocar(Proceso* p) = 0;              // false si no cabe
    virtual void descargar(int id) = 0;                // deja el hueco, SIN unir
    virtual bool condensar() = 0;                      // une huecos o compañeros; true si unió algo
    virtual std::vector<std::string> eventos() = 0;    // avisos pendientes; al leerlos se borran
    virtual std::string imprimir() = 0;                // "[1,300,10][0,3796,0]"
    virtual ~Memoria() {}
};
