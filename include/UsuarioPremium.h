#ifndef USUARIOPREMIUM_H
#define USUARIOPREMIUM_H

#include <climits>
#include "Usuario.h"

/**
 * @class UsuarioPremium
 * @brief Classe que representa um usuário premium.
 *
 * A classe UsuarioPremium é uma subclasse de Usuario e representa um tipo específico de usuário
 * com benefícios adicionais, como limite de playlists ilimitado.
 */
class UsuarioPremium : public Usuario {
public:
    /**
     * @brief Construtor da classe UsuarioPremium.
     *
     * @param id ID do usuário.
     */
    UsuarioPremium(int id) : Usuario(id) {
        limitePlaylists = INT_MAX; ///< Define o limite de playlists para usuários premium como infinito.
    };

    /**
     * @brief Método para exibir benefícios premium.
     *
     * Este método sobrescreve o método virtual da classe base para exibir os benefícios adicionais
     * que usuários premium possuem em relação às playlists.
     */
    void playlistsRestantes() override {
        cout << "Aproveite os benefícios do premium! Playlists sem limites.";
    }

    /**
     * @brief Método para adicionar uma nova playlist.
     *
     * Este método é uma implementação específica para usuários premium da classe base,
     * para adicionar uma nova playlist com nome e descrição fornecidos.
     *
     * @param nome Nome da nova playlist.
     * @param descricao Descrição da nova playlist.
     */
    void adicionarPlaylist(string nome, string descricao) override;
};

#endif // USUARIOPREMIUM_H
