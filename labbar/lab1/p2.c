#include <stdio.h>

int main() {
    for (int i = 1; i < 11; i++) {
        printf("%d\n", ((i - 1) % 10) + 1);
    }
    return 0;
}