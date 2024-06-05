#ifndef USUARIOFREE_H
#define USUARIOFREE_H

#include "Usuario.h"

class UsuarioFree : public Usuario {
public:
    UsuarioFree(const string& nome, const string& email, const string& senha, int limitePlaylists, int id);

    void exibirInformacoes() const override;

    void adicionarPlaylist(const Playlist& playlist);
};

#endif // USUARIOFREE_H