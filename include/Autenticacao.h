#ifndef AUTENTICACAO_H
#define AUTENTICACAO_H

#include <string>
#include <unordered_map>
#include <utility>
#include "JsonService.h"
#include "Usuario.h"

using namespace std;

class Autenticacao {
public:
    pair<bool, string> validarRegistro(const string& nome, const string& email, const string& senha);
    int validarLogin(const string& email, const string& senha);
    void carregarUsuarios(unordered_map<string, pair<string, string>>& usuarios);
    void salvarUsuarios(const unordered_map<string, pair<string, string>>& usuarios);
    //string obterNomeUsuario(int userId);
};

#endif // AUTENTICACAO_H
