#ifndef AUTENTICACAO_H
#define AUTENTICACAO_H

#include <string>
#include <unordered_map>

using namespace std;

class Autenticacao {
public:
    pair<bool, int> validarLogin(const string& email, const string& senha);
    bool verificarUsuarioPremium(int id);
    pair<bool, string> validarRegistro(const string& username, const string& email, const string& senha); // Corrigido para retornar pair<bool, string>

private:
    void carregarUsuarios(unordered_map<string, pair<string, string>>& usuarios);
    void salvarUsuarios(const unordered_map<string, pair<string, string>>& usuarios);
};

#endif // AUTENTICACAO_H
