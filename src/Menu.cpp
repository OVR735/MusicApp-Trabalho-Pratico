#include "Menu.h"
#include <iostream>

Menu::Menu(Usuario* usuario) : usuario(usuario) {}

void Menu::exibirMenu() {
    int opcao;
    while (true) {
        cout << "Bem-vindo, " << usuario->getNome() << "!\n";
        cout << "1. Alterar Credenciais\n2. Adicionar Playlist\n3. Mostrar minhas Playlists\n4. Logout\n5. Me tornar Premium\nEscolha uma opção: ";
        cin >> opcao;

        if (opcao == 1) {
            alterarCredenciais();
        } else if (opcao == 2) {
            adicionarPlaylistUsuario();
        } else if (opcao == 3){
            int selectedId = 0;
            vector<int> playlistsIds = exibirPlaylists();
            cout << "Escolha uma playlist: ";
            cin >> selectedId;
            int idPlaylist = playlistsIds[selectedId-1];
            cout << idPlaylist << endl;
            exibirMenuPlaylist(idPlaylist);
        } else if (opcao == 4) {
            cout << "Logout realizado com sucesso.\n";
            break;
         } else if (opcao == 5) {
            tornarUsuarioPremium();
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

void Menu::tornarUsuarioPremium() {
    if (usuario->isPremium()) {
        cout << "\n\nVocê já é um usuário premium.\n\n";
    } else {
        usuario->tornarPremium();
    }
}

void Menu::operacaoExemplo() {
    cout << "Executando operação de exemplo...\n";
}

vector<int> Menu::exibirPlaylists() {
    JSONService reader;
    vector<int> playlistsIds;

    if (!reader.openFile("../data/Playlists.json")) {
        cout << "Não foi possível abrir o arquivo playlists.json\n";
        return playlistsIds;
    }

    if (!reader.parseJSON()) {
        cout << "Erro ao analisar o arquivo JSON\n";
        return playlistsIds;
    }

    json playlists = reader.getJSON();

    cout << "Suas Playlists:\n";
    int count = 1;

    for (const auto& playlist : playlists["playlists"]) {
        if (playlist["idUsuario"] == usuario->getId()) {
            playlistsIds.push_back(playlist["id"]);
            cout << count << "): Nome: " << playlist["nome"] << ", Descrição: " << playlist["descricao"] << "\n";
            count++;
        }
    }

    return playlistsIds;
}

void Menu::exibirMenuPlaylist(int idPlaylist) {
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

    Playlist playlistEncontrada(idPlaylist);

    // for (const auto& playlist : playlists["playlists"]) {
    //     if (playlist["id"] == idPlaylist) {
    //         playlistEncontrada.setDescricao(playlist["descricao"]);
    //         playlistEncontrada.setNome(playlist["nome"]);
    //         playlistEncontrada.setID(playlist["id"]);
    //         vector<int> muscs = playlist["musicas"];
    //         for (int i = 0; i < muscs.size(); i++) {
    //             playlistEncontrada.musicas.push_back(muscs[i]);
    //         }
    //     }
    // }

    int opcao;
    while (true) {
        cout << "1. Adicionar música\n2. Remover música\n3. Mostrar músicas\n4. Remover Playlist \n5. Voltar\nEscolha uma opção: ";
        cin >> opcao;

        if (opcao == 1) {
            string nomeMusica;
            cout << "Digite o nome da música: ";
            cin.ignore();
            getline(cin, nomeMusica);
            playlistEncontrada.adicionarMusica(nomeMusica);
        } else if (opcao == 2) {
            string nomeMusica;
            cout << "Digite o nome da música: ";
            cin >> nomeMusica;
            playlistEncontrada.removerMusica(nomeMusica);
        } else if (opcao == 3) {
            playlistEncontrada.listarMusicas();
        } else if (opcao == 4) {
            usuario->removerPlaylist(idPlaylist);
        } else if(opcao==5){
            break;
        }else {
            cerr << "Opção inválida.\n";
        }
    }
}