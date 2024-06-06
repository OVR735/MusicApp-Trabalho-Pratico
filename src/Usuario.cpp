#include "Usuario.h"
#include <iostream>

Usuario::Usuario(int sessionId){
    JSONService reader;

    if (!reader.openFile("../data/Usuarios.json")) {
        throw "deu erro fml";
    }

    // Analisar o conteúdo do JSON
    if (!reader.parseJSON()) {
        throw "deu erro fml";
    }

    json usuarios = reader.getJSON();

    for (auto& user : usuarios["usuarios"]) {
        if(sessionId == user["id"]) {
            id = sessionId;
            nome = user["nome"];
            email = user["email"];
            senha = user["senha"];
            vector<int> vetor;
            for (auto& idPlaylist : usuarios["playlists"]) {
                vetor.push_back(idPlaylist);
            }
            playlists = vetor;
            cout << "coisa";
        }
    }

    throw "deu erro fml"; //Programar exceção depois
}

const std::string& Usuario::getNome() const { return nome; }
const std::string& Usuario::getEmail() const { return email; }
const std::string& Usuario::getSenha() const { return senha; }

void Usuario::removerPlaylist(const std::string& descricao) {

}

Usuario::~Usuario() {

}