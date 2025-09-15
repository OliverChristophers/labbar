#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>


bool is_number(char *str){
    for (int i = 0; i < strlen(str); i++){
        if (!isdigit(str[i]) && (i != 0 || (str[0] != '-' || strlen(str) == 1))) {
                return false;
        }        
    }
    return true;
}


int main(int argc, char *argv[]) {
    if (!(is_number(argv[1]) && is_number(argv[2]))) {
        printf("give me numbers!!!!!\n");
        return 0;
    };

    int num1 = atoi(argv[1]);
    int num2 = atoi(argv[2]);

    int a = num1;
    int b = num2;


    while (num1 != num2)
    {
        if(num1 > num2){
            num1 -= num2;
        }
        else{
            num2 -= num1;
        }
    }

    printf("gcd(%d", a);
    printf(", %d)", b);
    printf(" = %d\n", num1);
    
    return 0;
}