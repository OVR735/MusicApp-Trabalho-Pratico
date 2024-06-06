#ifndef PLAYLIST_H
#define PLAYLIST_H

#include <string>
#include <vector>
#include "Musica.h"
#include "JsonService.h"

#include <utility>

using namespace std;

class Playlist {
    private:
        int id;
        int idUsuario;
        string nome;
        string descricao;
        vector<Musica> musicas;

    public:
        Playlist(const string& nome, const string& descricao, int idUser);
        pair<bool, string> adicionarMusica();
        pair<bool, string> removerMusica(string nomeMusica);

        void setNome(string nome);
        void setDescricao(string descricao);

        string getDescricao();
        string getNome();
        int getID();
};

#endif // PLAYLIST_H