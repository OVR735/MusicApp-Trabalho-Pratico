#include <iostream>
#include <fstream>
#include "Autenticacao.h"
#include "JsonService.cpp"
#include <utility>
#include <string>

using namespace std;

pair<bool, string> Autenticacao::validarRegistro(const string& nome, const string& email, const string& senha) {
    JSONService reader;

    pair<bool, string> resultado = make_pair(false, "");

    try {
        if (!reader.openFile("../data/Usuarios.json")) {
            throw runtime_error("Não foi possível abrir o arquivo Usuarios.json");
        }

        if (!reader.parseJSON()) {
            throw runtime_error("Erro ao analisar o arquivo JSON");
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
            {"premium", false}
        };

        usuarios["usuarios"].push_back(novoUsuario);

        reader.setJSONData(usuarios);

        if (!reader.writeJSONToFile("../data/Usuarios.json")) {
            throw runtime_error("Erro ao atualizar o arquivo JSON com o novo usuário.");
        }

        resultado.first = true;
        return resultado;
    } catch (const exception& e) {
        cerr << "Exceção capturada ao validar registro: " << e.what() << std::endl;
        resultado.first = false;
        resultado.second = "Erro ao realizar o registro. Verifique os dados e tente novamente.\n";
        return resultado;
    }
}
   
int Autenticacao::validarLogin(const string& email, const string& senha) {
    JSONService reader;

    try {
        if (!reader.openFile("../data/Usuarios.json")) {
            throw std::runtime_error("Não foi possível abrir o arquivo Usuarios.json");
        }

        if (!reader.parseJSON()) {
            throw std::runtime_error("Erro ao analisar o arquivo JSON");
        }

        json usuarios = reader.getJSON();
        for (const auto& usuario : usuarios["usuarios"]) {
            if (email == usuario["email"] && senha == usuario["senha"]) {
                return usuario["id"];
            }
        }

        return -1; 
    } catch (const std::exception& e) {
        std::cerr << "Exceção capturada ao validar login: " << e.what() << std::endl;
        return -1; 
    }
}