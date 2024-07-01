#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "Autenticacao.h"
#include <unordered_map>
#include <string>
#include <utility>
#include <fstream>

using namespace std;

class AutenticacaoFixture {
public:
    Autenticacao autenticacao;

    // criarTemp() será chamado antes de cada caso de teste
    void criarTemp() {
        // Criação de um arquivo Usuarios.json temporário para os testes
        ofstream file("../data/Usuarios.json");
        file << R"({
            "usuarios": [
                {
                    "id": 1,
                    "nome": "Usuario Existente",
                    "email": "usuario_existente@example.com",
                    "senha": "senha_correta",
                    "playlists": [],
                    "premium": false
                }
            ]
        })";
        file.close();
    }

    // removerTemp() será chamado após cada caso de teste
    void removerTemp() {
        // Remover o arquivo Usuarios.json temporário após os testes
        remove("../data/Usuarios.json");
    }
};

TEST_CASE_FIXTURE(AutenticacaoFixture, "Testando validarRegistro com sucesso") {
    criarTemp();
    string nome = "Teste";
    string email = "teste@example.com";
    string senha = "1234";

    auto resultado = autenticacao.validarRegistro(nome, email, senha);
    CHECK(resultado.first == true);
    removerTemp();
}

TEST_CASE_FIXTURE(AutenticacaoFixture, "Testando validarRegistro com email já cadastrado") {
    criarTemp();
    string nome = "Teste";
    string email = "usuario_existente@example.com"; // Suponha que este email já exista no JSON
    string senha = "1234";

    auto resultado = autenticacao.validarRegistro(nome, email, senha);
    CHECK(resultado.first == false);
    CHECK(resultado.second == "Erro: Email já cadastrado.\n");
    removerTemp();
}

TEST_CASE_FIXTURE(AutenticacaoFixture, "Testando validarLogin com sucesso") {
    criarTemp();
    string email = "usuario_existente@example.com"; // Suponha que este usuário exista no JSON
    string senha = "senha_correta";

    int userId = autenticacao.validarLogin(email, senha);
    CHECK(userId == 1); // Suponha que o ID do usuário existente é 1
    removerTemp();
}

TEST_CASE_FIXTURE(AutenticacaoFixture, "Testando validarLogin com falha") {
    criarTemp();
    string email = "usuario_nao_existente@example.com";
    string senha = "senha_errada";

    int userId = autenticacao.validarLogin(email, senha);
    CHECK(userId == -1);
    removerTemp();
}