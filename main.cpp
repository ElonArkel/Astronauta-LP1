#include "sistemaGestao.h"

#include <iostream>
using std::cout, std::cin, std::endl;

int main()
{
    sistemaGestao sistema;

    int escolha;

    do
    {
        sistema.exibirMenu();
        cout << "Escolha uma opção: ";
        cin >> escolha;
        cin.ignore();

        switch (escolha)
        {
        case 1:
        {
            string cpf, nome;
            int idade;
            cout << "CPF: ";
            getline(cin, cpf);
            cout << "Nome: ";
            getline(cin, nome);
            cout << "Idade: ";
            cin >> idade;
            sistema.cadastrarAstronauta(cpf, nome, idade);
            break;
        }
        case 2:
        {
            int codigo;
            cout << "Código do Voo: ";
            cin >> codigo;
            sistema.cadastrarVoo(codigo);
            break;
        }
        case 3:
        {
            int codigoVoo;
            string cpf;
            cout << "Código do Voo: ";
            cin >> codigoVoo;
            cout << "CPF do Astronauta: ";
            cin.ignore();
            getline(cin, cpf);
            sistema.adicionarAstronautaEmVoo(codigoVoo, cpf);
            break;
        }
        case 4:
        {
            int codigoVoo;
            string cpf;
            cout << "Código do Voo: ";
            cin >> codigoVoo;
            cout << "CPF do Astronauta: ";
            cin.ignore();
            getline(cin, cpf);
            sistema.removerAstronautaDeVoo(codigoVoo, cpf);
            break;
        }
        case 5:
        {
            int codigoVoo;
            cout << "Código do Voo: ";
            cin >> codigoVoo;
            sistema.lancarVoo(codigoVoo);
            break;
        }
        case 6:
        {
            int codigoVoo;
            cout << "Código do Voo: ";
            cin >> codigoVoo;
            sistema.explodirVoo(codigoVoo);
            break;
        }
        case 7:
        {
            int codigoVoo;
            cout << "Código do Voo: ";
            cin >> codigoVoo;
            sistema.finalizarVoo(codigoVoo);
            break;
        }
        case 8:
            sistema.listarVoos();
            break;
        case 9:
            sistema.listarAstronautasMortos();
            break;
        case 0:
            cout << "Saindo do programa..." << endl;
            break;
        default:
            cout << "Opção inválida. Tente novamente." << endl;
            break;
        }
    } while (escolha != 0);

    return 0;
}