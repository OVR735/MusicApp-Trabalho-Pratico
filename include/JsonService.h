#ifndef JSONREADER_H
#define JSONREADER_H

#include <string>
#include <fstream>
#include <iostream>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

class JSONReader {
public:
    JSONReader();
    ~JSONReader();

    bool openFile(const std::string& filename);
    void closeFile();

    bool parseJSON(); // Método para analisar o JSON e armazenar os dados

    // Método para acessar o JSON como um objeto
    json getJSON() const;

    // Método para escrever o JSON de volta ao arquivo
    bool writeJSONToFile(const std::string& filename);

private:
    std::ifstream fileStream;
    json jsonData;
};

#endif // JSONREADER_H