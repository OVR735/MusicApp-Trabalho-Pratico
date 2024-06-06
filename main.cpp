#include <iostream>
#include "Registro.h"
#include "Login.h"
#include "include/Playlist.h"
#include "UsuarioFree.h"
#include "UsuarioPremium.h"
#include "Menu.h"

int main() {
    while (true) {
        int opcao;
        cout << "1. Registrar\n2. Login\n3. Sair\nEscolha uma opção: ";
        cin >> opcao;

        if (cin.fail()) {
            cin.clear(); // limpa o estado de erro
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // ignora o restante da linha de entrada
            cout << "Opção inválida. Por favor, digite um número.\n";
            continue;
        }

        if (opcao == 1) {
            Registro registro;
            registro.registrarUsuario();
        } else if (opcao == 2) {
            Login login;
            pair <bool, int> loginSucesso = login.fazerLogin();
            
            if(loginSucesso.first) { //login deu certo?
                bool usuarioPremium = login.obterInfoUsuarioPremium(loginSucesso.second);

                if(usuarioPremium) {
                    UsuarioPremium usuarioPremium(loginSucesso.second);
                    Menu menu(usuarioPremium);
                    menu.exibirMenu();
                } else {
                    UsuarioFree usuarioFree(loginSucesso.second);
                    Menu menu(usuarioFree);
                    menu.exibirMenu();
                }
            } else {
                continue;
            };
         } else if (opcao == 3) {
                break;
        } else {
            cout << "Opção inválida.\n";
        }
    }

    return 0;
}
