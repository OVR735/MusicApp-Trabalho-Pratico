#ifndef SERVICES_H
#define SERVICES_H

#include "Autenticacao.h"

class Services {
public:
    Services();
    vector<int> obterMusicasPorString(string pesquisa);
    bool obterStatusUsuario(int userId);
    void clearConsole();
private:
    
};

#endif // SERVICES_H
