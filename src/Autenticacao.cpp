#include <iostream>
#include <fstream>
#include "Autenticacao.h"

bool Autenticacao::validarRegistro(const std::string& username, const std::string& email, const std::string& senha) {
    // Carregando os usuários do arquivo
    std::unordered_map<std::string, std::pair<std::string, std::string>> usuarios;
    carregarUsuarios(usuarios);

    // Verificando se o usuário já existe
    if (usuarios.find(username) != usuarios.end()) {
        std::cerr << "Erro: Nome de usuário já existe.\n";
        return false;
    }

    // Adicionando novo usuário
    usuarios[username] = std::make_pair(email, senha);
    salvarUsuarios(usuarios);
    return true;
}

void Autenticacao::carregarUsuarios(std::unordered_map<std::string, std::pair<std::string, std::string>>& usuarios) {
    std::ifstream file("usuarios.txt");
    if (!file.is_open()) {
        return;
    }
    std::string username, email, senha;
    while (file >> username >> email >> senha) {
        usuarios[username] = std::make_pair(email, senha);
    }
    file.close();
}

void Autenticacao::salvarUsuarios(const std::unordered_map<std::string, std::pair<std::string, std::string>>& usuarios) {
    std::ofstream file("usuarios.txt");
    for (const auto& entry : usuarios) {
        file << entry.first << " " << entry.second.first << " " << entry.second.second << "\n";
    }
    file.close();
}
