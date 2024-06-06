#ifndef USUARIOPREMIUM_H
#define USUARIOPREMIUM_H

#include <string>
#include "Usuario.h"

class UsuarioPremium : public Usuario {
public:
    UsuarioPremium(const string& nome, const string& email, const string& senha, int limitePlaylists, int id);

    void exibirInformacoes() const override;

    const string& getLimitePlaylists() const;

    void adicionarPlaylist(const Playlist& playlist);
};

#endif // USUARIOPREMIUM_H