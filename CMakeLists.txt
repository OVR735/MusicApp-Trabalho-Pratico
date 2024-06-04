cmake_minimum_required(VERSION 3.10)

# Nome do projeto
project(MusicApp)

# Definição do padrão C++
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Adiciona o diretório de cabeçalhos ao caminho de pesquisa
include_directories(include)

# Adiciona os arquivos de origem
add_executable(MusicApp main.cpp src/Registro.cpp src/Autenticacao.cpp)
