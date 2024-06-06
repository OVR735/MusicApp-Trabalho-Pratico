#include <iostream>
#include "Login.h"

void Login::fazerLogin() {
    std::string email, senha;

    std::cout << "Digite o e-mail: ";
    std::cin >> email;
    std::cout << "Digite a senha: ";
    std::cin >> senha;

    if (autenticacao.validarLogin(email, senha)) {
        std::cout << "Login realizado com sucesso! Redirecionando para o menu...\n";
    } else {
        std::cerr << "Erro: Credenciais incorretas.\n";
    }
}