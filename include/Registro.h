#ifndef REGISTRO_H
#define REGISTRO_H

#include "Autenticacao.h"

/**
 * @class Registro
 * @brief Classe responsável pelo registro de novos usuários.
 *
 * A classe Registro fornece métodos para registrar novos usuários, validando suas informações
 * através da classe Autenticacao.
 */
class Registro
{
public:
    /**
     * @brief Registra um novo usuário.
     *
     * Este método solicita ao usuário que insira suas informações e usa a classe Autenticacao
     * para validar e registrar o novo usuário.
     */
    void registrarUsuario();

private:
    Autenticacao autenticacao; ///< Instância da classe Autenticacao para validar e registrar usuários.
};

#endif // REGISTRO_H
