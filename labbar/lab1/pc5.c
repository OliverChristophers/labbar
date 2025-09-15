#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int main(int argc, char *argv[]) {

    int num = atoi(argv[1]);
    int lim = floor(sqrt(num)) + 1;

    for (int i = 2; i < (num); i++) {
        for (int k = 2; k < (lim); k++) {
            if (i * k == num) {
                printf("%d är inte primtal\n", num);
                return 0;
            };
        }
    }
    printf("%d är ett primtal\n", num);
    return 0;
}