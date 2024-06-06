#include <iostream>
#include "Registro.h"
#include "Login.h"
#include "Menu.h"
#include "UsuarioPremium.h"
#include "UsuarioFree.h"

void exibirMenuParaUsuario(int userId, bool userStatus) {
    if (userStatus) {
        UsuarioPremium usuario(userId);
        Menu menu(&usuario); 
        menu.exibirMenu();
    } else {
        UsuarioFree usuario(userId);
        Menu menu(&usuario); 
        menu.exibirMenu();
    }
}

int main() {
    Autenticacao autenticacao;
    while (true) {
        int opcao;
        std::cout << "1. Registrar\n2. Login\n3. Sair\nEscolha uma opção: ";
        std::cin >> opcao;

        if (opcao == 1) {
            Registro registro;
            registro.registrarUsuario();
        } else if (opcao == 2) {
            Login login;
            int userId = login.fazerLogin();
            if (userId != -1) {
                bool userStatus = autenticacao.obterStatusUsuario(userId);
                exibirMenuParaUsuario(userId, userStatus);
            } else {
                std::cerr << "Falha no login. Tente novamente.\n";
            }
        } else if (opcao == 3) {
            break;
        } else {
            std::cerr << "Opção inválida.\n";
        }
    }

    return 0;
}
