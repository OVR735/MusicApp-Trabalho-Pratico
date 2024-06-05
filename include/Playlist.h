#ifndef PLAYLIST_H
#define PLAYLIST_H

#include <string>
#include <vector>
#include "Musica.h"

using namespace std;

class Playlist {
    private:
        string nome;
        string descricao;
        vector<Musica> musicas;

    public:
        Playlist(const string& descricao);

        void adicionarMusica(const Musica& musica);
        void removerMusica(const string& nomeMusica);
        void exibirInformacoes() const;

        void setNome(const string& nome);
        void setDescricao(const string& descricao);

        const string& getDescricao() const;
        const string& getNome() const;
};

#endif // PLAYLIST_H