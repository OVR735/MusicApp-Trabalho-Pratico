#include "UsuarioPremium.h"
#include <iostream>

void UsuarioPremium::playlistRestantes()
{
    cout << "Aproveite os beneficios do premium! Playlists sem limites";
}

void UsuarioPremium::adicionarPlaylist(string nome, string descricao)
{

    JSONService reader;

    Playlist newPlaylist(nome, descricao, id);

    playlists.push_back(newPlaylist.getID());

    if (!reader.openFile("../data/Usuarios.json"))
    {
        throw "deu erro aqui";
    }

    // Analisar o conteúdo do JSON
    if (!reader.parseJSON())
    {
        throw "deu erro aqui";
    }

    json usuarios = reader.getJSON();

    for (auto &user : usuarios["usuarios"])
    {
        if (user["id"] == id)
        {
            user["playlists"] = playlists;
            reader.setJSONData(usuarios);
            if (!reader.writeJSONToFile("../data/Usuarios.json")) {
                throw "Erro ao escrever no arquivo JSON";
            }
            cout << "Playlist Criada com sucesso! \n" << endl;
        }
    }
}
