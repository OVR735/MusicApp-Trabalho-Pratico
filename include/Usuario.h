#ifndef USUARIO_H
#define USUARIO_H

#include <string>
#include <vector>
#include "Playlist.h"

class Usuario {
protected:
    std::string nome;
    std::string email;
    std::string senha;
    int limitePlaylists;
    std::vector<Playlist> playlists;

public:
    Usuario(const std::string& nome, const std::string& email, const std::string& senha, int limitePlaylists);

    virtual void exibirInformacoes() const = 0;

    const std::string& getNome() const;
    const std::string& getEmail() const;
    const std::string& getSenha() const;
    
    int getLimitePlaylists() const;

    void adicionarPlaylist(const Playlist& playlist);
    void removerPlaylist(const std::string& descricao);

    virtual ~Usuario();
};

#endif // USUARIO_H
