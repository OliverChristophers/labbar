#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "utils.h"

#include <stdlib.h>


int read_string(char *buf, int buf_siz)
{
    int count = 0;    
    int c;      

    while ((c = getchar()) != '\n' && c != EOF) {
        if (count < buf_siz - 1) {
            buf[count++] = c; 
        }
    }
    buf[count] = '\0';
    return count;
}

bool not_empty(char *str)
{
  return strlen(str) > 0;
}

answer_t ask_question(char *question, check_func *f, convert_func *g) {
    int buf_siz = 255;
    char buffer[buf_siz]; 

    do {
        printf("%s", question);
        read_string(buffer, buf_siz);
    }
    while (!f(strdup(buffer)));

    return g(buffer);

}

int ask_question_int(char *question)
{
  answer_t answer = ask_question(question, is_number, (convert_func *) atoi);
  return answer.int_value;
}

char *ask_question_string(char *question)
{
  return ask_question(question, not_empty, (convert_func *) strdup).string_value;
}
bool is_number(char *str){
    for (int i = 0; i < strlen(str); i++){
        if (!isdigit(str[i]) && (i != 0 || (str[0] != '-' || strlen(str) == 1))) {
                return false;
        }
    }
    return true;
}
