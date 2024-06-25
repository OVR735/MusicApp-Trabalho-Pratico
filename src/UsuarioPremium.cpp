#include "UsuarioPremium.h"
#include <iostream>
#include <stdexcept> // para std::runtime_error

using namespace std;

void UsuarioPremium::adicionarPlaylist(string nome, string descricao)
{
    JSONService reader;

    try
    {
        Playlist newPlaylist(nome, descricao, id);
        playlists.push_back(newPlaylist.getID());

        if (!reader.openFile("../data/Usuarios.json"))
        {
            throw runtime_error("Erro ao abrir o arquivo JSON");
        }

        // Analisar o conteúdo do JSON
        if (!reader.parseJSON())
        {
            throw runtime_error("Erro ao analisar o JSON");
        }

        json usuarios = reader.getJSON();

        bool userFound = false;

        for (auto &user : usuarios["usuarios"])
        {
            if (user["id"] == id)
            {
                user["playlists"] = playlists;
                reader.setJSONData(usuarios);
                if (!reader.writeJSONToFile("../data/Usuarios.json"))
                {
                    throw runtime_error("Erro ao escrever no arquivo JSON");
                }
                userFound = true;
                cout << "Playlist criada com sucesso! \n"
                     << endl;
                break;
            }
        }

        if (!userFound)
        {
            throw runtime_error("Usuário não encontrado no JSON");
        }
    }
    catch (const runtime_error &e)
    {
        cerr << "Erro: " << e.what() << endl;
    }
    catch (const exception &e)
    {
        cerr << "Erro inesperado: " << e.what() << endl;
    }
}
