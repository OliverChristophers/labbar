#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>
#include "utils.h"


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



int main(int argc, char *argv[])
{
    char *array1[] = { "Laser",        "Polka",    "Extra" };
    char *array2[] = { "förnicklad",   "smakande", "ordinär" };
    char *array3[] = { "skruvdragare", "kola",     "uppgift" };

    int array_size = 3;

    if (argc < 2)
    {
        printf("Usage: %s number\n", argv[0]);
    }
    else
    {
        item_t db[16]; // Array med plats för 16 varor
        int db_siz = 0; // Antalet varor i arrayen just nu

        int items = atoi(argv[1]); // Antalet varor som skall skapas

        if (items > 0 && items <= 16)
        {
        for (int i = 0; i < items; ++i)
        {
            // Läs in en vara, lägg till den i arrayen, öka storleksräknaren
            item_t item = input_item();
            db[db_siz] = item;
            ++db_siz;
        }
        }
        else
        {
        puts("Sorry, must have [1-16] items in database.");
        return 1; // Avslutar programmet!
        }

        for (int i = db_siz; i < 16; ++i)
        {
            char *name = magick(array1, array2, array3, array_size); // TODO: Lägg till storlek
            char *desc = magick(array1, array2, array3, array_size); // TODO: Lägg till storlek
            int price = random() % 200000;
            char shelf[] = { random() % ('Z'-'A') + 'A',
                            random() % 10 + '0',
                            random() % 10 + '0',
                            '\0' };
            item_t item = make_item(name, desc, price, strdup(shelf));

            db[db_siz] = item;
            ++db_siz;
        }

        // Skriv ut innehållet
        list_db(db, 16);
        printf("\n\n\n");
        edit_db(db);
        printf("\n\n\n");
        list_db(db, 16);

    }
    return 0;
}