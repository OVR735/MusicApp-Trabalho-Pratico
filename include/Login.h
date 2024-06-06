<<<<<<< HEAD
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
=======
#ifndef LOGIN_H
#define LOGIN_H

#include "Autenticacao.h"

class Login {
public:
    void fazerLogin();

private:
    Autenticacao autenticacao;
};

#endif // LOGIN_H
>>>>>>> 327c2dd4992fe2586cff41cb5f34084d457d489f
