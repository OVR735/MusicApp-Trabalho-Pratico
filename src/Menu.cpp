#include "Menu.h"
#include <iostream>

Menu::Menu(const string& username) : username(username) {}

void Menu::exibirMenu() {
    int opcao;
    while (true) {
        cout << "Bem-vindo, " << username << "!\n";
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
