#include <iostream>
#include "Registro.h"
#include <utility>

using namespace std;

void Registro::registrarUsuario() {
    string username, email, senha;

    cout << "Digite o nome de usuário: ";
    cin >> username;
    cout << "Digite o e-mail: ";
    cin >> email;
    cout << "Digite a senha: ";
    cin >> senha;

    pair<bool, string> resultado = autenticacao.validarRegistro(username, email, senha);
    if (resultado.first) {
        cout << "Usuário registrado com sucesso!\n";
    } else {
        cerr << "Erro ao registrar o usuário.\n";
        cerr << resultado.second << "\n";
    }
}
