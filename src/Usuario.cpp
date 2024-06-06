#include "Usuario.h"
#include <iostream>
#include "JsonService.cpp"

Usuario::Usuario(int sessionId){
    JSONService reader;

    if (!reader.openFile("../data/Usuarios.json")) {
        resultado.second = "Não foi possível abrir o arquivo Usuarios.json";
        return resultado;
    }

    // Analisar o conteúdo do JSON
    if (!reader.parseJSON()) {
        resultado.second = "Erro ao analisar o arquivo JSON";
        return resultado;
    }

    json usuarios = reader.getJSON();

    for (const auto& idUsuario : usuarios["id"]) {
        if(sessionId == idUsuario) {
            id = sessionId;
            nome = usuarios["nome"];
            email = usuarios["email"];
            senha = usuarios["senha"];
            playlists = usuarios["playlists"];
            return;
        }
    }

    throw exception; //Programar exceção depois
}

const std::string& Usuario::getNome() const { return nome; }
const std::string& Usuario::getEmail() const { return email; }
const std::string& Usuario::getSenha() const { return senha; }

void Usuario::removerPlaylist(const std::string& descricao) {
    auto it = std::remove_if(playlists.begin(), playlists.end(), [&](const Playlist& playlist) {
        return playlist.getDescricao() == descricao;
    });
    playlists.erase(it, playlists.end());
}

Usuario::~Usuario() {

}