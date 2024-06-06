#ifndef USUARIOPREMIUM_H
#define USUARIOPREMIUM_H
#define INT_MAX 2147483647

#include <string>
#include "Usuario.h"

class UsuarioPremium : public Usuario {
public:
    UsuarioPremium(int id):Usuario(id){
        limitePlaylists = INT_MAX;
    };

    void playlistRestantes();

    void adicionarPlaylist();
};

#endif // USUARIOPREMIUM_H