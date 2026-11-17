#pragma once
#include "memoria.h"
// Germán: la parte pública no se cambia. Agrega tus datos en private
// y escribe las funciones en primer_ajuste.cpp.
class PrimerAjuste : public Memoria {
public:
    PrimerAjuste(int memoriaKB);                       // empieza con un solo hueco [0,memoriaKB,0]
    bool colocar(Proceso* p) override;
    void descargar(int id) override;
    bool condensar() override;
    std::vector<std::string> eventos() override;
    std::string imprimir() override;
private:
};
