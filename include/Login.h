#ifndef LOGIN_H
#define LOGIN_H

#include "Autenticacao.h"
#include <string>
using namespace std;

class Login {
public:
    string fazerLogin();

private:
    Autenticacao autenticacao;
};

#endif // LOGIN_H
