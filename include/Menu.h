#ifndef MENU_H
#define MENU_H

#include <string>
#include "Usuario.h"

using namespace std;

class Menu {
public:
    Menu(int userId);
    void exibirMenu();

private:
    Usuario usuario;

    void alterarCredenciais();
    void operacaoExemplo(); // Placeholder para futuras operações
};

#endif // MENU_H
