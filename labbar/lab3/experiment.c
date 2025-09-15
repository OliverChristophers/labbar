#include <stdio.h>
#include <stdlib.h>

#include "utils.h"

typedef union { 
  int   int_value;
  float float_value;
  char *string_value;
} answer_t;

typedef bool check_func(char *str);
typedef answer_t convert_func(char *str);
 
answer_t ask_question(char *question, check_func *f, convert_func *g) {
    int buf_siz = 255;
    char buffer[buf_siz]; 
    
    char *str;
    do {
        print(question);
        str = read_string(buffer, buf_siz);
    }
    while (f(str));

    return g(str);

}
bool not_empty(char *str)
{
  return strlen(str) > 0;
}

int main() {


}