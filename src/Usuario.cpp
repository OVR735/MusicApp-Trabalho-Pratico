#include "Usuario.h"
#include <iostream>

Usuario::Usuario(const std::string& nome, const std::string& email, const std::string& senha, int limitePlaylists, int id)
    : nome(nome), email(email), senha(senha), limitePlaylists(limitePlaylists) {}

const std::string& Usuario::getNome() const { return nome; }
const std::string& Usuario::getEmail() const { return email; }
const std::string& Usuario::getSenha() const { return senha; }
int Usuario::getLimitePlaylists() const { return limitePlaylists; }

void Usuario::removerPlaylist(const std::string& descricao) {
    auto it = std::remove_if(playlists.begin(), playlists.end(), [&](const Playlist& playlist) {
        return playlist.getDescricao() == descricao;
    });
    playlists.erase(it, playlists.end());
}

Usuario::~Usuario() {}