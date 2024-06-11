#include <iostream>
#include "Registro.h"
#include "Login.h"
#include "Menu.h"
#include "UsuarioPremium.h"
#include "UsuarioFree.h"
#include "Services.h"

using namespace std;

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
    Services services;
    while (true) {
        int opcao;
        cout << "1. Registrar\n2. Login\n3. Sair\nEscolha uma opção: ";
        cin >> opcao;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // descarta a entrada inválida
            cerr << "Opção inválida. Por favor, insira um número válido.\n";
            continue;
        }

        if (opcao == 1) {
            Registro registro;
            registro.registrarUsuario();
        } else if (opcao == 2) {
            Login login;
            int userId = login.fazerLogin();
            if (userId != -1) {
                bool userStatus = services.obterStatusUsuario(userId);
                exibirMenuParaUsuario(userId, userStatus);
            } else {
                cerr << "Falha no login. Tente novamente.\n";
            }
        } else if (opcao == 3) {
            break;
        } else {
            cerr << "Opção inválida.\n";
        }
    }

    return 0;
}
