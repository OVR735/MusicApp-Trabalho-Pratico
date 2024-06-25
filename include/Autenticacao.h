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
};

#endif // AUTENTICACAO_H
