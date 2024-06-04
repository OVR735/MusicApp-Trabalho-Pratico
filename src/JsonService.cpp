#include "../include/JsonService.h"

JSONReader::JSONReader() {
    // Construtor
}

JSONReader::~JSONReader() {
    // Destrutor
    closeFile();
}

bool JSONReader::openFile(const std::string& filename) {
    fileStream.open(filename);
    return fileStream.is_open();
}

void JSONReader::closeFile() {
    if (fileStream.is_open()) {
        fileStream.close();
    }
}

bool JSONReader::parseJSON() {
    if (fileStream.is_open()) {
        try {
            fileStream >> jsonData;
            return true;
        } catch (const std::exception& e) {
            std::cerr << "Error parsing JSON: " << e.what() << std::endl;
            return false;
        }
    } else {
        std::cerr << "No file open." << std::endl;
        return false;
    }
}

json JSONReader::getJSON() const {
    return jsonData;
}

bool JSONReader::writeJSONToFile(const std::string& filename) {
    std::ofstream outFile(filename);
    if (outFile.is_open()) {
        try {
            outFile << std::setw(4) << jsonData; // Pretty-print JSON with indentation
            outFile.close();
            return true;
        } catch (const std::exception& e) {
            std::cerr << "Error writing JSON to file: " << e.what() << std::endl;
            outFile.close();
            return false;
        }
    } else {
        std::cerr << "Unable to open file for writing: " << filename << std::endl;
        return false;
    }
}