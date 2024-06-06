#include <iostream>
#include "Login.h"
using namespace std;

string Login::fazerLogin() {
    string email, senha;

    cout << "Digite o e-mail: ";
    cin >> email;
    cout << "Digite a senha: ";
    cin >> senha;

    if (autenticacao.validarLogin(email, senha)) {
        cout << "Login realizado com sucesso! Redirecionando para o menu...\n";
        return autenticacao.obterNomeUsuario(email);
    } else {
        cerr << "Erro: Credenciais incorretas.\n";
        return "";
    }
}
