#ifndef AUTENTICACAO_H
#define AUTENTICACAO_H

#include <string>
#include <unordered_map>
#include <utility>
#include "JsonService.h"
#include "Usuario.h"

using namespace std;

/**
 * @class Autenticacao
 * @brief Classe responsável pela autenticação de usuários.
 *
 * A classe Autenticacao fornece métodos para validar o registro e login de usuários.
 */
class Autenticacao
{
public:
    /**
     * @brief Valida o registro de um novo usuário.
     *
     * Este método verifica se o nome, email e senha fornecidos atendem aos critérios de registro.
     * Se o registro for válido, o usuário será adicionado ao sistema.
     *
     * @param nome Nome do usuário.
     * @param email Email do usuário.
     * @param senha Senha do usuário.
     * @return Um par onde o primeiro elemento é um booleano indicando o sucesso do registro,
     *         e o segundo elemento é uma mensagem de erro ou sucesso.
     */
    pair<bool, string> validarRegistro(const string &nome, const string &email, const string &senha);

    /**
     * @brief Valida o login de um usuário existente.
     *
     * Este método verifica se o email e a senha fornecidos correspondem a um usuário registrado.
     *
     * @param email Email do usuário.
     * @param senha Senha do usuário.
     * @return O ID do usuário se a autenticação for bem-sucedida, ou -1 se falhar.
     */
    int validarLogin(const string &email, const string &senha);
};

#endif // AUTENTICACAO_H
