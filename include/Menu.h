// Menu.h
#ifndef MENU_H
#define MENU_H

#include <string>
#include "Usuario.h"

using namespace std;

class Menu {
public:
    Menu(Usuario* usuario);
    void exibirMenu();

private:
    Usuario* usuario;

    void alterarCredenciais();
    void adicionarPlaylistUsuario();
    vector<int> exibirPlaylists();
    void exibirMenuPlaylist(int idPlaylist);
    void tornarUsuarioPremium();
};

#endif // MENU_H