#ifndef USUARIOFREE_H
#define USUARIOFREE_H

#include "Usuario.h"

class UsuarioFree : public Usuario {
public:
    UsuarioFree(int id):Usuario(id){
        limitePlaylists = 10;
    };

    void playlistsRestantes()
    {
        cout << "Você ainda tem " << limitePlaylists << "restantes!";
    }

    void adicionarPlaylist(string nome, string descricao) override;
};

#endif // USUARIOFREE_H