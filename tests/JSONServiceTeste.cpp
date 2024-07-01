#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "JSONService.h"

TEST_CASE("Testando JSONService") {
    JSONService jsonService;

    CHECK(jsonService.openFile("../data/Usuarios.json") == true);
    CHECK(jsonService.parseJSON() == true);

    auto jsonData = jsonService.getJSON();
    CHECK(jsonData.is_object() == true);
    CHECK(jsonData.contains("usuarios") == true);
}
