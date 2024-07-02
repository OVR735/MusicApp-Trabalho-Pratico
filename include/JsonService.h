#ifndef JSONSERVICE_H
#define JSONSERVICE_H

#include <string>
#include <fstream>
#include <iostream>
#include <nlohmann/json.hpp>

using namespace std;
using json = nlohmann::json;

/**
 * @class JSONService
 * @brief Classe responsável por ler, analisar e escrever dados JSON.
 *
 * A classe JSONService fornece métodos para abrir arquivos JSON, analisar seu conteúdo,
 * acessar e modificar dados JSON e gravar dados JSON de volta em um arquivo.
 */
class JSONService {
public:
    /**
     * @brief Construtor da classe JSONService.
     */
    JSONService();

    /**
     * @brief Destrutor da classe JSONService.
     */
    ~JSONService();

    /**
     * @brief Abre um arquivo JSON.
     *
     * @param filename Nome do arquivo JSON a ser aberto.
     * @return true se o arquivo foi aberto com sucesso, false caso contrário.
     */
    bool openFile(const string& filename);

    /**
     * @brief Fecha o arquivo JSON.
     */
    void closeFile();

    /**
     * @brief Analisa o conteúdo do arquivo JSON e armazena os dados.
     *
     * @return true se a análise foi bem-sucedida, false caso contrário.
     */
    bool parseJSON();

    /**
     * @brief Obtém os dados JSON como um objeto.
     *
     * @return Um objeto JSON contendo os dados analisados.
     */
    json getJSON() const;

    /**
     * @brief Define os dados JSON.
     *
     * @param data Dados JSON a serem definidos.
     */
    void setJSONData(json data);

    /**
     * @brief Escreve os dados JSON de volta para um arquivo.
     *
     * @param filename Nome do arquivo JSON onde os dados serão gravados.
     * @return true se os dados foram gravados com sucesso, false caso contrário.
     */
    bool writeJSONToFile(const string& filename);

private:
    ifstream fileStream; ///< Fluxo de arquivo para leitura do arquivo JSON.
    json jsonData; ///< Objeto JSON contendo os dados analisados.
};

#endif // JSONSERVICE_H
