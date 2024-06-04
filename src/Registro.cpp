#include <iostream>
#include "Registro.h"

void Registro::registrarUsuario() {
    std::string username, email, senha;

    std::cout << "Digite o nome de usuário: ";
    std::cin >> username;
    std::cout << "Digite o e-mail: ";
    std::cin >> email;
    std::cout << "Digite a senha: ";
    std::cin >> senha;

    if (autenticacao.validarRegistro(username, email, senha)) {
        std::cout << "Usuário registrado com sucesso!\n";
    } else {
        std::cerr << "Erro ao registrar o usuário.\n";
    }
}
