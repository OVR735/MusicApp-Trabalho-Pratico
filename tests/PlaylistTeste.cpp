#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "Playlist.h"

TEST_CASE("Testando Playlist") {
    Playlist playlists(0);

    //Para realizar esses testes, o JSON deve ter ao menos uma playlist
    CHECK(playlists.listarMusicas().size() == 1);
    CHECK(playlists.buscarMusica("Musica Teste").first == true);
    CHECK(playlists.buscarMusica("Nao Identificado").first == false);
    CHECK(playlists.getDescricao() != "");
    CHECK(playlists.getNome() != "");
    CHECK(playlists.getID() == 0);

    CHECK(playlists.removerMusica(0).first == true);
}