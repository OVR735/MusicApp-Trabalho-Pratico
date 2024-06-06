#include "UsuarioPremium.h"
#include <iostream>
#include "JsonService.cpp"

const std::string& UsuarioPremium::playlistRestantes(){
    return "Aproveite os beneficios do premium! Playlists sem limites"
}

void UsuarioPremium::adicionarPlaylist() {

    JSONService reader;
    
    Playlist newPlaylist = new Playlist("aaaa", "bb", id)

    playlists.push_back(newPlaylist.getID());

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
        if(idUsuario == id) {
            usuarios["playlists"] = playlists
            if (!reader.writeJSONToFile("../data/Usuarios.json")) {
                throw "Erro ao escrever no arquivo JSON";
            }
            return;
        }
    }

    throw exception; //Programar exceção depois
}
