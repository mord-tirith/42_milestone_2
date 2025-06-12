#include <stdio.h>

int main() {
    char myChar = 'A';
    printf("\x1b[31m%c\x1b[0m\n", myChar); // Red text
    printf("\x1b[42m%c\x1b[0m\n", myChar); // Green background
    printf("\x1b[33m%c\x1b[0m\n", myChar); // Yellow text
    return 0;
}
