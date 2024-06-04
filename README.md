# MusicApp-Trabalho-Pratico
Aplicativo inspirado no app de músicas spotify. 
Feito para o trabalho prático da matéria Programação e Desenvolvimento de Software 2 da Universidade Federal de Minas Gerais 

## Instalando o CMake:
Para instalar o CMake no Ubuntu, execute os seguintes comandos no terminal: 
  
  ```sudo apt update```  
  
  ```sudo apt install cmake```

Para instalar o CMake no Windows, execute o seguinte comando no terminal:
  
  ```wget https://github.com/Kitware/CMake/releases/download/v3.21.3/cmake-3.21.3.tar.gz```


Para compilar o projeto, siga estas etapas:

1. Crie uma pasta `build` na raiz do projeto:

    ```sh
    mkdir build
    cd build
    ```

2. Execute o CMake a partir da pasta `build`:

    ```sh
    cmake ..
    ```

3. Compile o projeto:

    ```sh
    cmake --build .
    ```

## Execução

Após a compilação, você encontrará um Target executável chamado `MusicApp` (ou `MusicApp.exe` no Windows) na pasta `build`. Execute-o a partir da linha de comando:

```sh
./MusicApp