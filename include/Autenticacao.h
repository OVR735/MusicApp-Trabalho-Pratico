#ifndef AUTENTICACAO_H
#define AUTENTICACAO_H

#include <string>
#include <unordered_map>
#include <utility>

using namespace std;

class Autenticacao {
    public:
        pair<bool, string> validarRegistro(const string& nome, const string& email, const string& senha);

    private:
        void carregarUsuarios(unordered_map<string, pair<string, string>>& usuarios);
        void salvarUsuarios(const unordered_map<string, pair<string, string>>& usuarios);
};

#endif // AUTENTICACAO_H
