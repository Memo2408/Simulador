#pragma once
#include <deque>                // para la lista RR
#include "memoria.h"
#include "generador.h"
// Héctor: la parte pública no se cambia. Los datos de private ya están;
// si necesitas otro, agrégalo ahí. Las funciones van en simulador.cpp.
class Simulador {
public:
    Simulador(Memoria& memoria, Generador& generador, int cuantoSistema);
    void correr();              // imprime la memoria inicial y repite ciclos hasta que aprieten S
    void ciclo();               // un solo ciclo, con toda su salida (también sirve para pruebas)
    void agregar(Proceso* p);   // solo pruebas: pone al final de la lista RR un proceso ya colocado
private:
    Memoria& memoria;           // referencia: Memoria es abstracta y no se copia
    Generador& generador;       // referencia
    int cuantoSistema;
    std::deque<Proceso*> lista; // la lista RR
    Proceso* listo = nullptr;   // el que espera entrar a memoria
};
