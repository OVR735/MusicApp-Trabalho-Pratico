#include "UsuarioFree.h"
#include <iostream>
#include <string>
#include "JsonService.cpp"

const std::string &UsuarioFree::playlistRestantes()
{
    return "Você ainda tem " + std::to_string(limitePlaylists) + "restantes!";
}

void UsuarioFree::adicionarPlaylist()
{

    JSONService reader;

    if (limitePlaylists < playlists.size())
    {

        Playlist newPlaylist = new Playlist("aaaa", "bb", id)

        playlists.push_back(newPlaylist.getID());

        if (!reader.openFile("../data/Usuarios.json"))
        {
            resultado.second = "Não foi possível abrir o arquivo Usuarios.json";
            return resultado;
        }

        // Analisar o conteúdo do JSON
        if (!reader.parseJSON())
        {
            resultado.second = "Erro ao analisar o arquivo JSON";
            return resultado;
        }

        json usuarios = reader.getJSON();

        for (const auto &idUsuario : usuarios["id"])
        {
            if (idUsuario == id)
            {
                usuarios["playlists"] = playlists;
                limitePlaylists--;
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

    throw exception; // Programar exceção depois
}
