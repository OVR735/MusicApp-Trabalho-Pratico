#ifndef MUSICA_H
#define MUSICA_H

#include <string>

using namespace std;

/**
 * @class Musica
 * @brief Classe que representa uma música.
 *
 * A classe Musica contém informações sobre uma música, como nome, duração e nome do artista.
 * Também fornece métodos para acessar essas informações e exibir os detalhes da música.
 */
class Musica {
private:
    string nome; ///< Nome da música.
    double duracao; ///< Duração da música em minutos.
    string nomeArtista; ///< Nome do artista da música.

public:
    /**
     * @brief Construtor da classe Musica.
     *
     * @param nome Nome da música.
     * @param duracao Duração da música em minutos.
     * @param nomeArtista Nome do artista da música.
     */
    Musica(const string& nome, double duracao, const string& nomeArtista);

    /**
     * @brief Obtém o nome da música.
     *
     * @return Uma referência constante para o nome da música.
     */
    const string& getNome() const;

    /**
     * @brief Obtém a duração da música.
     *
     * @return A duração da música em minutos.
     */
    double getDuracao() const;

    /**
     * @brief Obtém o nome do artista da música.
     *
     * @return Uma referência constante para o nome do artista.
     */
    const string& getArtista() const;

    /**
     * @brief Exibe as informações da música.
     */
    void exibirInformacoes() const;
};

#endif // MUSICA_H
