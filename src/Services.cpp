#include "Services.h"
#include "JsonService.cpp"
#include <iostream>
#include <string>
#include <cstdlib>

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

        if(nomeMusica.find(pesquisa) != std::string::npos || nomeArtista.find(pesquisa) != std::string::npos){
            result.push_back(musc["id"]);
        }
    }

    return result;
}

