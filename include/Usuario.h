#ifndef USUARIO_H
#define USUARIO_H

#include <string>
#include <vector>
#include "Playlist.h"
#include "JsonService.h" // Incluindo o JSONService

using namespace std;

/**
 * @class Usuario
 * @brief Classe que representa um usuário.
 *
 * A classe Usuario contém informações sobre um usuário, como id, nome, email, senha, status premium,
 * limite de playlists e uma lista de playlists. Fornece métodos para gerenciar playlists e alterar credenciais.
 */
class Usuario
{
protected:
    int id;                ///< ID do usuário.
    string nome;           ///< Nome do usuário.
    string email;          ///< Email do usuário.
    string senha;          ///< Senha do usuário.
    bool premium;          ///< Status premium do usuário.
    int limitePlaylists;   ///< Limite de playlists que o usuário pode ter.
    vector<int> playlists; ///< Vetor contendo os IDs das playlists do usuário.

public:
    /**
     * @brief Construtor da classe Usuario.
     *
     * @param id ID do usuário.
     */
    Usuario(int id);

    /**
     * @brief Obtém o ID do usuário.
     *
     * @return O ID do usuário.
     */
    const int getId() const;

    /**
     * @brief Obtém o nome do usuário.
     *
     * @return Uma referência constante para o nome do usuário.
     */
    const string &getNome() const;

    /**
     * @brief Obtém o email do usuário.
     *
     * @return Uma referência constante para o email do usuário.
     */
    const string &getEmail() const;

    /**
     * @brief Obtém a senha do usuário.
     *
     * @return Uma referência constante para a senha do usuário.
     */
    const string &getSenha() const;

    /**
     * @brief Verifica se o usuário é premium.
     *
     * @return true se o usuário for premium, false caso contrário.
     */
    const bool isPremium() const;

    /**
     * @brief Adiciona uma nova playlist para o usuário.
     *
     * Método virtual puro que deve ser implementado pelas classes derivadas.
     *
     * @param nome Nome da playlist.
     * @param descricao Descrição da playlist.
     */
    virtual void adicionarPlaylist(string nome, string descricao) = 0;

    /**
     * @brief Remove uma playlist do usuário.
     *
     * @param idPlaylist ID da playlist a ser removida.
     */
    void removerPlaylist(int idPlaylist);

    /**
     * @brief Torna o usuário premium.
     */
    void tornarPremium();

    /**
     * @brief Método virtual para listar playlists restantes.
     *
     * Método virtual que pode ser implementado pelas classes derivadas.
     */
    virtual void playlistsRestantes() {}

    /**
     * @brief Altera as credenciais do usuário.
     *
     * @param novoNome Novo nome do usuário.
     * @param novoEmail Novo email do usuário.
     * @param novaSenha Nova senha do usuário.
     */
    void alterarCredenciais(const string &novoNome, const string &novoEmail, const string &novaSenha);
};

#endif // USUARIO_H
