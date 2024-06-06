#include "Menu.h"
#include <iostream>

Menu::Menu(int userId) : usuario(userId) {}

void Menu::exibirMenu() {
    int opcao;
    while (true) {
        cout << "Bem-vindo, " << usuario.getNome() << "!\n";
        cout << "1. Alterar Credenciais\n2. Operação Exemplo\n3. Logout\nEscolha uma opção: ";
        cin >> opcao;

        if (opcao == 1) {
            alterarCredenciais();
        } else if (opcao == 2) {
            operacaoExemplo();
        } else if (opcao == 3) {
            cout << "Logout realizado com sucesso.\n";
            break;
        } else {
            cerr << "Opção inválida.\n";
        }
    }
}

void Menu::alterarCredenciais() {
    string novoNome, novoEmail, novaSenha;
    cout << "Digite o novo nome: ";
    cin.ignore();
    getline(cin, novoNome);
    cout << "Digite o novo email: ";
    getline(cin, novoEmail);
    cout << "Digite a nova senha: ";
    getline(cin, novaSenha);

    try {
        usuario.alterarCredenciais(novoNome, novoEmail, novaSenha);
        cout << "Credenciais atualizadas com sucesso.\n";
    } catch (const char* msg) {
        cerr << msg << endl;
    }
}

void Menu::operacaoExemplo() {
    cout << "Executando operação de exemplo...\n";
}