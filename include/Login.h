#ifndef LOGIN_H
#define LOGIN_H

#include "Autenticacao.h"

class Login {
public:
    pair <bool, int> fazerLogin();
    bool obterInfoUsuarioPremium(int id);

private:
    Autenticacao autenticacao;
};

#endif // LOGIN_H
