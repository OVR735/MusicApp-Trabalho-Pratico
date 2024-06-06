#include "Menu.h"
#include <iostream>

Menu::Menu(Usuario& usuario) {
    if (dynamic_cast<UsuarioFree*>(&usuario)) {
        cout << "\nAssinatura do tipo grátis." << endl;
        user = &usuario;
    } else if (dynamic_cast<UsuarioPremium*>(&usuario)) {
        cout << "\nAssinatura do tipo premium." << endl;
        user = &usuario;
    } else {
        cout << "\nUsuário é de um tipo desconhecido." << endl;
    }
}

void Menu::exibirMenu() {
    int opcao;
    while (true) {
        cout << "Bem-vindo, " << user->getNome() << "!\n";
        cout << "1. Operação Exemplo\n2. Logout\nEscolha uma opção: ";
        cin >> opcao;

        if (opcao == 1) {
            operacaoExemplo();
        } else if (opcao == 2) {
            cout << "Logout realizado com sucesso.\n";
            break;
        } else {
            cerr << "Opção inválida.\n";
        }
    }
}

void Menu::operacaoExemplo() {
    cout << "Executando operação de exemplo...\n";
}