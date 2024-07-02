#ifndef MENU_H
#define MENU_H

#include <string>
#include <vector>
#include "Usuario.h"

using namespace std;

/**
 * @class Menu
 * @brief Classe responsável por exibir e gerenciar o menu do usuário.
 *
 * A classe Menu fornece métodos para exibir o menu principal, alterar credenciais, 
 * adicionar playlists, exibir playlists e tornar o usuário premium.
 */
class Menu {
public:
    /**
     * @brief Construtor da classe Menu.
     *
     * @param usuario Ponteiro para um objeto Usuario.
     */
    Menu(Usuario* usuario);

    /**
     * @brief Exibe o menu principal para o usuário.
     */
    void exibirMenu();

private:
    Usuario* usuario; ///< Ponteiro para o objeto Usuario associado ao menu.

    /**
     * @brief Permite ao usuário alterar suas credenciais.
     */
    void alterarCredenciais();

    /**
     * @brief Adiciona uma nova playlist para o usuário.
     */
    void adicionarPlaylistUsuario();

    /**
     * @brief Exibe as playlists do usuário.
     *
     * @return Um vetor contendo os IDs das playlists do usuário.
     */
    vector<int> exibirPlaylists();

    /**
     * @brief Exibe o menu para uma playlist específica.
     *
     * @param idPlaylist ID da playlist a ser exibida.
     */
    void exibirMenuPlaylist(int idPlaylist);

    /**
     * @brief Torna o usuário premium.
     */
    void tornarUsuarioPremium();
};

#endif // MENU_H
