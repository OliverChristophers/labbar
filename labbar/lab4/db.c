#include <stdio.h>
#include <stdbool.h>

#include "utils.h"

struct item
{
    char *name;
    char *description;
    int *price;
    char *shelf;
};

typedef struct item item_t;


void print_item(item_t *a){
    printf("Name: %s\nDesc: %s\nPrice: %d SEK\nShelf: %s", a->name, a->description, a->price, a->shelf);
}

item_t make_item(char *n, char *d, int p, char *s){
    item_t new_item = { .name = n, .description = d, .price = p, .shelf = s};
    return new_item;
}

item_t input_item(){

}