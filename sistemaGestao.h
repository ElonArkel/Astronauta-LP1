#ifndef SISTEMA_GESTAO_H
#define SISTEMA_GESTAO_H

#include <unordered_map>
#include <list>
#include <string>

#include "Astronauta.h"
#include "Voo.h"

using std::unordered_map, std::string, std::list;

class sistemaGestao
{
private:
    unordered_map<string, Astronauta *> astronautas;
    unordered_map<int, Voo *> voos;
    list<Astronauta *> astronautasMortos;

public:
    sistemaGestao();
    ~sistemaGestao();

    void cadastrarAstronauta(string cpf, string nome, int idade);
    void cadastrarVoo(int codigo);
    void adicionarAstronautaEmVoo(int codigoVoo, string cpf);
    void removerAstronautaDeVoo(int codigoVoo, string cpf);
    void lancarVoo(int codigoVoo);
    void explodirVoo(int codigoVoo);
    void finalizarVoo(int codigoVoo);
    void listarVoos();
    void listarAstronautasMortos();
    void exibirMenu();
};

#endif