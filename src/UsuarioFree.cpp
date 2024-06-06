#include "UsuarioFree.h"
#include <iostream>
#include <string>

void UsuarioFree::playlistRestantes()
{
    cout << "Você ainda tem " << limitePlaylists << "restantes!";
}

void UsuarioFree::adicionarPlaylist()
{

    JSONService reader;

    if (limitePlaylists < playlists.size())
    {

        Playlist newPlaylist("aaaa", "bb", id);

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
                limitePlaylists--;
                reader.setJSONData(usuarios);
                if (!reader.writeJSONToFile("../data/Usuarios.json")) {
                    throw "Erro ao escrever no arquivo JSON";
                }
                return;
            }
        }
    }
    else
    {
        throw "Você antigiu o limite de playlists. Assine o premium para músicas sem limite!";
    }

    throw "deu erro aqui"; // Programar exceção depois
}
