#ifndef USUARIOFREE_H
#define USUARIOFREE_H

#include "Usuario.h"

class UsuarioFree : public Usuario {
public:
    UsuarioFree(int id):Usuario(id){
        
    };

    void playlistRestantes();

    void adicionarPlaylist();
};

#endif // USUARIOFREE_H