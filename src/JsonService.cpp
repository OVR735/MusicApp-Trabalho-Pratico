#include "../include/JsonService.h"

JSONService::JSONService() {
    // Construtor
}

JSONService::~JSONService() {
    // Destrutor
    closeFile();
}

bool JSONService::openFile(const std::string& filename) {
    fileStream.open(filename);
    return fileStream.is_open();
}

void JSONService::closeFile() {
    if (fileStream.is_open()) {
        fileStream.close();
    }
}

bool JSONService::parseJSON() {
    if (fileStream.is_open()) {
        try {
            fileStream >> jsonData;
            return true;
        } catch (const std::exception& e) {
            std::cerr << "Erro ao converter para JSON " << e.what() << std::endl;
            return false;
        }
    } else {
        std::cerr << "Arquivo não aberto" << std::endl;
        return false;
    }
}

json JSONService::getJSON() const {
    return jsonData;
}

void JSONService::setJSONData(json data) {
    jsonData = data;
};

bool JSONService::writeJSONToFile(const std::string& filename) {
    std::ofstream outFile(filename);
    if (outFile.is_open()) {
        try {
            outFile << std::setw(4) << jsonData; // Pretty-print JSON with indentation
            outFile.close();
            return true;
        } catch (const std::exception& e) {
            std::cerr << "Erro ao escrever no arquivo: " << e.what() << std::endl;
            outFile.close();
            return false;
        }
    } else {
        std::cerr << "Impossível abrir arquivo para escrita." << filename << std::endl;
        return false;
    }
}