#ifndef USUARIOPREMIUM_H
#define USUARIOPREMIUM_H

#include <string>
#include "Usuario.h"

class UsuarioPremium : public Usuario {
public:
    UsuarioPremium(int id):Usuario(id){
        
    };

    void playlistRestantes();

    void adicionarPlaylist();
};

#endif // USUARIOPREMIUM_H