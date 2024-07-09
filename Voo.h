#ifndef VOO_H
#define VOO_H

#include <list>
#include <string>
class Voo
{

public:
    int codigo;
    std::list<std::string> passageiros;
    bool emPlanejamento;
    bool emCurso;
    bool finalizado;
    bool sucesso;

    Voo(int cod);
};

#endif