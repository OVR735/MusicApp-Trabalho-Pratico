#ifndef USUARIOFREE_H
#define USUARIOFREE_H

#include "Usuario.h"

class UsuarioFree : public Usuario {
public:
    UsuarioFree(int id):Usuario(id){
        limitePlaylists = 10;
    };

    void playlistRestantes();

    void adicionarPlaylist();
};

#endif // USUARIOFREE_H