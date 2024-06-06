#ifndef MENU_H
#define MENU_H

#include <string>
using namespace std;

class Menu {
public:
    Menu(const string& username);
    void exibirMenu();

private:
   string username;

    void operacaoExemplo(); // Placeholder para futuras operações
};

#endif // MENU_H
