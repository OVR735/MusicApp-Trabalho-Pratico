#include "UsuarioPremium.h"
#include <iostream>


void UsuarioPremium::playlistRestantes(){
    cout << "Aproveite os beneficios do premium! Playlists sem limites";
}

void UsuarioPremium::adicionarPlaylist() {

    JSONService reader;
    
    Playlist newPlaylist("aaaa", "bb", id);

    playlists.push_back(newPlaylist.getID());

    if (!reader.openFile("../data/Usuarios.json")) {
        cout << "erro...";
    }

    // Analisar o conteúdo do JSON
    if (!reader.parseJSON()) {
        cout << "erro...";
    }

    json usuarios = reader.getJSON();

    for (const auto& idUsuario : usuarios["id"]) {
        if(idUsuario == id) {
            usuarios["playlists"] = playlists;
            if (!reader.writeJSONToFile("../data/Usuarios.json")) {
                throw "Erro ao escrever no arquivo JSON";
            }
            return;
        }
    }

    throw "aqui não passou";
}
