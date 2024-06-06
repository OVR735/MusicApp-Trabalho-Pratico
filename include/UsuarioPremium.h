#ifndef USUARIOPREMIUM_H
#define USUARIOPREMIUM_H
#define INT_MAX 2147483647

#include "Usuario.h"

class UsuarioPremium : public Usuario {
public:
    UsuarioPremium(int id):Usuario(id){
        limitePlaylists = INT_MAX;
    };

    void playlistRestantes();

    void adicionarPlaylist(string nome, string descricao) override;
};

#endif // USUARIOPREMIUM_H