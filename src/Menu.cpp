#include "Menu.h"
#include <iostream>
#include <cstdlib>
#include <Services.h>
#include <limits>
#include <stdexcept>
using namespace std;

Menu::Menu(Usuario* usuario) : usuario(usuario) {}

void Menu::exibirMenu() {
    int opcao;
    Services services;

    while (true) {
        try {
            cout << "Bem-vindo, " << usuario->getNome() << "!\n";
            cout << "1. Alterar Credenciais\n2. Adicionar Playlist\n3. Mostrar minhas Playlists\n4. Logout\n5. Me tornar Premium\nEscolha uma opção: ";
            cin >> opcao;
    
            if (cin.fail()) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
                services.clearConsole();
                throw invalid_argument("Opção inválida. Por favor, insira um número válido.");
            }

            services.clearConsole();

            switch(opcao) {
                case 1:
                    alterarCredenciais();
                    break;
                case 2:
                    adicionarPlaylistUsuario();
                    break;
                case 3: {
                    int selectedId = 0;
                    vector<int> playlistsIds = exibirPlaylists();
                    if (!playlistsIds.empty()) {
                        cout << "Escolha uma playlist: ";
                        cin >> selectedId;

                        if (cin.fail() || selectedId < 1 || selectedId > playlistsIds.size()) {
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // descarta a entrada inválida
                            services.clearConsole();
                            throw out_of_range("Seleção de playlist inválida.");
                        }

                        int idPlaylist = playlistsIds[selectedId - 1];
                        exibirMenuPlaylist(idPlaylist);
                    }
                    break;
                }
                case 4:
                    cout << "Logout realizado com sucesso.\n";
                    return;
                case 5:
                    tornarUsuarioPremium();
                    break;
                default:
                    throw out_of_range("Opção inválida. Por favor, escolha uma opção entre 1 e 5.");
            }
        } catch (const invalid_argument &e) {
            cerr << "\nErro: " << e.what() << "\n\n";
        } catch (const out_of_range &e) {
            cerr << "\nErro: " << e.what() << "\n\n";
        } catch (const exception &e) {
            cerr << "\nErro inesperado: " << e.what() << "\n\n";
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
        cout << "Você já é um usuário premium.\n\n";
    } else {
        usuario->tornarPremium();
    }
}

vector<int> Menu::exibirPlaylists() {
    vector<int> playlistsIds;
    JSONService reader;

    try {
        if (!reader.openFile("../data/Playlists.json")) {
            throw runtime_error("Não foi possível abrir o arquivo playlists.json");
        }

        if (!reader.parseJSON()) {
            throw runtime_error("Erro ao analisar o arquivo JSON");
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

        if (count == 1) {
            cout << "Você ainda não possui playlists! Adicione playlists com suas faixas preferidas. \n" << endl;
        }
    } catch (const runtime_error &e) {
        cerr << "Erro: " << e.what() << endl;
    } catch (const exception &e) {
        cerr << "Erro inesperado: " << e.what() << endl;
    }

    return playlistsIds;
}

void Menu::exibirMenuPlaylist(int idPlaylist) {
    while (true) {
        try {
            JSONService reader;
            Services services;

            if (!reader.openFile("../data/Playlists.json")) {
                throw runtime_error("Não foi possível abrir o arquivo playlists.json");
            }

            if (!reader.parseJSON()) {
                throw runtime_error("Erro ao analisar o arquivo JSON");
            }

            json playlists = reader.getJSON();
            Playlist playlistEncontrada(idPlaylist);

            int opcao;
            cout << "1. Adicionar música\n2. Remover música\n3. Mostrar músicas\n4. Remover Playlist \n5. Playlists Restantes \n6. Voltar\nEscolha uma opção: ";
            cin >> opcao;

            if (cin.fail()) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // descarta a entrada inválida
                throw invalid_argument("Opção inválida. Por favor, insira um número válido.");
            }

            services.clearConsole();

            switch (opcao) {
                case 1: {
                    string nomeMusica;
                    cout << "Pesquise uma música: ";
                    cin.ignore();
                    getline(cin, nomeMusica);

                    vector<int> musicasEncontradas = services.obterMusicasPorString(nomeMusica);
                    if (musicasEncontradas.empty()) {
                        cout << "Nenhuma música encontrada." << endl;
                        break;
                    }

                    int idSelecionado = 0;
                    int count = 1;
                    for (int id : musicasEncontradas) {
                        cout << count << "): ";
                        services.obterMusicaPorID(id);
                        cout << "----------------------" << endl;
                        count++;
                    }

                    cout << "Escolha uma música: ";
                    cin >> idSelecionado;

                    if (cin.fail() || idSelecionado < 1 || idSelecionado > musicasEncontradas.size()) {
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // descarta a entrada inválida
                        throw out_of_range("Seleção de música inválida.");
                    }

                    int idMusica = musicasEncontradas[idSelecionado - 1];
                    pair<bool, string> result = playlistEncontrada.adicionarMusica(idMusica);
                    if (result.first) {
                        cout << "Música adicionada com sucesso!" << endl << endl;
                    } else {
                        throw runtime_error(result.second);
                    }
                    break;
                }
                case 2: {
                    vector<int> musicasEncontradas = playlistEncontrada.listarMusicas();
                    if (musicasEncontradas.empty()) {
                        cout << "Nenhuma música encontrada na playlist." << endl;
                        break;
                    }

                    int idSelecionado = 0;
                    cout << "Escolha uma música: ";
                    cin >> idSelecionado;

                    if (cin.fail() || idSelecionado < 1 || idSelecionado > musicasEncontradas.size()) {
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // descarta a entrada inválida
                        throw out_of_range("Seleção de música inválida.");
                    }

                    int idMusica = musicasEncontradas[idSelecionado - 1];
                    pair<bool, string> result = playlistEncontrada.removerMusica(idMusica);
                    if (result.first) {
                        cout << "Música removida com sucesso!" << endl << endl;
                    } else {
                        throw runtime_error(result.second);
                    }
                    break;
                }
                case 3:
                    playlistEncontrada.listarMusicas();
                    break;
                case 4: {
                    int confirmacao = 0;
                    cout << "Você tem certeza? 1-Sim 2-Não: ";
                    cin >> confirmacao;

                    if (cin.fail() || (confirmacao != 1 && confirmacao != 2)) {
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // descarta a entrada inválida
                        throw invalid_argument("Confirmação inválida.");
                    }

                    if (confirmacao == 1) {
                        usuario->removerPlaylist(idPlaylist);
                        cout << "Playlist removida com sucesso!" << endl;
                        return;
                    }
                    break;
                }
                case 5:
                    usuario->playlistsRestantes();
                    break;
                case 6:
                    return;
                default:
                    throw out_of_range("Opção inválida. Por favor, escolha uma opção entre 1 e 6.");
            }
        } catch (const invalid_argument &e) {
            cerr << "Erro: " << e.what() << endl;
        } catch (const out_of_range &e) {
            cerr << "Erro: " << e.what() << endl;
        } catch (const runtime_error &e) {
            cerr << "Erro: " << e.what() << endl;
        } catch (const exception &e) {
            cerr << "Erro inesperado: " << e.what() << endl;
        }
    }
}
