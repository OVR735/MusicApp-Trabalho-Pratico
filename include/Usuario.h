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
        Usuario(int id);
        virtual ~Usuario() = default;

        const int getId() const;
        const string& getNome() const;
        const string& getEmail() const;
        const string& getSenha() const;
        
        void adicionarPlaylist();
        void removerPlaylist(const std::string& descricao);

        void playlistRestantes();
};

#endif // USUARIO_H
