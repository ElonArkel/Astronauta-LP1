#ifndef ASTRONAUTA_H
#define ASTRONAUTA_H

#include <string>
#include <list>
using std::string, std::list;

class Astronauta{

    public:
        string cpf;
        string nome;
        int idade;
        bool disponivel;
        bool morto;
        list<int> voos;

    Astronauta(string c, string n, int i);
};

#endif