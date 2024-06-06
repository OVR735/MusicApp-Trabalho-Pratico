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
        cout << "erro...";
    }

    // Analisar o conteúdo do JSON
    if (!reader.parseJSON())
    {
        cout << "erro...";
    }

    json usuarios = reader.getJSON();

    for (auto &user : usuarios["usuarios"])
    {
        if (user["id"] == id)
        {
            user["playlists"] = playlists;
            limitePlaylists--;
            reader.setJSONData(usuarios);
            if (!reader.writeJSONToFile("../data/Usuarios.json"))
            {
                throw "Erro ao escrever no arquivo JSON";
            }
            cout << "Playlist Criada com sucesso!";
        }
    }
}
