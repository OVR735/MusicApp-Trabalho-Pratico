#ifndef SERVICES_H
#define SERVICES_H

#include <vector>
#include <string>

using namespace std;
class Services {
public:
    Services();
    vector<int> obterMusicasPorString(string pesquisa);
    bool obterStatusUsuario(int userId);
    void clearConsole();
    void obterMusicaPorID(int id);
private:
    
};

#endif // SERVICES_H
