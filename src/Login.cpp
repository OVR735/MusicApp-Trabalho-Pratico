#include "Login.h"
#include <iostream>
#include <stdexcept>
#include "Services.h"

Login::Login() {}

int Login::fazerLogin() {
    Services services;
    
    std::string email, senha;

    try {
        std::cout << "Digite o e-mail: ";
        std::cin >> email;
        std::cout << "Digite a senha: ";
        std::cin >> senha;

        if (email.empty() || senha.empty()) {
            throw std::invalid_argument("Email e senha não podem estar vazios.");
        }

        int userId = autenticacao.validarLogin(email, senha);
        if (userId != -1) {
            services.clearConsole();
            std::cout << "Login realizado com sucesso! Redirecionando para o menu...\n";
            return userId;
        } else {
            throw std::runtime_error("Erro: Credenciais incorretas.");
        }
    } catch (const std::invalid_argument& e) {
        std::cerr << "Erro de entrada: " << e.what() << '\n';
        return -1;
    } catch (const std::runtime_error& e) {
        std::cerr << "Erro: " << e.what() << '\n';
        return -1;
    } catch (const std::exception& e) {
        std::cerr << "Ocorreu um erro inesperado: " << e.what() << '\n';
        return -1;
    } catch (...) {
        std::cerr << "Ocorreu um erro desconhecido.\n";
        return -1;
    }
}
