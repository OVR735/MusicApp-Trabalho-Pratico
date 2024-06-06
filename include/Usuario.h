#ifndef USUARIO_H
#define USUARIO_H

#include <string>
#include <vector>
#include "Playlist.h"
#include "JsonService.h" // Incluindo o JSONService

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

    const int getId() const;
    const string& getNome() const;
    const string& getEmail() const;
    const string& getSenha() const;
    
    virtual void adicionarPlaylist(string nome, string descricao) = 0;
    void removerPlaylist(const std::string& descricao);
    void playlistRestantes();

    void alterarCredenciais(const string& novoNome, const string& novoEmail, const string& novaSenha);
};

#endif // USUARIO_H
