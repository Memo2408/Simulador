#pragma once
#include "memoria.h"
// Leonardo: la parte pública no se cambia. Agrega tus datos en private
// y escribe las funciones en buddy.cpp.
class Buddy : public Memoria {
public:
    Buddy(int memoriaKB);                              // empieza con un solo bloque libre de memoriaKB
    bool colocar(Proceso* p) override;
    void descargar(int id) override;
    bool condensar() override;
    std::vector<std::string> eventos() override;
    std::string imprimir() override;
private:
    struct Bloque {
        int inicio;
        int tamano;
        Proceso* proceso; // nullptr indica que el bloque esta libre
    };

    int memoriaKB;
    std::vector<Bloque> bloques;
    std::vector<std::string> avisos;
};
