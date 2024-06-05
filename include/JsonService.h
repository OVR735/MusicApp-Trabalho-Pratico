#ifndef JSONREADER_H
#define JSONREADER_H

#include <string>
#include <fstream>
#include <iostream>
#include <nlohmann/json.hpp>

using namespace std;
using json = nlohmann::json;

class JSONService {
    public:
        JSONService();
        ~JSONService();

        bool openFile(const string& filename);
        void closeFile();

        bool parseJSON(); // Método para analisar o JSON e armazenar os dados

        // Método para acessar o JSON como um objeto
        json getJSON() const;

        void setJSONData(json data);

        // Método para escrever o JSON de volta ao arquivo
        bool writeJSONToFile(const string& filename);
        

    private:
        ifstream fileStream;
        json jsonData;
};

#endif // JSONREADER_H