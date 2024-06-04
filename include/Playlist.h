#ifndef PLAYLIST_H
#define PLAYLIST_H

#include <string>
#include <vector>
#include "Musica.h"

class Playlist {
private:
    std::string nome;
    std::string descricao;
    std::vector<Musica> musicas;

public:
    Playlist(const std::string& descricao);

    void adicionarMusica(const Musica& musica);
    void removerMusica(const std::string& nomeMusica);
    void exibirInformacoes() const;

    void setNome(const std::string& nome);
    void setDescricao(const std::string& descricao);

    const std::string& getDescricao() const;
    const std::string& getNome() const;
};

#endif // PLAYLIST_H