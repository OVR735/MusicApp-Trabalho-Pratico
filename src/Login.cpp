#include "Login.h"
#include <iostream>

Login::Login() {}

int Login::fazerLogin() {
    std::string email, senha;

    std::cout << "Digite o e-mail: ";
    std::cin >> email;
    std::cout << "Digite a senha: ";
    std::cin >> senha;

    int userId = autenticacao.validarLogin(email, senha);
    if (userId != -1) {
        std::cout << "Login realizado com sucesso! Redirecionando para o menu...\n";
        return userId;
    } else {
        std::cerr << "Erro: Credenciais incorretas.\n";
        return -1;
    }
}
