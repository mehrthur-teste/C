#include <stdio.h>

int count; // global variable
void func1(void);
void func2(void);

void func1(void) {
    int temp; // local variable
    temp = count;
    func2();
    printf(" count é : %d\n", temp);
}

void func2(void) {
    int count; // local variable
    for (count = 0; count < 10; count++) {
        putchar('.');
    }
}

int main() {
    count = 100;
    func1();
    return 0;
}
