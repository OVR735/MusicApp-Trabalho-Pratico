#include <iostream>
#include "../include/Playlist.h"
#include "JsonService.h"
#include <algorithm>
#include <utility>

using namespace std;

Playlist::Playlist(int idPlaylist) {
    JSONService reader;

    if (!reader.openFile("../data/Playlists.json")) {
        cout << "Não foi possível abrir o arquivo playlists.json" << endl;
    }

    if (!reader.parseJSON()) {
        cout << "Erro ao analisar o arquivo JSON" << endl;
    }

    json playlists = reader.getJSON();

    for (const auto& play : playlists["playlists"]) {
        if(play["id"] == idPlaylist) {
            id = play["id"];
            idUsuario = play["idUsuario"];
            nome = play["nome"];
            descricao = play["descricao"];
            
            auto &muscs = play["musicas"];
            for (int i = 0; i < muscs.size(); i++) {
                musicas.push_back(muscs[i]);
            }
            
            break;
        }
    }
}

Playlist::Playlist(const string& nome, const string& descricao, int idUser) : nome(nome), descricao(descricao), idUsuario(idUser) {
    JSONService reader;

    if (!reader.openFile("../data/Playlists.json")) {
        cout << "Não foi possível abrir o arquivo playlists.json" << endl;
    }

    if (!reader.parseJSON()) {
        cout << "Erro ao analisar o arquivo JSON" << endl;
    }

    json playlists = reader.getJSON();

    int newId = 0;

    if(playlists["playlists"].size() > 0) {
        int newId = playlists["playlists"].back()["id"];
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
        cout << "Erro ao atualizar o arquivo JSON com a nova playlist." << endl;
    }
}

vector<int> Playlist::listarMusicas() {
    JSONService readerMusicas;
    vector<int> muscArray;

    if (!readerMusicas.openFile("../data/Musicas.json")) {
        return muscArray;
    }

    if (!readerMusicas.parseJSON()) {
        return muscArray;
    }

    json musicasJson = readerMusicas.getJSON();

    int counter = 1;

    for (const auto& musc : musicasJson["musicas"]) {
        int idMusica = musc["id"];
        if(std::find(musicas.begin(), musicas.end(), idMusica) != musicas.end()) {
            muscArray.push_back(idMusica);
            cout << counter << ") Nome: " << musc["nome"] << ", Artista: " << musc["artista"] << ", Duração: " << musc["duracao"] << endl;
            counter++;
        }
    }

    if(counter == 1) {
        cout << "Essa playlist ainda não tem músicas! Pesquise e adicione novas faixas. \n" << endl;
    }

    return muscArray;
}

pair<bool, int> Playlist::buscarMusica(string nomeMusica) {
    JSONService readerMusicas;

    pair<bool, int> resultado = make_pair(false, 0);

    if (!readerMusicas.openFile("../data/Musicas.json")) {
        return resultado;
    }

    if (!readerMusicas.parseJSON()) {
        return resultado;
    }

    json musicas = readerMusicas.getJSON();

    for (const auto& musc : musicas["musicas"]) {
        string nome = musc["nome"];
        size_t found = nome.find(nomeMusica);
        if(found != string::npos) {
            resultado.first = true;
            resultado.second = musc["id"];
            return resultado;
        }
    }

    return resultado;
}

pair<bool, string> Playlist::adicionarMusica(int idMusica) {
    JSONService readerPlaylists;
    JSONService readerMusicas;

    pair<bool, string> resultado = make_pair(false, "");

    if (!readerMusicas.openFile("../data/Musicas.json")) {
        resultado.second = "Não foi possível abrir o arquivo musicas.json";
        return resultado;
    }

    if (!readerPlaylists.openFile("../data/Playlists.json")) {
        resultado.second = "Não foi possível abrir o arquivo playlists.json";
        return resultado;
    }

    if (!readerPlaylists.parseJSON()) {
        resultado.second = "Erro ao analisar o arquivo JSON de playlists";
        return resultado;
    }

    if (!readerMusicas.parseJSON()) {
        resultado.second = "Erro ao analisar o arquivo JSON de músicas.";
        return resultado;
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

            for(auto& it : musicasNaPlaylist){
                cout << "Codigo de musicas na playlist: " << it << endl;
            }

            readerPlaylists.setJSONData(playlists);

            if (!readerPlaylists.writeJSONToFile("../data/Playlists.json")) {
                resultado.second = "Erro ao atualizar o arquivo JSON da playlist com a nova música.";
                return resultado;
            }

            resultado.first = true;
            return resultado;
        }
    }

    resultado.second = "Playlist não encontrada.";
    return resultado;
}

pair<bool, string> Playlist::removerMusica(int idMusica) {
    JSONService readerPlaylists;
    JSONService readerMusicas;

    pair<bool, string> resultado = make_pair(false, "");

    if (!readerMusicas.openFile("../data/Musicas.json")) {
        resultado.second = "Não foi possível abrir o arquivo musicas.json";
        return resultado;
    }

    if (!readerPlaylists.openFile("../data/Playlists.json")) {
        resultado.second = "Não foi possível abrir o arquivo playlists.json";
        return resultado;
    }

    if (!readerPlaylists.parseJSON()) {
        resultado.second = "Erro ao analisar o arquivo JSON de playlists";
        return resultado;
    }

    if (!readerMusicas.parseJSON()) {
        resultado.second = "Erro ao analisar o arquivo JSON de músicas.";
        return resultado;
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
                resultado.second = "Erro ao atualizar o arquivo JSON da playlist.";
                return resultado;
            }

            resultado.first = true;
            return resultado;
        }
    }

    resultado.second = "Playlist não encontrada.";
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