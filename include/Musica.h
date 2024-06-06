#ifndef MUSICA_H
#define MUSICA_H

#include <string>

using namespace std;

class Musica {
    private:
        string nome;
        double duracao; // em minutos
        string nomeArtista;

    public:
        Musica(const string& nome, double duracao, const string& nomeArtista);

        const string& getNome() const;
        double getDuracao() const;
        const string& getArtista() const;

        void exibirInformacoes() const;
};

#endif // MUSICA_H