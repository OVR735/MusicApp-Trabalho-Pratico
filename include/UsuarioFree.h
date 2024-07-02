#ifndef USUARIOFREE_H
#define USUARIOFREE_H

#include "Usuario.h"

/**
 * @class UsuarioFree
 * @brief Classe que representa um usuário gratuito.
 *
 * A classe UsuarioFree é uma subclasse de Usuario e representa um tipo específico de usuário
 * com limitações diferentes em relação ao número de playlists que pode ter.
 */
class UsuarioFree : public Usuario {
public:
    /**
     * @brief Construtor da classe UsuarioFree.
     *
     * @param id ID do usuário.
     */
    UsuarioFree(int id) : Usuario(id) {
        limitePlaylists = 10; ///< Define o limite de playlists para usuários gratuitos como 10.
    };

    /**
     * @brief Método para exibir o número de playlists restantes.
     *
     * Este método sobrescreve o método virtual da classe base para exibir o número de playlists
     * que o usuário gratuito ainda pode adicionar.
     */
    void playlistsRestantes() override {
        cout << "Você ainda tem " << limitePlaylists << " playlists restantes!";
    }

    /**
     * @brief Método para adicionar uma nova playlist.
     *
     * Este método é uma implementação específica para usuários gratuitos da classe base,
     * para adicionar uma nova playlist com nome e descrição fornecidos.
     *
     * @param nome Nome da nova playlist.
     * @param descricao Descrição da nova playlist.
     */
    void adicionarPlaylist(string nome, string descricao) override;
};

#endif // USUARIOFREE_H
