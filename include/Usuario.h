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
    bool premium;
    int limitePlaylists;
    vector<int> playlists;

private: 
    void removeElement(std::vector<int>& vec, int value);

public:
    Usuario(int id);

    const int getId() const;
    const string& getNome() const;
    const string& getEmail() const;
    const string& getSenha() const;
    const bool isPremium() const;
    
    virtual void adicionarPlaylist(string nome, string descricao) = 0;
    void removerPlaylist(int idPlaylist);
    void playlistRestantes();
    void tornarPremium();

    void alterarCredenciais(const string& novoNome, const string& novoEmail, const string& novaSenha);
};

#endif // USUARIO_H
