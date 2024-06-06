#include <iostream>
#include "Registro.h"
#include "Login.h"
#include "include/Playlist.h"

int main() {
    while (true){
        int opcao;
        std::cout << "1. Registrar\n2. Login\n3. Sair\nEscolha uma opção: ";
        std::cin >> opcao;

        if (opcao == 1) {
            Registro registro;
            registro.registrarUsuario();
        } else if (opcao == 2) {
            Login login;
            login.fazerLogin();
         } else if (opcao == 3) {
                break;
        } else {
            std::cerr << "Opção inválida.\n";
        }
    }

    return 0;
}
