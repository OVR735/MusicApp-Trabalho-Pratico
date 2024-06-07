#include "Menu.h"
#include <iostream>

Menu::Menu(Usuario* usuario) : usuario(usuario) {}

void Menu::exibirMenu() {
    int opcao;
    while (true) {
        cout << "Bem-vindo, " << usuario->getNome() << "!\n";
        cout << "1. Alterar Credenciais\n2. Adicionar Playlist\n3. Mostrar minhas Playlists\n4. Logout\nEscolha uma opção: ";
        cin >> opcao;

        if (opcao == 1) {
            alterarCredenciais();
        } else if (opcao == 2) {
            adicionarPlaylistUsuario();
        } else if (opcao == 3){
            exibirPlaylists();
        } else if (opcao == 4) {
            cout << "Logout realizado com sucesso.\n";
            break;
        } else {
            cerr << "Opção inválida.\n";
        }
    }
}

void Menu::adicionarPlaylistUsuario(){
    std::string nomePlaylist, descricaoPlaylist;
    cout << "Digite o nome da playlist: ";
    cin.ignore();
    getline(cin, nomePlaylist);
    cout << "Digite a descrição da playlist: ";
    getline(cin, descricaoPlaylist);
    
    usuario->adicionarPlaylist(nomePlaylist, descricaoPlaylist);
}

void Menu::alterarCredenciais() {
    string novoNome, novoEmail, novaSenha;
    cout << "Digite o novo nome: ";
    cin.ignore();
    getline(cin, novoNome);
    cout << "Digite o novo email: ";
    getline(cin, novoEmail);
    cout << "Digite a nova senha: ";
    getline(cin, novaSenha);

    try {
        usuario->alterarCredenciais(novoNome, novoEmail, novaSenha);
        cout << "Credenciais atualizadas com sucesso.\n";
    } catch (const char* msg) {
        cerr << msg << endl;
    }
}

void Menu::operacaoExemplo() {
    cout << "Executando operação de exemplo...\n";
}

void Menu::exibirPlaylists() {
    JSONService reader;

    if (!reader.openFile("../data/Playlists.json")) {
        cout << "Não foi possível abrir o arquivo playlists.json\n";
        return;
    }

    if (!reader.parseJSON()) {
        cout << "Erro ao analisar o arquivo JSON\n";
        return;
    }

    json playlists = reader.getJSON();

    cout << "Suas Playlists:\n";
    for (const auto& playlist : playlists["playlists"]) {
        if (playlist["idUsuario"] == usuario->getId()) {
            cout << "ID: " << playlist["id"] << ", Nome: " << playlist["nome"] << ", Descrição: " << playlist["descricao"] << "\n";
        }
    }
}