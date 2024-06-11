#include "Services.h"
#include "JsonService.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <stdexcept>

Services::Services() {}

void Services::clearConsole() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

bool Services::obterStatusUsuario(int userId) {
    JSONService reader;

    if (!reader.openFile("../data/Usuarios.json")) {
        throw "Não foi possível abrir o arquivo Usuarios.json";
    }

    if (!reader.parseJSON()) {
        throw "Erro ao analisar o arquivo JSON";
    }

    json usuarios = reader.getJSON();
    for (const auto& usuario : usuarios["usuarios"]) {
        if (userId == usuario["id"]) {
            return usuario["premium"];
        }
    }

    throw "Usuário não encontrado";
}

bool containsIgnoreCase(const std::string& str, const std::string& substr) {
    // Cria cópias das strings para converter para minúsculas
    std::string strLower = str;
    std::string substrLower = substr;

    // Converte ambas as strings para minúsculas
    std::transform(strLower.begin(), strLower.end(), strLower.begin(), ::tolower);
    std::transform(substrLower.begin(), substrLower.end(), substrLower.begin(), ::tolower);

    // Verifica se a substring está contida na string
    return strLower.find(substrLower) != std::string::npos;
}

vector<int> Services::obterMusicasPorString(string pesquisa){
    JSONService reader;

    if (!reader.openFile("../data/Musicas.json")) {
        throw "Não foi possível abrir o arquivo Musicas.json";
    }

    if (!reader.parseJSON()) {
        throw "Erro ao analisar o arquivo JSON";
    }

    json musicas = reader.getJSON();

    std::vector<int> result;

    for (const auto& musc : musicas["musicas"]) {
        string nomeMusica = musc["nome"];
        string nomeArtista = musc["artista"];

        if(containsIgnoreCase(nomeArtista, pesquisa) || containsIgnoreCase(nomeMusica, pesquisa)){
            result.push_back(musc["id"]);
        }
    }

    return result;
}

void Services::obterMusicaPorID(int id) {
    JSONService reader;

    if (!reader.openFile("../data/Musicas.json")) {
        throw std::runtime_error("Não foi possível abrir o arquivo Musicas.json");
    }

    if (!reader.parseJSON()) {
        throw std::runtime_error("Erro ao analisar o arquivo JSON");
    }

    json musicas = reader.getJSON();

    for (const auto& musc : musicas["musicas"]) {
        if (musc["id"] == id) {
            cout << "Nome: " << musc["nome"] << ", Artista: " << musc["artista"] << ", Duração: " << musc["duracao"] << "\n";
        }
    }

    //throw std::runtime_error("Música com o ID fornecido não foi encontrada");
}
