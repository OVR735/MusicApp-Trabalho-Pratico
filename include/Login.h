#ifndef LOGIN_H
#define LOGIN_H

#include "Autenticacao.h"

class Login {
public:
    Login();
    int fazerLogin();

private:
    Autenticacao autenticacao;
};

#endif // LOGIN_H
