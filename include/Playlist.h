#ifndef PLAYLIST_H
#define PLAYLIST_H

#include <string>
#include <vector>
#include "Musica.h"
#include "JsonService.h"

#include <utility>

using namespace std;

/**
 * @class Playlist
 * @brief Classe que representa uma playlist de músicas.
 *
 * A classe Playlist contém informações sobre uma playlist, como nome, descrição, e as músicas que fazem parte dela.
 * Também fornece métodos para gerenciar músicas na playlist e acessar suas informações.
 */
class Playlist {
private:
    int id; ///< ID da playlist.
    int idUsuario; ///< ID do usuário dono da playlist.
    string nome; ///< Nome da playlist.
    string descricao; ///< Descrição da playlist.

    /**
     * @brief Define o ID do usuário dono da playlist.
     *
     * @param idUsuario ID do usuário.
     */
    void setUsuarioDono(int idUsuario);

public:
    vector<int> musicas; ///< Vetor contendo os IDs das músicas na playlist.

    /**
     * @brief Construtor da classe Playlist.
     *
     * @param id ID da playlist.
     */
    Playlist(int id);

    /**
     * @brief Construtor da classe Playlist.
     *
     * @param nome Nome da playlist.
     * @param descricao Descrição da playlist.
     * @param idUser ID do usuário dono da playlist.
     */
    Playlist(const string& nome, const string& descricao, int idUser);

    /**
     * @brief Adiciona uma música à playlist.
     *
     * @param idMusica ID da música a ser adicionada.
     * @return Um par onde o primeiro elemento é um booleano indicando o sucesso da operação,
     *         e o segundo elemento é uma mensagem de erro ou sucesso.
     */
    pair<bool, string> adicionarMusica(int idMusica);

    /**
     * @brief Remove uma música da playlist.
     *
     * @param idMusica ID da música a ser removida.
     * @return Um par onde o primeiro elemento é um booleano indicando o sucesso da operação,
     *         e o segundo elemento é uma mensagem de erro ou sucesso.
     */
    pair<bool, string> removerMusica(int idMusica);

    /**
     * @brief Busca uma música na playlist pelo nome.
     *
     * @param nomeMusica Nome da música a ser buscada.
     * @return Um par onde o primeiro elemento é um booleano indicando se a música foi encontrada,
     *         e o segundo elemento é o ID da música se encontrada, ou -1 caso contrário.
     */
    pair<bool, int> buscarMusica(string nomeMusica);

    /**
     * @brief Lista todas as músicas da playlist.
     *
     * @return Um vetor contendo os IDs das músicas na playlist.
     */
    vector<int> listarMusicas();

    /**
     * @brief Define o nome da playlist.
     *
     * @param nome Nome da playlist.
     */
    void setNome(string nome);

    /**
     * @brief Define a descrição da playlist.
     *
     * @param descricao Descrição da playlist.
     */
    void setDescricao(string descricao);

    /**
     * @brief Obtém a descrição da playlist.
     *
     * @return A descrição da playlist.
     */
    string getDescricao();

    /**
     * @brief Obtém o nome da playlist.
     *
     * @return O nome da playlist.
     */
    string getNome();

    /**
     * @brief Obtém o ID da playlist.
     *
     * @return O ID da playlist.
     */
    int getID();
};

#endif // PLAYLIST_H
