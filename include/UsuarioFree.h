#ifndef USUARIOFREE_H
#define USUARIOFREE_H

#include "Usuario.h"

class UsuarioFree : public Usuario {
public:
    UsuarioFree(int id);

    const string& playlistRestantes() const;

    void adicionarPlaylist();
};

#endif // USUARIOFREE_H