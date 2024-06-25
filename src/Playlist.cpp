#include <iostream>
#include <stdexcept>
#include "JsonService.h"
#include <algorithm>
#include <utility>
#include "../include/Playlist.h"

using namespace std;

Playlist::Playlist(int idPlaylist) {
    try {
        JSONService reader;

        if (!reader.openFile("../data/Playlists.json")) {
            throw runtime_error("Não foi possível abrir o arquivo playlists.json");
        }

        if (!reader.parseJSON()) {
            throw runtime_error("Erro ao analisar o arquivo JSON");
        }

        json playlists = reader.getJSON();
        bool playlistEncontrada = false;

        for (const auto& play : playlists["playlists"]) {
            if (play["id"] == idPlaylist) {
                id = play["id"];
                idUsuario = play["idUsuario"];
                nome = play["nome"];
                descricao = play["descricao"];

                auto &muscs = play["musicas"];
                for (int i = 0; i < muscs.size(); i++) {
                    musicas.push_back(muscs[i]);
                }

                playlistEncontrada = true;
                break;
            }
        }

        if (!playlistEncontrada) {
            throw runtime_error("Playlist não encontrada");
        }

    } catch (const runtime_error &e) {
        cerr << "Erro: " << e.what() << endl;
    } catch (const exception &e) {
        cerr << "Erro inesperado: " << e.what() << endl;
    }
}

Playlist::Playlist(const string& nome, const string& descricao, int idUser) : nome(nome), descricao(descricao), idUsuario(idUser) {
    try {
        JSONService reader;

        if (!reader.openFile("../data/Playlists.json")) {
            throw runtime_error("Não foi possível abrir o arquivo playlists.json");
        }

        if (!reader.parseJSON()) {
            throw runtime_error("Erro ao analisar o arquivo JSON");
        }

        json playlists = reader.getJSON();

        int newId = 0;

        if (playlists["playlists"].size() > 0) {
            newId = playlists["playlists"].back()["id"];
        }

        newId += 1;
        id = newId;

        json novaPlaylist = {
            {"id", newId},
            {"idUsuario", idUser},
            {"nome", nome},
            {"descricao", descricao},
            {"musicas", {}}
        };

        playlists["playlists"].push_back(novaPlaylist);

        reader.setJSONData(playlists);

        if (!reader.writeJSONToFile("../data/Playlists.json")) {
            throw runtime_error("Erro ao atualizar o arquivo JSON com a nova playlist.");
        }
    } catch (const runtime_error &e) {
        cerr << "Erro: " << e.what() << endl;
    } catch (const exception &e) {
        cerr << "Erro inesperado: " << e.what() << endl;
    }
}

vector<int> Playlist::listarMusicas() {
    vector<int> muscArray;

    try {
        JSONService readerMusicas;

        if (!readerMusicas.openFile("../data/Musicas.json")) {
            throw runtime_error("Não foi possível abrir o arquivo Musicas.json");
        }

        if (!readerMusicas.parseJSON()) {
            throw runtime_error("Erro ao analisar o arquivo JSON");
        }

        json musicasJson = readerMusicas.getJSON();

        int counter = 1;

        for (const auto& musc : musicasJson["musicas"]) {
            int idMusica = musc["id"];
            if (std::find(musicas.begin(), musicas.end(), idMusica) != musicas.end()) {
                muscArray.push_back(idMusica);
                cout << counter << ") Nome: " << musc["nome"] << ", Artista: " << musc["artista"] << ", Duração: " << musc["duracao"] << endl;
                counter++;
            }
        }

        if (counter == 1) {
            cout << "Essa playlist ainda não tem músicas! Pesquise e adicione novas faixas. \n" << endl;
        }
    } catch (const runtime_error &e) {
        cerr << "Erro: " << e.what() << endl;
    } catch (const exception &e) {
        cerr << "Erro inesperado: " << e.what() << endl;
    }

    return muscArray;
}

pair<bool, int> Playlist::buscarMusica(string nomeMusica) {
    JSONService readerMusicas;
    pair<bool, int> resultado = make_pair(false, 0);

    try {
        if (!readerMusicas.openFile("../data/Musicas.json")) {
            throw runtime_error("Não foi possível abrir o arquivo Musicas.json");
        }

        if (!readerMusicas.parseJSON()) {
            throw runtime_error("Erro ao analisar o arquivo JSON");
        }

        json musicas = readerMusicas.getJSON();

        for (const auto& musc : musicas["musicas"]) {
            string nome = musc["nome"];
            size_t found = nome.find(nomeMusica);
            if (found != string::npos) {
                resultado.first = true;
                resultado.second = musc["id"];
                return resultado;
            }
        }
    } catch (const runtime_error &e) {
        cerr << "Erro: " << e.what() << endl;
    } catch (const exception &e) {
        cerr << "Erro inesperado: " << e.what() << endl;
    }

    return resultado;
}

pair<bool, string> Playlist::adicionarMusica(int idMusica) {
    pair<bool, string> resultado = make_pair(false, "");

    try {
        JSONService readerPlaylists;
        JSONService readerMusicas;

        if (!readerMusicas.openFile("../data/Musicas.json")) {
            throw runtime_error("Não foi possível abrir o arquivo musicas.json");
        }

        if (!readerPlaylists.openFile("../data/Playlists.json")) {
            throw runtime_error("Não foi possível abrir o arquivo playlists.json");
        }

        if (!readerPlaylists.parseJSON()) {
            throw runtime_error("Erro ao analisar o arquivo JSON de playlists");
        }

        if (!readerMusicas.parseJSON()) {
            throw runtime_error("Erro ao analisar o arquivo JSON de músicas");
        }

        json playlists = readerPlaylists.getJSON();
        json musicas = readerMusicas.getJSON();

        for (auto& playlist : playlists["playlists"]) {
            if (getID() == playlist["id"]) {
                auto& musicasNaPlaylist = playlist["musicas"];
                auto it = std::find(musicasNaPlaylist.begin(), musicasNaPlaylist.end(), idMusica);
                if (it != musicasNaPlaylist.end()) {
                    resultado.second = "Música já está na playlist.";
                    return resultado;
                }

                musicasNaPlaylist.push_back(idMusica);

                for (auto& it : musicasNaPlaylist) {
                    cout << "Codigo de musicas na playlist: " << it << endl;
                }

                readerPlaylists.setJSONData(playlists);

                if (!readerPlaylists.writeJSONToFile("../data/Playlists.json")) {
                    throw runtime_error("Erro ao atualizar o arquivo JSON da playlist com a nova música.");
                }

                resultado.first = true;
                return resultado;
            }
        }

        resultado.second = "Playlist não encontrada.";
    } catch (const runtime_error &e) {
        resultado.second = e.what();
    } catch (const exception &e) {
        resultado.second = "Erro inesperado: " + string(e.what());
    }

    return resultado;
}

pair<bool, string> Playlist::removerMusica(int idMusica) {
    pair<bool, string> resultado = make_pair(false, "");

    try {
        JSONService readerPlaylists;
        JSONService readerMusicas;

        if (!readerMusicas.openFile("../data/Musicas.json")) {
            throw runtime_error("Não foi possível abrir o arquivo musicas.json");
        }

        if (!readerPlaylists.openFile("../data/Playlists.json")) {
            throw runtime_error("Não foi possível abrir o arquivo playlists.json");
        }

        if (!readerPlaylists.parseJSON()) {
            throw runtime_error("Erro ao analisar o arquivo JSON de playlists");
        }

        if (!readerMusicas.parseJSON()) {
            throw runtime_error("Erro ao analisar o arquivo JSON de músicas");
        }

        json playlists = readerPlaylists.getJSON();
        json musicas = readerMusicas.getJSON();

        for (auto& playlist : playlists["playlists"]) {
            if (getID() == playlist["id"]) {
                auto& musicasNaPlaylist = playlist["musicas"];
                auto it = std::find(musicasNaPlaylist.begin(), musicasNaPlaylist.end(), idMusica);

                if (it == musicasNaPlaylist.end()) {
                    resultado.second = "Música não encontrada na playlist.";
                    return resultado;
                }

                musicasNaPlaylist.erase(it);

                readerPlaylists.setJSONData(playlists);

                if (!readerPlaylists.writeJSONToFile("../data/Playlists.json")) {
                    throw runtime_error("Erro ao atualizar o arquivo JSON da playlist");
                }

                resultado.first = true;
                return resultado;
            }
        }

        resultado.second = "Playlist não encontrada.";
    } catch (const runtime_error &e) {
        resultado.second = e.what();
    } catch (const exception &e) {
        resultado.second = "Erro inesperado: " + string(e.what());
    }

    return resultado;
}

void Playlist::setNome(string nome) {
    this->nome = nome;
}

void Playlist::setDescricao(string descricao) {
    this->descricao = descricao;
}

string Playlist::getDescricao() {
    return descricao;
}

string Playlist::getNome() {
    return nome;
}

void Playlist::setUsuarioDono(int idUsuario) {
    this->idUsuario = idUsuario;
}

int Playlist::getID() {
    return id;
}