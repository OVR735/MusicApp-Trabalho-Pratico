#ifndef USUARIOPREMIUM_H
#define USUARIOPREMIUM_H

#include <string>
#include "Usuario.h"

class UsuarioPremium : public Usuario {
public:
    UsuarioPremium(int id);

    const string& playlistRestantes() const;

    void adicionarPlaylist();
};

#endif // USUARIOPREMIUM_H