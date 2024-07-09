#include <iostream>

#include "sistemaGestao.h"
using std::cout, std::endl;

sistemaGestao::sistemaGestao()
{
}

sistemaGestao::~sistemaGestao()
{
}

void sistemaGestao::cadastrarAstronauta(string cpf, string nome, int idade)
{
    if (astronautas.find(cpf) == astronautas.end())
    {
        astronautas[cpf] = new Astronauta(cpf, nome, idade);
        cout << "Astronauta cadastrado com sucesso!" << endl;
    }
    else
    {
        cout << "Esse CPF já foi cadastrado." << endl;
    }
}

void sistemaGestao::cadastrarVoo(int codigo)
{
    if (voos.find(codigo) == voos.end())
    {
        voos[codigo] = new Voo(codigo);
        cout << "Voo cadastrado com sucesso!" << endl;
    }
    else
    {
        cout << "Voo com esse código já está cadastrado." << endl;
    }
}

void sistemaGestao::adicionarAstronautaEmVoo(int codigoVoo, string cpf)
{
    if (voos.find(codigoVoo) != voos.end() && astronautas.find(cpf) != astronautas.end())
    {
        Voo *voo = voos[codigoVoo];
        Astronauta *astronauta = astronautas[cpf];
        if (voo->emPlanejamento && astronauta->disponivel)
        {
            voo->passageiros.push_back(cpf);
            astronauta->voos.push_back(codigoVoo);
            cout << "Astronauta adicionado ao voo com sucesso!" << endl;
        }
        else
        {
            cout << "Astronauta não pode ser adicionado. Verifique se o voo está em planejamento e se o astronauta está disponível." << endl;
        }
    }
    else{
        cout << "CPF ou Voo não encontrado." << endl;
    }
}

void sistemaGestao::removerAstronautaDeVoo(int codigoVoo, string cpf)
{
    if (voos.find(codigoVoo) != voos.end() && astronautas.find(cpf) != astronautas.end())
    {
        Voo *voo = voos[codigoVoo];
        if (voo->emPlanejamento)
        {
            voo->passageiros.remove(cpf);
            astronautas[cpf]->voos.remove(codigoVoo);
            cout << "Astronauta removido do voo com Sucesso!" << endl;
        }
        else
        {
            cout << "Astronauta não pode ser removido. O voo não está em planejamento." << endl;
        }
    }
    else
    {
        cout << "Voo ou astronauta não encontrado." << endl;
    }
}

void sistemaGestao::lancarVoo(int codigoVoo)
{
    if (voos.find(codigoVoo) != voos.end())
    {
        Voo *voo = voos[codigoVoo];
        if (voo->emPlanejamento && !voo->passageiros.empty())
        {
            bool todosDisponiveis = true;
            for (const string &cpf : voo->passageiros)
            {
                if (!astronautas[cpf]->disponivel)
                {
                    todosDisponiveis = false;
                    break;
                }
            }
            if (todosDisponiveis)
            {
                voo->emPlanejamento = false;
                voo->emCurso = true;
                for (const string &cpf : voo->passageiros)
                {
                    astronautas[cpf]->disponivel = false;
                }
                cout << "Voo lançado com sucesso!!!" << endl;
            }
        }
        else
        {
            cout << "Voo não pode ser lançado. Verifique se está em planejamento e se há astronautas a bordo." << endl;
        }
    }
    else
    {
        cout << "Voo não encontrado." << endl;
    }
}

void sistemaGestao::explodirVoo(int codigoVoo)
{
    if (voos.find(codigoVoo) != voos.end())
    {
        Voo *voo = voos[codigoVoo];
        if (voo->emCurso)
        {
            voo->emCurso = false;
            voo->finalizado = true;
            voo->sucesso = false;
            for (const string &cpf : voo->passageiros)
            {
                Astronauta *astronauta = astronautas[cpf];
                astronauta->morto = true;
                astronautasMortos.push_back(astronauta);
            }
            cout << "Oh não ... o voo explodiu e todos os astronautas do voo " << codigoVoo << " morreram :(" << endl;
        }
        else
        {
            cout << "Voo não está em curso." << endl;
        }
    }
    else
    {
        cout << "Voo não encontrado." << endl;
    }
}

void sistemaGestao::finalizarVoo(int codigoVoo)
{
    if (voos.find(codigoVoo) != voos.end())
    {
        Voo *voo = voos[codigoVoo];
        if (voo->emCurso)
        {
            voo->emCurso = false;
            voo->finalizado = true;
            voo->sucesso = true;
            for (const string &cpf : voo->passageiros)
            {
                astronautas[cpf]->disponivel = true;
            }
            cout << "Voo finalizado com sucesso." << endl;
        }
        else
        {
            cout << "Voo não está em curso." << endl;
        }
    }
    else
    {
        cout << "Voo não encontrado." << endl;
    }
}

void sistemaGestao::listarVoos()
{
    cout << "Voos Planejados: " << endl;
    for (const auto &pair : voos)
    {
        Voo *voo = pair.second;
        if (voo->emPlanejamento)
        {
            cout << "Voo " << voo->codigo << " com astronautas: ";
            for (const string &cpf : voo->passageiros)
            {
                cout << astronautas[cpf]->nome << "|";
            }
            cout << endl;
        }
    }
    cout << "Voos em Curso: " << endl;
    for (const auto &pair : voos)
    {
        Voo *voo = pair.second;
        if (voo->emCurso)
        {
            cout << "Voo " << voo->codigo << " com astronautas: ";
            for (const string &cpf : voo->passageiros)
            {
                cout << astronautas[cpf]->nome << "|";
            }
            cout << endl;
        }
    }
    cout << "Voos Finalizados: " << endl;
    for (const auto &pair : voos)
    {
        Voo *voo = pair.second;
        if (voo->finalizado)
        {
            cout << "Voo " << voo->codigo << " com astronautas: ";
            for (const string &cpf : voo->passageiros)
            {
                cout << astronautas[cpf]->nome << "|";
            }
            cout << " - " << (voo->sucesso ? "Sucesso" : "Falhou") << endl;
        }
    }
}

void sistemaGestao::listarAstronautasMortos()
{
    cout << "Astronautas Mortos:" << endl;
    for (Astronauta *astronauta : astronautasMortos)
    {
        cout << "CPF: " << astronauta->cpf << ", Nome: " << astronauta->nome << ", Voos: ";
        for (int codigoVoo : astronauta->voos)
        {
            cout << codigoVoo << " ";
        }
        cout << endl;
    }
}

void sistemaGestao::exibirMenu()
{
    cout << "1. Cadastrar Astronauta" << endl;
    cout << "2. Cadastrar Voo" << endl;
    cout << "3. Adicionar Astronauta em Voo" << endl;
    cout << "4. Remover Astronauta de Voo" << endl;
    cout << "5. Lançar Voo" << endl;
    cout << "6. Explodir Voo" << endl;
    cout << "7. Finalizar Voo" << endl;
    cout << "8. Listar Voos" << endl;
    cout << "9. Listar Astronautas Mortos" << endl;
    cout << "0. Sair" << endl;
}
