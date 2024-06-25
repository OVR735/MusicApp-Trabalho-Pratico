#include "Usuario.h"
#include <iostream>

Usuario::Usuario(int sessionId) {
    JSONService reader;

    try {
        if (!reader.openFile("../data/Usuarios.json")) {
            throw std::runtime_error("Não foi possível abrir o arquivo Usuarios.json");
        }

        if (!reader.parseJSON()) {
            throw std::runtime_error("Erro ao analisar o arquivo JSON");
        }

        json usuarios = reader.getJSON();

        for (auto& user : usuarios["usuarios"]) {
            if (sessionId == user["id"]) {
                id = sessionId;
                nome = user["nome"];
                email = user["email"];
                senha = user["senha"];
                premium = user["premium"];
                for (auto& idPlaylist : user["playlists"]) {
                    playlists.push_back(idPlaylist);
                }
                return;
            }
        }

        throw std::runtime_error("Usuário não encontrado");
    } catch (const std::exception& e) {
        std::cerr << "Erro ao inicializar usuário: " << e.what() << std::endl;
        throw;
    } catch (...) {
        std::cerr << "Exceção desconhecida ao inicializar usuário" << std::endl;
        throw;
    }
}

const int Usuario::getId() const { return id; }
const std::string& Usuario::getNome() const { return nome; }
const std::string& Usuario::getEmail() const { return email; }
const std::string& Usuario::getSenha() const { return senha; }
const bool Usuario::isPremium() const { return premium; }

void Usuario::removerPlaylist(int idPlaylist) {
    JSONService readerUsuarios;
    JSONService readerPlaylists;

    try {
        if (!readerUsuarios.openFile("../data/Usuarios.json") || !readerPlaylists.openFile("../data/Playlists.json")) {
            throw std::runtime_error("Erro ao abrir arquivo(s) JSON.");
        }

        if (!readerUsuarios.parseJSON() || !readerPlaylists.parseJSON()) {
            throw std::runtime_error("Erro ao analisar arquivo(s) JSON.");
        }

        json usuarios = readerUsuarios.getJSON();
        json playlists = readerPlaylists.getJSON();

        bool usuarioEncontrado = false;

        for (auto& user : usuarios["usuarios"]) {
            if (id == user["id"]) {
                auto& userPlaylists = user["playlists"];

                auto it = std::find(userPlaylists.begin(), userPlaylists.end(), idPlaylist);
                if (it != userPlaylists.end()) {
                    userPlaylists.erase(it);

                    readerUsuarios.setJSONData(usuarios);

                    if (!readerUsuarios.writeJSONToFile("../data/Usuarios.json")) {
                        throw std::runtime_error("Erro ao atualizar arquivo Usuarios.json.");
                    }

                    std::cout << "Playlist do usuário removida com sucesso." << std::endl;
                    limitePlaylists++;
                    usuarioEncontrado = true;
                } else {
                    std::cerr << "Playlist não encontrada para o usuário." << std::endl;
                }
                break;
            }
        }

        if (!usuarioEncontrado) {
            throw std::runtime_error("Usuário não encontrado.");
        }

        bool playlistEncontrada = false;

        for (auto it = playlists["playlists"].begin(); it != playlists["playlists"].end(); ++it) {
            if ((*it)["id"] == idPlaylist) {
                playlists["playlists"].erase(it);
                playlistEncontrada = true;
                break;
            }
        }

        if (!playlistEncontrada) {
            throw std::runtime_error("Playlist não encontrada.");
        }

        readerPlaylists.setJSONData(playlists);

        if (!readerPlaylists.writeJSONToFile("../data/Playlists.json")) {
            throw std::runtime_error("Erro ao atualizar arquivo Playlists.json.");
        }
    } catch (const std::exception& e) {
        std::cerr << "Erro ao remover playlist: " << e.what() << std::endl;
        throw; 
    } catch (...) {
        std::cerr << "Exceção desconhecida ao remover playlist." << std::endl;
        throw;
    }
}

void Usuario::alterarCredenciais(const string &novoNome, const string &novoEmail, const string &novaSenha) {
    JSONService reader;

    try {
        if (!reader.openFile("../data/Usuarios.json")) {
            throw std::runtime_error("Não foi possível abrir o arquivo Usuarios.json");
        }

        if (!reader.parseJSON()) {
            throw std::runtime_error("Erro ao analisar o arquivo JSON");
        }

        json usuarios = reader.getJSON();

        bool usuarioEncontrado = false;

        for (auto &user : usuarios["usuarios"]) {
            if (id == user["id"]) {
                user["nome"] = novoNome;
                user["email"] = novoEmail;
                user["senha"] = novaSenha;
                reader.setJSONData(usuarios);

                if (!reader.writeJSONToFile("../data/Usuarios.json")) {
                    throw std::runtime_error("Erro ao atualizar o arquivo JSON com as novas credenciais.");
                }

                nome = novoNome;
                email = novoEmail;
                senha = novaSenha;
                usuarioEncontrado = true;
                break;
            }
        }

        if (!usuarioEncontrado) {
            throw std::runtime_error("Usuário não encontrado");
        }
    } catch (const std::exception &e) {
        std::cerr << "Erro ao alterar credenciais: " << e.what() << std::endl;
        throw; 
    } catch (...) {
        std::cerr << "Exceção desconhecida ao alterar credenciais." << std::endl;
        throw; 
    }
}

void Usuario::tornarPremium() {
    JSONService reader;

    try {
        if (!reader.openFile("../data/Usuarios.json")) {
            throw std::runtime_error("Não foi possível abrir o arquivo Usuarios.json");
        }

        if (!reader.parseJSON()) {
            throw std::runtime_error("Erro ao analisar o arquivo JSON");
        }

        json usuarios = reader.getJSON();

        bool usuarioEncontrado = false;

        for (auto& user : usuarios["usuarios"]) {
            if (user["id"] == id) {
                user["premium"] = true;
                premium = true;
                reader.setJSONData(usuarios);

                if (!reader.writeJSONToFile("../data/Usuarios.json")) {
                    throw std::runtime_error("Erro ao escrever no arquivo JSON");
                }

                cout << "Agora você é um usuário premium!\n\n";
                usuarioEncontrado = true;
                break;
            }
        }

        if (!usuarioEncontrado) {
            throw std::runtime_error("Usuário não encontrado");
        }
    } catch (const std::exception& e) {
        std::cerr << "Erro ao tornar usuário premium: " << e.what() << std::endl;
        throw; // Re-throw para que o erro seja tratado onde a função foi originalmente chamada
    } catch (...) {
        std::cerr << "Exceção desconhecida ao tornar usuário premium." << std::endl;
        throw; // Re-throw para que o erro seja tratado onde a função foi originalmente chamada
    }
}
