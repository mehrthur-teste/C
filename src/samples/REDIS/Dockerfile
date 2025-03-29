# Imagem base com o GCC e as ferramentas necessárias
FROM gcc:latest

# Instalar hiredis
RUN apt-get update && \
    apt-get install -y libhiredis-dev

# Adicionar o código fonte do seu programa
COPY redis_example.c /usr/src/redis.c

# Compilar o código C
RUN gcc -o /usr/src/redis_example /usr/src/redis.c -lhiredis

# Executar o programa
CMD ["/usr/src/redis_example"]
