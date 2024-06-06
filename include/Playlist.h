#ifndef PLAYLIST_H
#define PLAYLIST_H

#include <string>
#include <vector>
#include "Musica.h"
#include "JsonService.h"

using namespace std;

class Playlist {
    private:
        int id;
        int idUsuario;
        string nome;
        string descricao;
        vector<Musica> musicas;

    public:

        void adicionarMusica(const Musica& musica);
        void removerMusica(const string& nomeMusica);
        void exibirInformacoes();

        void setNome(const string& nome);
        void setDescricao(const string& descricao);

        const string& getDescricao();
        const string& getNome();
};

#endif // PLAYLIST_H