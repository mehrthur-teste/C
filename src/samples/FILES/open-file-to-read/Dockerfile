# Use a imagem base do Alpine com Clang pré-instalado
FROM gcc:latest

# Defina o diretório de trabalho
WORKDIR /app

# Copie o código-fonte C para dentro do contêiner
COPY open-file.c .

# Compile o programa C usando clang
RUN clang -o open-file open-file.c

# Defina o comando para executar o programa
CMD ["./open-file"]
