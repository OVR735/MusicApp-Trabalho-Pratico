#include "UsuarioFree.h"
#include <iostream>
#include <string>

void UsuarioFree::adicionarPlaylist(string nome, string descricao)
{
    JSONService reader;

    try {
        if (playlists.size() >= limitePlaylists) {
            cout << "Você atingiu o limite de playlists. Assine o premium para músicas sem limite!" << endl;
            return;
        }

        Playlist newPlaylist(nome, descricao, id);
        playlists.push_back(newPlaylist.getID());

        if (!reader.openFile("../data/Usuarios.json")) {
            throw std::runtime_error("Não foi possível abrir o arquivo Usuarios.json");
        }

        if (!reader.parseJSON()) {
            throw std::runtime_error("Erro ao analisar o arquivo JSON");
        }

        json usuarios = reader.getJSON();

        bool usuarioEncontrado = false;

        for (auto &user : usuarios["usuarios"]) {
            if (user["id"] == id) {
                user["playlists"] = playlists;
                limitePlaylists--;
                reader.setJSONData(usuarios);

                if (!reader.writeJSONToFile("../data/Usuarios.json")) {
                    throw std::runtime_error("Erro ao escrever no arquivo JSON");
                }

                cout << "Playlist criada com sucesso!" << endl;
                usuarioEncontrado = true;
                break;
            }
        }

        if (!usuarioEncontrado) {
            throw std::runtime_error("Usuário não encontrado");
        }
    } catch (const std::exception &e) {
        std::cerr << "Erro ao adicionar playlist: " << e.what() << std::endl;
        throw;
    } catch (...) {
        std::cerr << "Exceção desconhecida ao adicionar playlist." << std::endl;
        throw;
    }
}
