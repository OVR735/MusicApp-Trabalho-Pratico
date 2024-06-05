#ifndef USUARIO_H
#define USUARIO_H

#include <string>
#include <vector>
#include "Playlist.h"

using namespace std;

class Usuario {
    protected:
        int id;
        string nome;
        string email;
        string senha;
        int limitePlaylists;
        vector<int> playlists;

    public:
        Usuario(const string& nome, const string& email, const string& senha, int limitePlaylists, int id);

        virtual void exibirInformacoes() const = 0;

        const int getId() const;
        const string& getNome() const;
        const string& getEmail() const;
        const string& getSenha() const;
        
        int getLimitePlaylists() const;

        void adicionarPlaylist(const Playlist& playlist);
        void removerPlaylist(const std::string& descricao);

        virtual ~Usuario();
};

#endif // USUARIO_H
