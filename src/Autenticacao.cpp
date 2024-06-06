#include <iostream>
#include <fstream>
#include "Autenticacao.h"
#include "JsonService.cpp"
#include <utility>

using namespace std;

pair<bool, string> Autenticacao::validarRegistro(const string& nome, const string& email, const string& senha) {
    JSONService reader;

    pair<bool, string> resultado = make_pair(false, "");

    if (!reader.openFile("../data/Usuarios.json")) {
        resultado.second = "Não foi possível abrir o arquivo Usuarios.json";
        return resultado;
    }

    if (!reader.parseJSON()) {
        resultado.second = "Erro ao analisar o arquivo JSON";
        return resultado;
    }

    json usuarios = reader.getJSON();
    for (const auto& usuario : usuarios["usuarios"]) {
        if (email == usuario["email"]) {
            resultado.first = false;
            resultado.second = "Erro: Email já cadastrado.\n";
            return resultado;
        }
    }

    int newId = usuarios["usuarios"].back()["id"];
    newId += 1;
    json novoUsuario = {
        {"id", newId},
        {"nome", nome},
        {"email", email},
        {"senha", senha},
        {"playlists", {}},
    };

    usuarios["usuarios"].push_back(novoUsuario);

    reader.setJSONData(usuarios);

    if (!reader.writeJSONToFile("../data/Usuarios.json")) {
        resultado.first = false;
        resultado.second = "Erro ao atualizar o arquivo JSON com o novo usuário.";
        return resultado;
    }

    resultado.first = true;
    return resultado;
}

int Autenticacao::validarLogin(const string& email, const string& senha) {
    JSONService reader;

    if (!reader.openFile("../data/Usuarios.json")) {
        cerr << "Não foi possível abrir o arquivo Usuarios.json\n";
        return -1;
    }

    if (!reader.parseJSON()) {
        cerr << "Erro ao analisar o arquivo JSON\n";
        return -1;
    }

    json usuarios = reader.getJSON();
    for (const auto& usuario : usuarios["usuarios"]) {
        if (email == usuario["email"] && senha == usuario["senha"]) {
            return usuario["id"];
        }
    }

    return -1;
}

void Autenticacao::carregarUsuarios(unordered_map<string, pair<string, string>>& usuarios) {
    ifstream file("usuarios.txt");
    if (!file.is_open()) {
        return;
    }
    string username, email, senha;
    while (file >> username >> email >> senha) {
        usuarios[username] = make_pair(email, senha);
    }
    file.close();
}

void Autenticacao::salvarUsuarios(const unordered_map<string, pair<string, string>>& usuarios) {
    ofstream file("usuarios.txt");
    for (const auto& entry : usuarios) {
        file << entry.first << " " << entry.second.first << " " << entry.second.second << "\n";
    }
    file.close();
}

string Autenticacao::obterNomeUsuario(int userId) {
    JSONService reader;

    if (!reader.openFile("../data/Usuarios.json")) {
        throw "Não foi possível abrir o arquivo Usuarios.json";
    }

    if (!reader.parseJSON()) {
        throw "Erro ao analisar o arquivo JSON";
    }

    json usuarios = reader.getJSON();
    for (const auto& usuario : usuarios["usuarios"]) {
        if (userId == usuario["id"]) {
            return usuario["nome"];
        }
    }

    throw "Usuário não encontrado";
}
