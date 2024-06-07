#include "Usuario.h"
#include <iostream>

Usuario::Usuario(int sessionId)
{
	JSONService reader;

	if (!reader.openFile("../data/Usuarios.json"))
	{
		throw "Não foi possível abrir o arquivo Usuarios.json";
	}

	if (!reader.parseJSON())
	{
		throw "Erro ao analisar o arquivo JSON";
	}

	json usuarios = reader.getJSON();

	for (auto &user : usuarios["usuarios"])
	{
		if (sessionId == user["id"])
		{
			id = sessionId;
			nome = user["nome"];
			email = user["email"];
			senha = user["senha"];
			for (auto &idPlaylist : user["playlists"])
			{
				playlists.push_back(idPlaylist);
			}
			return;
		}
	}

	throw "Usuário não encontrado";
}
const int Usuario::getId() const { return id; }
const std::string& Usuario::getNome() const { return nome; }
const std::string& Usuario::getEmail() const { return email; }
const std::string& Usuario::getSenha() const { return senha; }

void Usuario::removerPlaylist(int idPlaylist)
{
	JSONService readerUsuarios;
	JSONService readerPlaylists;

	if (!readerUsuarios.openFile("../data/Usuarios.json") || (!readerPlaylists.openFile("../data/Playlists.json")))
	{
		throw "Erro ao ler arquivo!";
	}
	// Analisar o conteúdo do JSON
	if (!readerUsuarios.parseJSON() || !readerPlaylists.parseJSON())
	{
		throw "deu erro aqui";
	}

	json usuarios = readerUsuarios.getJSON();
	json playlists = readerPlaylists.getJSON();

	for (auto &user : usuarios["usuarios"])
	{
		if (id == user["id"])
		{
			auto &userPlaylists = user["playlists"];

			auto it = std::find(userPlaylists.begin(), userPlaylists.end(), idPlaylist);
			if (it != userPlaylists.end())
			{
				userPlaylists.erase(it);

				readerUsuarios.setJSONData(usuarios);

				if (!readerUsuarios.writeJSONToFile("../data/Usuarios.json"))
				{
					throw "Erro ao atualizar o arquivo JSON";
				}

				std::cout << "Playlist do usuário removida com sucesso." << std::endl;
			}
			else
			{
				std::cerr << "Playlist não encontrada para o usuário" << std::endl;
			}
		}
	}

	/* for (auto &user : usuarios["usuarios"])
	{
		if (id == user["id"])
		{
			readerUsuarios.setJSONData(usuarios);

			if (!readerUsuarios.writeJSONToFile("../data/Usuarios.json"))
			{
				throw "Erro ao atualizar o arquivo JSON";
			}
		}
	} */

	for (auto &playlist : playlists["playlists"])
	{
		auto &playlistsArray = playlists["playlists"];
		for (auto it = playlistsArray.begin(); it != playlistsArray.end(); ++it)
		{
			if ((*it)["id"] == id)
			{
				playlistsArray.erase(it);
				break;
			}
		}

		readerPlaylists.setJSONData(playlists);

		if (!readerPlaylists.writeJSONToFile("../data/Playlists.json"))
		{
			throw "Erro ao atualizar o arquivo JSON";
		}
	}
}

void Usuario::alterarCredenciais(const string &novoNome, const string &novoEmail, const string &novaSenha)
{
	JSONService reader;

	if (!reader.openFile("../data/Usuarios.json"))
	{
		throw "Não foi possível abrir o arquivo Usuarios.json";
	}

	if (!reader.parseJSON())
	{
		throw "Erro ao analisar o arquivo JSON";
	}

	json usuarios = reader.getJSON();

	for (auto &user : usuarios["usuarios"])
	{
		if (id == user["id"])
		{
			user["nome"] = novoNome;
			user["email"] = novoEmail;
			user["senha"] = novaSenha;
			reader.setJSONData(usuarios);

			if (!reader.writeJSONToFile("../data/Usuarios.json"))
			{
				throw "Erro ao atualizar o arquivo JSON com as novas credenciais.";
			}

			nome = novoNome;
			email = novoEmail;
			senha = novaSenha;
			return;
		}
	}

	throw "Usuário não encontrado";
}
