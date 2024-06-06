#include <iostream>
#include "../include/Playlist.h"
#include "JsonService.h"
#include <utility>

using namespace std;

Playlist::Playlist(const string& nome, const string& descricao, int idUser) : nome(nome), descricao(descricao), idUsuario(idUser) {
    JSONService reader;

    if (!reader.openFile("../data/Playlists.json")) {
        cout << "Não foi possível abrir o arquivo playlists.json" << endl;
    }

    if (!reader.parseJSON()) {
        cout << "Erro ao analisar o arquivo JSON" << endl;
    }

    json playlists = reader.getJSON();

    int newId = playlists["playlists"].back()["id"];
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

pair<bool, string> Playlist::adicionarMusica() {
    JSONService reader;

    pair<bool, string> resultado = make_pair(false, "");

    if (!reader.openFile("../data/Playlists.json")) {
        resultado.second = "Não foi possível abrir o arquivo playlists.json";
        return resultado;
    }

    if (!reader.parseJSON()) {
        resultado.second = "Erro ao analisar o arquivo JSON";
        return resultado;
    }

    json playlists = reader.getJSON();

    for (auto& playlist : playlists["playlists"]) {
        if(getID() == playlist["id"]) {  
            json novaMusica = {
                // {"id", id},
                // {"nome", musica.getNome()},
                // {"artista", musica.getArtista()},
                // {"duracao", musica.getDuracao()}
            };

            playlist["musicas"].push_back(1);

            reader.setJSONData(playlists);

            if (!reader.writeJSONToFile("../data/Playlists.json")) {
                resultado.first = false;
                resultado.second = "Erro ao atualizar o arquivo JSON da playlist com a nova música.";
                return resultado;
            }
        }
    }

    return resultado;
}

pair<bool, string> Playlist::removerMusica(string nomeMusica) {
    JSONService reader;
    pair<bool, string> resultado = make_pair(false, "");
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

int Playlist::getID() {
    return id;
}