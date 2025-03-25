To use mac os

nano hello.c

#include <stdio.h>

int main() {
    printf("Hello, World!\n");
    return 0;
}


clang -o hello hello.c

./hello
