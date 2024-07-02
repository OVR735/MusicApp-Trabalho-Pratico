#ifndef SERVICES_H
#define SERVICES_H

#include <vector>
#include <string>

using namespace std;

/**
 * @class Services
 * @brief Classe que fornece vários serviços auxiliares.
 *
 * A classe Services oferece métodos para pesquisar músicas, verificar o status do usuário,
 * limpar o console e obter informações de músicas por ID.
 */
class Services
{
public:
    /**
     * @brief Construtor da classe Services.
     */
    Services();

    /**
     * @brief Obtém uma lista de IDs de músicas com base em uma string de pesquisa.
     *
     * @param pesquisa A string usada para pesquisar músicas.
     * @return Um vetor contendo os IDs das músicas que correspondem à pesquisa.
     */
    vector<int> obterMusicasPorString(string pesquisa);

    /**
     * @brief Verifica o status de um usuário.
     *
     * @param userId O ID do usuário.
     * @return true se o usuário estiver ativo, false caso contrário.
     */
    bool obterStatusUsuario(int userId);

    /**
     * @brief Limpa o console.
     */
    void clearConsole();

    /**
     * @brief Obtém informações de uma música pelo ID.
     *
     * @param id O ID da música.
     */
    void obterMusicaPorID(int id);
};

#endif // SERVICES_H
