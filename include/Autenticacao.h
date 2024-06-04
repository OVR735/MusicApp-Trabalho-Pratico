#ifndef AUTENTICACAO_H
#define AUTENTICACAO_H

#include <string>
#include <unordered_map>

class Autenticacao {
public:
    bool validarRegistro(const std::string& username, const std::string& email, const std::string& senha);

private:
    void carregarUsuarios(std::unordered_map<std::string, std::pair<std::string, std::string>>& usuarios);
    void salvarUsuarios(const std::unordered_map<std::string, std::pair<std::string, std::string>>& usuarios);
};

#endif // AUTENTICACAO_H
