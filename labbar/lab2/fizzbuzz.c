#include <stdio.h>
#include <stdlib.h>
void print_number(int num)
{
    if (num % 3 == 0 && num % 5 == 0)
    {
        printf("Fizz Buzz");
    }
    else if (num % 3 == 0)
    {
        printf("Fizz");
    }
    else if (num % 5 == 0)
    {
        printf("Buzz");
    }
    else
    {
        printf("%d", num);
    }
    return 0;
}

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        printf("ge ett tal");
        return 0; 
    }
    int limit = atoi(argv[1]);

    for (int i = 1; i <= limit; ++i)
    {
        print_number(i);
        if (i < limit)
        {
            printf(", ");
        }
    }
    printf("\n"); 
    return 0;
}