#include "Menu.h"
#include <iostream>
#include <cstdlib>
#include <Services.h>

Menu::Menu(Usuario* usuario) : usuario(usuario) {}

void Menu::exibirMenu() {
    int opcao;
    Services services;
    cout << "Bem-vindo, " << usuario->getNome() << "!\n";
    while (true) {
        services.clearConsole();
        cout << "1. Alterar Credenciais\n2. Adicionar Playlist\n3. Mostrar minhas Playlists\n4. Logout\n5. Me tornar Premium\nEscolha uma opção: ";
        cin >> opcao;

        if (opcao == 1) {
            alterarCredenciais();
        } else if (opcao == 2) {
            adicionarPlaylistUsuario();
        } else if (opcao == 3){
            int selectedId = 0;
            vector<int> playlistsIds = exibirPlaylists();
            if(playlistsIds.size() != 0){
                cout << "Escolha uma playlist: ";
                cin >> selectedId;
                int idPlaylist = playlistsIds[selectedId-1];
                exibirMenuPlaylist(idPlaylist);
            }
        } else if (opcao == 4) {
            services.clearConsole();
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

    if(count == 1){
        cout << "Você ainda não possui playlists! Adicione playlists com suas faixas preferidas. \n" << endl; 
    }

    return playlistsIds;
}

void Menu::exibirMenuPlaylist(int idPlaylist) {
    JSONService reader;
    Services services;

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

    int opcao;
    while (true) {
        cout << "1. Adicionar música\n2. Remover música\n3. Mostrar músicas\n4. Remover Playlist \n5. Voltar\nEscolha uma opção: ";
        cin >> opcao;
    
        if (opcao == 1) {
            string nomeMusica;
            cout << "Pesquise uma música: ";
            cin.ignore();
            getline(cin, nomeMusica);

            std::vector<int> musicasEncontradas = services.obterMusicasPorString(nomeMusica);

            int idSelecionado = 0;
            int count = 1;
            for (int id : musicasEncontradas) {
                cout << count << "): ";
                services.obterMusicaPorID(id);
                std::cout << "----------------------" << std::endl;
                count++;
            }

            cout << "Escolha uma musica: ";
            cin >> idSelecionado;

            int idMusica = musicasEncontradas[idSelecionado-1];

            std::pair<bool, std::string> result = playlistEncontrada.adicionarMusica(idMusica);
            if(result.first){
                cout << "Musica adicionada com sucesso!" << endl << endl;
            }
        } else if (opcao == 2) {
            std::vector<int> musicasEncontradas = playlistEncontrada.listarMusicas();

            int idSelecionado = 0;

            cout << "Escolha uma musica: ";
            cin >> idSelecionado;

            int idMusica = musicasEncontradas[idSelecionado-1];

            std::pair<bool, std::string> result = playlistEncontrada.removerMusica(idMusica);
            if(result.first){
                cout << "Musica removida com sucesso!" << endl << endl;
            }
        } else if (opcao == 3) {
            playlistEncontrada.listarMusicas();
        } else if (opcao == 4) {
            int confirmacao = 0;
            cout << "Você tem certeza? 1-Sim 2-Não: ";
            cin >> confirmacao;
            if(confirmacao == 1) {
                usuario->removerPlaylist(idPlaylist);
                cout << "Playlist removida com sucesso!" << endl;
                break;
            }
        } else if(opcao==5){
            break;
        } else {
            cerr << "Opção inválida.\n";
        }
    }
}
