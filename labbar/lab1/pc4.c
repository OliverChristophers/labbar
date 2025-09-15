#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {

    int num1 = atoi(argv[1]);
    int num2 = atoi(argv[2]);

    for (int i = 0; i < num1; i++) {
        for (int k = 0; k < num2 * (i + 1); k++) {
            printf("*");
        }
        puts("");
    }
    return 0;
}