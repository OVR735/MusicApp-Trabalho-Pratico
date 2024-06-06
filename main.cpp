#include <iostream>
#include "Registro.h"
#include "Login.h"
#include "include/Playlist.h"
#include "UsuarioFree.h"

int main() {
    while (true) {
        int opcao;
        cout << "1. Registrar\n2. Login\n3. Sair\nEscolha uma opção: ";
        cin >> opcao;

        if (opcao == 1) {
            Registro registro;
            registro.registrarUsuario();
        } else if (opcao == 2) {
            Login login;
            login.fazerLogin();
            UsuarioFree userteste(2);
            userteste.adicionarPlaylist();
         } else if (opcao == 3) {
                break;
        } else {
            cerr << "Opção inválida.\n";
        }
    }

    return 0;
}
