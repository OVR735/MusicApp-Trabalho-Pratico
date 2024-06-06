#ifndef MENU_H
#define MENU_H
#include "UsuarioFree.h"
#include "UsuarioPremium.h"

#include <string>
using namespace std;

class Menu {
public:
    Menu(Usuario& usuario);
    void exibirMenu();

private:
    Usuario* user;

    void operacaoExemplo(); // Placeholder para futuras operações
};

#endif // MENU_H
