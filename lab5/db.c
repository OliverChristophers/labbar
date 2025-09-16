#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>
#include "utils.h"
#include <ctype.h>


struct item
{
    char *name;
    char *description;
    int price;
    char *shelf;
};

typedef struct item item_t;


void print_item(item_t *a){
    printf("Name:  %s\n", a->name);
    printf("Desc:  %s\n", a->description);
    printf("Price: %d.%02d SEK\n", a->price / 100, a->price % 100);
    printf("Shelf: %s\n\n", a->shelf);

    }

item_t make_item(char *n, char *d, int p, char *s){
    item_t new_item = { .name = n, .description = d, .price = p, .shelf = s};
    return new_item;
}

item_t input_item()
{
    char *name = ask_question_string("Namn på varan: ");
    char *description = ask_question_string("Beskrivning av varan: ");
    int price = ask_question_int("Pris i ören: ");
    char *shelf = ask_question_shelf("Lagerhylla (t.ex. A25): ");

    return make_item(name, description, price, shelf);
}



char *magick(char *a1[], char *a2[], char *a3[], int a_len)
{
    char buf[255];

    char *w1 = a1[random() % a_len];
    char *w2 = a2[random() % a_len];
    char *w3 = a3[random() % a_len];

    strcpy(buf, w1);
    strcpy(buf, "-");
    strcpy(buf, w2);
    strcpy(buf, " ");
    strcpy(buf, w3);

    return strdup(buf);
}


void list_db(item_t *items, int l)
{
    printf("db innehåll:\n");
    for (int i = 0; i < l; ++i)
    {
        printf("%d. %s\n", i + 1, items[i].name);
    }
    printf("\n");
}



void edit_db(item_t *db)
{
    int index = ask_question_int("Vilken vara vill du redigera?: ");
    printf("\nNuvarande vara:\n");
    print_item(&db[index - 1]);

    printf("Ange ny information för varan:\n");
    db[index - 1] = input_item();

    printf("\nVaran har uppdaterats.\n\n");
}


void print_menu()
{
    printf("[L]ägga till en vara\n"
           "[T]a bort en vara\n"
           "[R]edigera en vara\n"
           "Ån[g]ra senaste ändringen\n"
           "Lista [h]ela varukatalogen\n"
           "[A]vsluta\n");
}


char ask_question_menu()
{
    print_menu();
    int found = 0;
    char *choice = "";
    while (found == 0)
    {
        choice = ask_question_string("Välj: ");
        char arr[] = {'L', 'T', 'R', 'G', 'H', 'A'};
        for (int i = 0; i < strlen(arr); i++) {
            if (arr[i] == toupper(choice[0]) && strlen(choice) == 1)  {
                found = 1;
                break;
            }
        }

        printf("\n");
    }
    return toupper(choice[0]);
}



int main()
{
    ask_question_menu();
    return 1;
}