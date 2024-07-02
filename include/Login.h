#ifndef LOGIN_H
#define LOGIN_H

#include "Autenticacao.h"

/**
 * @class Login
 * @brief Classe responsável por gerenciar o processo de login de usuários.
 *
 * A classe Login fornece métodos para realizar o login de usuários, validando suas credenciais
 * através da classe Autenticacao.
 */
class Login {
public:
    /**
     * @brief Construtor da classe Login.
     */
    Login();

    /**
     * @brief Realiza o login de um usuário.
     *
     * Este método solicita ao usuário que insira seu email e senha, e usa a classe Autenticacao
     * para validar as credenciais.
     *
     * @return O ID do usuário se o login for bem-sucedido, ou -1 se falhar.
     */
    int fazerLogin();

private:
    Autenticacao autenticacao; ///< Instância da classe Autenticacao para validar credenciais.
};

#endif // LOGIN_H
