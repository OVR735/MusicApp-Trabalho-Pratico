#ifndef MUSICA_H
#define MUSICA_H

#include <string>

class Musica {
private:
    std::string nome;
    double duracao; // em minutos
    std::string artista;

public:
    Musica(const std::string& nome, double duracao, const std::string& artista);

    const std::string& getNome() const;
    double getDuracao() const;
    const std::string& getArtista() const;

    void exibirInformacoes() const;
};

#endif // MUSICA_H