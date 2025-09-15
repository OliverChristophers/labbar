#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "utils.h"

int main(void)
{
    srandom(time(NULL)); 
    int secret_number = (random() % 100);
    int guess = 0;
    int guesses_left = 8;

    char *name = ask_question_string("Skriv in ditt namn:\n");
    printf("Du %s, jag tänker på ett tal mellan 1 och 100... kan du gissa vilket?\n", name);

    while (guesses_left > 0)
    {
        guess = ask_question_int("");

        if (guess < secret_number)
        {
            puts("För litet!");
        }
        else if (guess > secret_number)
        {
            puts("För stort!");
        }
        else 
        {
            printf("Bingo!\n");
            printf("Det tog %s %d gissningar att komma fram till %d\n", name, 8 - guesses_left + 1, secret_number);
            return 0;
        }

        guesses_left--;
    }

    printf("Nu har du slut på gissningar! Jag tänkte på %d!\n", secret_number);

    return 0;
}