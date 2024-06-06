#include <iostream>
#include "Musica.h"

Musica::Musica(const std::string& nome, double duracao, const std::string& artista) : nome(nome), duracao(duracao), artista(artista) {}

const std::string& Musica::getNome() const {
    return nome;
}

double Musica::getDuracao() const {
    return duracao;
}

const std::string& Musica::getArtista() const {
    return nomeArtista;
}

void Musica::exibirInformacoes() const {
    std::cout << std::endl;
    std::cout << "Nome: " << nome << std::endl;
    std::cout << "Duração: " << duracao << " minutos" << std::endl;
    std::cout << "Artista: " << nomeArtista << std::endl;
    std::cout << std::endl;
};