#include <iostream>
#include "Login.h"

pair <bool, int> Login::fazerLogin() {
    std::string email, senha;

    std::cout << "Digite o e-mail: ";
    std::cin >> email;
    std::cout << "Digite a senha: ";
    std::cin >> senha;

    pair<bool, int> resultado = autenticacao.validarLogin(email, senha);
    if (resultado.first) {
        std::cout << "Login realizado com sucesso! Redirecionando para o menu...\n";
    } else {
        std::cerr << "Erro: Credenciais incorretas.\n";
    }

    return resultado;
}

bool Login::obterInfoUsuarioPremium(int id) {
    return autenticacao.verificarUsuarioPremium(id);
}