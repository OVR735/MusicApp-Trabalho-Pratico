cmake_minimum_required(VERSION 3.10)

# Nome do projeto
project(MusicApp)

# Definição do padrão C++
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Adiciona o diretório de cabeçalhos ao caminho de pesquisa
include_directories(include)

# Adiciona os arquivos de origem

include(FetchContent)

FetchContent_Declare(
    json
    GIT_REPOSITORY https://github.com/nlohmann/json.git
    GIT_TAG v3.11.2  # Substitua pela versão desejada
)

FetchContent_MakeAvailable(json)


add_executable(MusicApp main.cpp src/Registro.cpp src/Autenticacao.cpp src/Login.cpp src/Menu.cpp src/Usuario.cpp src/UsuarioFree.cpp src/UsuarioPremium.cpp src/Playlist.cpp)

target_link_libraries(MusicApp PRIVATE nlohmann_json::nlohmann_json)