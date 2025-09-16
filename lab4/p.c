#include <stdio.h>

void print(char *str)
{
    while (*str != '\0')
    {
        putchar(*str);
        str++;
    }
}


int main() {
    print("knfdnsdlfmsd");
    return 1;
}