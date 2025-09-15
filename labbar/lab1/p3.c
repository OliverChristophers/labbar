#include <stdio.h>

int main() {
    int t = 0;
    for (int i = 0; i < 11; i++) {
        for (int k = 0; k < i; k++) {
            printf("*");
            t++;
        }
        puts("");
    }
    printf("%d\n", t);
    return 0;
}